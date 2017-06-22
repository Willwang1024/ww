/** ###################################################################
**     Filename  : Events.c
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
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <io_map.h>
//extern unsigned int HalAdcValue[];
extern void HalBLDCMotorControlMain(int zero_adc_cnt[2], int max_adc_cnt[2]);

#pragma CODE_SEG DEFAULT

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
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
}

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

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
