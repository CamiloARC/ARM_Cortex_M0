#include "mostrar.h"

void visualizar(unsigned long int arreglo[12])
{
	int i=0; /** \param i variable contador */

	for( i;i<12;i++)
	{
		printf("R%d:%0.8X\t",i,arreglo[i]);
		if((i==3)||(i==7)||(i==11))
		{
			printf("\n");
		}
	}
	/** for utilizado para organizar los registros */
}
