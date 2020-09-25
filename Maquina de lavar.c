sbit Motor at RD0_bit;
sbit LED1 at RD1_bit;
sbit LED2 at RD2_bit;
sbit LED3 at RD3_bit;

sbit Button_start at RB0_bit;
sbit Button_stop at RB1_bit;
sbit Button_prog at RB2_bit;

int i = 0;
int programa = 0;
int start=0;

void tilt()
{
          LED1=1;
          LED2=1;
          LED3=1;
          delay_ms(200);
          LED1=0;
          LED2=0;
          LED3=0;
}

void interromper()
{
    Motor=0;
    start=0;
}

void check()
{
        if (Button_stop)
        {
            interromper();
        }
}

 void centrifugar()
{
    Motor=1;
    for ( i = 0; i < 200; i++)
    {
       delay_ms(1);
       check();
    }
}

void enxague()
{
    Motor=1;
    for (i = 0; i < 200; i++)
    {
        delay_ms(1);
        check();
    }

}

void main()
{
    ADCON1 = 0x0F;
    CMCON = 7;
    TRISB=0b11111111;
    TRISD=0;
  while(1)
  {
      if (Button_prog)
      {
          programa++;
          if (programa == 3)
          {
              programa = 1;
          }
      }
      if (Button_start)
      {
          start=1;
      }
      if (start)
      {
          LED3=1;
      }
      else 
      {
          LED3=0;
      }
      if ( programa == 1 && start==1)
      {
          centrifugar();
      }
      if ( programa == 2 && start==1)
      {
          i=200;
          centrifugar();
      }
      switch (programa)
      {
        case 0:
            tilt();    
        break;
        case 1:
            LED1=1;
        break;
        case 2:
            LED2=1;
        break;
      }
  }
}