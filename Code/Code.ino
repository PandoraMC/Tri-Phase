int sig[] = {5, 1, 3, 2, 6, 4};
int i = 0;

void setup() {
  
  DDRB = 0x07;
  
  TCCR1A = 0x01;
  TCCR1B = 0x15;
  OCR1AL = 0x50;
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
