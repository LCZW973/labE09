#define LERBUTTON (PIND&(1<<PD0))
#define ONLEDRED (PORTD|=(1<<PD1))
#define OFFLEDRED (PORTD&=~(1<<PD1))
#define ONLEDYELLOW (PORTD|=(1<<PD2))
#define OFFLEDYELLOW (PORTD&=~(1<<PD2))
#define ONLEDBLUE (PORTD|=(1<<PD3))
#define OFFLEDBLUE (PORTD&=~(1<<PD3))
  char estado = 0;
void setup()
{
  DDRD |= ((1<<PD1)|(1<<PD2)|(1<<PD3));
  PORTD |= (1<<PD0);
}
void loop()
{
  
  switch(estado)
  {
  case 0 :  
    OFFLEDBLUE;
    ONLEDRED;
    _delay_ms(5000);
    if(LERBUTTON==0)
      estado=1;
   break;
   case 1:
    OFFLEDRED;
    for(char i=0 ;i<3;i++)
    {
     ONLEDYELLOW;
      _delay_ms(500000);
     OFFLEDYELLOW;
      _delay_ms(500000);
    }
    estado = 3;
    break;
     case 3 :
     ONLEDBLUE;
     if(LERBUTTON==0)
       estado=0;
    break;
  }
}
