#include "opl_driver.h"
#include "peekpoke.h"
#include <stdint.h>
#include "debug.h"

#define OPLREG  ((uint8_t*)0xdf40)
#define OPLDATA ((uint8_t*)0xdf50)

uint8_t __fastcall__ OPL_Init(void)
{
    /*detect chip*/
    OPL_Reset();
    PRINT_DEBUG("EXIT");
    return 1;
}

void __fastcall__ OPL_Reset(void)
{
    uint16_t i; //tmp index variable
    PRINT_DEBUG("1"); 
    
    for (i = 0 ; i < 256 ; i++)
    {
        OPL_WriteReg(i, 0);
    }

    PRINT_DEBUG("2"); 
}

void __fastcall__ OPL_WriteReg(uint8_t reg, uint8_t value)
{   
    uint16_t i; //tmp index variable
    POKE(OPLREG, reg);
    // wait 12 cycles for register select
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("nop");
 
    POKE(OPLDATA, value);
    
    //wait 36 cycles before next write
    i=5;
    do
    {
       __asm__ volatile("nop");
       i--;
    }while(i); 
                        		
}
