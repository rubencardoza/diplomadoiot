/*! @file : gpio.h
 * @author  ruben cardoza
 * @version 1.0.0
 * @date    1/09/2021
 * @brief   Driver para
 * @details
 *
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include"led.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
unsigned int test_global_var=100;
float dato_float=3.1416;
/*
 * @brief   genera bloqueo de micro por tiempo fijo
 */
void delay_block(void){

	uint32_t i;
	for(i=0;i<0xfffff;i++){

	}
}

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World\r\n");
    PRINTF("test_global_var: %d\r\n",test_global_var);
    PRINTF("dato_float: %g\r\n",dato_float);
    encender_led_verde();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    unsigned char cont_LR = 0;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        printf("i:%u\r\n",i);
        encender_led_verde();
        delay_block();
        apagar_led_verde();
        delay_block();
        if (i % 10 == 0){
                	cont_LR++;
                	if (cont_LR % 2 == 0){
                		apagar_led_rojo();
                	}
                	else{
                		encender_led_rojo();
                	}
                }

        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}
