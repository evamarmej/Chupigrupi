#include "Funcion2.h"


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

void FCASO2 (mentex reg2[], int idmensaje)
{
	char sn;
	char caracter;
	char cadena[160]="";
	int cont=161;
	int largo;
	reg2[idmensaje].codigo=idmensaje+1;
	strcpy(reg2[idmensaje].mensaje, "");
		
	time_t t;
	struct tm *tm;
	t=time(NULL);
	char fechayhora[100];
	tm=localtime(&t);
	strftime(fechayhora, 100, "%d/%m/%Y", tm);
	
	printf("Maximo caracteres: 160 Quedan: 160\n");
	printf("----------------------------------\n");
	printf ("Texto: ");
	
	do
	{
		if (caracter == 8)
		{
				if (cont!=160)
				{
					system("cls");
					largo=strlen(reg2[idmensaje].mensaje);
					reg2[idmensaje].mensaje[largo-1]='\0';
					printf("Maximo caracteres: 160 Quedan: ");
					cont = cont + 1;
					printf ("%d\n", cont);
					printf("----------------------------------\n");
					printf ("Texto: %s\n", reg2[idmensaje].mensaje);
				}
		}
		else
		{
			if (cont>0)
			{
				cadena[0]=caracter;
				cadena[1]='\0';
				strcat(reg2[idmensaje].mensaje, cadena);
				system("cls");
				printf("Maximo caracteres: 160 Quedan: ");
				cont = cont - 1;
				printf ("%d\n", cont);
				printf("----------------------------------\n");
				printf ("Texto: %s\n", reg2[idmensaje].mensaje);
			}
		}
		caracter=getch();
	}
	while (caracter != '\r');
	{
	}

	printf ("\nNumero destino: ");
	scanf("%d", &reg2[idmensaje].destino);
	fflush (stdin);
	printf ("\nEmpleado: ");
	gets(reg2[idmensaje].empleado);
	printf ("\n\tMensaje listo para envio (s/n): ");
	scanf ("%c", &sn);
	fflush(stdin);
	
	while (sn != 's' && sn != 'n')
	{
		printf ("\n\tMensaje listo para envio (s/n): ");
		scanf ("%c", &sn);
		fflush(stdin);
	}
		
	if (sn == 's')
	{
	printf ("\nMensaje listo para envio\n\n");
	}
	if (sn == 'n')
	{

		FCASO2(reg2, idmensaje);
		return;
	}
	
	strcpy(reg2[idmensaje].eliminado, "No");
	
	printf ("El codigo de este mensaje es: %d\n\n", reg2[idmensaje].codigo);
	strcpy (reg2[idmensaje].fecha, fechayhora);
	
}
