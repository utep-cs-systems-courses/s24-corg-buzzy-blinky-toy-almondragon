COMMON_OBJECTS = main.o
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: musicBox.elf

musicBox.elf: ${COMMON_OBJECTS} buzzer.o led.o p2_interrupt_handler.o stateMachines.o vector_interrupt_handlers.o switches.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: musicBox.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
