#include <stdint.h>
#include "instrucciones.h"

#define HALF ((1<<31)-1) // variable half igual a 2^32-1

char i=0;


void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
     *Rd=Rn+Rm;

	if(((Rn&HALF)==1) && ((Rm&HALF)==1) && ((*Rd&HALF)==0))   //  se utiliza AND binario (&) y  AND lógico(&&)
	{
		bandera->C=1; // La bandera carry es 1
	}
	else
	{
		bandera->C=0;
	}
	if(*Rd>(1<<31))	 // se cumple cuando el resultado es mayor a 2^32
	{
	    bandera->N=1; // la bandera de negativo es 1
	}
	else
	{
		bandera->N=0;
	}
	if(*Rd==0) // se cumple cuando el resultado es 0
	{
		bandera->Z=1; // la bandera de cero es 1
	}
	else
	{
		bandera->Z=0;
	}
	if((Rn&HALF) == (Rm&HALF))
	{
		if((Rn&HALF) != (*Rd&HALF))
		{
			bandera->V=1; // bandera de sobreflujo igual a 1
		}
	}
	else
	{
		bandera->V=0;
	}
}

void AND(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd&=Rm;

	if((*Rd&(1<<31-1)==1) && (Rm&(1<<31-1)==1) && (*Rd&(1<<31-1)==0))
	{
		bandera->C=1;
	}
	else
	{
		bandera->C=0;
	}
	if((*Rd&(1<<31)) == (1<<31))
	{
		bandera->N=1;
    }
	else
	{
		bandera->N=0;
	}
	if(*Rd==0)
	{
		bandera->Z=1;
	}
	else
	{
		bandera->Z=0;
	}
	if(((*Rd&((1<<31)-1)) == (Rm&1<<31-1)) != (*Rd&1<<31-1))
	{
		bandera->V=1;
	}
	else
	{
		bandera->V=0;
	}
}

void EOR(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd^=Rm;

	if((*Rd&(1<<31-1)==1) && (Rm&(1<<31-1)==1) && (*Rd&(1<<31-1)==0))
	{
		bandera->C=1;
	}
	else
	{
		bandera->C=0;
	}
	if((*Rd&(1<<31)) == (1<<31))
	{
		bandera->N=1;
	}
	else
	{
		bandera->N=0;
	}
	if(*Rd==0)
	{
		bandera->Z=1;
	}
	else
	{
		bandera->Z=0;
	}
	if(((*Rd&1<<31-1) == (Rm&1<<31-1)) != (*Rd&1<<31-1))
	{
		bandera->V=1;
	}
	else
	{
		bandera->V=0;
	}
}

void MOV(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rm;

	if((*Rd&(1<<31-1)==1) && (Rm&(1<<31-1)==1) && (*Rd&(1<<31-1)==0))
	{
		bandera->C=1;
	}
	else
	{
		bandera->C=0;
	}
	if((*Rd&(1<<31)) == (1<<31))
	{
		bandera->N=1;
	}
	else
	{
		bandera->N=0;
	}
	if(*Rd==0)
	{
		bandera->Z=1;
	}
	else
	{
		bandera->Z=0;
	}
	if(((*Rd&1<<31-1) == (Rm&1<<31-1)) != (*Rd&1<<31-1))
	{
		bandera->V=1;
	}
	else
	{
		bandera->V=0;
	}
}

void ORR(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd|=Rm;
	if((*Rd&(1<<31-1)==1) && (Rm&(1<<31-1)==1) && (*Rd&(1<<31-1)==0))
	{
		bandera->C=1;
	}
	else
	{
		bandera->C=0;
	}
	if((*Rd&(1<<31)) == (1<<31))
	{
		bandera->N=1;
	}
	else
	{
		bandera->N=0;
	}
	if(*Rd==0)
	{
		bandera->Z=1;
	}
	else
	{
		bandera->Z=0;
	}
	if(((*Rd&1<<31-1) == (Rm&1<<31-1)) != (*Rd&1<<31-1))
	{
		bandera->V=1;
	}
	else
	{
		bandera->V=0;
	}
}

