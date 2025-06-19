// peri_buzzer.h
#ifndef PERI_BUZZER_H
#define PERI_BUZZER_H

#define MESSAGE_ID 1122
typedef struct
{
    long int messageNum;
    int keyInput;
    int pressed;
} BUTTON_MSG_T;

int buzInit(void);
int buzPlay(int scale);
int buzStop(void);
int buzExit(void);


#endif
