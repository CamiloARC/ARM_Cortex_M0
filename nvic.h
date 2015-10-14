#ifndef NVIC_H_INCLUDED
#define NVIC_H_INCLUDED

#include "curses.h"
#include "instrucciones.h"
#include <stdint.h>

/** \file nvic.h
 *  \brief Documento utilizado para definir las funciones que actuan en las interrupciones
*/

/** \brief funcion utlizada para generar interrupciones
 * \param puntero que define la veracidad de la interrupcion
 * \param indicador de banderas
 * \param Puntero con la primera posicion de los registros
 * \param Puntero para operar la estructura de banderas
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void NVIC(bool *interrupcion,bool *FlagInt,uint32_t *registro,flags_t *bandera,uint8_t *SRAM);

/** \brief funcion PUSH con inclusion de banderas
 * \param Puntero con la primera posicion de los registros
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \param Puntero para operar la estructura de banderas
 * \return la funcion no retorna nada
 */

void PUSHH(uint32_t *registro,uint8_t *SRAM,flags_t *bandera);

/** \brief funcion POP con inclusion de banderas
 * \param Puntero con la primera posicion de los registros
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \param Puntero para operar la estructura de banderas
 * \return la funcion no retorna nada
 */

void POPP(uint32_t *registro,uint8_t *SRAM,flags_t *bandera);

#endif // NVIC_H_INCLUDED
