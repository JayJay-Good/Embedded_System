// =======================
// peri_colour_led.h
// =======================
#ifndef PERI_CLED_H
#define PERI_CLED_H

int cledInit(void);
int cledSetColor(int r_percent, int g_percent, int b_percent);
int cledExit(void);

#endif
