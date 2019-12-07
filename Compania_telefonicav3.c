#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>

typedef struct dato1
{
	char cliente [30];
	char gerente [50];
	char numero [9];
	char operador [15];
}registro;

typedef struct dato2
{
	char destino [9];
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
    	printf ("El fichero no abre. \n");
    	exit(1);
	}
	
	printf ("\nIntroduzca el Cliente: ");
	gets(reg.cliente);
	printf ("\nIntroduzca el Gerente: ");
	gets(reg.gerente);
	printf ("\nIntroduzca el Numero: ");
	gets(reg.numero);
	printf ("\nIntroduzca el Operador: ");
	gets(reg.operador);	
	fwrite (bufreg,bytesreg,1,pfich);
	printf ("\n\tDatos incorporados al fichero\n");
	fclose (pfich);
}

void FCASO2 (mentex reg2)
{
	FILE *pfich2;
	mentex *bufreg2;
	bufreg2 = &reg2;
	char sn;
	int bytesreg2 = sizeof(reg2);
	char caracter;
	char cadena[160]="";
	reg2.mensaje[160]="";
	int cont=160;
	int largo;
		
	pfich2 = fopen ("Mensajes_texto.txt","a");
    if (pfich2 == NULL)
    {
    	printf ("El fichero no abre. \n");
    	exit(1);
	}
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
				system("cls");
				largo=strlen(reg2.mensaje);
				reg2.mensaje[largo-1]='\0';
				printf("Maximo caracteres: 160 Quedan: ");
				cont = cont + 1;
				printf ("%d\n", cont);
				printf("----------------------------------\n");
				printf ("Texto: %s\n", reg2.mensaje);
		}
		else
		{
			if (cont>0)
			{
				cadena[0]=caracter;
				cadena[1]='\0';
				strcat(reg2.mensaje, cadena);
				system("cls");
				printf("Maximo caracteres: 160 Quedan: ");
				cont = cont - 1;
				printf ("%d\n", cont);
				printf("----------------------------------\n");
				printf ("Texto: %s\n", reg2.mensaje);
			}
		}
		caracter=getch();
	}
	while (caracter != '\r');
	{
	}

	printf ("\nNúmero destino: ");
	gets(reg2.destino);
	printf ("\nEmpleado: ");
	gets(reg2.empleado);
	printf ("\n\tMensaje listo para envío (s/n): ");
	scanf ("%c", &sn);
	fflush(stdin);
	
	while (sn != 's' && sn != 'n')
	{
		printf ("\n\tMensaje listo para envío (s/n): ");
		scanf ("%c", &sn);
		fflush(stdin);
	}
	if (sn == 's')
	{
	reg2.eliminado == "No";
	printf ("\nMensaje enviado\n\n");
	}
	if (sn == 'n')
	{
		reg2.eliminado == "Si";
		printf ("\nMensaje eliminado\n\n");
	}
	
	strcpy (reg2.fecha, fechayhora);
	fwrite(bufreg2,bytesreg2,1,pfich2);
	fclose (pfich2);
	
}

int main() {
	
	setlocale(LC_CTYPE, "Spanish");
	mentex reg2;
	reg2.codigo=1;
	printf ("\nEl codigo es %d", reg2.codigo);
	int ident1 = 0;
	int ident2 = 0;
	int ident3 = 0;
	char pass [10];
	int opcion;
	
	do {
	
	printf ("APLICACION MENSAJES MOVILES");
	printf ("\n\n1)  Rellenar fichero de clientes");
	printf ("\n2)  Componer el mensaje de texto");
	printf ("\n3)  Formatear mensaje");
	printf ("\n4)  Introducir la clave");
	printf ("\n5)  Codificar mensaje de un envío");
	printf ("\n6)  Comprobar numero del envio");
	printf ("\n7)  Salir");
	printf ("\n\nOpcion: ");
	scanf ("%d", &opcion);
	fflush(stdin);
	
		switch (opcion){
			case 1:
				FCASO1();
				ident1 = 1;
			break;
			case 2:
				FCASO2(reg2);
				reg2.codigo++;
				ident2 = 1;
				
			break;
			case 3:
				printf("Introduzca una key: ");
				gets(pass);
				printf("La contraseña es: %s\n\n", pass);
				ident3 = 1;
			break;
			case 4:
			break;
			case 5:
			break;
			case 6:
			break;
		}
	}
	while (opcion != 7); {
	}
    return 0;
}
