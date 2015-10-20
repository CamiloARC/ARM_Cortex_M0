#include "nvic.h"

/** \file nvic.c
 *  \brief Documento en donde se encuentran las funciones dedicadas a administrar las interrupciones ademas de cargar y guardar registros.
*/

void NVIC(uint8_t *interrupcion,bool *FlagInt,uint32_t *registro,flags_t *bandera,uint8_t *SRAM)
{
    int i;
    if(*FlagInt==1)
    {
        if(registro[15]==0xFFFFFFFF)
        {
            POPP(registro,SRAM,bandera);
            *FlagInt=0;
        }
    }
    if(*FlagInt==0)
    {
        for(i=0;i<16;i++)
        {
            if(interrupcion[i]==1)
            {
                PUSHH(registro,SRAM,bandera);
                registro[15]=i+1;
                registro[14]=0xFFFFFFFF;
                *FlagInt=1;
                interrupcion[i]=0;
                break;
            }
        }
    }
}
void PUSHH(uint32_t *registro,uint8_t *SRAM,flags_t *bandera)
{
    int i,j;    // variables con uso de contador
    uint32_t direccion,bitcount=7;
    direccion=registro[13]-4*bitcount-1;
    for(j=0;j<16;j++)
    {
        if((j==0)||(j==1)||(j==2)||(j==3)||(j==12)||(j==14)||(j==15))
        {
            for(i=0;i<4;i++)
            {
                SRAM[direccion+i]=registro[j]>>(8*(3-i));
            }
            direccion+=4;
        }
    }
    SRAM[direccion]=((bandera->N)<<3)+((bandera->Z)<<2)+((bandera->C)<<1)+bandera->V;
    registro[13]=registro[13]-4*bitcount-1;
}
void POPP(uint32_t *registro,uint8_t *SRAM,flags_t *bandera)
{
    int i;
    uint32_t direccion,bitcount=7;
    direccion=registro[13];
    for(i=0;i<16;i++)
    {
        if((i==0)||(i==1)||(i==2)||(i==3)||(i==12)||(i==14)||(i==15))
        {
            registro[i]=(uint32_t)(SRAM[direccion]<<24)+(uint32_t)(SRAM[direccion+1]<<16)+(uint32_t)(SRAM[direccion+2]<<8)+SRAM[direccion+3];
            direccion=direccion+4;
        }
    }
    bandera->V=(1&SRAM[direccion]);
    bandera->C=(2&SRAM[direccion])>>1;
    bandera->Z=(4&SRAM[direccion])>>2;
    bandera->N=(8&SRAM[direccion])>>3;
    registro[13]=registro[13]+4*bitcount+1;
}
