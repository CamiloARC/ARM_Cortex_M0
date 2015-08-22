#ifndef INSTRUCCIONES_H_INCLUDED
#define INSTRUCCIONES_H_INCLUDED

/**
* \brief Función que realiza la suma entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void ADDS(unsigned long int *Rd,unsigned long int Rn,unsigned long int Rm);

/**
* \brief Función que realiza operacion AND
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void AND(unsigned long int *Rd,unsigned long int Rm);

/**
* \brief Función que realiza operación XOR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void EOR(unsigned long int *Rd,unsigned long int Rm);

/**
* \brief Función que realiza una copia de Rm
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void MOV(unsigned long int *Rd,unsigned long int Rm);

/**
* \brief Función que realiza operación OR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void ORR(unsigned long int *Rd,unsigned long int Rm);

/**
* \brief Función que realiza la resta entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void SUB(unsigned long int *Rd,unsigned long int Rn,unsigned long int Rm);

#endif // INSTRUCCIONES_H_INCLUDED
