#include "L99SM81V_Interface.h"
#include "mcc_generated_files/mcc.h"
#include "timers.h"
#include <string.h>
#include <stdio.h>
#include "shell.h"


void L99SM81V_SpiInit(void)
{
    SPI1_Initialize();
    SPI1_Open(SPI1_DEFAULT);
}

void L99SM81V_SpiDeinit(void)
{
    SPI1_Close();
}

void L99SM81V_EnterShutdown(void)
{
    EN_SetLow();
    delay_ms(100);
}

void L99SM81V_ExitShutdown(void)
{
    EN_SetHigh();
    send_chars("EN High\n");
    delay_ms(10);
    send_chars("after delay EN High\n");
}

GSB_t L99SM81V_SpiWriteRegisters(uint8_t cRegAddress, uint8_t* out_buffer, uint8_t* in_buffer)
{
    uint8_t cmd;
    GSB_t gsb;
    cmd=cRegAddress&0x3F;
    CSN_SetLow();
    gsb=(GSB_t)SPI1_ExchangeByte(cmd);
    in_buffer[0]=SPI1_ExchangeByte(out_buffer[0]);
    in_buffer[1]=SPI1_ExchangeByte(out_buffer[1]);
    CSN_SetHigh();
    return gsb;
}

GSB_t L99SM81V_SpiReadRegisters(uint8_t cRegAddress, uint8_t* in_buffer)
{
    uint8_t cmd,b;
    GSB_t gsb;
    b=0;
    cmd=(cRegAddress&0x3F)|0x40;
    CSN_SetLow();
    gsb=(GSB_t)SPI1_ExchangeByte(cmd);
    in_buffer[0]=SPI1_ExchangeByte(b);
    in_buffer[1]=SPI1_ExchangeByte(b);
    CSN_SetHigh();
    return gsb;
}


GSB_t L99SM81V_SpiReadClearRegisters(uint8_t cRegAddress, uint8_t* out_mask, uint8_t* in_buffer)
{
    uint8_t cmd;
    GSB_t gsb;
    cmd=(cRegAddress&0x3F)|0x80;
    CSN_SetLow();
    gsb=(GSB_t)SPI1_ExchangeByte(cmd);
    in_buffer[0]=SPI1_ExchangeByte(out_mask[0]);
    in_buffer[1]=SPI1_ExchangeByte(out_mask[1]);
    CSN_SetHigh();
    return gsb;
}

GSB_t L99SM81V_SpiReadDeviceInformation(uint8_t cRegAddress, uint8_t* in_buffer)
{
    uint8_t cmd,b,b1;
    GSB_t gsb;
    b=0;
    cmd=(cRegAddress&0x3F)|0xC0;
    CSN_SetLow();
    gsb=(GSB_t)SPI1_ExchangeByte(cmd);
    in_buffer[0]=SPI1_ExchangeByte(b);
    b1=SPI1_ExchangeByte(b);
    CSN_SetHigh();
    return gsb;
}


