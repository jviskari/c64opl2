//player

#include <stdint.h>
#include <stdio.h>
#include <conio.h>
#include "vgmtypes.h"
#include "opl_driver.h"
#include "debug.h"

#ifndef offsetof
#define offsetof(s,memb) \
    ((size_t)((char *)&((s *)0)->memb-(char *)0))
#endif


static uint16_t ofs;
static uint16_t start;

extern unsigned char vgmData[];

static uint8_t run;
static uint16_t frames;

static void wait(uint16_t samples)
{
    // assuming 60 Hz VGM files
    frames = samples / 735;
    
    while (frames--) waitvsync();
}

static uint8_t __fastcall__  song_init(VGM_HEADER * header)
{
    uint8_t retval = 0;

    PRINT_DEBUG("1"); 

    if (header->fccVGM ==  0x206d6756)
    {
        PRINT_DEBUG("2"); 
        //printf("ID:%x\n", header->fccVGM);

        if (header->lngHzYM3812 != 0)
        {
            PRINT_DEBUG("3"); 
            printf("YM3812\n");
            retval = 1;
        }

        if (header->lngHzYM3526!=0)
        {
            PRINT_DEBUG("4"); 
            printf("YM3526\n");
            retval = 2;
        }
    }

    return retval;
}

uint8_t __fastcall__ PLAYER_Init(void)
{
    PRINT_DEBUG("1"); 

    if (OPL_Init())
    {
        PRINT_DEBUG("2"); 
        return song_init( (VGM_HEADER*)vgmData );
    }

    PRINT_DEBUG("3"); 
    //It didn't go like in strömsö.
    return 0;
}

void  __fastcall__ PLAYER_Run(void)
{
    VGM_HEADER * header = (VGM_HEADER*)vgmData;
    PRINT_DEBUG("1"); 
    // calculate absolute data offset
    start = header->lngDataOffset;
    start += offsetof(VGM_HEADER, lngDataOffset);

    PRINT_DEBUG("2"); 

    while (1)
    {
        ofs = start;
        run = 1;

        PRINT_DEBUG("3"); 

        while (run)
         {                                 
            uint8_t cmd = vgmData[ofs++];    
            switch (cmd) {
                case 0x5B:
                case 0x5A: 
                {
                    OPL_WriteReg(vgmData[ofs++], vgmData[ofs++]);
                    break;
                }
                case 0x61:
                {
                    uint16_t n = vgmData[ofs++];
                    n += vgmData[ofs++] << 8;
                    wait(n);
                    break;
                }
                case 0x62:
                {
                    wait(735);
                    break;
                }
                case 0x63:
                {
                    wait(882);
                    break;
                }
                case 0x66:
                {
                    run = 0;
                    break;
                }

                default:
                {
                    if (cmd >= 0x70 && cmd <= 0x7f)
                    {
                        wait(cmd & 0xf);
                    }
                    break;
                }
            }
            if (kbhit()) {
                cgetc();
                return;
            }
        }
    }


    OPL_Reset();
}
