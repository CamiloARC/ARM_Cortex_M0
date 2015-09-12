#include <stdint.h>
#include "instrucciones.h"
#include "banderas.h"
#include "conversion.h"


int i=0, j=0; //variables utilizadas como contadores

void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
     *Rd=Rn+Rm;
}

void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
     *Rd=Rn+Rm;
     flags_aritmetica(*Rd,Rn,Rm,bandera);
}

void AND(uint32_t *Rd,uint32_t Rm)
{
	*Rd&=Rm;
}

void ANDS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd&=Rm;
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
}

void EOR(uint32_t *Rd,uint32_t Rm)
{
	*Rd^=Rm;
}

void EORS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd^=Rm;
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
}
void MOV(uint32_t *Rd,uint32_t Rm)
{
	*Rd=Rm;
}

void MOVS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rm;
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
}

void ORR(uint32_t *Rd,uint32_t Rm)
{
	*Rd|=Rm;
}

void ORRS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd|=Rm;
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
}

void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm)
{
	*Rd=Rn-Rm;
}

void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rn-Rm;
    flags_aritmetica(Rd,Rn,Rm,bandera);
}

void REVSH(uint32_t *Rd,uint32_t Rm)
{
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd[0]);
    reg2bin(Rm,&BitRm[0]);

    for(i=0;i<8;i++)
    {
        BitRd[i]=BitRm[i+8];
    }
    for(i=8;i<32;i++)
	{
        BitRd[i]=BitRm[7];
    }
    bin2reg(Rd,&BitRd[0]);
}

void REV16(uint32_t *Rd,uint32_t Rm)
{
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd[0]);
    reg2bin(Rm,&BitRm[0]);
    for(i=0;i<16;i++)
    {
        BitRd[31-i]=BitRm[15-i];
        BitRd[15-i]=BitRm[31-i];
    }
    bin2reg(Rd,&BitRd[0]);
}

void REV(uint32_t *Rd,uint32_t Rm)
{
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd[0]);
    reg2bin(Rm,&BitRm[0]);

    for(i=0;i<8;i++)
    {
        BitRd[31-i]=BitRm[7-i];
        BitRd[23-i]=BitRm[15-i];
        BitRd[15-i]=BitRm[23-i];
        BitRd[7-i]=BitRm[31-i];
    }
    bin2reg(Rd,&BitRd[0]);
}

void NOP()
{

}

void RSB(uint32_t *Rd,uint32_t Rn)
{
    *Rd=~Rn+1;
}

void RSBS(uint32_t *Rd,uint32_t Rn,flags_t *bandera)
{
    *Rd=~Rn+1;
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
}

void MVN(uint32_t *Rd,uint32_t Rm)
{
    *Rd=~Rm;
}

void MVNS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
    *Rd=~Rm;
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
}

void BIC(uint32_t *Rdn,uint32_t Rm)
{
    *Rdn&=~Rm;
}

void BICS(uint32_t *Rdn,uint32_t Rm,flags_t *bandera)
{
    *Rdn&=~Rm;
	if(*Rdn>(1<<31))	 // se cumple cuando el resultado es mayor a 2^32
	{
	    bandera->N=1; // la bandera de negativo es 1
	}
	else
	{
		bandera->N=0;
	}
	if(*Rdn==0) // se cumple cuando el resultado es 0
	{
		bandera->Z=1; // la bandera de cero es 1
	}
	else
	{
		bandera->Z=0;
	}
}

void ASR(uint32_t *Rd,uint32_t Rm)
{
    uint32_t aux;
    aux=*Rd&(1<<31);
    *Rd=*Rd>>Rm;
    *Rd=*Rd|aux;
}

void ASRS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
    uint32_t aux;
    aux=*Rd&(1<<31);
    *Rd=*Rd>>Rm;
    *Rd=*Rd|aux;
}

void ROR(uint32_t *Rdn,uint32_t Rm)
{
    uint32_t aux1,aux2;
    aux1=*Rdn>>Rm;
    aux2=*Rdn<<(32-Rm);
    *Rdn=aux1|aux2;
}

void LSR(uint32_t *Rdn,uint32_t Rm)
{
    *Rdn=*Rdn>>Rm;
}

void LSRS(uint32_t *Rdn,uint32_t Rm,flags_t *bandera)
{
    *Rdn=*Rdn>>Rm;
	if(*Rdn>(1<<31))	 // se cumple cuando el resultado es mayor a 2^32
	{
	    bandera->N=1; // la bandera de negativo es 1
	}
	else
	{
		bandera->N=0;
	}
	if(*Rdn==0) // se cumple cuando el resultado es 0
	{
		bandera->Z=1; // la bandera de cero es 1
	}
	else
	{
		bandera->Z=0;
	}
}

void LSL(uint32_t *Rdn,uint32_t Rm)
{
    *Rdn=*Rdn<<Rm;
}

void LSLS(uint32_t *Rdn,uint32_t Rm,flags_t *bandera)
{
    *Rdn=*Rdn<<Rm;
	if(*Rdn>(1<<31))	 // se cumple cuando el resultado es mayor a 2^32
	{
	    bandera->N=1; // la bandera de negativo es 1
	}
	else
	{
		bandera->N=0;
	}

	if(*Rdn==0) // se cumple cuando el resultado es 0
	{
		bandera->Z=1; // la bandera de cero es 1
	}
	else
	{
		bandera->Z=0;
	}
}

void MUL(uint32_t *Rdm,uint32_t Rn,uint32_t Rm)
{
    *Rdm=(uint32_t)(Rn*Rm);
}

void CMN(uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
     Rn+=Rm;
}

void CMP(uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    Rn-=Rm;
    flags_aritmetica(Rn,Rn,Rm,bandera);
}

void TST(uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    Rn&=Rm;
    flags_aritmetica(Rn,Rn,Rm,bandera);
}

void ADC(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
     *Rd=Rn+Rm;
     flags_aritmetica(Rd,Rn,Rm,bandera);
     *Rd+=bandera->C;
}

void SBC(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=Rn-Rm;
    flags_aritmetica(Rd,Rn,Rm,bandera);
    *Rd+=bandera->C;
}


