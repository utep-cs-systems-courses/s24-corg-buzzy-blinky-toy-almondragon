#include <msp430.h>
#include "led.h"
#include "libTimer.h"
#include "stateMachines.h"


char green_dim_start = 4; // limit for green light
char red_bright_start = 1; // limit for red light
char green_count = 0; // count how many times light is green
char red_count = 0; // count how many times light is red

int led_sec = 0; // counting current interrupts
char counter_led_sec = 0; // count number of times led_sec has met limit

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

// does light show according to melody of song... same for all other functions below excluding DTB_BTD
void twinkle_led(){
  char twinkle_lights[44] = {1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 3, 0, 2, 2, 0, 1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 3, 0, 1, 1, 0, 2, 0, 2, 0, 1, 0, 1, 0, 2, 0, 2, 0, 3};
  if(counter_led_sec == 44){ //checks if all lights have been shown
    counter_led_sec = 0;
    transition_state(waiting);
  }else{
    led_sec++;
    if(led_sec>65){ // turns a light on every 65th of a second
      led_sec = 0;
      counter_led_sec++;
      char index = counter_led_sec -1;
      if(twinkle_lights[index] == 0) // if value is zero, no lights on
	lightsOff();
      if(twinkle_lights[index] == 1) // if value is one, only red is on
	led_redOn();
      if(twinkle_lights[index] == 2) // if value is two, only green is on
	led_greenOn();
      if(twinkle_lights[index] == 3) // if value is three, both lights on
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
  green_count++;
  if(green_count >= green_dim_start){ // checks if limit has been met for green lights
    green_count = 0;
    P1OUT |= LED_GREEN;
  } else if (green_count < green_dim_start){
    P1OUT &= ~LED_GREEN;
  }
  if(red_count >= red_bright_start){ // checks if limit has been met for red lights
    red_count = 0;
    P1OUT|= LED_RED;
  } else if(red_count < red_bright_start){
    P1OUT &= ~LED_RED;
  }
  red_count++;
  led_sec++;
  if(led_sec >= 250){ // turns on light every 250th of a second
    led_sec = 0;
    red_bright_start++;
    green_dim_start--;
    if(green_dim_start <= 0){
      green_dim_start = 4;
    }
    if(red_bright_start > 4){
      red_bright_start = 1;
    }
  }
  
}
