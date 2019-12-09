#include "Funcion5.h"


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

void FCASO6 (mentex reg2[], int idmensaje)
{
	FILE *pfich;
	registro reg, *bufreg;
	bufreg = &reg;
	int k = 0;
	int bytesreg = sizeof(reg);
    pfich = fopen ("Compania_telefonica.txt","r");
    if (pfich == NULL)
    {
    	printf ("\nEl fichero no abre o no existe.\n");
    	exit(1);
	}
	
	printf ("\nEmpleado    Destino     Fecha\n");
	printf ("----------------------------------\n");
	fread(bufreg,bytesreg,1,pfich);
	
	while (! feof(pfich))
	{
		for(k = 0; k <= idmensaje; k++)
		{
			if (reg.numero == reg2[k].destino )
			{
				strcpy(reg2[k].eliminado, "Si");
			}
		}
		fread(bufreg,bytesreg,1,pfich);
	}
	
	fclose (pfich);
	
	for(k = 0; k <= idmensaje; k++)
	{
		if(strcmp(reg2[k].eliminado, "No") == 0)
		{
			printf ("  %s       %d   %s\n\n", reg2[k].empleado, reg2[k].destino, reg2[k].fecha);
		}
	}
}
