#include <main.h>

unsigned char button = 0;
long pausing = 1000;

#INT_RB
void  RB_isr(void) 
{
   int pinB4;
   pinB4 = input_state(PIN_B4);
   if(pinB4){
      button+=10;
      pausing = (long) 32*button;
   }
}

void main()
{
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   while(TRUE)
   {
      static char pinD0;
      static char pinD0Old;
      pinD0Old = pinD0;
      pinD0 = input_state(PIN_D0);
      if(pinD0 != pinD0Old){
         delay_us(pausing);
         output_high(PIN_D1);
         delay_us(200);
         output_low(PIN_D1);
      }
   }
}
