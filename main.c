/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16LF18446
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "L99SM81V_Interface.h"
#include "timers.h"
#include "shell.h"


/*
                         Main application
 */
void main(void)
{
    GSB_t gsb;
    uint8_t info;
    char buf[16];
    uint8_t reg[2];
    uint8_t reg1[2];
    uint8_t s,p;

    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    timers_init();
    L99SM81V_SpiInit();
    L99SM81V_ExitShutdown();
    
    send_chars("Init Drive1...\n\r");
    start_x_shell();
    while (1)
    {
        for(uint8_t i=0;i<11;i++)
        {
            gsb=L99SM81V_SpiReadDeviceInformation(i, &info);
            send_chars("address=");
            send_chars(ui8tox(i,buf));
            send_chars(" info=");
            send_chars(ui8tox(info,buf));
            send_chars(" gsb=");
            send_chars(ui8tox(gsb,buf));
            send_chars("\n\r");
        }
        CTRL3_SetLow();
        send_chars("\n\r");
        gsb=L99SM81V_SpiReadRegisters(GCR1, reg);
        send_chars("GCR1=");
        send_chars(ui8tox(reg[0],buf));
        send_chars(" ");
        send_chars(ui8tox(reg[1],buf));
        send_chars("\n\r");
        gsb=L99SM81V_SpiReadRegisters(MCR1, reg);
        send_chars("MCR1=");
        send_chars(ui8tox(reg[0],buf));
        send_chars(" ");
        send_chars(ui8tox(reg[1],buf));
        send_chars("\n\r");
        if(!(reg[0]&0x80))
        {
            reg[0]|=0x80;
            gsb=L99SM81V_SpiWriteRegisters(MCR1, reg, reg1);
        };
 /*       for(int j=0;j<1000;j++)
        {
            CTRL1_SetHigh();
            delay_us(10);
            CTRL1_SetLow();
            delay_ms(1);
        }  */ 
        set_s('F',&s);
        TMR2_Period8BitSet(s);
        set_s('M',&p);
        T2CON=0x80|(p<<4);
        TMR2_Start();
        delay_ms(1000);
        TMR2_Stop();
            
        delay_ms(5000);
    }
}
/**
 End of File
*/