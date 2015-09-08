#include <math.h>
#include "conversion.h"
#include <stdint.h>

int i;
void reg2bin(uint32_t R, uint32_t *Bit)
{
    for(i=0;i<32;i++)
	{
        Bit[31-i]=R/pow(2,31-i);
        R-=pow(2,31-i)*Bit[31-i];
    }
};
void bin2reg(uint32_t *R, uint32_t *Bit)
{
    *R=0;
    for(i=0;i<32;i++)
	{
        *R+=pow(2,i)*Bit[i];
    }
};
