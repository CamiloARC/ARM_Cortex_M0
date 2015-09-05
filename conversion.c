#include <math.h>
#include "conversion.h"

int i;
void reg2bin(unsigned long R, unsigned long *Bit)
{
    for(i=0;i<32;i++){
        Bit[31-i]=R/pow(2,31-i);
        R-=pow(2,31-i)*Bit[31-i];
    }
};
void bin2reg(unsigned long *R, unsigned long *Bit)
{
    *R=0;
    for(i=0;i<32;i++){
        *R+=pow(2,i)*Bit[i];
    }
};
