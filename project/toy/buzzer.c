#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init(){
  timerAUpmode();
  P2SEL &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCRO = cycles;
  CCR1 = cucles >> 1;
}

void twinkle_song(){
  static int current_index = 0;
  int notes[42] = {7644,7644,5102,5102,4545,4545,5102, 5727,5727,6067,6811,6811,7644,5102,5102,5727,5727,6067,6067,6811,5102,5102,5727,5727,6067,6067,6811,7644,7644,5102,5102,4545,4545,5102,5727,5727,6067,6811,6811,7644};
  if (current_index == 42){
    current_index = 0;
  }else{
    buzzer_set_period(notes[current_index]);
    current_index++;

  }

}

void hushBaby_song(){
  static int current_index = 0;
  int notes[22] ={7644,7644,6811,6067,6067,6811,5102,5102,6067,6067,6811,7644,7644,6811,6067,6067,6811,5102,5102,6067,,6811,7644};
  if (current_index == 22){
    current_index = 0;
  }else{
    buzzer_set_period(notes[current_index]);
    current_index++;
  }

}

void rockBaby_song(){
  static int current_index = 0;
  int notes[28] = {5102,5102,5102,6067,5102,5102,6067,6811,6811,6811,4050,6811,6811,4050,4545,4545,4545,5102,4545,4545,5102,5102,5102,5102,6067,5102,5102,6067};
  if (current_index == 22){
    current_index = 0;
  }else{
    buzzer_set_period(notes[current_index]);
    current_index++;
  }
}

void sunshine_song(){
  static int current_index = 0;
  int notes[59] = {7644,7644,6067,6067,5102,5102,6067,7644,7644,6067,6067,5102,5102,6067,7644,6067,5102,6067,7644,6067,5102,6067,7644,6067,5102,6067,7644,7644,6067,6067,5102,5102,6067,7644,7644,6067,6067,5102,5102,6067,7644,6067,5102,6067,7644,6067,5102,6067,7644,6067,5102,6067,7644,7644,6067,6067,5102,5102,6067};
  if (current_index == 59){
    current_index = 0;
  }else{
    buzzer_set_period(notes[current_index]);
    current_index++;
  }
}
