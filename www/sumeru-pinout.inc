#define PROW_HEADER(a,b,cll,c,d,clr,imgf)		\
    <tr>					\
	<td class=cll style="padding-top: 4px;">		\
	    a					\
	</td>					\
	<td class="pt-left" style="padding-top: 4px;">		\
	    b					\
	</td>					\
	<td rowspan=20>				\
	    <img src=imgf/> 			\
	</td>					\
	<td class=pt-right style="padding-top: 4px;">		\
	    c					\
	</td>					\
	<td class=clr style="padding-top: 4px;">		\
	    d					\
	</td>					\
    </tr>

#define PROW(a,b,cll,c,d,clr) 				\
    <tr>					\
	<td class=cll>				\
	    a					\
	</td>					\
	<td class=pt-left>			\
	    b					\
	</td>					\
	<td class=pt-right>			\
	    c					\
	</td>					\
	<td class=clr>				\
	    d					\
	</td>					\
    </tr>

<div>
<h2>Header P4:</h2>
<table class="pinout-table" style="font-size: 21px">
    PROW_HEADER(GPIO - 10, 	: F144, 	pt-left-gpio, 	F143 :, 	GPIO - 09, 	pt-right-gpio, "images/sumeru-header-p4.png")
    PROW(GPIO - 08, 	: F142, 	pt-left-gpio, 	F141 :, 	GPIO - 07, 	pt-right-gpio)
    PROW(GPIO - 06, 	: F138, 	pt-left-gpio, 	F137 :, 	GPIO - 05, 	pt-right-gpio)
    PROW(I2C1 - SDA, 	: F136, 	pt-left-i2c, 	F135 :, 	I2C1 - SCL,	pt-right-i2c)
    PROW(I2C0 - 11, 	: F133, 	pt-left-i2c, 	F132 :, 	I2C1 - SDA,	pt-right-i2c)
    PROW(SPI4 - MISO, 	: F129, 	pt-left-spi,	F128 :, 	SPI4 - MOSI,	pt-right-spi)
    PROW(SPI4 - SCK, 	: F127, 	pt-left-spi, 	F126 :, 	SPI4 - SS,	pt-right-spi)
    PROW(UART2 - RX, 	: F125, 	pt-left-uart,	F124 :, 	UART2 - TX,	pt-right-uart)
    PROW(PWM - 02, 	: F121, 	pt-left-pwm,	F120 :, 	PWM - 01,	pt-right-pwm)
    PROW(GPIO - 03, 	: F119, 	pt-left-gpio, 	F115 :, 	SPI2 - SCK (TOUCH),	pt-right-spi)
    PROW(SPI2 - SS (TOUCH), 	: F114, 	pt-left-spi,	F113 :, 	SPI2 - MOSI (TOUCH),	pt-right-spi)
    PROW(GPIO - 04, 	: F112, 	pt-left-gpio,	F111 :, 	SPI2 - MISO (TOUCH),	pt-right-spi)
    PROW(PWM - 00 (LCD),: F110, 	pt-left-pwm,	F106 :, 	GPIO - 02 (LCD),	pt-right-gpio)
    PROW(SPI1 - MISO (LCD), 	: F105, 	pt-left-spi,	F104 :, 	SPI1 - MOSI (LCD), 	pt-right-spi)
    PROW(SPI1 - DCX (LCD), 	: F103, 	pt-left-spi, 	F101 :, 	-,		pt-right)
    PROW(SPI1 - SCK (LCD), 	: F100, 	pt-left-spi,	F99 :, 		SPI1 - SS (LCD),	pt-right-spi)
    PROW(GPIO - 01, 	: F98, 		pt-left-gpio,	FC4 :, 		CLKIN - 04 (GPIO - 25), pt-right-gpi)
    PROW(CLKIN - 03 (GPIO - 24), 	: FC4, 		pt-left-gpi,	FC6 :, 		CLKIN - 02 (GPIO - 23), pt-right-gpi)
    PROW(UART1 - RX : (CONSOLE), 	: URX, 		pt-left-uart,	UTX :, 		UART0 - TX (CONSOLE), 	pt-right-uart)
    PROW(, 		GND, 		pt-left,  	3.3V,		,		pt-right)
</table>

<h3>Remarks:</h3>
<b>
<ul>
<li>LED-3 is connected to GPIO-00</li>
<li>PUSH-BUTTON-1 is connected to GPIO-31</li>
<li>LCD (SPI1,GPIO-02,PWM-00) & TOUCH (SPI2) pins are available for use in non-LCD models.</li>
<li>CLKIN pins can only be used for input.</li>
<li>UART0 is reserved for the USB-Serial Console.</li>
<li>Incorrect I/O pin usage can damage the board.</li>
</ul>
</b>

<hr/>


