#ifndef RAM_H_INCLUDED
#define RAM_H_INCLUDED

#include <stdint.h>
/** \file ram.h
 *  \brief Documento utilizado para definir las funciones de manejo de la RAM
*/

/** \brief funcion utlizada para guardar registros en la SRAM
 * \param registro puntero del primer elemento del arreglo registro
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \param registers_list puntero del primer elemento del arreglo de unos y ceros, que contiene los registros a guardar
 * \return la funcion no retorna nada
 */
void push(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list);

/** \brief funcion utlizada para extraer registros en la SRAM
 * \param registro puntero del primer elemento del arreglo registro
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \param registers_list puntero del primer elemento del arreglo de unos y ceros, que contiene los registros a extraer
 * \return la funcion no retorna nada
 */
void pop(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list);

#endif // RAM_H_INCLUDED
