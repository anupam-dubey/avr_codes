#include<avr/io.h>
#include<util/delay.h>
#include "lcd.h"







int main(void)
{  unsigned char i=0;
  lcd_init();//initialise the lcd
  lcd_cmd(0x01);//clear screen
   lcd_puts("  **Counter**");
   
   while(1)
   { 
      lcd_cmd(0xC5);
	 itoa(i);
	  i++;
	  if(i>59)
	  i=0;
	 _delay_ms(1000);
      
    }
	return 0;
}