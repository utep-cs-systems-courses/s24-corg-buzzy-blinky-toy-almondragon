#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"


int buzzer_sec = 0; // counting number of interrupts
char counter_buzzer_sec = 0; // counting the number of times buzzer_sec hits a limit

// initialzing the buzzer
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

// plays the each note of twinkle twinkle little star
void twinkle_song(){
  int notes[44]= {7644, 0, 7644, 0, 5102, 0 , 5102, 0, 4545, 0, 4545, 0, 5102, 5102, 0, 5727, 0, 5727, 0, 6067, 0, 6067, 0, 6811, 0, 6811, 0, 7644, 7644, 0, 5102, 0, 5102, 0, 5727, 0, 5727, 0, 6067, 0, 6067, 0, 6811, 6811};
  buzzer_sec++; 
  if(counter_buzzer_sec == 44){ // checking if all notes have been played
    counter_buzzer_sec = 0; // if so resets count of buzzer to 0
  }
  if(buzzer_sec >65){ // plays a note every 65th of a second
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
    
  }

}

// plays each note of hush little baby
void hushBaby_song(){
  int notes[37] = {5102, 0, 6067, 0, 6067, 0, 6067, 0, 5727, 0, 6067, 0, 6811, 0, 6811, 6811, 0, 5102, 0, 5102, 0, 6811, 0, 6811, 0, 6811, 0, 6067, 0, 6811, 0, 7644, 0, 7644, 7644, 0, 5102};
  buzzer_sec++;
  if(counter_buzzer_sec == 37){ // checks if all 37 notes have been played
    counter_buzzer_sec = 0;
  }
  if(buzzer_sec > 80){ // plays a note every 80th of a second
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
  }

}

// plays each note of rock a bye baby
void rockBaby_song(){
  int notes[44] = {6067, 0, 5102, 0, 6067, 0, 6811, 6811, 0, 7644, 0, 6067, 0, 5102, 0, 7644, 0, 4050, 4050, 0, 5727, 0, 5102, 0, 5727, 0, 6067, 0, 6811, 0, 6811, 0, 7644, 0, 4545, 0, 5102, 5102, 0, 6067, 0, 5102, 0, 6067};
  buzzer_sec++;
  if (counter_buzzer_sec == 44){ // checks if all 44 notes have been played
    counter_buzzer_sec = 0;
  }
  if (buzzer_sec > 70){ // plays a note every 70th of a second
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
  }
  
}
// plays each note of my little sunshine
void sunshine_song(){
  int notes[72] = {6811, 0, 5102, 0, 4545, 4050, 0, 4050, 0, 4050, 0, 4545, 0, 4050, 0, 5102, 0, 5102, 0, 5102, 0, 4545, 0, 4050, 0, 7644, 0, 6067, 0, 6067, 0, 6811, 0, 7644, 0, 4050, 0, 5102, 0, 4545, 0, 4050, 0, 7644, 0, 6067, 0, 6067, 0, 6811, 0, 7644, 0, 4050, 0, 5102, 0, 5102, 0, 4545, 0};
  buzzer_sec++;
  if (counter_buzzer_sec == 72){ // checks if all 72 notes have been played
    counter_buzzer_sec = 0;
  }
  if (buzzer_sec > 65){ // plays a note every 65th of a second
    buzzer_sec = 0;
    counter_buzzer_sec++;
    buzzer_set_period(notes[counter_buzzer_sec-1]);
  }  
  
}
