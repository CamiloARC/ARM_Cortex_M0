<<<<<<< HEAD
#ifndef INSTRUCCIONES_H_INCLUDED
#define INSTRUCCIONES_H_INCLUDED
#include <stdint.h>

typedef struct  flags{

  char N;
  char Z;
  char C;
  char V;

=======

typedef struct flags // estrutura flags_t
{
	char N;  // bandera de un resultado negativo, si este es negativo entonces N=1
	char Z;  // bandera de un resultado igual a 0, si este es cero entonces Z=1;
	char C;  // bandera de carry, si hay un carry en una operacion entonces C=1;
	char V;  // bandera de sobreflujo, si en una operación los bits mas signiticativos de los operandos son iguales y el bit mas significativo del resultado es el complemento de los bits de los operandos, se tiene un sobreflujo y V=1
>>>>>>> e378bbe0565c95e0f851c24e89b1a41d9ab457d7
}flags_t;


/**
* \brief Función que realiza la suma entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operacion AND
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void AND(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operación XOR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estrutura bandera de entrada
* \return La función no tiene retorno
*/
void EOR(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza una copia de Rm
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void MOV(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operación OR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void ORR(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza la resta entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
<<<<<<< HEAD
void SUB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

void flags(uint32_t Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

void REVSH(uint32_t *Rd,uint32_t Rm);

void REV16(uint32_t *Rd,uint32_t Rm);

void REV(uint32_t *Rd,uint32_t Rm);

void NOP();

void RSBS(uint32_t *Rd,uint32_t Rn);

void MVNS(uint32_t *Rd,uint32_t Rm);

void BIC(uint32_t *Rdn,uint32_t Rm);

void ASRS(uint32_t *Rd,uint32_t Rm);

void ROR(uint32_t *Rdn,uint32_t Rm);

void LSR(uint32_t *Rdn,uint32_t Rm);

void LSL(uint32_t *Rdn,uint32_t Rm);



#endif // INSTRUCCIONES_H_INCLUDED


=======
void SUB(unsigned long *Rd,unsigned long Rn,unsigned long Rm,flags_t *bandera);
>>>>>>> e378bbe0565c95e0f851c24e89b1a41d9ab457d7
