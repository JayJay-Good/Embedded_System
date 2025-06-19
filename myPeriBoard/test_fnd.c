//test_fnd.c
#include "peri_fnd.h"
int main() {
    fndInit();
    fndDisp(123456, 0b101010);
    sleep(2);
    fndOff();
    fndExit();
    return 0;
}
