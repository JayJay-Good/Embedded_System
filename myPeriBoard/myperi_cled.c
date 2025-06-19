// =======================
// myperi_cled.c
// =======================
#include "peri_colour_led.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SYSFS_PWM_R "/sys/class/pwm/pwmchip0/pwm0/"
#define SYSFS_PWM_G "/sys/class/pwm/pwmchip1/pwm0/"
#define SYSFS_PWM_B "/sys/class/pwm/pwmchip2/pwm0/"
#define SYSFS_EXPORT_FMT "/sys/class/pwm/pwmchip%d/export"
#define SYSFS_UNEXPORT_FMT "/sys/class/pwm/pwmchip%d/unexport"
#define SYSFS_PERIOD "period"
#define SYSFS_DUTY "duty_cycle"
#define SYSFS_ENABLE "enable"

#define PWM_PERIOD_NS 1000000

void write_sysfs(const char* path, const char* value) {
    int fd = open(path, O_WRONLY);
    if (fd >= 0) {
        write(fd, value, strlen(value));
        close(fd);
    }
}

int cledInit(void) {
    write_sysfs("/sys/class/pwm/pwmchip0/export", "0");
    write_sysfs("/sys/class/pwm/pwmchip1/export", "0");
    write_sysfs("/sys/class/pwm/pwmchip2/export", "0");
    usleep(100000);
    write_sysfs(SYSFS_PWM_R SYSFS_PERIOD, "1000000");
    write_sysfs(SYSFS_PWM_G SYSFS_PERIOD, "1000000");
    write_sysfs(SYSFS_PWM_B SYSFS_PERIOD, "1000000");
    write_sysfs(SYSFS_PWM_R SYSFS_ENABLE, "1");
    write_sysfs(SYSFS_PWM_G SYSFS_ENABLE, "1");
    write_sysfs(SYSFS_PWM_B SYSFS_ENABLE, "1");
    return 0;
}

int cledSetColor(int r, int g, int b) {
    char buf[16];
    snprintf(buf, sizeof(buf), "%d", (100 - r) * PWM_PERIOD_NS / 100);
    write_sysfs(SYSFS_PWM_R SYSFS_DUTY, buf);
    snprintf(buf, sizeof(buf), "%d", (100 - g) * PWM_PERIOD_NS / 100);
    write_sysfs(SYSFS_PWM_G SYSFS_DUTY, buf);
    snprintf(buf, sizeof(buf), "%d", (100 - b) * PWM_PERIOD_NS / 100);
    write_sysfs(SYSFS_PWM_B SYSFS_DUTY, buf);
    return 0;
}

int cledExit(void) {
    write_sysfs(SYSFS_PWM_R SYSFS_ENABLE, "0");
    write_sysfs(SYSFS_PWM_G SYSFS_ENABLE, "0");
    write_sysfs(SYSFS_PWM_B SYSFS_ENABLE, "0");
    write_sysfs("/sys/class/pwm/pwmchip0/unexport", "0");
    write_sysfs("/sys/class/pwm/pwmchip1/unexport", "0");
    write_sysfs("/sys/class/pwm/pwmchip2/unexport", "0");
    return 0;
}
