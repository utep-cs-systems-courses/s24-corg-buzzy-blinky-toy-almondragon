#ifndef stateMachine_included
#define stateMachine_included

typedef enum{
  waiting = 0,
  twinkle,
  hushBaby,
  rockBaby,
  sunshine
} State;


void state_twinkle();
void state_hushBaby();
void state_rockBaby();
void state_sunshine();
void state_waiting();
//void transition_state(State next_state);
//void update_250th();
//void sec();

extern State current_state;

#endif
