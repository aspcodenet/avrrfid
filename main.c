 

// Stefans kort
// vita 132 183 152 30 181
// blå 149 111 139 195 178

#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"
#include "mfrc522.h"
#include "uart.h"

int main()
{
	uint8_t byte;
	volatile uint8_t str[MAX_LEN];
	_delay_ms(50);
	init_serial();
	printf("hejsan\n");

	spi_init();
	_delay_ms(1000);

	mfrc522_init();
	
	byte = mfrc522_read(VersionReg);
	if(byte == 0x92)
	{
		printf("RC522v2\n");
	}else if(byte == 0x91 || byte==0x90)
	{
		printf("RC522v1\n");
	}else
	{
		printf("No reader???\n");
	}
	
	_delay_ms(1500);
	
	while(1){
		byte = mfrc522_request(PICC_REQALL,str);
		if(byte == CARD_FOUND) {
			byte = mfrc522_get_card_serial(str);
			if(byte == CARD_FOUND)
			{
				for(byte=0;byte<8;byte++)
					printf("%d ", str[byte]);
				printf("\n");
				_delay_ms(2500);
			}
		}
		_delay_ms(1000);
	} 
}