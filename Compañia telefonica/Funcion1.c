#include "Funcion1.h"


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

void FCASO1 ()
{
	FILE *pfich;
	registro reg, *bufreg;
	bufreg = &reg;
	int bytesreg = sizeof(reg);
    pfich = fopen ("Compania_telefonica.txt","a");
    if (pfich == NULL)
    {
    	printf ("\nEl fichero no abre o no existe.\n");
    	exit(1);
	}
	
	printf ("\nIntroduzca el Cliente: ");
	gets(reg.cliente);
	printf ("\nIntroduzca el Gerente: ");
	gets(reg.gerente);
	printf ("\nIntroduzca el Numero: ");
	scanf("%d", &reg.numero);
	fflush (stdin);
	printf ("\nIntroduzca el Operador: ");
	gets(reg.operador);	
	fwrite (bufreg,bytesreg,1,pfich);
	printf ("\n\tDatos incorporados al fichero\n\n");
	fclose (pfich);
}
