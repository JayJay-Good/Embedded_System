#include "peri_colour_led.h"
int main() {
    cledInit();
    cledSetColor(100, 0, 0);  // Red full
    sleep(1);
    cledSetColor(0, 100, 0);  // Green full
    sleep(1);
    cledSetColor(0, 0, 100);  // Blue full
    sleep(1);
    cledExit();
    return 0;
}
