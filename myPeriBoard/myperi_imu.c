// myperi_imu.c
#include "peri_imu.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int enable_sensor(const char* path) {
    int fd = open(path, O_WRONLY);
    if (fd < 0) return -1;
    dprintf(fd, "1");
    close(fd);
    return 0;
}

static int read_sensor(const char* path, Cartesian* sensor) {
    FILE* fp = fopen(path, "rt");
    if (!fp) return -1;
    fscanf(fp, "%d, %d, %d", &sensor->x, &sensor->y, &sensor->z);
    fclose(fp);
    return 0;
}

int readAccel(Cartesian* accel) {
    if (enable_sensor(ACCEL_PATH "enable") < 0) return -1;
    return read_sensor(ACCEL_PATH "data", accel);
}

int readMagnet(Cartesian* mag) {
    if (enable_sensor(MAGNE_PATH "enable") < 0) return -1;
    return read_sensor(MAGNE_PATH "data", mag);
}

int readGyro(Cartesian* gyro) {
    if (enable_sensor(GYRO_PATH "enable") < 0) return -1;
    return read_sensor(GYRO_PATH "data", gyro);
}
