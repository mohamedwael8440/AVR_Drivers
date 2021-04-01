
#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "timer.h"
#include "lcd.h"
#include "SEG_HAL.h"
#include"clk.h"

u32 overflow =30 ;
u32 min=0;
u32 hr=11;

void main(void)
{
	LCD_Init();
    CLK_vidInit();
	while(1)
	{
    CLK_vidStart();

	}

}
