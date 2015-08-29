#ifndef INSTRUCCIONES_H_INCLUDED
#define INSTRUCCIONES_H_INCLUDED


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
void ADDS(unsigned long *Rd,unsigned long Rn,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza operacion AND
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void AND(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza operación XOR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void EOR(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza una copia de Rm
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void MOV(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza operación OR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void ORR(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza la resta entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \return La función no tiene retorno
*/
void SUB(unsigned long *Rd,unsigned long Rn,unsigned long Rm,flags_t *bandera);


#endif // INSTRUCCIONES_H_INCLUDED


