#include "mostrar.h"
#include <windows.h>
#include "colors.h"

void visualizar(uint32_t arreglo[12])
{
	int i=0; // i variable utilizada como contador
    HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE); // inicializar hCon
	for(i;i<12;i++)
	{
        SetConsoleTextAttribute(hCon,YELLOW);
		printf("R%d:",i);
		SetConsoleTextAttribute(hCon,WHITE);
		printf("%0.8X\t",arreglo[i]);
		if((i==3)||(i==7)||(i==11))
		{
			printf("\n");
		}
	}
	// for utilizado para organizar los registros
}