<h2>Header P1:</h2>
<table class="pinout-table" style="font-size: 21px">
    PROW_HEADER(, 	: GND, 		pt-left, 	3.3v :,		, 	pt-right, "images/sumeru-header-p1.png")
    PROW(BLE RESET, 	: BRST, 	pt-left, 	B20 :, 	BLE - P2.0, 	pt-right-ble)
    PROW(BLE - P1.5, 	: B15, 		pt-left-ble, 	B14 :, 	BLE - P1.4, 	pt-right-ble)
    PROW(BLE UART RX, 	: BRX, 	pt-left-uart, 	BTX :, BLE UART TX,	pt-right-uart)
    PROW(SPI3 - SCK (microSD),	: F3, 	pt-left-spi, 	F7 :, SPI3 - MOSI (microSD),	pt-right-spi)
    PROW(SPI3 - SS (microSD),	: F10, 	pt-left-spi, 	F11 :, SPI3 - MISO (microSD),	pt-right-spi)
    PROW(SPI0 - MISO (Flash),	: FWMI, 	pt-left-spi, 	FWMO :, SPI0 - MOSI (Flash),	pt-right-spi)
    PROW(SPI0 - SS (Flash),	: FWSS, 	pt-left-spi, 	FWCL :, SPI0 - SCK (Flash),	pt-right-spi)
    PROW(BLE - P0.6, 	: B06, 		pt-left-ble, 	B07 :, 	BLE - P0.7 (RTC), 	pt-right-ble)
    PROW(FPGA nCE, 	: FnCE, 		pt-left, 	FnCFG :, 	FPGA nCFG, 	pt-right)
    PROW(BLE - P1.2 (RTC), 	: B12, 		pt-left-ble, 	B13 :, 	BLE - P1.3 (RTC), 	pt-right-ble)
    PROW(CLKIN - 00 (GPIO - 21), 	: FC2, 		pt-left-gpi,	FC3 :, 		CLKIN - 01 (GPIO - 22), pt-right-gpi)

</table>


<h3>Remarks:</h3>
<b>
<ul>
    <li>CLKIN pins can only be used for input.</li>
    <li>SPI0 port is reserved for onboard FLASH.
    <li>SPI3 pins can only be used if the microSD slot is not being used.</li>
    <li>Incorrect I/O pin usage can damage the board.</li>
</ul>

<hr/>
<h2>FPC J2:</h2>
<table>
    <tr>
	<td>PIN-1</td> <td class=pt-right>: Touchpad X1</td>
    </tr>
    <tr>
	<td>PIN-2</td> <td class=pt-right>: Touchpad Y1</td>
    </tr>
    <tr>
	<td>PIN-3</td> <td class=pt-right>: Touchpad X2</td>
    </tr>
    <tr>
	<td>PIN-4</td> <td class=pt-right>: Touchpad Y2</td>
    </tr>
    <tr>
	<td>PIN-5</td> <td class=pt-right>: GND</td>
    </tr>
    <tr>
	<td>PIN-6</td> <td class=pt-right>: 3.3v</td>
    </tr>
    <tr>
	<td>PIN-8</td> <td class=pt-right>: Not connected</td>
    </tr>
    <tr>
	<td>PIN-9</td> <td class=pt-right-spi>: SPI1 - SS : LCD</td>
    </tr>
    <tr>
	<td>PIN-10</td> <td class=pt-right-spi>: SPI1 - DCX : LCD</td>
    </tr>
    <tr>
	<td>PIN-11</td> <td class=pt-right-spi>: SPI1 - SCK : LCD</td>
    </tr>
    <tr>
	<td>PIN-12</td> <td class=pt-right>: 3.3v</td>
    </tr>
    <tr>
	<td>PIN-13</td> <td class=pt-right-spi>: SPI1 - MOSI : LCD</td>
    </tr>
    <tr>
	<td>PIN-14</td> <td class=pt-right-spi>: SPI1 - MISO : LCD</td>
    </tr>
    <tr>
	<td>PIN-15</td> <td class=pt-right-gpio>: GPIO - 02 : LCD RESET</td>
    </tr>
    <tr>
	<td>PIN-16 to PIN-32</td> <td class=pt-right>: GND</td>
    </tr>
    <tr>
	<td>PIN-33</td> <td class=pt-right-pwm>: PWM - 00 : LCD Backlight</td>
    </tr>
    <tr>
	<td>PIN-34 to PIN-37</td> <td class=pt-right>: GND</td>
    </tr>
    <tr>
	<td>PIN-38</td> <td class=pt-right>: (SW12 = 1, SW11 = 0): LCD IM0</td>
    </tr>
    <tr>
	<td>PIN-39</td> <td class=pt-right>: (SW10 = 1, SW09 = 0): LCD IM1</td>
    </tr>
    <tr>
	<td>PIN-40</td> <td class=pt-right>: 3.3v - LCD IM2</td>
    </tr>
</table>


<h3>Remarks:</h3>
<b>
<ul>
    <li>Configuration: IM0 = 1 (SW11), IM1 = 1 (SW9)</li>
    <li>Only one of SW12 or SW11 must me closed or a short will be caused.</li>
    <li>Only one of SW10 or SW09 must me closed or a short will be caused.</li>
    <li>Incorrect I/O pin usage can damage the board.</li>
</ul>

<hr/>

<h2>Onboard Buttons, Switches and Connectors</h2>
<h3>
<table>
    <tr>
    	<td>SW1</td> <td class=pt-right-gpio>: User-defined push-button (GPIO - 31)</td>
    </tr>
    <tr>
    	<td>SW2</td> <td class=pt-right>: Board RESET</td>
    </tr>
    <tr>
    	<td>SW3</td> <td class=pt-right>: Board Power Switch</td>
    </tr>
    <tr>
    	<td>SW3</td> <td class=pt-right>: BLE Power Switch</td>
    </tr>
    <tr>
    	<td>J1</td> <td class=pt-right>: 3.7v Li-ion Battery Connector</td>
    </tr>
    <tr>
    	<td>P2</td> <td class=pt-right-uart>: USB Serial Port (URX, UTX) and Power Connector</td>
    </tr>
    <tr>
    	<td>P3</td> <td class=ptr-right>: FPGA JTAG Connector</td>
    </tr>
    <tr>
    	<td>J4</td> <td class=ptr-right>: BLE CC2541 Programming Connector</td>
    </tr>
</table>
</h3>
</div>


