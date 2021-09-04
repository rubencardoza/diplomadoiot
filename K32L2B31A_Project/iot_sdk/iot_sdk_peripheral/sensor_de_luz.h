/*! @file : sensor_de_luz.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    4/09/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef IOT_SDK_PERIPHERAL_SENSOR_DE_LUZ_H_
#define IOT_SDK_PERIPHERAL_SENSOR_DE_LUZ_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"

/*!
 * @addtogroup X
 * @{
 */
/*!
 * @addtogroup X
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define SENSOR_DE_LUZ_ADC16_BASE          ADC0
#define SENSOR_DE_LUZ_ADC16_CHANNEL_GROUP 0U
#define SENSOR_DE_LUZ_ADC16_USER_CHANNEL  3U /* PTE22, ADC0_SE3 */
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/


void sensorDeLuzIniciarCaptura(void);
 void sensorDeLuzEsperarResultado(void);
 uint32_t sensorDeLuzObtenerDatosADC(void);

/** @} */ // end of X group
/** @} */ // end of X group

#endif /* IOT_SDK_PERIPHERAL_SENSOR_DE_LUZ_H_ */
