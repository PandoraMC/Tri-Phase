int sig[] = {0x31, 0x23, 0x07, 0x0E, 0x1C, 0x38};
int i = 0;

void setup() {
  
  DDRB = 0x3F;
  
  TCCR1A = 0x01;
  TCCR1B = 0x15;
  OCR1AL = 0x28;
  TIMSK1 = 0x02;
  
  sei();
}

void loop(){
}

ISR(TIMER1_COMPA_vect){  
  PORTB = *(sig + i++);
  if(i > 5)
    i = 0;
}
