# another-ATmega328p-project

A bare-metal thermometer built from scratch in C for the ATmega328P microcontroller. This project demonstrates register-level programming and custom protocol implementation by interfacing with a DHT sensor and an I2C LCD without using any Arduino libraries or external hardware abstractions.

## Building and Flashing

| LCD Backpack Pin | ATmega328P Pin |
|------------------|----------------|
| GND              | pin 8          |
| VCC              | pin 7          |
| SDA              | pin 27         |
| SCL              | pin 28         |

*Check the dot on the ATmega328p to orient it correctly. The dot should be in the top-left corner.*