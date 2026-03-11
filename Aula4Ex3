// C++ code
//
void setup()
{
  DDRD = 0b00000011;
}

void loop()
{
    int estado = 1 ;
    
    do{
    switch(estado)
    {case 1 :
      PORTD = 0b00000001;
      if(!(PIND & (1<<2)))
      {  _delay_ms(500);
         if(!(PIND & (1<<2)))
            estado = 2 ;}
       _delay_ms(500);
      break;
    case 2 :
      PORTD = 0b00000010;
       if(!(PIND & (1<<2)))
      {  _delay_ms(500);
         if(!(PIND & (1<<2)))
            estado = 3 ;}
      _delay_ms(500);
      break;
    case 3 :
      PORTD = 0b00000000;
       if(!(PIND & (1<<2)))
      {  _delay_ms(500);
         if(!(PIND & (1<<2)))
            estado = 1 ;}
      _delay_ms(500);
      break;
    default:
      estado = 1 ;
      break;
    }
    }while(1); 
      
}
