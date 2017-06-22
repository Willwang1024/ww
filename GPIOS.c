/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : GPIOS.c
**     Project   : Project
**     Processor : MC9S12XEP100MAG
**     Component : Init_GPIO
**     Version   : Component 01.114, Driver 01.08, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/8/14, 15:02
**     Abstract  :
**          This file implements the General Purpose Input Output (S)
**          module initialization according to the Peripheral Initialization
**          settings, and defines interrupt service routines prototypes.
**
**     Settings  :
**          Component name                                 : GPIOS
**          Device                                         : S
**          Port control                                   : Entire I/O port
**
**          Port direction                                 : Input
**          Port output value                              : 0x00
**          Pull resistor                                  : no pull resistor
**          Open drain                                     : push-pull
**
**          Call Init method                               : yes
**     Contents  :
**         Init - void GPIOS_Init(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE GPIOS. */

#include "GPIOS.h"
/*
** ===================================================================
**     Method      :  GPIOS_Init (component Init_GPIO)
**
**     Description :
**         This method initializes registers of the GPIO module
**         according to this Peripheral Initialization settings. Call
**         this method in the user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void GPIOS_Init(void)
{
  /* PTS: PTS7=0,PTS6=0,PTS5=0,PTS4=0,PTS3=0,PTS2=0,PTS1=0,PTS0=0 */
  setReg8(PTS, 0x00U);                  
  /* WOMS: WOMS7=0,WOMS6=0,WOMS5=0,WOMS4=0,WOMS3=0,WOMS2=0,WOMS1=0,WOMS0=0 */
  setReg8(WOMS, 0x00U);                 
  /* PERS: PERS7=0,PERS6=0,PERS5=0,PERS4=0,PERS3=0,PERS2=0,PERS1=0,PERS0=0 */
  setReg8(PERS, 0x00U);                 
  /* DDRS: DDRS7=0,DDRS6=0,DDRS5=0,DDRS4=0,DDRS3=0,DDRS2=0,DDRS1=0,DDRS0=0 */
  setReg8(DDRS, 0x00U);                 
}

/* END GPIOS. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
