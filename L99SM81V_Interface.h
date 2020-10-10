/* 
 * File:   L99SM81V_Interface.h
 * Author: ilya_000
 *
 * Created on 4 октября 2020 г., 20:16
 */

#ifndef L99SM81V_INTERFACE_H
#define	L99SM81V_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
    
#define GSR     0x01
#define MSR     0x02
#define GCR1    0x03
#define GCR1    0x03
#define MCR1    0x05
#define MCR2    0x06

typedef struct
{
    uint8_t GSBN:1;
    uint8_t RSTB:1;
    uint8_t SPIE:1;
    uint8_t PLE:1;
    uint8_t FE:1;
    uint8_t DE:1;
    uint8_t GW:1;
    uint8_t FS:1;
} GSB;



#define GSB_t uint8_t
    
void L99SM81V_SpiInit(void);
void L99SM81V_SpiDeinit(void);
void L99SM81V_EnterShutdown(void);
void L99SM81V_ExitShutdown(void);
GSB_t L99SM81V_SpiWriteRegisters(uint8_t cRegAddress, uint8_t* out_buffer, uint8_t* in_buffer);
GSB_t L99SM81V_SpiReadRegisters(uint8_t cRegAddress, uint8_t* in_buffer);
GSB_t L99SM81V_SpiReadClearRegisters(uint8_t cRegAddress, uint8_t* out_mask, uint8_t* in_buffer);
GSB_t L99SM81V_SpiReadDeviceInformation(uint8_t cRegAddress, uint8_t* in_buffer);

#ifdef	__cplusplus
}
#endif

#endif	/* L99SM81V_INTERFACE_H */

