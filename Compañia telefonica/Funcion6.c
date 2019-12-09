#include "Funcion6.h"


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

void FCASO7 (mentex reg2[], int idmensaje)
{
	int comp=0;
	int contelim=0;
	int i = 0;
	int k = 0;
	int control = 99;
	char salida;
	int total[][2] = {{}};
	
	printf ("\nListado de mensajes rechazados");
	printf ("\n-----------------------------");
	printf ("\n\n Empleado   Mensajes\n---------   ---------");
	
	for (comp=0; comp<=idmensaje; comp++)
	{
		if (strcmp(reg2[comp].eliminado, "No") == 0)
		{
			contelim = contelim + 1;
			int id = atoi(reg2[comp].empleado);
			if (control == 99)
			{
				total[k][0] = id;
				total[k][1] = 0;
				control = 1;
				k = k + 1;
			}
			for (i = 0; i < k; i++)
			{
				if (total[i][0] == id)
				{
					total[i][1] = total[i][1] + 1;
					control = 1;
				}
			}
			if (control == 0)
			{
				total[k][0] = id;
				total[k][1] = 1;
				k = k + 1;
			}
			else
			{
				control = 0;
			}
		}
	}
	
	for (i = 0; i < k; i++)
	{
		printf ("\n    %d        %d\n---------   ---------",total[i][0], total[i][1]);
	}
	
	printf ("\n\n Total mensajes rechazados: %d\n\n", contelim);
	printf ("Pulse cualquier tecla para salir\n\n");
	while (!kbhit());
	{
		return;
	}
}
