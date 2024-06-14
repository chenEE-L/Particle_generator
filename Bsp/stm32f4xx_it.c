/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    31-October-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include <ucos_ii.h>
#include "stm32f4x7_eth.h"
#include "stm32f4x7_eth_bsp.h"
#include "main.h"
#include "bsp.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  //TimingDelay_Decrement();
    OS_CPU_SR  cpu_sr;
	//TimeTick_Decrement();
    OS_ENTER_CRITICAL();                         /* Tell uC/OS-II that we are starting an ISR          */
    OSIntNesting++;
    OS_EXIT_CRITICAL();
    OSTimeTick();                                /* Call uC/OS-II's OSTimeTick()                       */
    OSIntExit();   //�����жϼ�������
		WatchDog = !WatchDog;
}

/**
  * @brief  This function handles External line 10 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
//   if(EXTI_GetITStatus(ETH_LINK_EXTI_LINE) != RESET)
//   {
// //     Eth_Link_ITHandler(DP83848_PHY_ADDRESS);
//     /* Clear interrupt pending bit */
//     EXTI_ClearITPendingBit(ETH_LINK_EXTI_LINE);
//   }
}
/**
  * @brief  This function handles ethernet DMA interrupt request.
  * @param  None
  * @retval None
  */
void ETH_IRQHandler(void)
{
	//INT8U err;
//	OS_CPU_SR cpu_sr;
//	OS_ENTER_CRITICAL();    // ���ж�                               
//    OSIntNesting++;	   		//�ж�Ƕ�ײ�����֪ͨucos
//    OS_EXIT_CRITICAL();	   	//���ж�
	/* Handles all the received frames */
    /* check if any packet received */
//    while(ETH_CheckFrameReceived())
//    { 
//      /* process received ethernet packet */
//      LwIP_Pkt_Handle();
//    }
//	/* Clear the Eth DMA Rx IT pending bits */
//	ETH_DMAClearITPendingBit(ETH_DMA_IT_R);
//	ETH_DMAClearITPendingBit(ETH_DMA_IT_NIS);
//	OSIntExit();//�ж��˳���֪ͨucos�����þ����ӣ�	
}
/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/