#include "peri_led.h"
#include <fcntl.h>
#include <unistd.h>
#define LED_DEVICE "/dev/periled"
static int fd_led = -1;
int ledInit(void) {
	fd_led = open(LED_DEVICE, O_WRONLY);
	return (fd_led < 0) ? -1 : 0;
}
int ledWrite(unsigned char value) {
	if (fd_led < 0) return -1;
	return write(fd_led, &value, 1);
}
int ledExit(void) {
	if (fd_led >= 0) close(fd_led);
	fd_led = -1;
	return 0;
}
