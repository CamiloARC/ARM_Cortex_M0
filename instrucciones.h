#include <stdint.h>

typedef struct flags // estrutura flags_t
{
	char N;  // bandera de un resultado negativo, si este es negativo entonces N=1
	char Z;  // bandera de un resultado igual a 0, si este es cero entonces Z=1;
	char C;  // bandera de carry, si hay un carry en una operacion entonces C=1;
	char V;  // bandera de sobreflujo, si en una operación los bits mas signiticativos de los operandos son iguales y el bit mas significativo del resultado es el complemento de los bits de los operandos, se tiene un sobreflujo y V=1

}flags_t;

/**
* \brief Función que realiza la suma entre Rn y Rm
* \param Rd puntero del registro Rd
* \param Rn registro n
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operacion AND
* \param Rd puntero del registro Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void AND(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operación XOR
* \param Rd puntero del registro Rd
* \param Rm registro m o número
* \param bandera puntero a la estrutura bandera de entrada
* \return La función no tiene retorno
*/
void EOR(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza una copia de Rm
* \param Rd puntero del registro Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void MOV(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operación OR
* \param Rd puntero del registro Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void ORR(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza la resta entre Rn y Rm
* \param Rd puntero del registro Rd
* \param Rn registro n
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief Función que realiza extension de signo y cambia el orden de los Bytes del halfword bajo
 * \param Rd puntero del registro Rd
 * \param Rm registro m o un número
 * \return La función no tiene retorno
 */
void REVSH(uint32_t *Rd,uint32_t Rm);

/**
 * \brief Función que cambia el orden de los Bytes en cada halfword de 16 bits
 * \param Rd puntero del registro Rd
 * \param Rm registro m o un número
 * \return La función no tiene retorno
 */
void REV16(uint32_t *Rd,uint32_t Rm);

/**
 * \brief Función que cambia el orden de los bytes
 * \param Rd puntero del registro Rd
 * \param Rm registro m o un número
 * \return La función no tiene retorno
 */
void REV(uint32_t *Rd,uint32_t Rm);

/**
 * \brief Función que no realiza nada en un ciclo de reloj
 * \return La función no tiene retorno
 */
void NOP();

/**
 * \brief Función que obtiene el complemento a dos de un número o registro n y lo guarda en Rd
 * \param Rd puntero del registro Rd
 * \param Rn registro n o un número
 * \return La función no tiene retorno
 */
void RSB(uint32_t *Rd,uint32_t Rn);

/**
 * \brief Función que guarda el complemento de un número o registro m y lo guarda en Rd
 * \param Rd puntero del registro Rd
 * \param Rm registro n o un número
 * \return La función no tiene retorno
 */
void MVN(uint32_t *Rd,uint32_t Rm);

/**
 * \brief Función que realiza la operacion AND entre un registro dn y el complemento de un número o un registro m
 * \param Rdn puntero del registro Rdn
 * \param Rm registro n o un número
 * \return La función no tiene retorno
 */
void BIC(uint32_t *Rdn,uint32_t Rm);

/**
 * \brief Función que realiza desplazamiento aritmetico a un registro Rd, Rm veces
 * \param Rd puntero del registro Rd
 * \param Rm número
 * \return La función no tiene retorno
 */
void ASR(uint32_t *Rd,uint32_t Rm);

/**
 * \brief Función que realiza rotacion a la derecha del registro Rdn, Rm veces
 * \param Rdn puntero del registro Rdn
 * \param Rm número
 * \return La función no tiene retorno
 */
void ROR(uint32_t *Rdn,uint32_t Rm);

/**
 * \brief Función que realiza desplazamiento lógico del registro Rdn a la derecha, Rm veces
 * \param Rdn puntero del registro Rdn
 * \param Rm número
 * \return La función no tiene retorno
 */
void LSR(uint32_t *Rdn,uint32_t Rm);

/**
 * \brief Función que realiza desplazamiento lógico del registro Rdn a la izquierda, Rm veces
 * \param Rdn puntero del registro Rdn
 * \param Rm número
 * \return La función no tiene retorno
 */
void LSL(uint32_t *Rdn,uint32_t Rm);

/**
 * \brief Función banderas
 * \param Rd
 * \param Rn
 * \param Rm
 * \param bandera puntero de la estructutura flags_t bandera
 * \return La función no tiene retorno
 */
void flags(uint32_t Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);