void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rn-Rm;
	if( (Rn&(1<<31-1)==1) && (Rm&(1<<31-1)==1) && (*Rd&(1<<31-1)==0))
	{
		bandera->C=1;
	}
	else
	{
		bandera->C=0;
	}
	if((*Rd&(1<<31)) == (1<<31))
	{
		bandera->N=1;
	}
	else
	{
		bandera->N=0;
	}
	if(*Rd==0)
	{
		bandera->Z=1;
	}
	else
	{
		bandera->Z=0;
	}
	if(((Rn&1<<31-1) == (Rm&1<<31-1)) != (*Rd&1<<31-1))
	{
		bandera->V=1;
	}
	else
	{
		bandera->V=0;
	}
}


void REVSH(uint32_t*Rd,uint32_t Rm)
{
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd);
    reg2bin(Rm,&BitRm);

    for(i=0;i<8;i++)
    {
        BitRd[8+i]=BitRm[i];
        BitRd[i]=BitRm[i+8];
    }
    for(i=16;i<32;i++){
        BitRd[i]=BitRm[7];
    }
   bin2reg(Rd,&BitRd);
}


void REV16(uint32_t *Rd,uint32_t Rm)
{
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd);
    reg2bin(Rm,&BitRm);

    for(i=0;i<16;i++)
    {
        BitRd[31-i]=BitRm[15-i];
        BitRd[15-i]=BitRm[31-i];
    }
    bin2reg(Rd,&BitRd);
}

void REV(uint32_t *Rd,uint32_t Rm)
{
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd);
    reg2bin(Rm,&BitRm);

    for(i=0;i<8;i++)
    {
        BitRd[31-i]=BitRm[7-i];
        BitRd[23-i]=BitRm[15-i];
        BitRd[15-i]=BitRm[23-i];
        BitRd[7-i]=BitRm[31-i];
    }
    bin2reg(Rd,&BitRd);
}
void NOP()
{

}

void RSBS(uint32_t *Rd,uint32_t Rn)
{
    *Rd=~Rn+1;
}
void MVNS(uint32_t *Rd,uint32_t Rm)
{
    *Rd=~Rm;
}

void BIC(uint32_t *Rdn,uint32_t Rm)
{
    *Rdn&=~Rm;
}

void ASRS(uint32_t *Rd,uint32_t Rm)
{
    uint32_t BitRd[32],aux,j;
    reg2bin(*Rd,&BitRd);
    aux=BitRd[31];
    for(j=0;j<Rm;j++)
    {
    for(i=0;i<31;i++)
    {
        BitRd[i]=BitRd[i+1];
    }
    BitRd[31]=0;
    }
    BitRd[31]=aux;
    bin2reg(Rd,&BitRd);
}

void ROR(uint32_t *Rdn,uint32_t Rm)
{
    uint32_t BitRdn[32],aux,j;
    reg2bin(*Rdn,&BitRdn);

    for(j=0;j<Rm;j++)
    {
    aux=BitRdn[0];
    for(i=0;i<31;i++)
    {
        BitRdn[i]=BitRdn[i+1];
    }
    BitRdn[31]=aux;
    }
    bin2reg(Rdn,&BitRdn);
}

LSR(uint32_t *Rdn,uint32_t Rm)
{
    uint32_t BitRdn[32],j;
    reg2bin(*Rdn,&BitRdn);
    for(j=0;j<Rm;j++)
    {
    for(i=0;i<31;i++)
    {
        BitRdn[i]=BitRdn[i+1];
    }
    BitRdn[31]=0;
    }
    bin2reg(Rdn,&BitRdn);
}

LSL(uint32_t *Rdn,uint32_t Rm)
{
    uint32_t BitRdn[32],j;
    reg2bin(*Rdn,&BitRdn);
    for(j=0;j<Rm;j++)
    {
    for(i=0;i<31;i++)
    {
        BitRdn[31-i]=BitRdn[30-i];
    }
    BitRdn[0]=0;
    }
    bin2reg(Rdn,&BitRdn);
}
