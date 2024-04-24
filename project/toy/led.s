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
	.global DTB_BTD
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
	cmp.b #44, &counter_led_sec
	jnz twinkle_else
	mov.b #0, &counter_led_sec
	mov #0, r12
	call #transition
twinkle_else:
	inc &led_sec
	cmp #65, &led_sec
	jnc end
	mov #0, &led_sec
	inc.b &counter_led_sec
	mov.b &counter_led_sec, r12
	sub #1, r12
	mov.b twinkle_lights(r12), r13
	cmp.b #0, r13
	jnz lights_zero
	cmp.b #1, r13
	jnz lights_one
	cmp.b #2, r13
	jnz lights_two
	cmp.b #3, r13
	jnz lights_three

hush_led:
huhs_else:	

rock_led:
rock_else:	

sunshine_led:
sunshine_else:	
	
lights_zero:
	push #end
	mov #lightsOff, r0
lights_one:
	push #end
	mov #led_redOn, r0
lights_two:
	push #end
	mov #led_greenOn, r0
lights_three:
	push #end
	mov #lightOn, r0
end:
	ret
