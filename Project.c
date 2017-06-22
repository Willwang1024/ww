/** ###################################################################
**     Filename  : Project.c
**     Project   : Project
**     Processor : MC9S12XEP100MAG
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2015/7/10, 20:08
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Project */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AD0.h"
#include "AD1.h"
#include "GPIOA.h"
#include "GPIOD.h"
#include "GPIOE.h"
#include "GPIOH.h"
#include "GPIOC.h"
#include "GPIOB.h"
#include "GPIOK.h"
#include "CAN2.h"
#include "CAN3.h"
#include "GPIOS.h"
#include "GPIOJ.h"
#include "SPI2.h"
#include "Wdg.h"
#include "CAN0.h"
#include "CAN1.h"
#include "TickTimer.h"
#include "TimeStamp.h"
#include "PWM0.h"
#include "PWM1.h"
#include "PWM2.h"
#include "PWM3.h"
#include "PWM4.h"
#include "PWM5.h"
#include "PWM6.h"
#include "PWM7.h"
#include "Flash.h"
#include "EEPROM.h"
#include "ECT.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <hidef.h>      /* common defines and macros */
#include "xgate.h"

extern void OS_Main(void);

volatile unsigned char Hal_CCR_reg;

#pragma push

/* this variable definition is to demonstrate how to share data between XGATE and S12X */
#pragma DATA_SEG SHARED_DATA

/* Two stacks in XGATE core3 */ 
#pragma DATA_SEG XGATE_STK_L
word XGATE_STACK_L[1]; 
#pragma DATA_SEG XGATE_STK_H
word XGATE_STACK_H[1];

#pragma pop

#define ROUTE_INTERRUPT(vec_adr, cfdata)                \
  INT_CFADDR= (vec_adr) & 0xF0;                         \
  INT_CFDATA_ARR[((vec_adr) & 0x0F) >> 1]= (cfdata)

#define SOFTWARETRIGGER0_VEC  0x72 /* vector address= 2 * channel id */

#define ECT_OVF_VEC (0xDE)
#define ECT_CH7_VEC (0xE0)
#define ECT_CH6_VEC (0xE2)
#define ECT_CH5_VEC (0xE4)
#define ECT_CH4_VEC (0xE6)
#define ECT_CH3_VEC (0xE8)
#define ECT_CH2_VEC (0xEA)
#define ECT_CH1_VEC (0xEC)
#define ECT_CH0_VEC (0xEE)

#define CAN0_RX_VEC (0X59*2)
#define CAN1_RX_VEC (0X55*2)
#define CAN2_RX_VEC (0X51*2)
#define CAN3_RX_VEC (0X4D*2)
#define PIT_1_VEC (0x3C*2)

#define PTH_INT_VEC (0x66*2)
#define PTJ_INT_VEC (0x67*2)

void SetupXGATE(void) 
{
  /* initialize the XGATE vector block and
     set the XGVBR register to its start address */
  XGVBR= (unsigned int)(void*__far)(XGATE_VectorTable - XGATE_VECTOR_OFFSET);

  /* switch software trigger 0 interrupt to XGATE */
  //ROUTE_INTERRUPT(SOFTWARETRIGGER0_VEC, 0x84); /* RQST=1 and PRIO=4 */

  ROUTE_INTERRUPT(ECT_OVF_VEC,0x84);
  ROUTE_INTERRUPT(ECT_CH7_VEC,0x84);
  //ROUTE_INTERRUPT(ECT_CH6_VEC,0x84);
  //ROUTE_INTERRUPT(ECT_CH5_VEC,0x84);
  ROUTE_INTERRUPT(ECT_CH4_VEC,0x84);
  ROUTE_INTERRUPT(ECT_CH3_VEC,0x84);
  ROUTE_INTERRUPT(ECT_CH2_VEC,0x84);
  ROUTE_INTERRUPT(ECT_CH1_VEC,0x84);
  ROUTE_INTERRUPT(ECT_CH0_VEC,0x84);
  ROUTE_INTERRUPT(PIT_1_VEC, 0x84);
/*
  ROUTE_INTERRUPT(CAN0_RX_VEC,0x84);
  ROUTE_INTERRUPT(CAN1_RX_VEC,0x84);
  ROUTE_INTERRUPT(CAN2_RX_VEC,0x84);
  ROUTE_INTERRUPT(CAN3_RX_VEC,0x84);
*/
  /* when changing your derivative to non-core3 one please remove next five lines */
  XGISPSEL= 1;
  XGISP31= (unsigned int)(void*__far)(XGATE_STACK_L + 1);
  XGISPSEL= 2;
  XGISP74= (unsigned int)(void*__far)(XGATE_STACK_H + 1);
  XGISPSEL= 0;

  /* enable XGATE mode and interrupts */
  XGMCTL= 0xFBC1; /* XGE | XGFRZ | XGIE */

  /* force execution of software trigger 0 handler */
  //XGSWT= 0x0101;
}


void __far main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* Write your code here */
  SetupXGATE(); 

  __EI(); 							 /* Disable interrupts */

  OS_Main();
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END Project */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
