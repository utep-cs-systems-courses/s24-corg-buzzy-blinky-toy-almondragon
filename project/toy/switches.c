#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"


char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  char button1 = (p2val & SW1) ? 0 : 1;
  char button2 = (p2val & SW2) ? 0 : 1;
  char button3 = (p2val & SW3) ? 0 : 1;
  char button4 = (p2val & SW4) ? 0 : 1;

  // setting each button to a respective state when pressed

  if (button1){
    current_state = twinkle;
  }
  if (button2){
    current_state = hushBaby;
  }
  if (button3) {
    current_state = rockBaby;
  }
  if (button4){
    current_state = sunshine;
  }
  
}
