// test_button.c
#include "peri_button.h"
#include <stdio.h>
int main() {
	buttonInit();
	while (1) {
		int key = buttonRead();
		printf("Button pressed: %d\n", key);
		if (key == 0) break;
	}
	buttonExit();
	return 0;
}
