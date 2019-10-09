#include <stdint.h>
#include <stdio.h>
#include <conio.h>
#include "vgmtypes.h"
static uint16_t gd3;

extern unsigned char vgmData[];

static char* readWideString(uint16_t* pos)
{
    static uint8_t buf[256];
    uint8_t i = 0;
    while (1) {
        uint16_t wc = vgmData[*pos];
        (*pos)++;
        wc |= vgmData[*pos];
        (*pos)++;
        if (wc >= 65 && wc <= 90) {
            wc += 32;
        } else if (wc >= 97 && wc <= 122) {
            wc -= 32;
        }
        buf[i++] = wc;
        if (wc == 0) break;
    }
    return buf;
}

void __fastcall__ GD3_Show(void)
{
    VGM_HEADER * header = (VGM_HEADER*)vgmData;
        // calculate GD3 offset
    gd3 = header->lngGD3Offset;

    // parse GD3 info
    if (gd3) {
        gd3 += 29;
        readWideString(&gd3);
        printf(" Song title : %s\n", readWideString(&gd3));
        readWideString(&gd3);
        readWideString(&gd3);
        readWideString(&gd3);
        readWideString(&gd3);
        readWideString(&gd3);
        printf(" Author name: %s\n", readWideString(&gd3));
    }
}    