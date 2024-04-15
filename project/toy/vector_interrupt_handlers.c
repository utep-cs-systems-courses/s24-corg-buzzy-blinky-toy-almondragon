#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  switch(current_state){
  case waiting:
    state_waiting();
  case twinkle:
    state_twinkle();
  case hushBaby:
    state_hushBaby();
  case rockBaby:
    state_rockBaby();
  case sunshine:
    state_sunshine();
  }
}
