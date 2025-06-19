// =======================
// test_lcd.c (LCD 테스트용 예제)
// =======================

#include "peri_lcd.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    lcdTextWrite("Hello, World!", "Jaewon Jeon", CMD_DATA_WRITE_BOTH_LINE);
    sleep(2);

    lcdTextWrite("Embedded OS", "", CMD_DATA_WRITE_LINE_1);
    sleep(2);

    lcdTextWrite("", "", CMD_DATA_WRITE_BOTH_LINE);  // clear 처리
    return 0;
}
