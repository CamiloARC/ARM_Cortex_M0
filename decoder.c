#include <stdint.h>
#include "decoder.h"

/** \file decoder.c
 *  \brief Documento en el cual se realiza el proceso de extraer las instrucciones del code.txt, segmentarlas y comparar el mnemonic con el nombre de cada instruccion, asi realizar la instruccion deseada
*/

void decodeInstruction(instruction_t instruction,uint32_t *registro,flags_t *bandera, uint8_t *SRAM, uint16_t *codificacion, char **Flash)
{
    int i;
    *codificacion=0;    // valor incial
	//	comparar el mnemonic con el nombre de cada una de las funciones, y asi ejecutar la adecuada
	if( strcmp(instruction.mnemonic,"LDR") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            *codificacion=(13<<11)+((instruction.op3_value&0xFF)<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            instruction.op3_value<<=2;
            if(((*(registro+instruction.op2_value)+instruction.op3_value)>=0x20000000)&&((*(registro+instruction.op2_value)+instruction.op3_value)<0x40000000))
            {
                LDR(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,instruction.op3_value&0xFF,SRAM);
            }
            if((*(registro+instruction.op2_value)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registro+instruction.op2_value)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='S') && (instruction.op3_type=='#'))
        {
            *codificacion=(19<<11)+(instruction.op1_value<<8)+(instruction.op3_value&0xFF);
            instruction.op3_value<<=2;
            if(((*(registro+13)+instruction.op3_value)>=0x20000000)&&((*(registro+13)+instruction.op3_value)<0x40000000))
            {
                LDR(registro+instruction.op1_value,(*(registro+13))&0xFF,instruction.op3_value&0xFF,SRAM);
            }
            if((*(registro+13)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registro+13)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='P') && (instruction.op3_type=='#')) // label
        {
            *codificacion=(9<<11)+(instruction.op1_value<<8)+(instruction.op3_value&0xFF);
            instruction.op3_value<<=2;
            if(((*(registro+15)+instruction.op3_value)>=0x20000000)&&((*(registro+15)+instruction.op3_value)<0x40000000))
            {
                LDR(registro+instruction.op1_value,(*(registro+15))&0xFF,instruction.op3_value&0xFF,SRAM);
            }
            if((*(registro+15)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registro+15)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
            *codificacion=(11<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x20000000)&&(*(registro+instruction.op2_value)+*(registro+instruction.op3_value)<0x40000000))
            {
                LDR(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,(*(registro+instruction.op3_value))&0xFF,SRAM);
            }
            if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))<0x20000000)
            {

            }
            if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x40000000)
            {

            }
        }
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"LDRB") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            *codificacion=(15<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registro+instruction.op2_value)+instruction.op3_value)>=0x20000000)&&((*(registro+instruction.op2_value)+instruction.op3_value)<0x40000000))
            {
                LDRB(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,instruction.op3_value&0xFF,SRAM);
            }
            if((*(registro+instruction.op2_value)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registro+instruction.op2_value)+instruction.op3_value)>=0x40000000)
            {

            }

        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
            *codificacion=(1<<14)+(7<<10)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x20000000)&&(*(registro+instruction.op2_value)+*(registro+instruction.op3_value)<0x40000000))
            {
                LDRB(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,(*(registro+instruction.op3_value))&0xFF,SRAM);
            }
            if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))<0x20000000)
            {

            }
            if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x40000000)
            {

            }
        }
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"LDRH") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            *codificacion=(1<<15)+(1<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            instruction.op3_value<<=1;
            if(((*(registro+instruction.op2_value)+instruction.op3_value)>=0x20000000)&&((*(registro+instruction.op2_value)+instruction.op3_value)<0x40000000))
            {
                LDRH(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,instruction.op3_value&0xFF,SRAM);
            }
            if((*(registro+instruction.op2_value)+instruction.op3_value)<0x20000000)
            {

            }
            if((*(registro+instruction.op2_value)+instruction.op3_value)>=0x40000000)
            {

            }
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
            *codificacion=(5<<12)+(5<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            if(((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x20000000)&&(*(registro+instruction.op2_value)+*(registro+instruction.op3_value)<0x40000000))
            {
                LDRH(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,(*(registro+instruction.op3_value))&0xFF,SRAM);
            }
            }
            if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))<0x20000000)
            {

            }
            if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x40000000)
            {

            }
            registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"LDRSB") ==0)
    {
        *codificacion=(5<<12)+(3<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        if(((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x20000000)&&(*(registro+instruction.op2_value)+*(registro+instruction.op3_value)<0x40000000))
        {
            LDRSB(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,(*(registro+instruction.op3_value))&0xFF,SRAM);
        }
        if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))<0x20000000)
        {

        }
        if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x40000000)
        {

        }
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"LDRSH") ==0)
    {
        *codificacion=(5<<12)+(7<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        if(((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x20000000)&&(*(registro+instruction.op2_value)+*(registro+instruction.op3_value)<0x40000000))
        {
            LDRSH(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,(*(registro+instruction.op3_value))&0xFF,SRAM);
        }
        if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))<0x20000000)
        {

        }
        if((*(registro+instruction.op2_value)+*(registro+instruction.op3_value))>=0x40000000)
        {

        }
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"STR") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            STR(registro+instruction.op1_value,(*(registro+instruction.op2_value))&0xFF,(*(registro+instruction.op3_value))&0xFF,SRAM);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='S') && (instruction.op3_type=='#'))
        {
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
        }
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"STRB") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {

        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {

        }
    }
    if( strcmp(instruction.mnemonic,"STRH") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {

        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {

        }
    }

    if( strcmp(instruction.mnemonic,"PUSH") ==0)
    {
        for(i=0;i<8;i++)
        {
            *codificacion+=(instruction.registers_list[i]<<i);
        }
        *codificacion+=(11<<12)+(1<<10)+(instruction.registers_list[14]<<8);
        PUSH(registro,SRAM,&instruction.registers_list[0]);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"POP") ==0)
    {
        for(i=0;i<8;i++)
        {
            *codificacion+=(instruction.registers_list[i]<<i);
        }
        *codificacion=(11<<12)+(3<<10)+(instruction.registers_list[15]<<8);
        POP(registro,SRAM,&instruction.registers_list[0]);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"ADCS") ==0)
    {
        *codificacion=(1<<14)+(5<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        ADCS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
        registro[15]++;
	}
	if( strcmp(instruction.mnemonic,"ADD") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
        {
            ADDS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
            *codificacion=(1<<14)+(1<<10)+(instruction.op2_value<<3)+((8&instruction.op1_value)<<4)+(7&instruction.op1_value);
        }
         if((instruction.op1_type=='R') && (instruction.op2_type=='S') && (instruction.op3_type=='#'))
        {
            ADDS(registro+instruction.op1_value,*(registro+13),instruction.op2_value, bandera);
            *codificacion=(21<<11)+(instruction.op1_value<<8)+instruction.op3_value;
        }
        if((instruction.op1_type=='S') && (instruction.op2_type=='S') && (instruction.op3_type=='#'))
        {
            ADDS(registro+13,*(registro+13),instruction.op3_value, bandera);
            *codificacion=(11<<12)+instruction.op3_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='S') && (instruction.op3_type=='R'))
        {
            ADDS(registro+instruction.op1_value,*(registro+13),*(registro+instruction.op3_value),bandera);
            *codificacion=(1<<14)+(1<<10)+(13<<3)+((8&instruction.op1_value)<<4)+(7&instruction.op1_value);
        }
        if((instruction.op1_type=='S') && (instruction.op2_type=='R'))
        {
            ADDS(registro+13,*(registro+13),*(registro+instruction.op2_value), bandera);
            *codificacion=(1<<14)+(9<<7)+5+(instruction.op2_value<<3);
        }
        registro[15]++;
    }
	if( strcmp(instruction.mnemonic,"ADDS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            ADDS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
            *codificacion=(7<<10)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
        {
            ADDS(registro+instruction.op1_value,*(registro+instruction.op1_value),instruction.op2_value,bandera);
            *codificacion=(3<<12)+(instruction.op1_value<<8)+instruction.op2_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
        {
            ADDS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
            *codificacion=(3<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        registro[15]++;
	}
	// los parametros de las demas funciones aritmeticas, de desplazamiento y logicas son similares
    if( strcmp(instruction.mnemonic,"ANDS") ==0)
    {
        *codificacion=(1<<14)+(instruction.op2_value<<3)+instruction.op1_value;
        ANDS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"ASRS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
			ASRS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
			*codificacion=(1<<14)+(1<<8)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			ASRS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
            *codificacion=(1<<12)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"BICS") ==0)
    {
        *codificacion=(1<<14)+(14<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        BICS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"CMN") ==0)
    {
        *codificacion=(1<<14)+(11<6)+(instruction.op2_value<<3)+instruction.op1_value;
        CMN(*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera); //	En diferencia a las demas funciones, se envian como parametros 2 valores
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"CMP") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
		    if(instruction.op1_value>=8)
		    {
                CMP(*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);	//	En diferencia a las demas funciones, se envian como parametros 2 valores
                *codificacion=(1<<14)+(5<<8)+(instruction.op2_value<<3)+(7&instruction.op1_value)+((8&instruction.op1_value)<<4);
		    }
		    else
		    {
                CMP(*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);	//	En diferencia a las demas funciones, se envian como parametros 2 valores
                *codificacion=(1<<14)+(10<<6)+(instruction.op2_value<<3)+instruction.op1_value;
		    }
		}
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			CMP(*(registro+instruction.op1_value),instruction.op2_value, bandera);	// Como parametros se tienen el contenido de un registro y un valor
            *codificacion=(5<<11)+(instruction.op1_value<<8)+instruction.op2_value;
        }
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"EORS") ==0)
    {
        *codificacion=(1<<14)+(1<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        EORS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value),bandera);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"LSLS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
			LSLS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
			*codificacion=(1<<14)+(1<<7)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			LSLS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
            *codificacion=(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        registro[15]++;
	}
    if( strcmp(instruction.mnemonic,"LSRS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
	        LSRS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
	        *codificacion=(1<<14)+(3<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			LSRS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
			*codificacion=(1<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        registro[15]++;
	}
    if( strcmp(instruction.mnemonic,"MOV") ==0)
    {
        *codificacion=(1<<14)+(3<<9)+(instruction.op2_value<<3)+(7&instruction.op1_value)+((8&instruction.op1_value)<<4);
        MOV(registro+instruction.op1_value,*(registro+instruction.op2_value));	//	Envio como parametros una direccion y el contenido de un registro
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"MOVS") ==0)
    {
		if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			MOVS(registro+instruction.op1_value,instruction.op2_value, bandera);
			*codificacion=(1<<13)+(instruction.op1_value<<8)+instruction.op2_value;
		}
		if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
        {
            MOVS(registro+instruction.op1_value,*(registro+instruction.op2_value),bandera);
            *codificacion=(instruction.op2_value<<3)+instruction.op1_value;
        }
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"MULS") ==0)
    {
        *codificacion=(1<<14)+(13<<6)+(instruction.op2_value<<3)+instruction.op3_value;
        MULS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        registro[15]++;
	}
	if( strcmp(instruction.mnemonic,"MVNS") ==0)
    {
        *codificacion=(1<<14)+(15<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        RSBS(registro+instruction.op1_value,*(registro+instruction.op2_value), bandera);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"NOP") ==0)
    {
        *codificacion=(11<<12)+(15<<8);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"ORRS") ==0)
    {
        *codificacion=(1<<14)+(3<<8)+(instruction.op2_value<<3)+instruction.op1_value;
        ORRS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"REV") ==0)
    {
        *codificacion=(11<<12)+(5<<9)+(instruction.op2_value<<3)+instruction.op1_value;
        REV(registro+instruction.op1_value, *(registro+instruction.op2_value));
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"REV16") ==0)
    {
        *codificacion=(11<<12)+(5<<9)+(1<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        REV16(registro+instruction.op1_value,*(registro+instruction.op2_value));
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"REVSH") ==0)
    {
        *codificacion=(11<<12)+(5<<9)+(3<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        REVSH(registro+instruction.op1_value,*(registro+instruction.op2_value));
        registro[15]++;
    }
	if( strcmp(instruction.mnemonic,"RORS") ==0)
    {
        *codificacion=(1<<14)+(7<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        RORS(registro+instruction.op1_value,*(registro+instruction.op2_value), bandera);
        registro[15]++;
	}
    if( strcmp(instruction.mnemonic,"RSBS") ==0)
    {
        *codificacion=(1<<14)+(9<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        RSBS(registro+instruction.op1_value,*(registro+instruction.op2_value), bandera);
        registro[15]++;
    }
    if( strcmp(instruction.mnemonic,"SBCS") ==0)
    {
        *codificacion=(1<<14)+(3<<7)+(instruction.op2_value<<3)+instruction.op1_value;
        SBCS(registro+instruction.op1_value,*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);
        registro[15]++;
	}
	if( strcmp(instruction.mnemonic,"SUB") ==0)
    {
        if((instruction.op1_type=='S') && (instruction.op2_type=='S') && (instruction.op3_type=='#'))
        {
            SUBS(registro+13,*(registro+13),instruction.op3_value, bandera);
            *codificacion=(11<<12)+(1<<7)+instruction.op3_value;
        }
        registro[15]++;
    }
	if( strcmp(instruction.mnemonic,"SUBS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			SUBS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
			*codificacion=(15<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
        {
            SUBS(registro+instruction.op1_value,*(registro+instruction.op1_value),instruction.op2_value,bandera);
            *codificacion=(7<<11)+(instruction.op1_value<<8)+instruction.op2_value;
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			SUBS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
			*codificacion=(13<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        }
        registro[15]++;
	}
    if( strcmp(instruction.mnemonic,"TST") ==0)
    {
        *codificacion=(1<<14)+(1<<9)+(instruction.op2_value<<3)+instruction.op1_value;
        TST(*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);	// Como parametros se tienen el contenido de un registro y un valor
        registro[15]++;
    }
	// Las siguientes funciones, son funciones de saltos
    if( strcmp(instruction.mnemonic,"B") ==0)
    {
        *codificacion=(7<<13)+instruction.op1_value;
        B(registro,instruction.op1_value);	// Envio como parametroa la direccion de registro y el valor del salto
    }
    if( strcmp(instruction.mnemonic,"BL") ==0)
    {
        *codificacion=(31<<11)+(2047&instruction.op1_value);
        BL(registro,instruction.op1_value);	// Envio como parametroa la direccion de registro y el valor del salto
    }
    if( strcmp(instruction.mnemonic,"BLX") ==0)
    {
        *codificacion=(1<<14)+(15<<7)+(instruction.op1_value<<3);
        BLX(registro,*(registro+instruction.op1_value));	// Envio como parametroa la direccion de registro y el contenido de un registro
    }
    if( strcmp(instruction.mnemonic,"BX") ==0)
    {
        *codificacion=(1<<14)+(14<<7)+(instruction.op1_value<<3);
        if(instruction.op1_type=='L')	//	Sucede cuando
        {
            BX(registro,registro[14]);  //  PC=LR
        }
        if(instruction.op1_type=='R')	// Sucede cuando se tiene como parametro un registro diferente a LR
        {
            BX(registro,*(registro+instruction.op1_value));
        }
    }
    if( strcmp(instruction.mnemonic,"BEQ") ==0)
    {
        *codificacion=(13<<12)+instruction.op1_value;
        BEQ(registro,instruction.op1_value,*bandera);	// Envio como parametros la direccion de registro, el valor del salto y las banderas
    }
	// Todas las siguientes funciones de salto tienen los mismos parametro que BEQ
    if( strcmp(instruction.mnemonic,"BNE") ==0)
    {
        *codificacion=(13<<12)+(1<<8)+instruction.op1_value;
        BNE(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BCS") ==0)
    {
        *codificacion=(13<<12)+(2<<8)+instruction.op1_value;
        BCS(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BCC") ==0)
    {
        *codificacion=(13<<12)+(3<<8)+instruction.op1_value;
        BCC(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BMI") ==0)
    {
        *codificacion=(13<<12)+(4<<8)+instruction.op1_value;
        BMI(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BPL") ==0)
    {
        *codificacion=(13<<12)+(5<<8)+instruction.op1_value;
        BPL(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BVS") ==0)
    {
        *codificacion=(13<<12)+(6<<8)+instruction.op1_value;
        BVS(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BVC") ==0)
    {
        *codificacion=(13<<12)+(7<<8)+instruction.op1_value;
        BVC(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BHI") ==0)
    {
        *codificacion=(13<<12)+(8<<8)+instruction.op1_value;
        BHI(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BLS") ==0)
    {
        *codificacion=(13<<12)+(9<<8)+instruction.op1_value;
        BLS(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BGE") ==0)
    {
        *codificacion=(13<<12)+(10<<8)+instruction.op1_value;
        BGE(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BLT") ==0)
    {
        *codificacion=(13<<12)+(11<<8)+instruction.op1_value;
        BLT(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BGT") ==0)
    {
        *codificacion=(13<<12)+(12<<8)+instruction.op1_value;
        BGT(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BLE") ==0)
    {
        *codificacion=(13<<12)+(13<<8)+instruction.op1_value;
        BLE(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BAL") ==0)
    {
        *codificacion=(13<<12)+(14<<8)+instruction.op1_value;
        BAL(registro,instruction.op1_value,*bandera);
    }
}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:
			    if(split[0] == '[')
					split++;

				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}
	free(split);
	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}
	fclose(fp);	/* Cierra el archivo */
	return lines;
}

int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}

