#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "decoder.h"
#include "banderas.h"
#include "instrucciones.h"
#include "instrucciones_saltos.h"
#include "curses.h"

/** \mainpage Emulador del procesador ARM Cortex -M0
 *  Esta es la documentacion para un sofware que simula el procesador ARM Cortex -M0 el cual es el procesador ARM
 *  mas pequeno disponible con un rendimiento de 32 bits.  Este sofware codificado en lenguaje C, con ayuda del compilador
 *  codeblocks para su desarrollo y la libreria curses.h para la presentacion de su interfaz se basa en leer las instrucciones
 *  del archivo code.txt, que se encuentran en lenguaje de maquina y convertir estas instrucciones en un lenguaje de medio nivel como
 *  lo es el lenguaje C. En este se tradujeron 24 instrucciones de lenguaje de maquina a lenguaje C, con las respectivas modificaciones de banderas;
 *  tambien se llevo a cabo la traduccion de las funciones de salto.\n
 *  Para el desarrollo del sofware se implementaron 15 registros cada uno de 32 bits sin signo, 12 de ellos
 *  son utilizados para almacenamiento, uno para el program counter(PC) y otro para link register(LR), ademas se implemento una estructura para
 *  el manejo de las banderas de negativo, de cero, de acarreo y bandera de sobreflujo.
 */

/** \file main.c
 *  \brief Documento que utiliza la libreria curses.h para presentar la interfaz, tambien se definen los registros, la estructura bandera
 *  y ademas en ella se trabaja con las instrucciones adquiridas del code.txt
*/

int main()
{
    int i, num_instructions;
    ins_t read;
	char** instructions;
	instruction_t instruction;
    num_instructions = readFile("code.txt",&read);
    if(num_instructions==-1)
	 	return 0;
	if(read.array==NULL)
		return 0;
	instructions = read.array;

    flags_t bandera;
	uint32_t registro[15];  // PC=registro[14]  LR=registro[13]
	registro[14]=0; // PC=0
	registro[13]=0; // LR=0
	char entrada; //  Letra que se pulsa para ejecutar de cierta forma el programa

	bandera.C=0;
	bandera.N=0;
	bandera.V=0;
	bandera.Z=0;
	for(i=0; i<12; i++)
    {
        registro[i]=0;
    }
	initscr();		// Inicia modo curses
	curs_set(0);	// Cursor Invisible
	raw();			// Activa modo raw
	keypad(stdscr, TRUE);	// Obtener F1, F2, etc
	noecho();		// No imprimir los caracteres leidos
	start_color();	// Permite manejar colores
	init_pair(1, COLOR_WHITE, COLOR_BLUE);	// Pair 1 -> Texto blanco fondo azul
    attron(COLOR_PAIR(1));	// Activa el color blanco para el texto y azul para el fondo Pair 1
    bkgd(COLOR_PAIR(1));    //  Todo el fondo de color azul

    move(2,10);
    printw("Emulador ARM CORTEX M0");
    move(21,10);
    printw("Presione: t para ejecutar una instruccion cada segundo");
    move(22,20);
    printw("s para detener la ejecucion cada segundo");
    move(23,20);
    printw("o para salir del emulador");

    while(1)
    {
        move(9,10); // Mueve el cursor a la posición y=6, x=10
        printw("Registros:\t\t\t\t\tBanderas:");
        move(11,10);
        printw("R0:%0.8X\tR6:%0.8X\t\t\tC>>%d",registro[0],registro[6],bandera.C);
        move(12,10);
        printw("R1:%0.8X\tR7:%0.8X\t\t\tN>>%d",registro[1],registro[7],bandera.N);
        move(13,10);
        printw("R2:%0.8X\tR8:%0.8X\t\t\tZ>>%d",registro[2],registro[8],bandera.Z);
        move(14,10);
        printw("R3:%0.8X\tR9:%0.8X\t\t\tV>>%d",registro[3],registro[9],bandera.V);
        move(15,10);
        printw("R4:%0.8X\tR10:%0.8X",registro[4],registro[10]);
        move(16,10);
        printw("R5:%0.8X\tR11:%0.8X",registro[5],registro[11]);
        move(18,10);
        printw("PC: %d",registro[14]*2);    //  Se multiplica por 2 debido a que la memoria del programa es de 8 bits
        move(19,10);
        printw("LR: %d",registro[13]*2);

        move(5,10);
        printw("-> %s",instructions[registro[14]]); //  Muestra la funcion a ejecutar
        if(registro[14]<num_instructions-2)
        {
            move(6,10);
            printw("%s",instructions[registro[14]+1]);  // Muestra la siguiente funcion a ejecutar
        }
        instruction=getInstruction(instructions[registro[14]]); // Instrucción en la posición PC
        decodeInstruction(instruction,&registro[0],&bandera);

        border(ACS_VLINE, ACS_VLINE,ACS_HLINE, ACS_HLINE,ACS_ULCORNER, ACS_URCORNER,ACS_LLCORNER, ACS_LRCORNER);

        entrada=getch();

        if(entrada=='t')    //  Muestra instruccion cada segundo
        {
            timeout(1000);
        }
        if(entrada=='s')    //  Parar timeout
        {
            timeout(-1);
            getch();
        }
        if(entrada=='o')    //  Salir
        {
            registro[14]=num_instructions;
        }

        if(registro[14]>num_instructions-1) // Sucede cuando se termina la ejecucion
        {
            break;
        }

    }
    for(i=0; i<num_instructions; i++)
    {
        free(read.array[i]);
    }
	free(read.array);

    refresh();	// Imprime en la pantalla sin esto el printw no es mostrado
	attroff(COLOR_PAIR(1));	// Deshabilita los colores Pair 1
	endwin();	// Finaliza el modo curses
    return 0;
}
