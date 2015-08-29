#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "instrucciones.h"


int main()
{

    flags_t bandera;

	unsigned long registro[12];
	visualizar(registro);

	ADDS(&registro[0],(1<<31)-1,0,&bandera);
	printf("\nC>>%d\n \nN>>%d\n \nZ>>%d\n \nV>>%d\n \nRd>>%d\n",bandera.C,bandera.N,bandera.Z,bandera.V,registro[0]);



}
