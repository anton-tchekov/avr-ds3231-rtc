#ifndef __TWI_H__
#define __TWI_H__

#include <inttypes.h>

#define TWI_FREQ          100000L
#define TWI_BUFFER_LENGTH     32
#define TWI_READY              0
#define TWI_MRX                1
#define TWI_MTX                2
#define TWI_SRX                3
#define TWI_STX                4

void twi_init(void);
void twi_begin_transmission(uint8_t address);
uint8_t twi_end_transmission(void);
uint8_t twi_request_from(uint8_t address, uint8_t quantity);
void twi_write(uint8_t data);
uint8_t twi_read(void);
uint8_t twi_available(void);

#endif /* __TWI_H__ */
