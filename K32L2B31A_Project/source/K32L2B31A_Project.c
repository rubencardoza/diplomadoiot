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
#include "sensor_de_luz.h"
#include "irq_lptmr0.h"
#include "botones.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
unsigned int test_global_var=100;
float dato_float=3.1416;



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

    LPTMR_StartTimer(LPTMR0);

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    bool boton1,boton2;

    uint32_t adc_sensor_de_luz;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

    if (lptmr0_irq_counter !=0){
    	toggle_led_rojo();
    	lptmr0_irq_counter=0;

        i++ ;
        printf("i:%u\r\n",i);

        adc_sensor_de_luz=sensorDeLuzObtenerDatosADC();
        printf("adc_sensor_de_luz:%u\r\n",adc_sensor_de_luz);
        boton1=boton1leerEstado();
        boton2=boton2leerEstado();
        printf("boton1:%u\r\n",boton1);
        printf("boton2:%u\r\n",boton2);

    }
    }
    return 0 ;
}
