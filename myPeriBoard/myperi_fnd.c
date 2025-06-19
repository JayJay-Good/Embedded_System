// =======================
// myperi_fnd.c
// =======================
#include "peri_fnd.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define FND_DEVICE "/dev/perifnd"

static int fd_fnd = -1;

int fndInit(void) {
    fd_fnd = open(FND_DEVICE, O_WRONLY);
    return (fd_fnd < 0) ? -1 : 0;
}

int fndDisp(int num, int dotflag) {
    if (fd_fnd < 0) return -1;
    stFndWriteForm fnd;
    memset(&fnd, 0, sizeof(fnd));

    int temp = num;
    for (int i = 0; i < MAX_FND_NUM; i++) {
        fnd.DataNumeric[MAX_FND_NUM - 1 - i] = temp % 10;
        fnd.DataValid[MAX_FND_NUM - 1 - i] = 1;
        temp /= 10;
    }
    for (int i = 0; i < MAX_FND_NUM; i++) {
        fnd.DataDot[i] = (dotflag >> i) & 0x1;
    }
    return write(fd_fnd, &fnd, sizeof(fnd));
}

int fndOff(void) {
    stFndWriteForm fnd;
    memset(&fnd, 0, sizeof(fnd));
    write(fd_fnd, &fnd, sizeof(fnd));
    return 0;
}

int fndExit(void) {
    if (fd_fnd >= 0) close(fd_fnd);
    fd_fnd = -1;
    return 0;
}
