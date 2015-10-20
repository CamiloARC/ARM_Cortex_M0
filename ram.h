#ifndef RAM_H_INCLUDED
#define RAM_H_INCLUDED

#include "instrucciones.h"
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
void PUSH(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list);

/** \brief funcion utlizada para extraer registros en la SRAM
 * \param registro puntero del primer elemento del arreglo registro
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \param registers_list puntero del primer elemento del arreglo de unos y ceros, que contiene los registros a extraer
 * \return la funcion no retorna nada
 */

void POP(uint32_t *registro,uint8_t *SRAM,uint8_t *registers_list);

/** \brief funcion utlizada para la carga de 2 bytes de la RAM
 * \param Rt Registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void LDR(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/** \brief funcion utlizada para la carga de  4 bits de la RAM
 * \param Rt Registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void LDRB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/** \brief funcion utlizada para la carga de  1 byte de la RAM
 * \param Rt Registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void LDRH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/** \brief funcion utlizada para la carga de 4 bits de la RAM y hacer extension de signo
 * \param Rt Registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void LDRSB(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/** \brief funcion utlizada para la carga de 1 byte de la RAM y hacer extension de signo
 * \param Rt Registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */


void LDRSH(uint32_t *Rt,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/** \brief funcion utlizada para el almacenamiento de 2 bytes de la RAM
 * \param Rt Registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void STR(uint32_t Rt, uint32_t Rn, uint32_t Rm, uint8_t *SRAM);

/** \brief funcion utlizada para el almacenamiento de 4 bits de la RAM
 * \param Rt registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void STRB(uint32_t Rt, uint32_t Rn, uint32_t Rm, uint8_t *SRAM);

/** \brief funcion utlizada para el almacenamiento de 1 byte de la RAM
 * \param Rt Registro para almacenar la direccion
 * \param Rn registro operando
 * \param Rm registro a operar
 * \param SRAM puntero del primer elemento del arreglo SRAM
 * \return la funcion no retorna nada
 */

void STRH(uint32_t Rt, uint32_t Rn, uint32_t Rm, uint8_t *SRAM);

#endif // RAM_H_INCLUDED
