#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "banderas.h"
#include "instrucciones.h"
#include "curses.h"

int main()
{
    flags_t bandera;
    int contador=0;
	uint32_t registro[12];
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */

	init_pair(1, COLOR_WHITE, COLOR_BLUE);	/* Pair 1 -> Texto verde
											   fondo Cyan */
    bkgd(COLOR_PAIR(1));

	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

	attron(COLOR_PAIR(1));	/* Activa el color verde para el
							   texto y negro para el fondo Pair 1*/

    while(1)
    {
    move(6,10); // Mueve el cursor a la posición y=9, x=10
	printw("Registros:\t\t\t\t\t    Banderas:");
	move(8,10);
	printw("R0:%0.8X\tR6:%0.8X\t\t\tC>>%d",registro[0],registro[6],bandera.C);
	move(9,10);
	printw("R1:%0.8X\tR7:%0.8X\t\t\tN>>%d",registro[1],registro[7],bandera.N);
	move(10,10);
	printw("R2:%0.8X\tR8:%0.8X\t\t\tZ>>%d",registro[2],registro[8],bandera.Z);
	move(11,10);
	printw("R3:%0.8X\tR9:%0.8X\t\t\tV>>%d",registro[3],registro[9],bandera.V);
	move(12,10);
	printw("R4:%0.8X\tR10:%0.8X",registro[4],registro[10]);
	move(13,10);
	printw("R5:%0.8X\tR11:%0.8X",registro[5],registro[11]);
	getch();
	contador++;
	if(contador==10)
    {
        break;
    }
    }
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */
	attroff(COLOR_PAIR(1));	/* Deshabilita los colores Pair 1 */
	endwin();	/* Finaliza el modo curses */
    return 0;
}
