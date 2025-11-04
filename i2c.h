#ifndef I2C_H
#define I2C_H

void i2c_init(void);            // Initializes the I2C bus
void i2c_start(void);           // Sends a START condition
void i2c_stop(void);            // Sends a STOP condition
void i2c_write(uint8_t data);   // Generic byte sender


#endif