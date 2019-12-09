#include "Funcion3.h"


typedef struct dato1
{
	char cliente [30];
	char gerente [50];
	int numero;
	char operador [15];
}registro;

typedef struct dato2
{
	int destino;
	char mensaje [160];
	char fecha[100];
	char empleado[4];
	int codigo;
	char eliminado [2]; 
}mentex;

void FCASO4 (char passw[])
{		
	printf("\nIntroduzca una clave: \n");
	gets(passw);
	printf("La clave es: %s\n\n", passw);
}
