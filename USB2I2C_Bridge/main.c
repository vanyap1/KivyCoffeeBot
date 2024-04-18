/*
 * USB2i2c_Bridge.c
 *ff
 * Created: 18.04.2024 0:13:59
 * Author : Vanya
 */ 

#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "string.h"
#include "stdbool.h"
#include "uart_hal.h"
#include "gpio_driver.h"
#include "twi_hal1.h"
#include "dataHandler.h"



bridgeDatagram i2cDatagram;

#include <stdio.h>
static FILE mystdout = FDEV_SETUP_STREAM((void *)uart_send_byte, NULL, _FDEV_SETUP_WRITE);

//Leds definition section
#define RED			0
#define GREEN		1
#define BLUE		2

gpio dev1[2] = {{(uint8_t *)&PORTC , PORTC0} , {(uint8_t *)&PORTE , PORTE3}};
gpio dev2[3] = {{(uint8_t *)&PORTC , PORTC2} , {(uint8_t *)&PORTC , PORTC1}};
gpio dev3[3] = {{(uint8_t *)&PORTC , PORTC5} , {(uint8_t *)&PORTC , PORTC4},{(uint8_t *)&PORTC , PORTC3}};
//End of leds
gpio in1 = {(uint8_t *)&PORTD , PORTD3};




int main(void)
{
	gpio_set_pin_direction(&dev1[RED] , PORT_DIR_OUT); gpio_set_pin_level(&dev1[RED], true);
	gpio_set_pin_direction(&dev1[GREEN] , PORT_DIR_OUT); gpio_set_pin_level(&dev1[GREEN], true);
	
	gpio_set_pin_direction(&dev2[RED] , PORT_DIR_OUT); gpio_set_pin_level(&dev2[RED], true);
	gpio_set_pin_direction(&dev2[GREEN] , PORT_DIR_OUT); gpio_set_pin_level(&dev2[GREEN], true);
	
	gpio_set_pin_direction(&dev3[RED] , PORT_DIR_OUT); gpio_set_pin_level(&dev3[RED], true);
	gpio_set_pin_direction(&dev3[GREEN] , PORT_DIR_OUT); gpio_set_pin_level(&dev3[GREEN], true);
	gpio_set_pin_direction(&dev3[BLUE] , PORT_DIR_OUT); gpio_set_pin_level(&dev3[BLUE], true);

	gpio_set_port_direction(&in1 , 0);

    uart_init(250000,1);
    twi1_init(400000);
	
	sei();
	stdout = &mystdout;
	sleep_enable();
	uart_send_string((uint8_t *)"\rReady\n\r");
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    while (1) 
    {
		
		if(serial_complete()){
			gpio_set_pin_level(&dev1[GREEN], false);
			uint8_t* rxdata = serial_read_data();
			dataParce(rxdata, &i2cDatagram);
			gpio_set_pin_level(&dev1[GREEN], true);
				
		}
		
		
		//gpio_toggle_pin_level(&dev1[RED]);
		//gpio_toggle_pin_level(&dev2[RED]);
		//gpio_toggle_pin_level(&dev3[RED]);
		//_delay_ms(300);
		
    }
}

