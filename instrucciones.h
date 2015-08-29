
typedef struct flags // estrutura flags_t
{
	char N;  // bandera de un resultado negativo, si este es negativo entonces N=1
	char Z;  // bandera de un resultado igual a 0, si este es cero entonces Z=1;
	char C;  // bandera de carry, si hay un carry en una operacion entonces C=1;
	char V;  // bandera de sobreflujo, si en una operación los bits mas signiticativos de los operandos son iguales y el bit mas significativo del resultado es el complemento de los bits de los operandos, se tiene un sobreflujo y V=1
}flags_t;


/**
* \brief Función que realiza la suma entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void ADDS(unsigned long *Rd,unsigned long Rn,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza operacion AND
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void AND(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza operación XOR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estrutura bandera de entrada
* \return La función no tiene retorno
*/
void EOR(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza una copia de Rm
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void MOV(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza operación OR
* \param Rd puntero del registro en Rd
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void ORR(unsigned long *Rd,unsigned long Rm,flags_t *bandera);

/**
* \brief Función que realiza la resta entre Rn y Rm
* \param Rd puntero del registro en Rd
* \param Rn registro n
* \param Rm registro m o número
* \param bandera puntero a la estructura bandera de entrada
* \return La función no tiene retorno
*/
void SUB(unsigned long *Rd,unsigned long Rn,unsigned long Rm,flags_t *bandera);
