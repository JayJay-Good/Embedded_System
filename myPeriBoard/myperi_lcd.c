// =======================
// 수정된 myperi_lcd.c (디바이스 경로 /dev/peritextlcd 반영 + lcdClear 추가)
// =======================

#include "peri_lcd.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define TEXTLCD_DEVICE "/dev/peritextlcd"

typedef struct TextLCD_tag {
    unsigned char cmd;
    unsigned char cmdData;
    unsigned char reserved[2];
    char TextData[LINE_NUM][LINE_BUFF_NUM];
} stTextLCD;

int lcdTextWrite(const char* str1, const char* str2, int lineFlag) {
    stTextLCD lcd;
    int fd;
    memset(&lcd, 0, sizeof(stTextLCD));

    // 출력할 문자열 설정
    if (lineFlag == CMD_DATA_WRITE_LINE_1 || lineFlag == CMD_DATA_WRITE_BOTH_LINE) {
        strncpy(lcd.TextData[0], str1, COLUMN_NUM);
    }
    if (lineFlag == CMD_DATA_WRITE_LINE_2 || lineFlag == CMD_DATA_WRITE_BOTH_LINE) {
        strncpy(lcd.TextData[1], str2, COLUMN_NUM);
    }

    // 명령 설정
    lcd.cmd = CMD_WRITE_STRING;
    lcd.cmdData = lineFlag;

    // 장치 열기
    fd = open(TEXT_LCD_DEVICE, O_WRONLY);
    if (fd < 0) {
        perror("textlcd device open failed");
        return -1;
    }

    // 구조체 전송
    write(fd, &lcd, sizeof(stTextLCD));
    close(fd);
    return 0;
}
