# include "i2c.h"
# include <avr/io.h>

void i2c_init(void)
{
    // Set SCL to 100kHz for 8MHz CPU clock
    TWBR = 32;
}

void i2c_start(void)
{
    // Send the START command
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    // Wait for the hardware to finish
    while ( !(TWCR & (1 << TWINT)) );
	
    // Check if the TWSR is actually setted to start (mask other bits)
    if ((TWSR & 0xF8) != START)
	ERROR();
}

void i2c_stop(void)
{
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

    // No wait needed
}

void i2c_write(uint8_t data)
{
    TWDR = data; //Load data to write into TWDR register

    TWCR = (1<<TWINT) | (1<<TWEN);  // Clear TWINT bit in TWCR 
                                    // to start transmission of address

    while (!(TWCR & (1<<TWINT)));    // Wait for TWINT flag set. This
                                    // indicates that the Write bit has
                                    // been transmitted, and
                                    // ACK/NACK has been received.
    
    if ((((TWSR & 0xF8) != MT_SLA_ACK) && ((TWSR & 0xF8) != MT_DATA_ACK)))
    // Check in TWSR for the ACK bit both from data and peripheral address 
    	ERROR();	
}
