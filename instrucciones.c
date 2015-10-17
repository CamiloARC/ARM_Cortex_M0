#include <stdint.h>
#include "instrucciones.h"
#include "banderas.h"
#include "conversion.h"

/** \file instrucciones.c
 *  \brief Documento en el cual se realizan las operaciones necesarias para realizar cad instruccion, ademas se definen cuales banderas se modifican con cada instruccion
*/

void ADCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
     *Rd=Rn+Rm+bandera->C;
     flags_global(*Rd,bandera);	// flags_global modifican la bandera de cero y la bandera de negativo
     flags_aritmetica(*Rd,Rn,Rm,bandera);	// Modifican banderas de carry y sobreflujo
}

void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=Rn+Rm;
}

void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=Rn+Rm;
    flags_global(*Rd,bandera);
    flags_aritmetica(*Rd,Rn,Rm,bandera);
}

void ANDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rn&Rm;
	// no modifica bandera de sobreflujo, ni bandera de carry
	flags_global(*Rd,bandera);
}

void ASRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    uint32_t aux;
    aux=Rn&(1<<31);             // crear un auxiliar para el bit mas significativo
    *Rd=Rn>>Rm;                // realiza el corrimiento
    *Rd|=aux;                   // realiza la operacion ORR
    // no modifica bandera de sobreflujo
    bandera->C=(Rn>>(Rm-1))&1;   // el carry corresponde al último bit que sale por la derecha
    flags_global(*Rd,bandera);
}

void BICS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=Rn&(~Rm);
    // no modifica bandera de sobreflujo, ni bandera de carry
    flags_global(*Rd,bandera);
}

void CMN(uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
     Rn+=Rm;    //Suma pero no guarda el resultado, solo modifica banderas
     flags_global(Rn,bandera);
     flags_aritmetica(Rn,Rn,Rm,bandera);
}

void CMP(uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    uint32_t R;
    R=Rn+((~Rm)+1);     //Resta pero no guarda el resultado, solo modifica banderas
    flags_global(R,bandera);
    flags_aritmetica(R,Rn,((~Rm)+1),bandera);
}

void EORS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rn^Rm;
	//  no modifica bandera de sobreflujo, ni bandera de carry
	flags_global(*Rd,bandera);
}

void LSLS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=Rn<<Rm;
    //  no modifica bandera de sobreflujo
    bandera->C=((Rn<<(Rm-1))&(1<<31))>>31;   // el carry corresponde al último bit que sale por la izquierda
    flags_global(*Rd,bandera);
}

void LSRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=Rn>>Rm;
    //  no modifica bandera de sobreflujo
    bandera->C=(Rn>>(Rm-1))&1;   // el carry corresponde al último bit que sale por la derecha
    flags_global(*Rd,bandera);
}

void MOV(uint32_t *Rd,uint32_t Rm)
{
	*Rd=Rm;
	//  no modifica banderas
}

void MOVS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rm;
	//   no modifica bandera de sobreflujo, ni bandera de carry
	flags_global(*Rd,bandera);
}

void MULS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=(uint32_t)(Rn*Rm);
    //   no modifica bandera de sobreflujo, ni bandera de carry
    flags_global(*Rd,bandera);
}

void MVNS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
    *Rd=~Rm;
    //   no modifica bandera de sobreflujo, ni bandera de carry
    flags_global(*Rd,bandera);
}

void NOP()
{

}

void ORRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rn|Rm;
    //   no modifica bandera de sobreflujo, ni bandera de carry
	flags_global(*Rd,bandera);
}

void REV(uint32_t *Rd,uint32_t Rm)
{
    int i;
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd[0]);     //  Convertir Rd en binario y trabajar con el arreglo de unos y ceros Bit Rd
    reg2bin(Rm,&BitRm[0]);      //  Convertir Rm en binario y trabajar con el arreglo de unos y ceros Bit Rm

    for(i=0;i<8;i++)
    {
        BitRd[31-i]=BitRm[7-i];
        BitRd[23-i]=BitRm[15-i];
        BitRd[15-i]=BitRm[23-i];
        BitRd[7-i]=BitRm[31-i];
    }
    bin2reg(Rd,&BitRd[0]);      // Convertir BitRd en decimal y guardarlo en Rd
    // no modifica banderas
}

void REV16(uint32_t *Rd,uint32_t Rm)
{
    int i;
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd[0]);         //  Convertir Rd en binario y trabajar con el arreglo de unos y ceros Bit Rd
    reg2bin(Rm,&BitRm[0]);          //  Convertir Rm en binario y trabajar con el arreglo de unos y ceros Bit Rm
    for(i=0;i<16;i++)
    {
        BitRd[31-i]=BitRm[15-i];
        BitRd[15-i]=BitRm[31-i];
    }
    bin2reg(Rd,&BitRd[0]);      // Convertir BitRd en decimal y guardarlo en Rd
    //no modifica banderas
}

void REVSH(uint32_t *Rd,uint32_t Rm)
{
    int i;
    uint32_t BitRd[32],BitRm[32];
    reg2bin(*Rd,&BitRd[0]);       //  Convertir Rd en binario y trabajar con el arreglo de unos y ceros Bit Rd
    reg2bin(Rm,&BitRm[0]);        //  Convertir Rm en binario y trabajar con el arreglo de unos y ceros Bit Rm

    for(i=0;i<8;i++)
    {
        BitRd[i]=BitRm[i+8];
    }
    for(i=8;i<32;i++)
	{
        BitRd[i]=BitRm[7];
    }
    bin2reg(Rd,&BitRd[0]);      // Convertir BitRd en decimal y guardarlo en Rd
    // no modifica banderas
}

void RORS(uint32_t *Rd,uint32_t Rm,flags_t *bandera)
{
    uint32_t aux1,aux2;
    aux1=*Rd>>Rm;          //  Bits que se desplazan a la derecha
    aux2=*Rd<<(32-Rm);     //  Bits que "entran" por la izquierda
    bandera->C=(*Rd>>(Rm-1))&1;     // el carry corresponde al último bit que sale por la derecha
    *Rd=aux1|aux2;     // "Junta" los dos auxiliares
    //   no modifica bandera de sobreflujo
    flags_global(*Rd,bandera);
}

void RSBS(uint32_t *Rd,uint32_t Rn,flags_t *bandera)
{
    *Rd=~Rn+1;
    flags_global(*Rd,bandera);
    flags_aritmetica(*Rd,Rn,Rn,bandera);
}

void SBCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    *Rd=Rn+~Rm+bandera->C;
    flags_global(*Rd,bandera);
    flags_aritmetica(*Rd,Rn,~Rm,bandera);
}

void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rn+~Rm+1;
}

void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
	*Rd=Rn+~Rm+1;
	flags_global(*Rd,bandera);
    flags_aritmetica(*Rd,Rn,~Rm+1,bandera);
}

void TST(uint32_t Rn,uint32_t Rm,flags_t *bandera)
{
    Rn&=Rm;     //AND bit a bit pero no guarda el resultado, solo modifica banderas
    //   no modifica bandera de sobreflujo, ni bandera de carry
    flags_global(Rn,bandera);
}
