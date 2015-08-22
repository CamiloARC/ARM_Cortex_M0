#include "instrucciones.h"

void ADDS(unsigned long int *Rd,unsigned long int Rn,unsigned long int Rm)
{
     *Rd=Rn+Rm;
}

void AND(unsigned long int *Rd,unsigned long int Rm)
{
	*Rd&=Rm;
};

void EOR(unsigned long int *Rd,unsigned long int Rm)
{
	*Rd^=Rm;
};

void MOV(unsigned long int *Rd,unsigned long int Rm)
{
	*Rd=Rm;
};

void ORR(unsigned long int *Rd,unsigned long int Rm)
{
	*Rd|=Rm;
};

void SUB(unsigned long int *Rd,unsigned long int Rn,unsigned long int Rm)
{
	*Rd=Rn-Rm;
};
