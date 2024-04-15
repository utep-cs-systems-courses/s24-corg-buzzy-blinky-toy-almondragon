COMMON_OBJECTS 	= main.o
CPU 		= msp430g2553
CFLAGS 		= -mmcu=${CPU} -I../h 
LFLAGS		= -L/opt/ti/msp430_gcc/include

CC 		= msp430-elf-gcc
AS 		= msp430-elf-as

all: combined.elf

combined.elf: ${COMMON_OBJECTS} buzzer.o p2_interrupt_handler.o stateMachines.o vector_interrupt_handlers.o led.o switches.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: combined.elf
	msp430loader.sh $^
clean:
	rm -f *.o *.elf
