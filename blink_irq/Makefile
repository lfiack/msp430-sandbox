#makefile configuration
NAME	= blink_irq
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

CC		= msp430-gcc
LD		= msp430-gcc

CFLAGS	= -Os -Wall -g -mmcu=msp430g2553
LDFLAGS	= -mmcu=msp430g2553

all: ${NAME}.elf

${NAME}.elf: ${OBJ}
	${LD} ${LDFLAGS} -o $@ ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c $<

flash: ${NAME}.elf
	mspdebug rf2500 "prog ${NAME}.elf"

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf ${NAME}.elf
