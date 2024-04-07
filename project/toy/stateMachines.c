#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

void state_twinkle(){
  twinkle_song();
}

void state_hushBaby(){
  hushBaby_song();

}

void state_rockBaby(){
  rockBaby_song();
}

void state_sunshine(){
  sunshine_song();
}

//void state_waiting(){
//}
