// peri_temp.h
#ifndef PERI_TEMP_H
#define PERI_TEMP_H

#define SPI_DEV_PATH "/dev/spidev1.0"

int spi_init(const char* device_path);

double read_temperature(int spi_fd);

#endif
