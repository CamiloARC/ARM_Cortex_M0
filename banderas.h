#ifndef BANDERAS_H_INCLUDED
#define BANDERAS_H_INCLUDED

#include <stdint.h>
#include "instrucciones.h"
#define HALF 2147483647UL

void flags_aritmetica(uint32_t Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

#endif // BANDERAS_H_INCLUDED
