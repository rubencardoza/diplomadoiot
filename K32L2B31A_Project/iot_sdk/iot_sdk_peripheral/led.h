/*! @file : led.h
 * @author ruben cardoza ramos
 * @version 1.0.0
 * @date    2/09/2021
 * @brief   Driver para controlar leds de tarjeta FDRM-K32L2B3
 * @details
 *
 */
#ifndef IOT_SDK_PERIPHERAL_LED_H_
#define IOT_SDK_PERIPHERAL_LED_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/


/*!
 * @addtogroup PERIPHERAL
 * @{
 */
/*!
 * @addtogroup LEDS
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
/*!
 * @brief enciende led verde de la tarjeta FRDM-K32L2B3
 *
 */
void encender_led_verde();
/*!
 * @brief APAGA led verde de la tarjeta FRDM-K32L2B3
 *
 */
void apagar_led_verde();
/*!
 * @brief enciende led rojo de la tarjeta FRDM-K32L2B3
 *
 */

void encender_led_rojo();
/*!
 * @brief apaga led rojo de la tarjeta FRDM-K32L2B3
 *
 */
void apagar_led_rojo();

/** @} */ // end of X LEDS
/** @} */ // end of X PERIPHERAL

#endif /* IOT_SDK_PERIPHERAL_LED_H_ */
