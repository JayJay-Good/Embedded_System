// test_led.c
#include "peri_led.h"
#include <unistd.h>
int main() {
	ledInit();
	for (int i = 0; i < 8; i++) {
		ledWrite(1 << i);
		sleep(1);
	}
	ledExit();
	return 0;
}
