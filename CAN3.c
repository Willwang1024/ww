/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CAN3.c
**     Project   : Project
**     Processor : MC9S12XEP100MAG
**     Component : Init_MSCAN
**     Version   : Component 01.067, Driver 01.11, CPU db: 3.00.034
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2017/5/26, 12:01
**     Abstract  :
**          This file implements the MSCAN (MSCAN3) module initialization
**          according to the Peripheral Initialization Bean settings,
**          and defines interrupt service routines prototypes.
**          The Motorola Scalable Controller Area Network (MSCAN) definition
**          is based on the MSCAN12 definition which is the specific
**          implementation of the Motorola Scalable CAN concept targeted
**          for the Freescale MC68HC12 Microcontroller Family.
**
**          The basic features of the MSCAN are as follows:
**          - Implementation of the CAN protocol - Version 2.0A/B
**           Standard and extended data frames
**           0 - 8 bytes data length
**           Programmable bit rate up to 1 Mbps1
**           Support for remote frames
**           5 receive buffers with FIFO storage scheme
**          - 3 transmit buffers with internal prioritization using a local
**          priority concept
**          - Flexible maskable identifier filter supports two full size
**          extended identifier filters (two 32-bit) or four 16-bit filters
**          or eight 8-bit filters
**          - Programmable wake-up functionality with integrated low-pass
**          filter
**          - Programmable loop back mode supports self-test operation
**          - Programmable listen-only mode for monitoring of CAN bus
**          - Separate signalling and interrupt capabilities for all CAN
**          receiver and transmitter error states
**          (Warning, Error Passive, Bus-Off)
**          - Programmable MSCAN clock source either Bus Clock or Oscillator
**          Clock
**          - Internal timer for time-stamping of received and transmitted
**          messages
**          - Three low power modes: Sleep, Power Down and MSCAN Enable
**          - Global initialization of configuration registers
**     Settings  :
**          Bean name                                      : CAN3
**          Device                                         : MSCAN3
**          Clock Source                                   : Oscillator Clock
**          Baud Rate Prescaler                            : 2
**          Synchr. Jump Width                             : 4
**          Sampling                                       : One sample per bit
**          Time Segment 1                                 : 8
**          Time Segment 2                                 : 7
**          CAN frequency                                  : 8 MHz
**          Time quantum                                   : 125 ns
**          Bit rate                                       : 500 kbit/s
**          CAN Stops in Wait Mode                         : no
**          Wake-Up Mode                                   : None
**          Loop Back Test Mode                            : Disabled
**          Listen Only Mode                               : Normal operation
**          Sleep Mode Request                             : Disabled
**          Time Stamp                                     : Enabled
**          Acceptance mode                                : Two 32 bit Acceptance Filters
**          Rx acceptance ID(1st bank)                     : 00000000
**          Rx acceptance ID(2nd bank)                     : 00000000
**          Rx acceptance ID mask (1st bank)               : FFFFFFFF
**          Rx acceptance ID mask (2nd bank)               : FFFFFFFF
**          RXCAN pin                                      : PM6_RxCAN3_RxCAN4_RxD3
**          RXCAN pin signal                               : 
**          TXCAN pin                                      : PM7_TxCAN3_TxCAN4_TxD3
**          TXCAN pin signal                               : 
**          Wake up                                        : 
**          Wake up                                        : Disabled
**          Interrupt                                      : Vcan3wkup
**          Wake interrupt priority                        : 4
**          ISR name                                       : 
**          Error                                          : 
**          Error Interrupt                                : Vcan3err
**          Status Change Interrupt                        : Disabled
**          Receiver Status Change                         : do not generate
**          Transmitt. Status Change                       : do not generate
**          Overrun Interrupt                              : Disabled
**          Error interrupt priority                       : 4
**          ISR name                                       : 
**          Receiver Full                                  : 
**          Receiver Full                                  : Disabled
**          Receiver Interrupt                             : Vcan3rx
**          Rx interrupt priority                          : 4
**          ISR name                                       : CAN3Rx
**          Transmitter empty                              : 
**          Transmitter Interrupt                          : Vcan3tx
**          Tx Empty Interrupt 0                           : Disabled
**          Tx Empty Interrupt 1                           : Disabled
**          Tx Empty Interrupt 2                           : Disabled
**          Tx interrupt priority                          : 4
**          ISR name                                       : CAN3Tx
**          Call Init in CPU init. code                    : yes
**          CAN Enable                                     : yes
**     Contents  :
**         Init - void CAN3_Init(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/* MODULE CAN3. */
#include "CAN3.h"

/*
** ###################################################################
**
**  The interrupt service routine(s) must be implemented
**  by user in one of the following user modules.
**
**  If the "Generate ISR" option is enabled, Processor Expert generates
**  ISR templates in the CPU event module.
**
**  User modules:
**      Project.c
**      Events.c
**
** ###################################################################
#pragma CODE_SEG __NEAR_SEG NON_BANKED
ISR(CAN3Rx)
        {
        // NOTE: The routine should include the following actions to obtain
        //       correct functionality of the hardware.
        //
        //      The ISR is invoked by RXF flag. The RXF flag is cleared
        //      if a "1" is written to the flag in CAN3RFLG register.
        //      Example: CAN3RFLG = CAN3RFLG_RXF_MASK;
        }
ISR(CAN3Tx)
        {
        // NOTE: The routine should include the following actions to obtain
        //       correct functionality of the hardware.
        //
        //       If you want to stop pending this interupt, corresponding enable bit
        //       must be cleared by writting "0". The interrupt must be enabled again before
        //       a next frame transmission start.
        //       Example: CAN3TIER_TXEIE0 = 0;
        //                CAN3TIER_TXEIE1 = 0;
        //                CAN3TIER_TXEIE2 = 0;
        //
        }
#pragma CODE_SEG DEFAULT
*/
/*
** ===================================================================
**     Method      :  CAN3_Init (component Init_MSCAN)
**
**     Description :
**         This method initializes registers of the CAN module
**         according to this Peripheral Initialization Bean settings.
**         Call this method in user code to initialize the module.
**         By default, the method is called by PE automatically; see
**         "Call Init method" property of the bean for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CAN3_Init(void)
{
  /* CAN3CTL0: INITRQ=1 */
  setReg8Bits(CAN3CTL0, 0x01U);         
  while(CAN3CTL1_INITAK == 0U) {       /* Wait for init acknowledge */
  }
  /* CAN3CTL1: CANE=1,CLKSRC=0,LOOPB=0,LISTEN=0,BORM=0,WUPM=0,SLPAK=0,INITAK=1 */
  setReg8(CAN3CTL1, 0x81U);             
  /* CAN3BTR1: SAMP=0,TSEG22=1,TSEG21=1,TSEG20=0,TSEG13=0,TSEG12=1,TSEG11=1,TSEG10=1 */
  setReg8(CAN3BTR1, 0x67U);             
  /* CAN3BTR0: SJW1=1,SJW0=1,BRP5=0,BRP4=0,BRP3=0,BRP2=0,BRP1=0,BRP0=1 */
  setReg8(CAN3BTR0, 0xC1U);             
  /* CAN3IDAC: ??=0,??=0,IDAM1=0,IDAM0=0,??=0,IDHIT2=0,IDHIT1=0,IDHIT0=0 */
  setReg8(CAN3IDAC, 0x00U);             
  /* CAN3IDAR0: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR0, 0x00U);            
  /* CAN3IDAR1: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR1, 0x00U);            
  /* CAN3IDAR2: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR2, 0x00U);            
  /* CAN3IDAR3: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR3, 0x00U);            
  /* CAN3IDAR4: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR4, 0x00U);            
  /* CAN3IDAR5: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR5, 0x00U);            
  /* CAN3IDAR6: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR6, 0x00U);            
  /* CAN3IDAR7: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN3IDAR7, 0x00U);            
  /* CAN3IDMR0: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR0, 0xFFU);            
  /* CAN3IDMR1: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR1, 0xFFU);            
  /* CAN3IDMR2: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR2, 0xFFU);            
  /* CAN3IDMR3: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR3, 0xFFU);            
  /* CAN3IDMR4: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR4, 0xFFU);            
  /* CAN3IDMR5: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR5, 0xFFU);            
  /* CAN3IDMR6: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR6, 0xFFU);            
  /* CAN3IDMR7: AM7=1,AM6=1,AM5=1,AM4=1,AM3=1,AM2=1,AM1=1,AM0=1 */
  setReg8(CAN3IDMR7, 0xFFU);            
  /* CAN3CTL0: INITRQ=0 */
  clrReg8Bits(CAN3CTL0, 0x01U);         
  while(CAN3CTL1_INITAK) {             /* Wait for init exit */
  }
  /* CAN3CTL0: RXFRM=0,RXACT=0,CSWAI=0,SYNCH=0,TIME=1,WUPE=0,SLPRQ=0,INITRQ=0 */
  setReg8(CAN3CTL0, 0x08U);             
  /* CAN3RIER: WUPIE=0,CSCIE=0,RSTATE1=0,RSTATE0=0,TSTATE1=0,TSTATE0=0,OVRIE=0,RXFIE=0 */
  setReg8(CAN3RIER, 0x00U);             
  /* CAN3TIER: ??=0,??=0,??=0,??=0,??=0,TXEIE2=0,TXEIE1=0,TXEIE0=0 */
  setReg8(CAN3TIER, 0x00U);             
}

/* END CAN3. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
