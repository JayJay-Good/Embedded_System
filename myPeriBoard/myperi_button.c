#include "peri_button.h"
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>

#define BUTTON_DEVICE "/dev/input/event5"
static int fd_button = -1;

int buttonInit(void) {
	fd_button = open(BUTTON_DEVICE, O_RDONLY);
	if (fd_button < 0) {
		perror("open");
		return -1;
	}
	return 0;
}

int buttonRead(void) {
	if (fd_button < 0) return -1;
	struct input_event ev;
	while (1) {
		int r = read(fd_button, &ev, sizeof(ev));
		if (r == sizeof(ev) && ev.type == EV_KEY && ev.value == 1) {
			return ev.code;
		}
	}
	return -1;
}

int buttonExit(void) {
	if (fd_button >= 0) close(fd_button);
	fd_button = -1;
	return 0;
}
