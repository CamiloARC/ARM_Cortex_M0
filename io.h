#ifndef _IO_H_
#define	_IO_H_

#include <stdint.h>
#include "curses.h"
/** \def XINIT
 *  \brief Posiciion en x para mostrar puertos
*/
#define XINIT 10
/** \def YINIT
 *  \brief Posiciion en y para mostrar puertos
*/
#define YINIT 25
/** \def HIGH
 *  \brief Valor que indica el estado del pin en 1
*/
#define HIGH	1
/** \def LOW
 *  \brief Valor que indica el estado del pin en 0
*/
#define LOW		0
/** \def Read
 *  \brief Dato que indica la lectura en la funcion IOAcess
*/
#define Read	1
/** \def Write
 *  \brief Dato que indica la escritura en la funcion IOAcess
*/
#define Write	0

/** \def BLUEBLACK
 *  \brief Indica configuracion de texto azul y fondo negro
*/
#define BLUEBLACK	10

/** \def REDBLACK
 *  \brief Indica configuracion de texto rojo y fondo negro
*/
#define REDBLACK	20

/** \def WHITEBLACK
 *  \brief Indica configuracion de texto blanco y fondo blanco
*/
#define WHITEBLACK	30

/** \file io.h
 *  \brief Documento en el cual se define la estructura port_t utilizada para representar los puertos de entrada y salida,
 *  tambien se definen funciones para modificar los miembros de la estructura port_t
*/

/** \struct port_t;
 *  \brief  Estructura en donde los miembros definen los puertos de entrada y salida
 */
typedef struct{
	uint8_t DDR;    /*!< Indica cuales son los pines de entrada y salida*/
	uint8_t PORT;   /*!< Registro que permite escribir en las salidas*/
	uint8_t PIN;    /*!< Lee tanto las entradas como salidas*/
	uint8_t Pins;   /*!< Pines externos a los puertos de entrada y salida*/
	uint8_t Interrupts; /*!< Registro que indica si se pueden realizar o no las interrupciones*/
}port_t;

/**
 * \brief La funcion escribe o lee los miembros de la escructura port_t
 * \param address indica la posicion del miembro a leer o a escribir
 * \param data registro que se leera en donde se guardara el miembro indicado por la direccion
 * \param r_w indica si se lee o se escribe data
 * \return La funcion no retorna nada
 */
void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w);

/**
 * \brief La funcion que cambia el miembro Pins, y activa las interrupciones dependiendo de ciertas condiciones
 * \param pin indica el pin del miembro Pins a cambiar
 * \param value alto o bajo
 * \return La funcion no retorna nada
 */
void changePinPortA(uint8_t pin, uint8_t value);

/**
 * \brief La funcion que cambia el miembro Pins, y activa las interrupciones dependiendo de ciertas condiciones
 * \param pin indica el pin del miembro Pins a cambiar
 * \param value alto o bajo
 * \return La funcion no retorna nada
 */
void changePinPortB(uint8_t pin, uint8_t value);

/**
 * \brief Funcion que determina las condiciones iniciales
 * \return La funcion no retorna nada
 */
void initIO(void);

/**
 * \brief Funcion que muestra ordenamente los miembros de PORTA Y PORTB
 * \return La funcion no retorna nada
 */
void showPorts(void);

/**
 * \brief Funcion utilizada por la funcion showPorts
 * \return La funcion no retorna nada
 */
void showFrame(int x,int y,int w,int h);

#endif /*_IO_H_*/
