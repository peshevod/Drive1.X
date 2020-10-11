/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16LF18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set FW aliases
#define FW_TRIS                 TRISAbits.TRISA4
#define FW_LAT                  LATAbits.LATA4
#define FW_PORT                 PORTAbits.RA4
#define FW_WPU                  WPUAbits.WPUA4
#define FW_OD                   ODCONAbits.ODCA4
#define FW_ANS                  ANSELAbits.ANSA4
#define FW_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define FW_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define FW_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define FW_GetValue()           PORTAbits.RA4
#define FW_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define FW_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define FW_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define FW_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define FW_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define FW_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define FW_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define FW_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set REV aliases
#define REV_TRIS                 TRISAbits.TRISA5
#define REV_LAT                  LATAbits.LATA5
#define REV_PORT                 PORTAbits.RA5
#define REV_WPU                  WPUAbits.WPUA5
#define REV_OD                   ODCONAbits.ODCA5
#define REV_ANS                  ANSELAbits.ANSA5
#define REV_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define REV_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define REV_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define REV_GetValue()           PORTAbits.RA5
#define REV_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define REV_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define REV_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define REV_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define REV_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define REV_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define REV_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define REV_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS                 TRISBbits.TRISB4
#define EN_LAT                  LATBbits.LATB4
#define EN_PORT                 PORTBbits.RB4
#define EN_WPU                  WPUBbits.WPUB4
#define EN_OD                   ODCONBbits.ODCB4
#define EN_ANS                  ANSELBbits.ANSB4
#define EN_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define EN_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define EN_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define EN_GetValue()           PORTBbits.RB4
#define EN_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define EN_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define EN_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define EN_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define EN_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define EN_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set DOUT2 aliases
#define DOUT2_TRIS                 TRISBbits.TRISB5
#define DOUT2_LAT                  LATBbits.LATB5
#define DOUT2_PORT                 PORTBbits.RB5
#define DOUT2_WPU                  WPUBbits.WPUB5
#define DOUT2_OD                   ODCONBbits.ODCB5
#define DOUT2_ANS                  ANSELBbits.ANSB5
#define DOUT2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define DOUT2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define DOUT2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define DOUT2_GetValue()           PORTBbits.RB5
#define DOUT2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define DOUT2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define DOUT2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define DOUT2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define DOUT2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define DOUT2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define DOUT2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define DOUT2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set DOUT1 aliases
#define DOUT1_TRIS                 TRISBbits.TRISB6
#define DOUT1_LAT                  LATBbits.LATB6
#define DOUT1_PORT                 PORTBbits.RB6
#define DOUT1_WPU                  WPUBbits.WPUB6
#define DOUT1_OD                   ODCONBbits.ODCB6
#define DOUT1_ANS                  ANSELBbits.ANSB6
#define DOUT1_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define DOUT1_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define DOUT1_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define DOUT1_GetValue()           PORTBbits.RB6
#define DOUT1_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define DOUT1_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define DOUT1_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define DOUT1_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define DOUT1_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define DOUT1_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define DOUT1_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define DOUT1_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set CSN aliases
#define CSN_TRIS                 TRISBbits.TRISB7
#define CSN_LAT                  LATBbits.LATB7
#define CSN_PORT                 PORTBbits.RB7
#define CSN_WPU                  WPUBbits.WPUB7
#define CSN_OD                   ODCONBbits.ODCB7
#define CSN_ANS                  ANSELBbits.ANSB7
#define CSN_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define CSN_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define CSN_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define CSN_GetValue()           PORTBbits.RB7
#define CSN_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define CSN_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define CSN_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define CSN_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define CSN_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define CSN_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define CSN_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define CSN_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set CTRL1 aliases
#define CTRL1_TRIS                 TRISCbits.TRISC0
#define CTRL1_LAT                  LATCbits.LATC0
#define CTRL1_PORT                 PORTCbits.RC0
#define CTRL1_WPU                  WPUCbits.WPUC0
#define CTRL1_OD                   ODCONCbits.ODCC0
#define CTRL1_ANS                  ANSELCbits.ANSC0
#define CTRL1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define CTRL1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define CTRL1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define CTRL1_GetValue()           PORTCbits.RC0
#define CTRL1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define CTRL1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define CTRL1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define CTRL1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define CTRL1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define CTRL1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define CTRL1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define CTRL1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set CTRL2 aliases
#define CTRL2_TRIS                 TRISCbits.TRISC1
#define CTRL2_LAT                  LATCbits.LATC1
#define CTRL2_PORT                 PORTCbits.RC1
#define CTRL2_WPU                  WPUCbits.WPUC1
#define CTRL2_OD                   ODCONCbits.ODCC1
#define CTRL2_ANS                  ANSELCbits.ANSC1
#define CTRL2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define CTRL2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define CTRL2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define CTRL2_GetValue()           PORTCbits.RC1
#define CTRL2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define CTRL2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define CTRL2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define CTRL2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define CTRL2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define CTRL2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define CTRL2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define CTRL2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set CTRL3 aliases
#define CTRL3_TRIS                 TRISCbits.TRISC2
#define CTRL3_LAT                  LATCbits.LATC2
#define CTRL3_PORT                 PORTCbits.RC2
#define CTRL3_WPU                  WPUCbits.WPUC2
#define CTRL3_OD                   ODCONCbits.ODCC2
#define CTRL3_ANS                  ANSELCbits.ANSC2
#define CTRL3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define CTRL3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define CTRL3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define CTRL3_GetValue()           PORTCbits.RC2
#define CTRL3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define CTRL3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define CTRL3_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define CTRL3_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define CTRL3_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define CTRL3_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define CTRL3_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define CTRL3_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set PG aliases
#define PG_TRIS                 TRISCbits.TRISC5
#define PG_LAT                  LATCbits.LATC5
#define PG_PORT                 PORTCbits.RC5
#define PG_WPU                  WPUCbits.WPUC5
#define PG_OD                   ODCONCbits.ODCC5
#define PG_ANS                  ANSELCbits.ANSC5
#define PG_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define PG_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define PG_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define PG_GetValue()           PORTCbits.RC5
#define PG_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define PG_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define PG_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define PG_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define PG_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define PG_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define PG_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define PG_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/