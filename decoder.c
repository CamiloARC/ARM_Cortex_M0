#include <stdint.h>
#include "decoder.h"

/** \file decoder.c
 *  \brief Documento en el cual se realiza el proceso de extraer las instrucciones del code.txt, segmentarlas y comparar el mnemonic con el nombre de cada instruccion, asi realizar la instruccion deseada
*/

void decodeInstruction(instruction_t instruction,uint32_t *registro,flags_t *bandera)
{
	//	comparar el mnemonic con el nombre de cada una de las funciones, y asi ejecutar la adecuada

	if( strcmp(instruction.mnemonic,"ADDS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))	//	si se tienen como parametros 2 registros
        {
            ADDS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera); // envio como parametros la direccion de registro[instruction.op1_value], el valor de registro[registro+instruction.op2_value] y de registro[registro+instruction.op3_value]
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))	// si se tienen como parametros un registro[instruction.op1_value], el valor de registro[registro+instruction.op2_value] y instruction.op3_value
        {
            ADDS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera); // envio como parametros la direccion de
        }
        registro[14]++;
	}
	// los parametros de las demas funciones aritmeticas, de desplazamiento y logicas son similares
    if( strcmp(instruction.mnemonic,"ANDS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			ANDS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			ANDS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"EORS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			EORS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value),bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			EORS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"MOV") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))	//	En la instruccion se tienen operando 2 registros
		{
            MOV(registro+instruction.op1_value,*(registro+instruction.op2_value));	//	Envio como parametros una direccion y el contenido de un registro
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))	//	En la instruccion se tienen operando un registro y un numero
		{
			MOV(registro+instruction.op1_value,instruction.op2_value);	// Envio como parametro una direccion y un valor
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"MOVS") ==0)
    {
		if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
			MOVS(registro+instruction.op1_value,*(registro+instruction.op2_value),bandera);
		}
		if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			MOVS(registro+instruction.op1_value,instruction.op2_value, bandera);
		}
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"ORRS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			ORRS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			ORRS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"SUBS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			SUBS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			SUBS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
	}
    if( strcmp(instruction.mnemonic,"RSBS") ==0)
    {
		if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
            RSBS(registro+instruction.op1_value,*(registro+instruction.op2_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			RSBS(registro+instruction.op1_value,instruction.op2_value,bandera);
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"MVNS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
            RSBS(registro+instruction.op1_value,*(registro+instruction.op2_value), bandera);
		}
		if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			RSBS(registro+instruction.op1_value,instruction.op2_value,bandera);
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"BICS") ==0)
    {
		if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			BICS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			BICS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"ASRS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			ASRS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			ASRS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"RORS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
			RORS(registro+instruction.op1_value,*(registro+instruction.op2_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			RORS(registro+instruction.op1_value,instruction.op2_value,bandera);
        }
        registro[14]++;
	}
    if( strcmp(instruction.mnemonic,"LSRS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
	        LSRS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			LSRS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
	}
    if( strcmp(instruction.mnemonic,"LSLS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			LSLS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			LSLS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
	}
	if( strcmp(instruction.mnemonic,"MUL") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			MUL(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			MUL(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
	}
    if( strcmp(instruction.mnemonic,"CMN") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
			CMN(*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera); //	En diferencia a las demas funciones, se envian como parametros 2 valores
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			CMN(*(registro+instruction.op1_value),instruction.op2_value, bandera);	// Como parametros se tienen el contenido de un registro y un valor
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"CMP") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
			CMP(*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);	//	En diferencia a las demas funciones, se envian como parametros 2 valores
		}
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			CMP(*(registro+instruction.op1_value),instruction.op2_value, bandera);	// Como parametros se tienen el contenido de un registro y un valor
        }
        registro[14]++;
    }
    if( strcmp(instruction.mnemonic,"ADCS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			ADCS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
		}
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			ADCS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
	}
    if( strcmp(instruction.mnemonic,"SBCS") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='R'))
		{
			SBCS(registro+instruction.op1_value,*(registro+instruction.op2_value),*(registro+instruction.op3_value), bandera);
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='R') && (instruction.op3_type=='#'))
		{
			SBCS(registro+instruction.op1_value,*(registro+instruction.op2_value),instruction.op3_value,bandera);
        }
        registro[14]++;
	}
    if( strcmp(instruction.mnemonic,"TST") ==0)
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
			TST(*(registro+instruction.op1_value),*(registro+instruction.op2_value), bandera);	// Como parametros se tienen el contenido de un registro y un valor
        }
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
			TST(*(registro+instruction.op1_value),instruction.op2_value, bandera);	// Como parametros se tienen el contenido de un registro y un valor
        }
        registro[14]++;
    }
	// Las siguientes funciones, son funciones de saltos
    if( strcmp(instruction.mnemonic,"B") ==0)
    {
        B(registro,instruction.op1_value);	// Envio como parametroa la direccion de registro y el valor del salto
    }
    if( strcmp(instruction.mnemonic,"BL") ==0)
    {
        BL(registro,instruction.op1_value);	// Envio como parametroa la direccion de registro y el valor del salto
    }
    if( strcmp(instruction.mnemonic,"BLX") ==0)
    {
        BLX(registro,*(registro+instruction.op1_value));	// Envio como parametroa la direccion de registro y el contenido de un registro
    }
    if( strcmp(instruction.mnemonic,"BX") ==0)
    {
        if(instruction.op1_type=='L')	//	Sucede cuando
        {
            BX(registro,registro[13]);  //  PC=LR
        }
        if(instruction.op1_type=='R')	// Sucede cuando se tiene como parametro un registro diferente a LR
        {
            BX(registro,*(registro+instruction.op1_value));
        }
    }
    if( strcmp(instruction.mnemonic,"BEQ") ==0)
    {
        BEQ(registro,instruction.op1_value,*bandera);	// Envio como parametros la direccion de registro, el valor del salto y las banderas
    }
	// Todas las siguientes funciones de salto tienen los mismos parametro que BEQ
    if( strcmp(instruction.mnemonic,"BNE") ==0)
    {
        BNE(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BCS") ==0)
    {
        BCS(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BCC") ==0)
    {
        BCC(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BMI") ==0)
    {
        BMI(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BPL") ==0)
    {
        BPL(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BVS") ==0)
    {
        BVS(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BVC") ==0)
    {
        BVC(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BHI") ==0)
    {
        BHI(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BLS") ==0)
    {
        BLS(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BGE") ==0)
    {
        BGE(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BLT") ==0)
    {
        BLT(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BGT") ==0)
    {
        BGT(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BLE") ==0)
    {
        BLE(registro,instruction.op1_value,*bandera);
    }
    if( strcmp(instruction.mnemonic,"BAL") ==0)
    {
        BAL(registro,instruction.op1_value,*bandera);
    }
}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
	char* split = (char*)malloc( strlen(instStr)+1);
	int num=0;

	strcpy( split, instStr);
	// Obtiene el mnemonico de la instrucción
	split = strtok( split, " ,");
	strcpy(instruction.mnemonic, split);

	// Separa los operandos
	while ( split != NULL)
	{
		switch(num){
			case 1:
				instruction.op1_type  = split[0];
				instruction.op1_value = (uint32_t)strtoll( split+1, NULL, 0);
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll( split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll( split+1, NULL, 0);
				break;
		}
		split = strtok(NULL, " ,.");
		num++;
	}
	if(num==3){
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
	}
	free( split);
	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	// Puntero a un archivo
	int lines;	// Cantidad de líneas del archivo
	int line=0;	// Línea leida
	char buffer[50]; // Almacena la cadena leida

	fp = fopen(filename, "r");	// Abrir el archivo como solo lectura
	if( fp==NULL )
		return -1;	// Error al abrir el archivo

	lines = countLines(fp);	// Cantidad de líneas
	// Asignación dinámica de memoria para cada instrucción
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc(( strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}
	fclose(fp);	// Cierra el archivo
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

