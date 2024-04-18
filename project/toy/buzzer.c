#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"


int buzzer_sec = 0;
char counter_buzzer_sec = 0;

void buzzer_init(){
  timerAUpmode();
  P2SEL &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void twinkle_song(){
  int notes[44]= {7644, 0, 7644, 0, 5102, 0 , 5102, 0, 4545, 0, 4545, 0, 5102, 5102, 0, 5727, 0, 5727, 0, 6067, 0, 6067, 0, 6811, 0, 6811, 0, 7644, 7644, 0, 5102, 0, 5102, 0, 5727, 0, 5727, 0, 6067, 0, 6067, 0, 6811, 6811};
  buzzer_sec++;
  if(counter_buzzer_sec == 44){
    counter_buzzer_sec = 0;
  }
  if(buzzer_sec >65){
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
    
  }

}

void hushBaby_song(){
  int notes[37] = {5102, 0, 6067, 0, 6067, 0, 6067, 0, 5727, 0, 6067, 0, 6811, 0, 6811, 6811, 0, 5102, 0, 5102, 0, 6811, 0, 6811, 0, 6811, 0, 6067, 0, 6811, 0, 7644, 0, 7644, 7644, 0, 5102};
  buzzer_sec++;
  if(counter_buzzer_sec == 37){
    counter_buzzer_sec = 0;
  }
  if(buzzer_sec > 80){
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
  }

}

void rockBaby_song(){
  int notes[44] = {6067, 0, 5102, 0, 6067, 0, 6811, 6811, 0, 7644, 0, 6067, 0, 5102, 0, 7644, 0, 4050, 4050, 0, 5727, 0, 5102, 0, 5727, 0, 6067, 0, 6811, 0, 6811, 0, 7644, 0, 4545, 0, 5102, 5102, 0, 6067, 0, 5102, 0, 6067};
  buzzer_sec++;
  if (counter_buzzer_sec == 44){
    counter_buzzer_sec = 0;
  }
  if (buzzer_sec > 65){
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
  }
  
}

void sunshine_song(){
  int notes[72] = {7644, 0, 7644, 0, 6067, 0, 6067, 0, 5102, 0, 5102, 0, 6067, 0, 7644, 0, 7644, 0, 6067, 0, 6067, 0, 5102, 0, 5102, 0, 6067, 0, 7644, 0, 6067, 0, 5102, 0, 6067, 0, 7644, 0, 6067, 0, 5102, 0, 6067, 0, 7644, 0, 6067, 0, 5102, 0, 6067, 0, 7644, 0, 7644, 0, 6067, 0, 6067, 0, 5102};
  buzzer_sec++;
  if (counter_buzzer_sec == 72){
    counter_buzzer_sec = 0;
  }
  if (buzzer_sec > 75){
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
  }  
  
}
