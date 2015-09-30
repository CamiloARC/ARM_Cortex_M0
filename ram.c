#include "ram.h"

void push(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list)
{
    uint32_t direccion,bitcount=0;
    int i,j;
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
void pop(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list)
{
    uint32_t direccion,bitcount=0;
    direccion=registro[13];
    int i;
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
