# msp430-sandbox

Some tests of the [MSP-EXP430G2](http://www.ti.com/tool/msp-exp430g2) kit from Texas Instruments.
The kit uses a [MSP430g2553](http://www.ti.com/product/MSP430G2553) MCU whose datasheet can be found [here](http://www.ti.com/lit/ds/symlink/msp430g2553.pdf) and user guide [there](http://www.ti.com/lit/ug/slau144j/slau144j.pdf).

## Installing on Ubuntu 16.04

`$ apt-cache search msp430`
```
binutils-msp430 - Utilitaires binaires de prise en charge de cibles TI MSP430
gcc-msp430 - Compilateur GNU C (compilateur croisé pour MSP430)
mspdebug - Outil de débogage pour les microcontrôleurs MSP430
gdb-msp430 - The GNU debugger for MSP430
msp430-libc - Standard C library for TI MSP430 development
msp430mcu - Spec files, headers and linker scripts for TI's MSP430 targets
```

Install the compiler:

`$ sudo apt-get install gcc-msp430`

Install the debugger/program-the-board-stuff

`$ sudo apt-get install mspdebug`

Setup udev rules:

`$ sudo vim /etc/udev/rules.d/46-TI_launchpad.rules`
```
ATTRS{idVendor}=="0451", ATTRS{idProduct}=="f432", MODE="0660", GROUP="plugdev"
```

Restart udev:

`$ sudo /etc/init.d/udev restart`

## First program
The headers of the devices are in `/usr/msp430/include`, and our MCU is `<msp430g2553.h>`.

Compile a file:

`$ msp430-gcc -mmcu=msp430g2553 -g -o main.elf main.c`

Programming the board:

`$ mspdebug rf2500`
```
prog main.elf
run
```

Or:

`$ mspdebug rf2500 "prog main.elf"`
