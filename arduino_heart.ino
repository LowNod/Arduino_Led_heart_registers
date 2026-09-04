void setup() {
  // 1. Налаштовуємо піни (D11, D13, D10 та D5) на OUTPUT
  DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2);
  DDRD |= (1 << PD5);

  // 2. Вмикаємо апаратний SPI (режим Master)
  SPCR = (1 << SPE) | (1 << MSTR); 

  // 3. Налаштовуємо апаратний ШІМ на Timer0
  TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
  TCCR0B = (1 << CS01) | (1 << CS00);
  
  // Вимикаємо світлодіоди на старті (повна шпаруватість = 255)
  OCR0B = 255; 

  // 4. Відправляємо байти
  sendByteSPI(0b11111111);
}

void SendByteSPI(byte data){
  PORTB &= ~(1 << PB2);

  SPDR = data;

  while (!(SPSR & (1 << SPIF))){
  }

  PORTB |= (1 << PB2);
}
// Функція плавного загоряння та затухання
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
