#ifndef _OPLDRIVER_H_
#define _OPLDRIVER_H_

#include <stdint.h>

uint8_t __fastcall__ OPL_Init(void);
void __fastcall__ OPL_Reset(void);
void __fastcall__ OPL_WriteReg(uint8_t reg, uint8_t value);

#endif
