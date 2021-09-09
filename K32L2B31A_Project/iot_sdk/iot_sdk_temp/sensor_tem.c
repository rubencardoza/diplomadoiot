/*! @file : sensor_tem.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    7/09/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include"sensor_tem.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
void sensorDetemperaturaIniciarCaptura(void);
 void sensorDetemperaturaEsperarResultado(void);

/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
void sensorDetemperaturaIniciarCaptura(){

 	 ADC16_SetChannelConfig(SENSOR_DE_temperatura_ADC16_BASE, SENSOR_DE_temperatura_ADC16_CHANNEL_GROUP, &ADC0_channelsConfig[1]);

  }
  void sensorDetemperaturaEsperarResultado(){
 	 while (0U == (kADC16_ChannelConversionDoneFlag &
 	                       ADC16_GetChannelStatusFlags(SENSOR_DE_temperatura_ADC16_BASE, SENSOR_DE_temperatura_ADC16_CHANNEL_GROUP)))
 	         {
 	         }
  }

/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
 float SensorDetemperaturaObtenerDatosADC(){
	 float resultadoADC;

		 sensorDetemperaturaIniciarCaptura();
		         sensorDetemperaturaEsperarResultado();
		 resultadoADC=ADC16_GetChannelConversionValue(SENSOR_DE_temperatura_ADC16_BASE, SENSOR_DE_temperatura_ADC16_CHANNEL_GROUP);
		 resultadoADC=(3*resultadoADC)/4095;
		 resultadoADC=(resultadoADC*90)/3.3;
		 return(resultadoADC);

 }


