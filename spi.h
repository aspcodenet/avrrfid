#ifndef SPI_H
#define SPI_H

/*
 * Set to 1, spi api will work in master mode
 * else in slave mode
 */
#define SPI_CONFIG_AS_MASTER 	1


/*
 * Config SPI pin diagram
 */
#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define SPI_PIN		PINB
#define SPI_MOSI	3
#define SPI_MISO	4
#define SPI_SS		2
#define SPI_SCK		5

#include <stdint.h>

void spi_init();
uint8_t spi_transmit(uint8_t data);

#define ENABLE_CHIP() (SPI_PORT &= (~(1<<SPI_SS)))
#define DISABLE_CHIP() (SPI_PORT |= (1<<SPI_SS))


#endif