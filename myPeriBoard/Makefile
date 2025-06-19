CC = arm-linux-gnueabi-gcc
AR = arm-linux-gnueabi-ar
CFLAGS = -Wall -O2 -I./header

OBJS = \
  myperi_fnd.o \
  myperi_lcd.o \
  myperi_cled.o \
  myperi_led.o \
  myperi_button.o \
  myperi_buzzer.o \
  myperi_temp.o \
  myperi_imu.o

LIBNAME = libMyPeri.a
TESTS = \
  test_fnd \
  test_lcd \
  test_cled \
  test_led \
  test_button \
  test_buzzer \
  test_temp \
  test_imu

all: $(LIBNAME) $(TESTS)

$(LIBNAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTS): %: %.c $(LIBNAME)
	$(CC) -o $@ $< -L. -lMyPeri

# 드라이버 빌드 (x86 gcc 사용)
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

driver:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

install:
	cp $(LIBNAME) /usr/lib/
	mkdir -p /usr/include/myperi
	cp header/*.h /usr/include/myperi/

clean:
	rm -f *.o *.a $(TESTS)
	$(MAKE) -C $(KDIR) M=$(PWD) clean
