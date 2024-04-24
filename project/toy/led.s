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
	cmp.b #37, &counter_led_sec
	jnz hush_else
	mov.b #0, &counter_led_sec
	mov #0, r12
	call #transition
huhs_else:
	inc &led_sec
	cmp #80, &led_sec
	jnc end
	mov #0, &led_sec
	inc.b &counter_led_sec
	mov.b &counter_led_sec, r12
	sub #1, r12
	mov.b hush_lights(r12), r13
	cmp.b #0, r13
	jnz lights_zero
	cmp.b #1, r13
	jnz lights_one
	cmp.b #2, r13
	jnz lights_two
	cmp.b #3, r13
	jnz lights_three

rock_led:
	cmp.b #44, &counter_led_sec
	jnz rock_else
	mov.b #0, &counter_led_sec
	mov #0, r12
	call #transition
rock_else:
	inc &led_sec
	cmp #70, &led_sec
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

sunshine_led:
	cmp.b #72, &counter_led_sec
	jnz sunshine_else
	mov.b #0, &counter_led_sec
	mov #0, r12
	call #transition
sunshine_else:
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

DTB_BTD:
	inc.b &green_count
	cmp.b &green_dim_start, &green_count
	jnc green_if
	mov.b #0, &green_count
	bis #1, &P1OUT
	jmp red_if

green_if:
	cmp.b &green_dim_start, &green_Count
	jc red_if
	and #~1, &P1OUT

red_if:
	cmp.b &red_bright_start, &red_count
	jnc red_if_2
	mov.b #0, &red_count
	bis #64, &P1OUT
	jmp DTB_BTD_else

red_if_2:
	cmp.b &red_bright_start, &red_count
	jc DTB_BTD_else
	and #~64, &P1OUT

DTB_BTD_else:
	cmp #250, &led_sec
	jnc end
	mov #0, &led_sec
	inc.b &red_bright_start
	sub.b #1, &green_dim_start
	mov.b #0, r14
	cmp.b &green_dim_start, r14
	jnc reset_light
	move.b #4, &green_dim_start

reset_light:
	mov.b #4, r14
	cmp.b &red_bright_start, r14
	jnc end
	mov.b #1, &red_bright_start
	jmp end
end:
	ret
