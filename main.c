#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"
#include "instrucciones.h"

int main()
{
	long registro[12];
	visualizar(registro);



ADDS(&registro[0],registro[1],3);

printf("\n%0.08X\n",registro[0]);
}
