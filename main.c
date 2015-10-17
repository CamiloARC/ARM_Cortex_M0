#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "decoder.h"
#include "banderas.h"
#include "instrucciones.h"
#include "instrucciones_saltos.h"
#include "curses.h"
#include "nvic.h"
#include "io.h"

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

extern uint8_t irq[16];
int main()
{
    // variables de desarrollo
    uint8_t data=0; // informacion de Pins de data
    bool FlagInt=0; // bandera que indica si hay o no una interrupcion
    uint16_t codificacion=0;
    bool cond=0;  // variable utilizada para realizar o no la funcion decodeInstruction()
    uint8_t SRAM[96];       // variable donde esta contenida parte de la RAM
    int j; // variable j utilizada como contador
	char entrada='.'; //  Letra que se pulsa para ejecutar de cierta forma el programa
    // terminan variables de desarrollo

    int i, num_instructions;
    ins_t read;
	char** instructions;
	instruction_t instruction;
    num_instructions = readFile("sustentacion.txt",&read);    // Abrir el codigo
    if(num_instructions==-1)
	 	return 0;
	if(read.array==NULL)
		return 0;
	instructions = read.array;

    //condiciones iniciales
    flags_t bandera;
	uint32_t registro[16];  // PC=registro[15]  LR=registro[14] SP=registro[13]
	registro[15]=0; // PC=0
	registro[14]=0; // LR=0
	registro[13]=96; // SP, puntero de pila debe estar una posicion mas arriba

	bandera.C=0;
	bandera.N=0;
	bandera.V=0;
	bandera.Z=0;
	for(i=0; i<13; i++) //inicializa todo en 0
    {
        registro[i]=0;
    }
    for(i=0;i<96;i++)   // datos de SRAM en FF
    {
        SRAM[i]=255;
    }
    for(i=0;i<16;i++)
    {
        irq[i]=0;
    }
    // terminan las condiciones iniciales
    initscr();		// Inicia modo curses
    curs_set(0);	// Cursor Invisible
    raw();			// Activa modo raw
    keypad(stdscr, TRUE);	// Obtener F1, F2, etc
    noecho();		// No imprimir los caracteres leidos
    start_color();	// Permite manejar colores
    init_pair(1, COLOR_WHITE, COLOR_BLUE);	// Pair 1 -> Texto blanco fondo azul
    init_pair(2, COLOR_YELLOW, COLOR_BLUE); // Pair 2 -> Texto amarillo fondo azul
    attron(COLOR_PAIR(1));	// Activa el color blanco para el texto y azul para el fondo Pair 1
    bkgd(COLOR_PAIR(1));    //  Todo el fondo de color azul
    initIO(); // Inicializa los puertos de E/S

    while(1)
    {
        showPorts();    //mostrar puertos
        NVIC(&irq[0],&FlagInt,&registro[0],&bandera,&SRAM[0]);
        move(2,10);
        printw("Emulador ARM CORTEX M0");
        move(19,10);
        printw("Presione: t para ejecutar una instruccion cada segundo");
        move(20,20);
        printw("s para detener la ejecucion cada segundo");
        move(21,20);
        printw("o para salir del emulador");
        move(22,20);
        printw("r para observar la SRAM");
        move(23,20);
        printw("ESPACIO para ejecutar la instruccion");

        move(7,10); // Mueve el cursor a la posición y=9, x=10
        printw("Registros:\t\t\t\t\tBanderas:");
        move(9,10);
        printw("R0:%0.8X\tR6:%0.8X\t\t\tC>>%d",registro[0],registro[6],bandera.C);
        move(10,10);
        printw("R1:%0.8X\tR7:%0.8X\t\t\tN>>%d",registro[1],registro[7],bandera.N);
        move(11,10);
        printw("R2:%0.8X\tR8:%0.8X\t\t\tZ>>%d",registro[2],registro[8],bandera.Z);
        move(12,10);
        printw("R3:%0.8X\tR9:%0.8X\t\t\tV>>%d",registro[3],registro[9],bandera.V);
        move(13,10);
        printw("R4:%0.8X\tR10:%0.8X",registro[4],registro[10]);
        move(14,10);
        printw("R5:%0.8X\tR11:%0.8X",registro[5],registro[11]);
        move(15,10);
        printw("\t\tR12:%0.8X",registro[12]);
        move(16,10);
        printw("PC: %0.2d",registro[15]*2);    //  Se multiplica por 2 debido a que la memoria del programa es de 8 bits
        move(17,10);
        printw("LR: %0.2d ",registro[14]*2);

        move(4,10);
        printw("-> %s",instructions[registro[15]]); //  Muestra la funcion a ejecutar
        move(4,40);
        printw("0x%0.4X",codificacion);
        if(registro[15]<num_instructions-1)
        {
            move(5,10);
            printw("%s",instructions[registro[15]+1]);  // Muestra la siguiente funcion a ejecutar
        }
        else
        {
            move(6,10);
            printw("                   ");  // Si es la ultima funcion, no muestra nada en la siguiente
        }

        border(ACS_VLINE, ACS_VLINE,ACS_HLINE, ACS_HLINE,ACS_ULCORNER, ACS_URCORNER,ACS_LLCORNER, ACS_LRCORNER);    //Borde

        entrada=getch();
        if(entrada=='i')
        {
            IOAccess(12,&data,Read);
            if(data&1)
            {
                changePinPortB(0,LOW);
            }
            else
            {
                changePinPortB(0,HIGH);
            }
            cond=1;
        }
        if(entrada==' ')
        {
            cond=1;
        }
        if(entrada=='r')    //  Observar la memoria ram
        {
            cond=0;
            clear();
            border(ACS_VLINE, ACS_VLINE,ACS_HLINE, ACS_HLINE,ACS_ULCORNER, ACS_URCORNER,ACS_LLCORNER, ACS_LRCORNER);
            move(2,10);
            printw("Emulador ARM CORTEX M0");
            move(4,10);
            printw("Memoria RAM");
            attron(COLOR_PAIR(2));
            for(j=0;j<6;j++)    // mostrar las direcciones de memoria de la SRAM
            {
                for(i=0;i<16;i++)
                {
                    move(i+6,10+j*10);
                    printw("0x%0.2X:",95-i-16*j);
                }
            }
            attron(COLOR_PAIR(1));
            for(j=0;j<6;j++)    // mostrar el contenido de las direcciones de memoria
            {
                for(i=0;i<16;i++)
                {
                    move(i+6,15+j*10);
                    printw("%0.2X",SRAM[95-i-16*j]);
                }
            }
            move(23,10);
            printw("Presione: r para salir del modo mostrar SRAM");
            while(1)    // Mientras presione una tecla diferente a r, muestra la memoria RAM y no ejecuta instrucciones
            {
                entrada=getch();
                if(entrada=='r')
                {
                    break;
                }
            }
            clear();
        }
        if(entrada=='s')    //  Parar timeout
        {
            timeout(-1);
            cond=0;
        }
        if(entrada=='t')    //  Muestra instruccion cada segundo
        {
            timeout(1000);
            cond=1;
        }
        if(entrada=='o')    //  Salir
        {
            cond=0;
            registro[15]=num_instructions;
            FlagInt=0;
        }
        if(cond==1) //realiza el ciclo si se presiono espacio o t
        {
            instruction=getInstruction(instructions[registro[15]]); // Instrucción en la posición PC
            decodeInstruction(instruction,&registro[0],&bandera,&SRAM[0],&codificacion,&instructions[0]);
            cond=0;
        }
        if((registro[15]>num_instructions-1)&&(FlagInt==0)) // Sucede cuando se termina la ejecucion
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
