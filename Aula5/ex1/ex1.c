#define LERBUTTONNA (PIND&(1<<PD0))
#define LERBUTTONNF (PIND&(1<<PD1))
#define LERBUTTONS1 (PIND&(1<<PD2))
#define ON_ESTEIRA (PORTD|=(1<<PD3))
#define OFF_ESTEIRA (PORTD&=~(1<<PD3))
#define ON_ALARME (PORTD|=(1<<PD4))
#define OFF_ALARME (PORTD&=~(1<<PD4))
void setup()
{
  DDRD |=((1<<PD3)+(1<<PD4));
  PORTD |=((1<<PD0)+(1<<PD1)+(1<<PD2)); 
}
void loop()
{
  
 if(LERBUTTONS1==0)
  {
   ON_ALARME;
   OFF_ESTEIRA;
  }
  else
  {
    OFF_ALARME;
  }
 
  if((LERBUTTONNA==0) && (LERBUTTONS1 !=0))
  {
  
   ON_ESTEIRA ;
  }
  
   if(LERBUTTONNF==0)
  {
    OFF_ESTEIRA;
  }
}
