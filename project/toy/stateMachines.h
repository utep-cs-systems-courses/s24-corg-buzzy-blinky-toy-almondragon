#ifndef stateMachine_included
#define stateMachine_included

typedef enum{
  twinkle = 1,
  hushBaby = 2 ,
  rockBaby = 3,
  sunshine = 4,
  waiting = 0
} State;


void state_twinkle();
void state_hushBaby();
void state_rockBaby();
void state_sunshine();
//void state_waiting();
//void transition_state(State next_state);
//void update_250th();
//void sec();

extern State current_state;

#endif
