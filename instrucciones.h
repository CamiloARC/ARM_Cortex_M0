#ifndef INSTRUCCIONES_H_INCLUDED
#define INSTRUCCIONES_H_INCLUDED
#include <stdint.h>

typedef struct  flags{

  char N;
  char Z;
  char C;
  char V;

}flags_t;


/**
* \brief Función que realiza la suma entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operacion AND
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void AND(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operación XOR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void EOR(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza una copia de Rm
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void MOV(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza operación OR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void ORR(uint32_t *Rd,uint32_t Rm,flags_t *bandera);

/**
* \brief Función que realiza la resta entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \return La función no tiene retorno
*/
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


