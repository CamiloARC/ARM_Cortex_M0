#include "conversion.h"
#include <stdint.h>

/** \file conversion.c
 *  \brief Documento en donde se convierte de decimal a binario y viceversa
*/

void reg2bin(uint32_t R, uint32_t *Bit)
{
    int contador; // variable utilizada como contador para los ciclos
    for(contador=0;contador<32;contador++) // ciclo entre 0 a 31, ya que son 32 bits
	{
        Bit[31-contador]=R>>(31-contador);  //  se divide R entre 2^(31-contador) y se guarda un 0 o un 1
        R-=Bit[31-contador]<<(31-contador); // se guarda en R el producto entre el bit y 2^(31-contador)
    }
};
void bin2reg(uint32_t *R, uint32_t *Bit)
{
    int contador; // variable utilizada como contador para los ciclos
    *R=0;
    for(contador=0;contador<32;contador++)
	{
        *R+=Bit[contador]<<contador; // Para pasar el número a decimal tan solo es multiplicar cada bit i por su orden 2^i
    }
};
