#ifndef led_included
#define led_included

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

void led_init();

void led_greenOn();

void led_redOn();

void lightOn();

void lightsOff();

void twinkle_led();

void hush_led();

void rock_led();

void sunshine_led();

void DTB_BTD();

#endif
