char esteira ;
void setup()
{
 DDRD |= (1<<PD0);  
 int8_t esteira2;
 EICRA |= (1<<ISC10);
 EIMSK |= (1<<INT0);
 PORTD|=(1<<PD0);
 sei();
}
void loop()
{
   esteira = ( PIND&(1<<PD0));
}
ISR(INT
{
    if( esteira == 0)
       PORTD|=(1<<PD0);
    else
      PORTD &=~(1<<PD0);
}
