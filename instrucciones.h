#ifndef INSTRUCCIONES_H_
#define INSTRUCCIONES_H_

#include <stdint.h>
/** \file instrucciones.h
 *  \brief Documento en donde esta definida la estructura flags y las funciones
*/
/** \struct flags;
 *  \brief  Estructura que contiene las banderas
 */

typedef struct flags // estrutura flags_t
{
	char N;  /*!< bandera de un resultado negativo, si este es negativo entonces N=1 */
	char Z;  /*!<  bandera de un resultado igual a 0, si este es cero entonces Z=1; */
	char C;  /*!< bandera de carry, si hay un carry en una operacion entonces C=1; */
	char V;  /*!< bandera de sobreflujo, si en una operación los bits mas signiticativos de los operandos son iguales y el bit mas significativo del resultado es el complemento de los bits de los operandos, se tiene un sobreflujo y V=1 */

}flags_t;

/**
* \brief funcion que realiza la suma entre Rn y Rm y lo guarda en *Rd
* \param Rd puntero del registro Rd
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void ADCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

void ADD(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza la suma entre Rn y Rm y lo guarda en *Rd
* \param Rd puntero del registro Rd
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void ADDS( uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza operacion AND entre *Rd y Rm
* \param Rd puntero del registro Rd
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void ANDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que realiza desplazamiento aritmetico del registro Rd, Rm veces
 * \param Rd puntero del registro Rd
 * \param Rm numero
 * \param bandera puntero a la estructura bandera de entrada
 * \return La funcion no tiene retorno
 */
void ASRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que realiza la operacion AND entre Rd y el complemento de un numero o un registro Rm
 * \param Rd puntero del registro Rd
 * \param Rm registro n o un numero
 * \param bandera puntero a la estructura bandera de entrada
 * \return La funcion no tiene retorno
 */
void BICS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza la suma entre Rn y Rm, pero no modifica Rn
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void CMN(uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza la resta entre Rn y Rm, pero no modifica Rn
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void CMP(uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza operación XOR entre *Rd y Rm
* \param Rd puntero del registro Rd
* \param Rm registro m o numero
* \param bandera puntero a la estrutura bandera de entrada
* \return La funcion no tiene retorno
*/
void EORS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que realiza desplazamiento lógico del registro Rd a la izquierda, Rm veces
 * \param Rd puntero del registro Rd
 * \param Rm numero
 * \param bandera puntero a la estructura bandera de entrada
 * \return La funcion no tiene retorno
 */
void LSLS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que realiza desplazamiento lógico del registro Rd a la derecha, Rm veces
 * \param Rd puntero del registro Rd
 * \param Rm numero
 * \param bandera puntero a la estructura bandera de entrada
 * \return La funcion no tiene retorno
 */
void LSRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza una copia de Rm en *Rd
* \param Rd puntero del registro Rd
* \param Rm registro m o numero
* \return La funcion no tiene retorno
*/
void MOV(uint32_t *Rd,uint32_t Rm);

/**
* \brief funcion que realiza una copia de Rm en *Rd
* \param Rd puntero del registro Rd
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void MOVS(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza la multiplicacion entre Rn y Rm y lo guarda en *Rd
* \param Rd puntero del registro Rd
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void MULS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que guarda el complemento de un numero o registro Rm y lo guarda en Rd
 * \param Rd puntero del registro Rd
 * \param Rm registro n o un numero
 * \param bandera puntero a la estructura bandera de entrada
 * \return La funcion no tiene retorno
 */
void MVNS(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que no realiza nada en un ciclo de reloj
 * \return La funcion no tiene retorno
 */
void NOP();

/**
* \brief funcion que realiza operación OR entre *Rd y Rm
* \param Rd puntero del registro Rd
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void ORRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que cambia el orden de los bytes
 * \param Rd puntero del registro Rd
 * \param Rm registro m o un numero
 * \return La funcion no tiene retorno
 */
void REV(uint32_t *Rd,uint32_t Rm);

/**
 * \brief funcion que cambia el orden de los Bytes en cada halfword de 16 bits
 * \param Rd puntero del registro Rd
 * \param Rm registro m o un numero
 * \return La funcion no tiene retorno
 */
void REV16(uint32_t *Rd,uint32_t Rm);

/**
 * \brief funcion que realiza extension de signo y cambia el orden de los Bytes del halfword bajo
 * \param Rd puntero del registro Rd
 * \param Rm registro m o un numero
 * \return La funcion no tiene retorno
 */
void REVSH(uint32_t *Rd,uint32_t Rm);

/**
 * \brief funcion que realiza rotacion a la derecha del registro Rd, Rm veces
 * \param Rd puntero del registro Rd
 * \param Rm numero
 * \param bandera puntero a la estructura bandera de entrada
 * \return La funcion no tiene retorno
 */
void RORS(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
 * \brief funcion que obtiene el complemento a dos de un numero o registro Rn y lo guarda en Rd
 * \param Rd puntero del registro Rd
 * \param Rn registro n o un numero
 * \param bandera puntero a la estructura bandera de entrada
 * \return La funcion no tiene retorno
 */
void RSBS(uint32_t *Rd,uint32_t Rn,flags_t *bandera);

/**
* \brief funcion que realiza la resta entre Rn y Rm y lo guarda en *Rd
* \param Rd puntero del registro Rd
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void SBCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza la resta entre Rn y Rm y lo guarda en *Rd
* \param Rd puntero del registro Rd
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief funcion que realiza operacion AND bit a bit entre Rn y Rm pero no modifica Rn
* \param Rn registro n
* \param Rm registro m o numero
* \param bandera puntero a la estructura bandera de entrada
* \return La funcion no tiene retorno
*/
void TST(uint32_t Rn,uint32_t Rm,flags_t *bandera);
#endif
