#ifndef _DECODER_H_
#define	_DECODER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "io.h"
#include "instrucciones.h"
#include "instrucciones_saltos.h"
#include "ram.h"

/** \file decoder.h
 *  \brief Documento en donde esta definida la estructura ins_t y la estructura instruction_t y ademas se definen las instrucciones de manejo del code.txt
*/
/** \struct ins_t;
 *  \brief  Estructura que contiene las instrucciones del code.txt
 */

typedef struct
{
	char** array;   /*!< Arreglo que utiliza memoria dinamica para obtener las lineas de codigo del code.txt*/
}ins_t;

/** \struct instruction_t;
 *  \brief  Estructura que contiene las instrucciones en segmentos del code.txt
 */

typedef struct
{
	char mnemonic[10];  /*!< Contiene el nombre de la instruccion*/
	char op1_type;      /*!< Contiene el tipo del primer parametro*/
	char op2_type;      /*!< Contiene el tipo del segundo parametro*/
	char op3_type;      /*!< Contiene el tipo del terce parametro*/
	uint32_t op1_value; /*!< Contiene el numero del registro a operar del primer parametro*/
    uint32_t op2_value; /*!< Contiene el numero del registro a operar del segundo parametro o un numero*/
	uint32_t op3_value; /*!< Contiene el numero del registro a operar del tercer parametro o un numero*/
    uint8_t registers_list[16];
}instruction_t;

/** \fn void decodeInstruction(instruction_t instruction,uint32_t *registro,flags_t *bandera);
    \brief Decodifica la instrucción y la ejecuta.
    \param instruction instrucción a decodificar y ejecutar.
*/
void decodeInstruction(instruction_t instruction,uint32_t *registro,flags_t *bandera, uint8_t *RAM, uint16_t *codificacion, char **Flash);

/** \fn instruction_t getInstruction(char* instStr)
    \brief Obtiene la instrucción separada por partes.
    \param instrStr cadena que contiene la instrucción.
	\return instruction_t la instrucción separada por partes.
*/
instruction_t getInstruction(char* instStr);

/** \fn int readFile(char** instructions)
    \brief Lee instrucciones de un archivo.
    \param filename Nombre del archivo.
    \param instructions estructura con arreglo con las instrucciones leidas.
	\return Entero indicando la cantidad de líneas.
*/
int readFile(char* filename, ins_t* instructions);

/** \fn int countLines(FILE fp)
    \brief Cuenta la cantidad de líneas de un archivo.
    \param fp Puntero al archivo.
	\return Entero con la cantidad de líneas del archivo.
*/
int countLines(FILE* fp);

#endif /*_DECODER_H_*/
