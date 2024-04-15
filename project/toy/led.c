#include <msp430.h>
#include "led.h"
#include "libTimer.h"

void led_init(){
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;

}

void led_greenOn(){
  P1OUT &= ~LEDS;
  P1OUT |= LED_GREEN;

}

void led_redOn(){
  P1OUT &= ~LEDS;
  P1OUT |= LED_RED;

}

void lightOn(){
  P1OUT &= ~LEDS;
  P1OUT |= LEDS;

}

void lightsOff(){
  P1OUT &= ~LEDS;

}

