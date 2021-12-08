#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#define INFO_SIZE	128
#define BD_ADDR_SIZE	6

typedef struct discovery_info {
    int			valid;
    int			printed;
    unsigned int 	flags;
    unsigned short	conn_itvl_min;
    unsigned short	conn_itvl_max;
    bdaddr_t		bdaddr;
    char		name[32];
    char		txpower;
} discovery_info_t;


static discovery_info_t discovered[INFO_SIZE];


static int
print_discovered_info(int idx)
{
    char addr[18];
    ba2str(&discovered[idx].bdaddr, addr);

    if (discovered[idx].printed == 0) {
	if (discovered[idx].name[0] != 0) {
	    printf("%s\t%s\n", addr, discovered[idx].name);
	    discovered[idx].printed = 2;
	} else {
	    printf("%s\n", addr);
	    discovered[idx].printed = 1;
	}
    } else if (discovered[idx].printed == 1 &&
	       discovered[idx].name[0] != 0)  
    {
	    printf("%s\t%s\n", addr, discovered[idx].name);
	    discovered[idx].printed = 2;
    }
}


static void
add_discovery_info(int idx, le_advertising_info *info)
{

#if 0
    for (int i = 0; i < info->length; ++i)
	printf("0x%x ", info->data[i]);
    printf("\n");
#endif

    discovered[idx].valid = 1;
    bcopy(info->bdaddr.b, discovered[idx].bdaddr.b, BD_ADDR_SIZE);
    for (int i = 0; i < info->length;) {
	switch(info->data[i]) {
	    case 2: /* More UUIDS */
		++i;
		break;
	    case 1: /* Flags */
		discovered[idx].flags = info->data[i + 1];
		i += 2;
		break;
	    case 0x0A: /* Tx Power Level */
		discovered[idx].txpower = info->data[i + 1];
		i += 2;
		break;
	    case 0x12: /* Conninterval */
		bcopy(&discovered[idx].conn_itvl_min, 
		      &info->data[i + 1], 
		      sizeof(unsigned short));
		bcopy(&discovered[idx].conn_itvl_max, 
		      &info->data[i + 3], 
		      sizeof(unsigned short));
		i += 5;
		break;
	    case 0x07: /* Local Name */
		strncpy(discovered[idx].name, 
			&info->data[i + 2],
			info->data[i + 1] - 2);
		i += info->data[i + 1];
		break;
	    default:
		/* printf("Unknown AD Type: 0x%x\n", info->data[i]); */
		return;
	}
    }
}


static int 
print_advertising_devices(int dd)
{
    unsigned char buf[HCI_MAX_EVENT_SIZE], *ptr;
    struct hci_filter nf, of;
    socklen_t olen;
    hci_event_hdr *hdr;
    int num, len;
    olen = sizeof(of);
    if (getsockopt(dd, SOL_HCI, HCI_FILTER, &of, &olen) < 0) {
    	printf("Could not get socket options\n");
    	return -1;
    }
    hci_filter_clear(&nf);
    hci_filter_set_ptype(HCI_EVENT_PKT, &nf);
    hci_filter_set_event(EVT_LE_META_EVENT, &nf);
    if (setsockopt(dd, SOL_HCI, HCI_FILTER, &nf, sizeof(nf)) < 0) {
    	printf("Could not set socket options\n");
    	return -1;
    }
   
    /* Wait for 10 report events */
    num = 10;
    while (num--) {
    	evt_le_meta_event *meta;
       	le_advertising_info *info;
    	while ((len = read(dd, buf, sizeof(buf))) < 0) {
	    if (errno == EAGAIN || errno == EINTR)
		continue;
	    goto done;
	}
    	hdr = (void *) (buf + 1);
    	ptr = buf + (1 + HCI_EVENT_HDR_SIZE);
       	len -= (1 + HCI_EVENT_HDR_SIZE);
    	meta = (void *) ptr;

    	if (meta->subevent != EVT_LE_ADVERTISING_REPORT)
       	    goto done;

	info = (le_advertising_info *) (meta->data + 1);

	int found = 0;

	for (int i = 0; i < INFO_SIZE; ++i) 
	{
	    if (discovered[i].valid &&
		bcmp(discovered[i].bdaddr.b, info->bdaddr.b, BD_ADDR_SIZE) == 0)
	    {
		add_discovery_info(i, info);
		print_discovered_info(i);
		found = 1;
		break;
	    }
	}

	if (found == 0) {
	    for (int i = 0; i < INFO_SIZE; ++i) {
		if (discovered[i].valid == 0) {
		    add_discovery_info(i, info);
		    print_discovered_info(i);
		    break;
		}
	    }
	}
    }
done:
    setsockopt(dd, SOL_HCI, HCI_FILTER, &of, sizeof(of));
    if (len < 0)
	return -1;
    return 0;
}


void
ble_inquiry()
{
    int dev_id;
    int err, opt, dd;
    uint8_t own_type = 0x00;
    uint8_t scan_type = 0x01;
    uint8_t filter_type = 0;
    uint8_t filter_policy = 0x00;
    uint16_t interval = htobs(0x0010);
    uint16_t window = htobs(0x0010);
    // uint8_t filter_dup = 1;
    uint8_t filter_dup = 0; // don't filter duplicate

    dev_id = hci_get_route(NULL);
    dd = hci_open_dev( dev_id );
    if (dev_id < 0 || dd < 0) {
        perror("opening socket");
        exit(1);
    }



    err = hci_le_set_scan_parameters(dd, scan_type, interval, window,
            own_type, filter_policy, 1000);

    if (err < 0) {
        perror("Set scan parameters failed");
    }

    err = hci_le_set_scan_enable(dd, 0x01, filter_dup, 1000);

    if (err < 0) {
        perror("Enable scan failed");
        exit(1);
    }

    printf("LE Scan ... \n");

    memset(&discovered, 0, sizeof(discovered));
    err = print_advertising_devices(dd);

    if (err < 0) {
        perror("Could not receive advertising events");
        exit(1);
    }

    err = hci_le_set_scan_enable(dd, 0x00, filter_dup, 1000);

    if (err < 0) {
        perror("Disable scan failed");
        exit(1);
    }

    hci_close_dev(dd);
    exit(0);
}

