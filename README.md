# LED Heart (Direct Port Manipulation)

A low-level embedded project built on ATmega328P (Arduino Nano) to control an LED heart using a 74HC595 shift register. 

This project was rewritten from standard Arduino libraries to direct AVR register manipulation for maximum optimization.

## Key Features
* **Hardware SPI:** Uses `SPCR`, `SPDR`, and `SPSR` registers instead of the slow `shiftOut()` function.
* **Fast PWM:** Uses Timer0 (`TCCR0A`, `TCCR0B`, `OCR0B`) for a smooth breathing effect without blocking the CPU with `analogWrite()`.
* **Direct Port Manipulation:** Uses `DDRx` and `PORTx` instead of `pinMode()` and `digitalWrite()`.
* **Highly Optimized:** Compiles to just 738 bytes (2% of storage).
