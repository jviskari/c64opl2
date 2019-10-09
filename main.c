// C64 SFX EXPANDER VGM PLAYER
// joenash 2019 (joonas.viskari@gmail.com)

#include <stdint.h>
#include <stdio.h>
#include <conio.h>
#include <6502.h>
#include <c64.h>
#include <peekpoke.h>
#include "player.h"


int main()
{  
    bgcolor(COLOR_BLACK);
    bordercolor(COLOR_BLACK);
    textcolor(COLOR_GRAY3);

    clrscr();
   

    printf("\nC64 OPL2 player test by joenash 2019\n\n");


    if ( PLAYER_Init() != 0 )
    {
        // play song until key press
        printf("\npress any key to stop\n");  
        PLAYER_Run();
    }
    else
    {
        printf("\nOOPS it did work on my PC\nCheck file & hardware config\n");  
    }
    
    return 0;
}
