#include <msp430.h>
#include "led.h"
#include "libTimer.h"
#include "stateMachines.h"

int led_sec = 0;
char counter_led_sec = 0;

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

void twinkle_led(){
  char twinkle_lights[44] = {1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 3, 0, 2, 2, 0, 1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 3, 0, 1, 1, 0, 2, 0, 2, 0, 1, 0, 1, 0, 2, 0, 2, 0, 3};
  if(counter_led_sec == 44){
    counter_led_sec = 0;
    transition_state(waiting);
  }else{
    led_sec++;
    if(led_sec>65){
      led_sec = 0;
      counter_led_sec++;
      char index = counter_led_sec -1;
      if(twinkle_lights[index] == 0)
	lightsOff();
      if(twinkle_lights[index] == 1)
	led_redOn();
      if(twinkle_lights[index] == 2)
	led_greenOn();
      if(twinkle_lights[index] == 3)
	lightOn();
    }

  }
}

void hush_led(){
  char hush_lights[37] = {2, 0, 2, 0, 2, 0, 2, 0, 1, 0, 2, 0, 3, 0, 3, 3, 0, 2, 0, 2, 0, 3, 0, 3, 0, 3, 0, 2, 0, 3, 0, 1, 0, 1, 1, 0, 2};
  if(counter_led_sec == 37){
    counter_led_sec = 0;
    transition_state(waiting);
  }else{
    led_sec++;
    if(led_sec>80){
      led_sec = 0;
      counter_led_sec++;
      char index = counter_led_sec -1;
      if(hush_lights[index] == 0)
	lightsOff();
      if(hush_lights[index] == 1)
	led_redOn();
      if(hush_lights[index] == 2)
	led_greenOn();
      if(hush_lights[index] == 3)
	lightOn();
    }
  }

}

void rock_led(){
  char rock_lights[44] = {2, 0, 2, 0, 2, 0, 3, 3, 0, 1, 0, 2, 0, 2, 0, 1, 0, 1, 1, 0, 1, 0, 2, 0, 1, 0, 2, 0, 3, 0, 3, 0, 1, 0, 3, 0, 2, 2, 0, 2, 0, 2, 0, 2};
  if(counter_led_sec == 44){
    counter_led_sec = 0;
    transition_state(waiting);
  }else{
    led_sec++;
    if(led_sec>70){
      led_sec = 0;
      counter_led_sec++;
      char index = counter_led_sec -1;
      if(rock_lights[index] == 0)
	lightsOff();
      if(rock_lights[index] == 1)
	led_redOn();
      if(rock_lights[index] == 2)
	led_greenOn();
      if(rock_lights[index] == 3)
	lightOn();
    }
  }

}

void sunshine_led(){
  char sunshine_lights[72] = {3, 0, 2, 0, 3, 1, 0, 1, 0, 1, 0, 3, 0, 1, 0, 2, 0, 2, 0, 2, 0, 3, 0, 1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 1, 0, 1, 0, 2, 0, 3, 0, 1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 1, 0, 1, 0, 2, 0, 2, 0, 3, 0};
  if(counter_led_sec == 72){
    counter_led_sec = 0;
    transition_state(waiting);
  }else{
    led_sec++;
    if(led_sec > 65){
      led_sec = 0;
      counter_led_sec++;
      char index = counter_led_sec -1;
      if(sunshine_lights[index] == 0)
	lightsOff();
      if(sunshine_lights[index] == 1)
	led_redOn();
      if(sunshine_lights[index] == 2)
	led_greenOn();
      if(sunshine_lights[index] == 3)
	lightOn();
    }
  }
}

void DTB_BTD(){


}
