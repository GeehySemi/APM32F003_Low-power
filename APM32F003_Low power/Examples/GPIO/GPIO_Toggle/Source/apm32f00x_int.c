/*!
 * @file        apm32f00x_int.c
 *
 * @brief       Main Interrupt Service Routines        
 *
 * @version     V1.0.0
 *
 * @date        2019-11-4
 *
 */

#include "apm32f00x_int.h"
#include "apm32f00x_eint.h"
#include "apm32f00x_gpio.h"
#include "apm32f00x_tmr4.h"
#include "apm32f00x_misc.h"

int Sleepflag = 0;
 /*!
  * @brief       This function handles NMI exception
  *
  * @param       None
  *
  * @retval      None
  *
  * @note       
  */
 void NMI_Handler(void)
 {
 }

/*!
 * @brief       This function handles Hard Fault exception
 *
 * @param       None
 *
 * @retval      None
 *
 * @note       
 */
void HardFault_Handler(void)
{

}

/*!
 * @brief       This function handles SVCall exception
 *
 * @param       None
 *
 * @retval      None
 *
 * @note       
 */
void SVC_Handler(void)
{
}

/*!
 * @brief       This function handles PendSV_Handler exception
 *
 * @param       None
 *
 * @retval      None
 *
 * @note       
 */
void PendSV_Handler(void)
{
}

/*!
 * @brief       This function handles SysTick Handler
 *
 * @param       None
 *
 * @retval      None
 *
 * @note       
 */
void SysTick_Handler(void)
{

}

	
void EINTD_IRQHandler(void)
{

 	  EINT_ClearIntFlag(EINT_PORT_D);
		Sleepflag=!Sleepflag;
	
}
