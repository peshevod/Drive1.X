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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
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

uint32_t count, max_steps;
uint8_t intr;

void TMR2_MyInterruptHandler(void){
    count++;
    if(count>=max_steps)
    {
        TMR2_Stop();
        count=0;
        intr=1;
    }
}

/*
                         Main application
 */
void main(void)
{
    GSB_t gsb;
    uint8_t info;
    char buf[16];
    uint8_t reg[2];
    uint8_t reg1[2],reg2[2],gsr[2],msr[2];
    uint8_t s,p,f,n,a;
    uint32_t spi_speed;
    uint32_t freq[8]={1000000,2000000,4000000,8000000,12000000,16000000,32000000,0};
    uint32_t fosc;

    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    timers_init();
    
    count=0;
    intr=0;
    TMR2_SetInterruptHandler(TMR2_MyInterruptHandler);

    L99SM81V_SpiInit();
    f=OSCFRQbits.HFFRQ;
    n=OSCCON1bits.NOSC;
    fosc=freq[f]/(0x00000001 << OSCCON1bits.NDIV);
    if(n==1 && f>2) fosc*=2;
    send_chars("\r\nFosc=");
    send_chars(ui32toa(fosc,buf));
    send_chars("MHz Req spi_speed=");
    send_chars(ui32toa(spi_speed,buf));
    send_chars("MHz\r\n");
    SSP1CON1bits.WCOL=0;
    SSP1CON1bits.SSPEN=1;
    SSP1CON1bits.CKP=0;
    set_s('S',&spi_speed);
    a=(spi_speed*4)/fosc-1;
    if(a==0)
    {
        SSP1CON1bits.SSPM=0;
        spi_speed=fosc/4;
    }
    else
    {
        SSP1CON1bits.SSPM=10;
        SSP1ADD=a;
    }
    send_chars("Fspi=");
    send_chars(ui32toa(spi_speed,buf));
    send_chars("MHz SSP1CON1=");
    send_chars(ui8tox(SSP1CON1,buf));
    send_chars(" SSP1ADD=");
    send_chars(ui8tox(SSP1ADD,buf));
    send_chars("\r\n");
    
    L99SM81V_ExitShutdown();
    
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
        
        gsb=L99SM81V_SpiReadRegisters(GSR, gsr);
        send_chars("GSR=");
        send_chars(ui8tox(gsr[0],buf));
        send_chars(" ");
        send_chars(ui8tox(gsr[1],buf));
        
        gsb=L99SM81V_SpiReadRegisters(MSR, msr);
        send_chars(" MSR=");
        send_chars(ui8tox(msr[0],buf));
        send_chars(" ");
        send_chars(ui8tox(msr[1],buf));
        send_chars("\n\r");
        
        gsb=L99SM81V_SpiReadRegisters(GCR1, reg);
        send_chars("GCR1=");
        send_chars(ui8tox(reg[0],buf));
        send_chars(" ");
        send_chars(ui8tox(reg[1],buf));
        send_chars("\n\r");
        gsb=L99SM81V_SpiReadRegisters(MCR1, reg);
        gsb=L99SM81V_SpiReadRegisters(MCR2, reg2);
        send_chars("MCR1=");
        send_chars(ui8tox(reg[0],buf));
        send_chars(" ");
        send_chars(i32toa((int)((reg[1]&0x7E)*90/32),buf));
        send_chars(" MCR2=");
        send_chars(ui8tox(reg2[0],buf));
        send_chars(" ");
        send_chars(ui8tox(reg2[1],buf));
//        send_chars("\n\r");
        reg2[1]&=0x3F;
        uint8_t decay_mode;
        set_s('D',&decay_mode);
        reg2[1]|=decay_mode<<6; //decay mode
//        reg2[1]|=0x40; //ol detection time = 60 ms
        gsb=L99SM81V_SpiWriteRegisters(MCR2, reg2, reg1);
        uint8_t step_mode;
        set_s('R',&step_mode);
        reg[0]|=step_mode; // ministep
            gsb=L99SM81V_SpiWriteRegisters(MCR1, reg, reg1);
            send_chars(" MCR1 after write=");
            send_chars(ui8tox(reg1[0],buf));
            send_chars(" ");
            send_chars(ui8tox(reg1[1],buf));
            send_chars("\n\r");
        while(1)
        {
            gsb=L99SM81V_SpiReadRegisters(MCR1, reg);
            if((reg[0]&0x7)==step_mode) break;
            send_chars("+");
            reg[0]=step_mode; // ministep
            gsb=L99SM81V_SpiWriteRegisters(MCR1, reg, reg1);
        }
        send_chars("\r\n");
        reg[0]|=0x80|step_mode; // motor on
//        reg[0]|=0x01; // ministep
            gsb=L99SM81V_SpiWriteRegisters(MCR1, reg, reg1);
            send_chars(" MCR1 after write=");
            send_chars(ui8tox(reg1[0],buf));
            send_chars(" ");
            send_chars(ui8tox(reg1[1],buf));
            send_chars("\n\r");
 /*       for(int j=0;j<1000;j++)
        {
            CTRL1_SetHigh();
            delay_us(10);
            CTRL1_SetLow();
            delay_ms(1);
        }  */ 
        set_s('F',&s);
        set_s('M',&p);
        send_chars("Period=");
        uint32_t t=(4000000*s/fosc)<<p;
        send_chars(ui32toa(t,buf));
        send_chars("us Frequency=");
        send_chars(ui32toa((fosc/(4*s))>>p,buf));
        send_chars("Hz\r\n");
        TMR2_Period8BitSet(s);
        T2CON=0x80|(p<<4); // prescaler

        uint32_t tt;
        if(step_mode!=0) tt=0x00000008>>(step_mode-1);
        else tt=16;
        max_steps=2000*tt;
        CTRL2_Toggle();
        TMR2_Start();
        while(!intr)
        {
            gsb=L99SM81V_SpiReadRegisters(GSR, gsr);
            gsb=L99SM81V_SpiReadRegisters(MSR, msr);
            if(gsr[0]||gsr[1]||msr[0]||msr[1])
            {
                send_chars("GSR=");
                send_chars(ui8tox(gsr[0],buf));
                send_chars(" ");
                send_chars(ui8tox(gsr[1],buf));

                send_chars(" MSR=");
                send_chars(ui8tox(msr[0],buf));
                send_chars(" ");
                send_chars(ui8tox(msr[1],buf));
                send_chars("\n\r");
                gsb=L99SM81V_SpiReadClearRegisters(GSR, gsr, reg1);
            }
            delay_ms(10);
        }
        intr=0;
 //       delay_ms(50*t*tt/1000);
 //       TMR2_Stop();
            
        delay_ms(5000);
    }
}
/**
 End of File
*/