#include <stdint.h>
/** \file conversion.h
 *  \brief Documento utilizado prar definir las funciones que convierten de decimal a binario y viceversa
*/

/**
 * \brief La funcion cumple el deber de convertir un decimal a binario, en donde cada elemento del arreglo bit corresponde a un bit de R
 * \param R Registro a convertir
 * \param Bit puntero a un arreglo que posee 32 elementos
 * \return La funcion no retorna nada
 */
void reg2bin(uint32_t R, uint32_t *Bit);

/**
 * \brief La funcion cumple el deber de convertir un binario a decimal, en donde cada elemento del arreglo bit corresponde a un bit de R
 * \param R puntero al registro a guardar la conversion
 * \param Bit puntero a un arreglo que posee 32 elementos
 * \return La funcion no retorna nada
 */
void bin2reg(uint32_t *R, uint32_t *Bit);

