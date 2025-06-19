// =======================
// peri_fnd.h
// =======================
#ifndef PERI_FND_H
#define PERI_FND_H

#define MAX_FND_NUM 6
#define FND_DATA_BUFF_LEN (MAX_FND_NUM + 2)

typedef struct FNDWriteDataForm_tag {
    char DataNumeric[FND_DATA_BUFF_LEN];  
    char DataDot[FND_DATA_BUFF_LEN];      
    char DataValid[FND_DATA_BUFF_LEN];    
} stFndWriteForm, *pStFndWriteForm;

int fndInit(void);
int fndDisp(int num, int dotflag);
int fndOff(void);
int fndExit(void);

#endif
