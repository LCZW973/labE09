void setup()
{
  DDRD |= (1<<PD6);
  PORTD |= (1<<PD2)|(1<<PD3);
  
  TCCR0A |= (1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
  TCCR0B |= (1<<CS00);
  OCR0A = 0 ;
  sei();
  
  EICRA |= (1<<ISC01)|(1<<ISC11);
  EIMSK |= (1<<INT0)|(1<<INT1);
}
void loop()
{
}
volatile int contador = 0 ;
ISR(INT0_vect)
{
    contador = 0 ;    
    OCR0A=contador ;
}
ISR(INT1_vect)
{
  if(contador<255)
     contador= contador + 25 ;
   OCR0A = contador;
}
