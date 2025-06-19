// test_buzzer.c
#include "peri_buzzer.h"

#include <unistd.h>

int main(void) {
    buzInit();

    // 도 ~ 시 ~ 도 1옥타브 재생
    for (int i = 0; i < 8; i++) {
        buzPlay(i);
        sleep(1);
    }

    buzStop();
    buzExit();
    return 0;
}
