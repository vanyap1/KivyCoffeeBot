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

#include <stdio.h>
static FILE mystdout = FDEV_SETUP_STREAM((void *)uart_send_byte, NULL, _FDEV_SETUP_WRITE);

gpio dev1_ld_red = {(uint8_t *)&PORTC , PORTC0};
gpio dev1_ld_grn = {(uint8_t *)&PORTE , PORTE3};
gpio dev2_ld_red = {(uint8_t *)&PORTC , PORTC2};
gpio dev2_ld_grn = {(uint8_t *)&PORTC , PORTC1};
gpio dev3_ld_red = {(uint8_t *)&PORTC , PORTC5};
gpio dev3_ld_grn = {(uint8_t *)&PORTC , PORTC4};
gpio dev3_ld_blu = {(uint8_t *)&PORTC , PORTC3};
gpio in1 = {(uint8_t *)&PORTD , PORTD3};




int main(void)
{
	gpio_set_pin_level(&dev1_ld_red, true); gpio_set_port_direction(&dev1_ld_red , PORT_DIR_OUT); 
	gpio_set_pin_level(&dev1_ld_grn, true); gpio_set_port_direction(&dev1_ld_grn , PORT_DIR_OUT); 
	gpio_set_pin_level(&dev2_ld_red, true); gpio_set_port_direction(&dev2_ld_red , PORT_DIR_OUT); 
	gpio_set_pin_level(&dev2_ld_grn, true); gpio_set_port_direction(&dev2_ld_grn , PORT_DIR_OUT); 
	gpio_set_pin_level(&dev3_ld_red, true); gpio_set_port_direction(&dev3_ld_red , PORT_DIR_OUT);
	gpio_set_pin_level(&dev3_ld_grn, true); gpio_set_port_direction(&dev3_ld_grn , PORT_DIR_OUT);
	gpio_set_pin_level(&dev3_ld_blu, true); gpio_set_port_direction(&dev3_ld_blu , PORT_DIR_OUT);

	gpio_set_port_direction(&in1 , 0);

    uart_init(250000,1);
    twi1_init(400000);
	
	sei();
	
    while (1) 
    {
    }
}

