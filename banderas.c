#include <stdint.h>
#include "banderas.h"

/** \file banderas.c
 *  \brief Documento en donde se especifica cada una de las condiciones para activar o desactivar las banderas
*/

void flags_aritmetica(uint32_t Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	if(( (Rn>=HALF)&&(Rm<HALF)&&(Rd<HALF)) || ((Rm>=HALF)&&(Rn<HALF)&&(Rd<HALF)) || ((Rn>=HALF)&&(Rm>=HALF)) ) // Rn y Rm son mayores o iguales a 2^31
																											   // Rn es mayor o igual a 2^31 y Rm y Rd son menores a 2^31
																											   // Rm es mayor o igual a 2^31 y Rn y Rd son menores a 2^31
	{
		bandera->C=1; // La bandera carry es 1
	}
	else
	{
		bandera->C=0;
	}
	if((Rn&(HALF)) == (Rm&HALF)) // Los bits mas significativo de Rn y Rm son iguales
	{
		if((Rn&HALF) != (Rd&HALF))	// Los bits mas significativos de Rn y Rd son diferentes
		{
			bandera->V=1; // bandera de sobreflujo igual a 1
		}
	}
	else
	{
		bandera->V=0;
	}
}
void flags_global(uint32_t Rd,flags_t *bandera)
{
    if(Rd==0) // se cumple cuando el resultado es 0
	{
		bandera->Z=1; // la bandera de cero es 1
	}
	else
	{
		bandera->Z=0;
	}
	if(Rd>=(1<<31))	 // se cumple cuando el resultado es mayor o igual a 2^31
	{
	    bandera->N=1; // la bandera de negativo es 1
	}
	else
	{
		bandera->N=0;
	}
}

