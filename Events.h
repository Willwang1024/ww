/** ###################################################################
**     Filename  : Events.h
**     Project   : Project
**     Processor : MC9S12XEP100MAG
**     Component : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2015/7/10, 20:08
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         AD1_OnEnd - void AD1_OnEnd(void);
**         AD0_OnEnd - void AD0_OnEnd(void);
**
** ###################################################################*/

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
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

#pragma CODE_SEG DEFAULT

void TI1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD1_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which
**         consists of <1 or more conversions>) is/are finished.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD0_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD0_OnEnd (module Events)
**
**     Component   :  AD0 [ADC]
**     Description :
**         This event is called after the measurement (which
**         consists of <1 or more conversions>) is/are finished.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
