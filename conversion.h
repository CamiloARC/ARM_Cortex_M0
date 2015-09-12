#include <stdint.h>

/**
 * \brief La funci�n cumple el deber de convertir un decimal a binario, en donde cada elemento del arreglo bit corresponde a un bit de R
 * \param R Registro a convertir
 * \param Bit puntero a un arreglo que posee 32 elementos
 * \return La funci�n no retorna nada
 */
void reg2bin(uint32_t R, uint32_t *Bit);

/**
 * \brief La funci�n cumple el deber de convertir un binario a decimal, en donde cada elemento del arreglo bit corresponde a un bit de R
 * \param R puntero al registro a guardar la conversi�n
 * \param Bit puntero a un arreglo que posee 32 elementos
 * \return La funci�n no retorna nada
 */
void bin2reg(uint32_t *R, uint32_t *Bit);

