#ifndef I2C_H
#define I2C_H

#define START 0x08              // Defs from the example
#define MT_SLA_ACK 0x18		// Table 21-2 in the ATmega328P 
#define MT_DATA_ACK 0x28	// datasheet
				// on which this driver is based
#define ERROR() while(1)	//

void i2c_init(void);            // Initializes the I2C bus
void i2c_start(void);           // Sends a START condition
void i2c_stop(void);            // Sends a STOP condition
void i2c_write(uint8_t data);   // Generic byte sender


#endif
