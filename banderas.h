#include <stdint.h>
#include "instrucciones.h"
/** \file banderas.h
 *  \brief Documento en donde estan definidas las funciones que modifican banderas
*/
/** \def    HALF
 *  \brief  numero igual a 2^31, utilizado en banderas.c
 */

#define HALF 2147483648UL   //  1<<31

/**
 * \brief Funcion que modifica banderas para funciones aritmeticas como la suma, resta
 * \param Rd registro donde se guardo el resultado
 * \param Rn registro que se opera con Rm
 * \param Rm registro o numero que se opera con Rn
 * \param bandera puntero de la estructura flags_t bandera
 * \return La Funcion no tiene retorno
 */
void flags_aritmetica(uint32_t Rd,uint32_t Rn,uint32_t Rm,flags_t *bandera);

/**
 * \brief Funcion que modifica bandera de negativo y bandera de cero
 * \param Rd registro donde se guardo el resultado
 * \param bandera puntero de la estructutura flags_t bandera
 * \return La Funcion no tiene retorno
 */
void flags_global(uint32_t Rd,flags_t *bandera);

