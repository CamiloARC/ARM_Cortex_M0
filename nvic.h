#ifndef NVIC_H_INCLUDED
#define NVIC_H_INCLUDED

#include "curses.h"
#include "io.h"
#include "instrucciones.h"
#include <stdint.h>

void NVIC(uint8_t *interrupcion,bool *FlagInt,uint32_t *registro,flags_t *bandera,uint8_t *SRAM);

void PUSHH(uint32_t *registro,uint8_t *SRAM,flags_t *bandera);

void POPP(uint32_t *registro,uint8_t *SRAM,flags_t *bandera);

#endif // NVIC_H_INCLUDED
