#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "instrucciones.h"
#include <stdint.h>
#include "curses.h"

int main()
{

    flags_t bandera;

	uint32_t registro[12];
	visualizar(registro);

    ADDS(&registro[0],(1<<32)-1,0,&bandera);


	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */

	init_pair(1, COLOR_BLUE, COLOR_GREEN);	/* Pair 1 -> Texto verde
											   fondo Negro */


	border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);

	attron(COLOR_PAIR(1));	/* Activa el color verde para el
							   texto y negro para el fondo Pair 1*/

	move(2, 34);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("\nC>>%d\n \nN>>%d\n \nZ>>%d\n \nV>>%d\n \nRd>>%d\n",bandera.C,bandera.N,bandera.Z,bandera.V,registro[0]);
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */

	attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */

	getch();	/* Espera entrada del usuario */
	endwin();	/* Finaliza el modo curses */







}
