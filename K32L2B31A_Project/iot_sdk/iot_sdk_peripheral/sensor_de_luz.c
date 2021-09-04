/*! @file : sensor_de_luz.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    4/09/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include"sensor_de_luz.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
void sensorDeLuzIniciarCaptura(void);
 void sensorDeLuzEsperarResultado(void);

/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

 void sensorDeLuzIniciarCaptura(){

 	 ADC16_SetChannelConfig(SENSOR_DE_LUZ_ADC16_BASE, SENSOR_DE_LUZ_ADC16_CHANNEL_GROUP, &ADC0_channelsConfig[0]);

  }
  void sensorDeLuzEsperarResultado(){
 	 while (0U == (kADC16_ChannelConversionDoneFlag &
 	                       ADC16_GetChannelStatusFlags(SENSOR_DE_LUZ_ADC16_BASE, SENSOR_DE_LUZ_ADC16_CHANNEL_GROUP)))
 	         {
 	         }
  }
/*******************************************************************************
 * Public Source Code
 ******************************************************************************/

 uint32_t sensorDeLuzObtenerDatosADC(){
	 uint32_t resultadoADC;

	 sensorDeLuzIniciarCaptura();
	         sensorDeLuzEsperarResultado();
	 resultadoADC=ADC16_GetChannelConversionValue(SENSOR_DE_LUZ_ADC16_BASE, SENSOR_DE_LUZ_ADC16_CHANNEL_GROUP);
	 return(resultadoADC);
 }
 
