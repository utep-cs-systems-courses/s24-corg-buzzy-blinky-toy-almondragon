#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  switch(current_state){
  case waiting:
    state_waiting();
    break;
  case twinkle:
    state_twinkle();
    break;
  case hushBaby:
    state_hushBaby();
    break;
  case rockBaby:
    state_rockBaby();
    break;
  case sunshine:
    state_sunshine();
    break;
  }
}
