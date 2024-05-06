#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port_2()
{
  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES; // checking if a button has been pressed
    switch_interrupt_handler();
  }
}
