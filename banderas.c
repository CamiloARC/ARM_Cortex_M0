#include "banderas.h"
#include <stdint.h>

void flags_aritmetica(uint32_t Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	if(((Rn&HALF)==1) && ((Rm&HALF)==1) && ((Rd&HALF)==0))   //  se utiliza AND binario (&) y  AND lógico(&&)
	{
		bandera->C=1; // La bandera carry es 1
	}

	else
	{
		bandera->C=0;
	}

	if(Rd>(1<<31))	 // se cumple cuando el resultado es mayor a 2^32
	{
	    bandera->N=1; // la bandera de negativo es 1
	}
	else
	{
		bandera->N=0;
	}

	if(Rd==0) // se cumple cuando el resultado es 0
	{
		bandera->Z=1; // la bandera de cero es 1
	}
	else
	{
		bandera->Z=0;
	}

	if((Rn&(HALF)) == (Rm&HALF))
	{
		if((Rn&HALF) != (Rd&HALF))
		{
			bandera->V=1; // bandera de sobreflujo igual a 1
		}
	}
	else
	{
		bandera->V=0;
	}
}

