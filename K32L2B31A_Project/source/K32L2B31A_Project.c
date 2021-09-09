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
#include "sensor_tem.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
//unsigned int test_global_var=100;
//float dato_float=3.1416;



int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    //PRINTF("Hello World\r\n");
   // PRINTF("test_global_var: %d\r\n",test_global_var);
    //PRINTF("dato_float: %g\r\n",dato_float);

    LPTMR_StartTimer(LPTMR0);

    /*trabajo para entregar*/
     /*
      * 1. leer sensor de temperatura (puede ser el interno o el lm35) y hacer un printf(temperatura)
      * 2. medida de sensor de luz en unidades de lux
      * 3. la medida de temperatura y lux se imprina  temperatura solo cuando se pulsa el boton 1 y lux con el boton 2(debe imprimir en tiempo real)
      */

    /* Force the counter to be placed into memory. */
//   volatile static int i = 0 ;
    bool boton1,boton2;
   float adc_sensor_de_luz;
    float adc_sensor_de_temperatura;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

    if (lptmr0_irq_counter !=0){
    	//toggle_led_rojo();
    	lptmr0_irq_counter=0;

       //i++ ;
        //printf("i:%u\r\n",i);
    	boton1=boton1leerEstado();
    	boton2=boton2leerEstado();
    	if (boton1 && !boton1_presionado){
    		boton1_presionado=1;
    		adc_sensor_de_luz=sensorDeLuzObtenerDatosADC();
    		printf("sensor de luz en lux:%.3f\r\n",adc_sensor_de_luz);
    	}

    	if (!boton1){
    		boton1_presionado=0;
    	}
    	if (boton2 && !boton2_presionado){
    	    boton2_presionado=1;
    	    adc_sensor_de_temperatura=SensorDetemperaturaObtenerDatosADC();
    	    printf("temperatura:%.3f\r\n",adc_sensor_de_temperatura);
    	}

    	if (!boton2){

    	    boton2_presionado=0;
        }

    }

        if (led_rojo_irq_counter==1000){
        	led_rojo_irq_counter=0;
        	toggle_led_rojo();
        }
     }
    return 0 ;
}
