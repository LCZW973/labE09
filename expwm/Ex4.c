void setup()
{
  DDRD |= (1<<PD6)|(1<<PD5);
  PORTD |= (1<<PD2)|(1<<PD3);
  
  TCCR0A |= (1<<COM0A1)|(1<<COM0B1)|(1<<COM0B0)|(1<<WGM01)|(1<<WGM00);
  TCCR0B |= (1<<CS00);
  OCR0A = 0 ;
  OCR0B = 0 ; 
  sei();
  
  EICRA |= (1<<ISC01)|(1<<ISC11);
  EIMSK |= (1<<INT0)|(1<<INT1);
}
void loop()
{
}
volatile int contadorA = 0;

ISR(INT0_vect)
{
 if(contadorA<255)
   contadorA = contadorA+25 ;
 else
   contadorA = 0 ;
  
 OCR0A = contadorA;
 OCR0B = contadorA; 
}
ISR(INT1_vect)
{
 if(contadorA>0)
   contadorA = contadorA-25 ;
 else
   contadorA = 0 ;
  
 OCR0A = contadorA;
 OCR0B = contadorA; 
 
}
