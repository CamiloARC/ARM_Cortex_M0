#ifndef RAM_H_INCLUDED
#define RAM_H_INCLUDED

#include <stdint.h>

void push(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list);

void pop(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list);

#endif // RAM_H_INCLUDED
