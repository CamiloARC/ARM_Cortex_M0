#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "instrucciones.h"

int main()
{
    flags_t bandera;            // se crea la estructura bandera
	unsigned long registro[12]; // se crean los registros de 32 bits
	visualizar(registro);       // observar registros
	ADDS(&registro[0],(1<<31)-1,0,&bandera);  // ejemplo de una operacion suma para observar las banderas
	printf("\nC>>%d\n \nN>>%d\n \nZ>>%d\n \nV>>%d\n \nRd>>%d\n",bandera.C,bandera.N,bandera.Z,bandera.V,registro[0]);
}
