#ifndef __SUMERU_UNISTD_H
#define __SUMERU_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#define FIONREAD	1000

#define UART1_FD	3
#define UART2_FD	4

int	sumeru_mount_root_fs();

int	sumeru_mount_fs(
    		char *mp, int flash_dev,
    		int start_block, int end_block,
    		int flash_erase_size, int flash_prog_size);

int	sumeru_umount_fs(char *mp);

int	sumeru_mount_sdcard(unsigned int unit, unsigned char speed);
int	sumeru_umount_sdcard();

void	waitms(unsigned int ms);

struct dirent {
    char		d_name[128];
};

struct dir_ctx*	opendir(const char *name);
struct dirent*  readdir(struct dir_ctx *dirp);
void		rewinddir(struct dir_ctx *dirp);
int		closedir(struct dir_ctx *dirp);

typedef struct dir_ctx DIR;


int	rmdir(const char *name);

#ifdef __cplusplus
}
#endif

#endif
