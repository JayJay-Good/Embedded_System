#ifndef __ACCEL_MAG_GYRO_H__
#define __ACCEL_MAG_GYRO_H__

#define ACCEL_PATH "/sys/class/misc/FreescaleAccelerometer/"
#define MAGNE_PATH "/sys/class/misc/FreescaleMagnetometer/"
#define GYRO_PATH  "/sys/class/misc/FreescaleGyroscope/"

typedef struct {
    int x;
    int y;
    int z;
} Cartesian;

int readAccel(Cartesian* accel);
int readMagnet(Cartesian* mag);
int readGyro(Cartesian* gyro);

#endif // __ACCEL_MAG_GYRO_H__
