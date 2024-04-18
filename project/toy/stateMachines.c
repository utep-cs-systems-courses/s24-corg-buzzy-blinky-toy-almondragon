#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

State current_state = waiting;

void state_twinkle(){
  twinkle_song();
  twinkle_led();
}

void state_hushBaby(){
  hushBaby_song();
  hush_led();

}

void state_rockBaby(){
  rockBaby_song();
  rock_led();
}

void state_sunshine(){
  sunshine_song();
  sunshine_led();
  
}

void state_waiting(){
  buzzer_set_period(0);
  lightOn();
}
void transition_state(State next_state){
  current_state = next_state;
}
