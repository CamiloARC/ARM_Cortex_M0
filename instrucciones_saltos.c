#include <stdint.h>
#include "instrucciones_saltos.h"

/** \file instrucciones_saltos.c
 *  \brief Documento utilizado para definir PC y RL en cada instruccion a traves de los saltos y ademas utilizar las banderas para identificar si se realiza o no un salto
*/

void B(uint32_t *registro,int salto)
{
    registro[14]+=salto;    // PC=PC+salto
}
void BL(uint32_t *registro,int salto)   // Siempre recibe un numero
{
    registro[13]=registro[14]+2;    //  LR=PC+2
    registro[14]+=salto;            //  PC=PC+salto
}
void BLX(uint32_t *registro,uint32_t R) // Siempre recibe un registro
{
    registro[13]=registro[14]+2;    //  LR=PC+2
    registro[14]+=(int32_t)R;       //  PC=PC+R
}
void BX(uint32_t *registro,uint32_t R)  // Siempre recibe un registro
{
    registro[14]=R;
}
void BEQ(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.Z==1)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BNE(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.Z==0)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BCS(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.C==1)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BCC(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.C==0)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BMI(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.N==1)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BPL(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.N==0)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BVS(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.V==1)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BVC(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.V==0)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BHI(uint32_t *registro,int salto,flags_t bandera)
{
    if((bandera.C==1)&&(bandera.Z==0))
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BLS(uint32_t *registro,int salto,flags_t bandera)
{
    if((bandera.C==0)||(bandera.Z==1))
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BGE(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.N==bandera.V)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BLT(uint32_t *registro,int salto,flags_t bandera)
{
    if(bandera.N!=bandera.V)
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BGT(uint32_t *registro,int salto,flags_t bandera)
{
    if((bandera.Z==0)&&(bandera.N==bandera.V))
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BLE(uint32_t *registro,int salto,flags_t bandera)
{
    if((bandera.Z==0)||(bandera.N!=bandera.V))
    {
        registro[14]+=salto;
    }
    else
    {
        registro[14]++;
    }
}
void BAL(uint32_t *registro,int salto,flags_t bandera)
{
    registro[14]+=salto;
}
