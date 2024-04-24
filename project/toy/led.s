	.arch msp430g2553
	.data
green_dim_start:	.byte 4
red_bright_start:	.byte 1
green_count:	.byte 0
red_count:	.byte 0
twinkle_lights:
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 3
	.byte 0
	.byte 2
	.byte 2
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
hush_lights:
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 3
	.byte 3
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 3
	.byte 0
	.byte 3
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 1
	.byte 0
	.byte 2
rock_lights:
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 3
	.byte 0
	.byte 2
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 2
sunshine_lights:
	.byte 3
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2
	.byte 0
	.byte 3
	.byte 0
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.byte 2
	.byte 0
	.byte 2

	.align 2
led_seconds:	.word 0
counter_led_sec:	.byte 0
	.p2align 1,0
	.text
	.global led_init
	.global led_greenOn
	.global led_redOn
	.global lightOn
	.global lightsOff
	.global twinkle_led
	.global hush_led
	.global rock_led
	.global sunshine_led
	.extern P1OUT
	.extern P1DIR

led_init:
	bis #65, &P1DIR
	mov #lightsOff, r0

led_greenOn:
	push #go
	mov #lightsOff, r0

go:
	bis #1, &P1OUT
	pop r0

led_redOn:
	push #ro
	mov #lightsOff, r0

ro:
	bis #64, &P1OUT
	pop r0

lightOn:
	push #lon
	mov #lightsOff, r0

lon:	bis #65, &P1OUT
	pop r0

lightsOff:
	and #~65, &P1OUT
	pop r0

twinkle_led:
twinkle_else:	

hush_led:
huhs_else:	

rock_led:
rock_else:	

sunshine_led:
sunshine_else:	
	
