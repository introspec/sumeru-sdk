<h2>Board Specifications</h2>

    <table class=spec-table>
	<tr class=table-heading-row>
	    <td colspan="3" class="spec-txt">
		<i>Core Specs</i>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    CPU
	    </td>
	    <td>
		    RISC-V RV32IM @ 72 MHz
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
	    </td>
	    <td>
		    4K I-Cache, 4K D-Cache
	    </td>
	</tr>
	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    RAM
	    </td>
	    <td>
		    32 MB SDRAM
	    </td>
	</tr>
	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    Storage
	    </td>
	    <td>
		    4 MB Flash (YAFF2),<br/>microSD slot (FAT32)
	    </td>
	</tr>

	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    Display
	    </td>
	    <td>
		    320 x 480 16-bit LCD Display<br/>
		    w/ Resistive Touch
	    </td>
	</tr>


	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    Onboard
	    </td>
	    <td>
		    Bluetooth LE<br/>
		    USB Serial Port<br/>
		    Realtime Clock<sup>+</sup><br/>
		    Li-ion 3.7v Battery Management<br/>
	    </td>
	</tr>

	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    Power
	    </td>
	    <td>
		    2.9v - 6v; 0.5W @ 5v	    
	    </td>
	</tr>

	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    Size
	    </td>
	    <td>
		    10 x 6.5 x 0.8 cm
	    </td>
	</tr>

	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    Features
	    </td>
	    <td>
		    OTA Field Upgradeable via both, UART and BLE<br/>
		    Stock RISC-V foundation GCC 9.2.0 toolchain<br/>
		    C, C++, SCM Scheme, CAML-Light,<br/>
		    microPython<sup>+</sup>, Python<sup>+</sup><br/>
		    LVGL.io, GMP, GSL, PRCE2,<br/>
		    FreeType, Cairo, Expat, ncurses,
		    ...
	    </td>
	</tr>
    </table>
    <hr/>
    <br/>

    <h2>Peripherals</h2>
    <table>
	<tr class=table-heading-row>
	    <td class="spec-txt">
		<i>Peripheral</i>
	    </td>
	    <td class="spec-txt">
		<i>Count</i>
	    </td>
	    <td class="spec-txt-expand"> 
		<i>Connection</i>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    UART
	    </td>
	    <td style="text-align: center;">
		    3
	    </td>
	    <td>
		    1. USB Serial Port<br/>
		    2. BLE Rx/Tx<br/>
		    3. Available
	    </td>
	</tr>
	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    SPI
	    </td>
	    <td style="text-align: center;">
		    5
	    </td>
	    <td>
		    1. Flash<br/>
		    2. microSD Slot<br/>
		    3. LCD Display<br/>
		    4. Touch controller<br/>
		    5. Available<br/>
	    </td>
	</tr>
	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    I2C
	    </td>
	    <td style="text-align: center;">
		    2
	    </td>
	    <td>
		    1. Available<br/>
		    2. Available<br/>
	    </td>
	</tr>
	<tr>
	    <td colspan=3>
		<hr/>
	    </td>
	</tr>
	<tr class=table-content-row-a>
	    <td>
		    GPIO
	    </td>
	    <td style="text-align: center;">
		    19
	    </td>
	    <td>
		    GPIO<sup>*</sup>: 9</br>
		    GPI<sup>*</sup>: 1 (BTN) + 5 (CLK IN)<br/>
		    GPO: 1 (LED) + 3 (PWM)<br/>
		    <p class=text-12p-blue>
			<sup>*</sup>All input pins support<br/>
			individual level interrupt<br/>
			triggers.<br/>
		    </p>
	    </td>
	</tr>
    </table>

