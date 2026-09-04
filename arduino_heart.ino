void setup() {
  DDRB |= (1 << PB3) | (1 << PB2) | (1 << PB5);
  DDRD |= (1 << PD5);
  
  SPCR = (1 << SPE) | (1 << MSTR);
  TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
  TCCR0B = (1 << CS01) | (1 << CS00);

  PORTD |= (1 << PD5);

  OCR0B = 255;
  
  SendByteSPI(0b11111111);
}

void SendByteSPI(byte data){
  PORTB &= ~(1 << PB2);

  SPDR = data;

  while (!(SPSR & (1 << SPIF))){
  }

  PORTB |= (1 << PB2);
}

void heartbeatpulse(){
  for(int brightness = 255; brightness >= 0; brightness -= 5){
    OCR0B = brightness;
    delay(3);
  }
  for(int brightness = 0; brightness <= 255; brightness += 5){
    OCR0B = brightness;
    delay(3);
  }
}
void loop() {
  heartbeatpulse();
  delay(100);

  heartbeatpulse();
  delay(800);

}
