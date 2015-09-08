#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "instrucciones.h"
#include <stdint.h>

int main()
{
    flags_t bandera;
	uint32_t registro[12];
	visualizar(registro);
	ADDS(&registro[0],0,0,&bandera);
	printf("\nC>>%d\n \nN>>%d\n \nZ>>%d\n \nV>>%d\n \nRd>>%d\n",bandera.C,bandera.N,bandera.Z,bandera.V,registro[0]);
	return 0;
}
