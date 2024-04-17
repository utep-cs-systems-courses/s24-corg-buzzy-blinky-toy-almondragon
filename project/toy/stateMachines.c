#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

State current_state = waiting;

void state_twinkle(){
  twinkle_song();
  led_greenOn();
}

void state_hushBaby(){
  hushBaby_song();
  led_redOn();

}

void state_rockBaby(){
  rockBaby_song();
  lightOn();
}

void state_sunshine(){
  sunshine_song();
  lightsOff();
}

void state_waiting(){
  lightsOff();
}
