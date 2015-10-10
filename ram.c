#include "ram.h"

/** \file ram.c
 *  \brief Documento en el cual se desarrollan las funciones relacionadas con el manejo de RAM
*/

void PUSH(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list)
{
    uint32_t direccion,bitcount=0;  //direccion es la cantidad de bytes de la RAM que se van a utilizar
                                    // bitcount es una variable auxiliar para reservar memoria enla RAM
    int i,j;                        //variables con uso de contador
    for(i=0;i<8;i++)
    {
        if(registers_list[i]==1)
            bitcount++;
    }
    if(registers_list[14]==1)
        bitcount++;
    direccion=registro[13]-4*bitcount;
    for(j=0;j<16;j++)
    {
        if(registers_list[j]==1)
        {
            for(i=0;i<4;i++)
            {
                SRAM[direccion+i]=registro[j]>>(8*(3-i));
            }
            direccion=direccion+4;
        }
    }
    registro[13]=registro[13]-4*bitcount;
}
void POP(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list)
{
    uint32_t direccion,bitcount=0;   //direccion es la cantidad de bytes de la RAM que se van a utilizar
                                     // bitcount es una variable auxiliar para reservar memoria enla RAM
    direccion=registro[13];          // direccion igual a SP
    int i;                           //  variable i utilizada como contador
    for(i=0;i<8;i++)
    {
        if(registers_list[i]==1)
            bitcount++;
    }
    if(registers_list[14]==1)
        bitcount++;

    for(i=0;i<16;i++)
    {
        if(registers_list[i]==1)
        {
            registro[i]=(uint32_t)(SRAM[direccion]<<24)+(uint32_t)(SRAM[direccion+1]<<16)+(uint32_t)(SRAM[direccion+2]<<8)+SRAM[direccion+3];
            direccion=direccion+4;
        }
    }
    registro[13]=registro[13]+4*bitcount;
}
void LDR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t direccion=Rn+Rm;
    *Rt=(uint32_t)(SRAM[direccion]<<24)+(uint32_t)(SRAM[direccion+1]<<16)+(uint32_t)(SRAM[direccion+2]<<8)+SRAM[direccion+3];
    //Rt recibe el valor de los 4 bytes superiores en memoria
}
void LDRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t direccion=Rn+Rm;
    *Rt=(uint32_t)SRAM[direccion];
}
void LDRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t direccion=Rn+Rm;
    *Rt=(uint32_t)(SRAM[direccion]<<8)+(uint32_t)SRAM[direccion+1];
}
void LDRSB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t direccion=Rn+Rm;
    *Rt=(uint32_t)SRAM[direccion];
    if(*Rt>=128)
    {
        *Rt+=0xFFFFFF00;
    }
}
void LDRSH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t direccion=Rn+Rm;
    *Rt=(uint32_t)(SRAM[direccion]<<8)+(uint32_t)SRAM[direccion+1];
    if(*Rt>=32768)
    {
        *Rt+=0xFFFF0000;
    }
}
void STR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{

}
void STRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{

}
void STRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{

}
