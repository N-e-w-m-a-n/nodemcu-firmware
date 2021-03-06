#ifndef SPI_APP_H
#define SPI_APP_H

#include "spi_register.h"
#include "ets_sys.h"
#include "osapi.h"
#include "uart.h"
#include "os_type.h"

/*SPI number define*/
#define SPI 			0
#define HSPI			1



//lcd drive function
void spi_lcd_mode_init(uint8 spi_no);
void spi_lcd_9bit_write(uint8 spi_no,uint8 high_bit,uint8 low_8bit);

//spi master init funtion
void spi_master_init(uint8 spi_no, unsigned cpol, unsigned cpha, unsigned databits, uint32_t clock);
//use spi send 8bit data
void spi_mast_byte_write(uint8 spi_no,uint8 *data);

//transmit data to esp8266 slave buffer,which needs 16bit transmission ,
//first byte is master command 0x04, second byte is master data
void spi_byte_write_espslave(uint8 spi_no,uint8 data);
//read data from esp8266 slave buffer,which needs 16bit transmission ,
//first byte is master command 0x06, second byte is to read slave data
void spi_byte_read_espslave(uint8 spi_no,uint8 *data);

 //esp8266 slave mode initial
void spi_slave_init(uint8 spi_no);
  //esp8266 slave isr handle funtion,tiggered when any transmission is finished.
  //the function is registered in spi_slave_init.
void spi_slave_isr_handler(void *para); 


//hspi test function, used to test esp8266 spi slave
void hspi_master_readwrite_repeat(void);


void ICACHE_FLASH_ATTR
    spi_test_init(void);


#endif

