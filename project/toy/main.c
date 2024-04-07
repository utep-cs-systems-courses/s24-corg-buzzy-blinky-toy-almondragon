#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


void main(void){
  configueClocks();
  enableWDTInterrupts();
  switch_init();
  //led_inint();
  buzzer_init();
  or_sr(0x18);
}
