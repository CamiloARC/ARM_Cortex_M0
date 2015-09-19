#ifndef INSTRUCCIONES_SALTOS_H_INCLUDED
#define INSTRUCCIONES_SALTOS_H_INCLUDED
#include "instrucciones.h"
#include <stdint.h>

/** \file instrucciones_saltos.h
 *  \brief Documento en donde estan definidas los tipos de saltos
*/

/**
 * \brief Funcion que realiza el salto en el emulador
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \return La funcion no tiene retorno
 */
void B(uint32_t *registro,int salto);

/** \brief Funcion que guarda en LR el valor de PC+2 y luego realiza el salto en el emulador
 * \param registro puntero al arreglo que contiene PC y realiza el salto
 * \param salto cantidad de lineas a saltar
 * \return La funcion no tiene retorno
 */
void BL(uint32_t *registro,int salto);

/** \brief Funcion que que guarda en LR el valor de PC+2 y luego realiza el salto en el emulador
 * \param registro puntero al arreglo que contiene PC
 * \param R registro que contiene las lineas a saltar
 * \return La funcion no tiene retorno
 */
void BLX(uint32_t *registro,uint32_t R);

/** \brief Funcion que conduce a cierta posicion en el emulador
 * \param registro puntero al arreglo que contiene PC
 * \param R registro que contiene la posicion a saltar
 * \return La funcion no tiene retorno
 */
void BX(uint32_t *registro,uint32_t R);

/** \brief Funcion que realiza el salto si el resultado anterior es 0
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BEQ(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior no es 0
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BNE(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es mayor o igual (sin signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BCS(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es menor (sin signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BCC(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es negativo
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BMI(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es positivo
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BPL(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior hubo sobreflujo
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BVS(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior no hubo sobreflujo
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BVC(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es mayor (sin signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BHI(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es menor o igual (sin signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BLS(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es mayor o igual (signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BGE(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es menor (signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BLT(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es mayor (signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BGT(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza el salto si el resultado anterior es menor o igual (signo)
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
* \return La funcion no tiene retorno
 */
void BLE(uint32_t *registro,int salto,flags_t bandera);

/** \brief Funcion que realiza siempre el salto
 * \param registro puntero al arreglo que contiene PC
 * \param salto cantidad de lineas a saltar
 * \param bandera estructura en donde estan las banderas
 * \return La funcion no tiene retorno
 */
void BAL(uint32_t *registro,int salto,flags_t bandera);
#endif // INSTRUCCIONES_SALTOS_H_INCLUDED
