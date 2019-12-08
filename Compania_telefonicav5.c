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
	printf ("\n\tDatos incorporados al fichero\n\n");
	fclose (pfich);
}

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
	
	printf("Máximo caracteres: 160 Quedan: 160\n");
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
					printf("Máximo caracteres: 160 Quedan: ");
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
				printf("Máximo caracteres: 160 Quedan: ");
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

	printf ("\nNúmero destino: ");
	gets(reg2[idmensaje].destino);
	printf ("\nEmpleado: ");
	gets(reg2[idmensaje].empleado);
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
	printf ("\nMensaje listo para envio\n\n");
	}
	if (sn == 'n')
	{

		FCASO2(reg2, idmensaje);
		return;
	}
	
	strcpy(reg2[idmensaje].eliminado, "No");
	
	printf ("El código de este mensaje es: %d\n\n", reg2[idmensaje].codigo);
	strcpy (reg2[idmensaje].fecha, fechayhora);
	
}

void FCASO4 (char passw[])
{		
	printf("Introduzca una key: ");
	gets(passw);
	printf("La contraseña es: %s\n\n", passw);
}

void FCASO5 (mentex reg2[], char passw[])
{

	char mensaje[160] ="";
	int i=0;
	int j=0;
	int cod;
	int mensajeauxint[160];
	int keycounter=0;
	int passint[160];
	int messageint[160];
	
	printf ("\nIntroduce el código del mensaje que quieres codificar: \n");
	scanf("%d", &cod);
	fflush(stdin);
	
	while (cod != reg2[j].codigo) 
	{	
		j++;
	}
	
	printf ("Texto a codificar: %s\n\n", reg2[j].mensaje);
	
	int largomensaje=strlen(reg2[j].mensaje);
	int largokey=strlen(passw);
	
	printf ("Texto ya codificado: ");
	
	for (i=0;i<largomensaje;i++)
	{
		if (keycounter==largokey)
		{
			keycounter=0;
		}
		messageint[i]= reg2[j].mensaje[i];
		if(ispunct(reg2[j].mensaje[i]) == 0)
		{		
			passint[keycounter]= passw[keycounter];
			mensajeauxint[i]=messageint[i]+passint[keycounter];
		}
		else
		{
			mensajeauxint[i] = messageint[i];
		}
		printf("%c", mensajeauxint[i]);		
		keycounter++;
	}
	
	printf ("\n\n");	

}

void FCASO6 (mentex reg2[])
{
	FILE *pfich;
	registro reg, *bufreg;
	bufreg = &reg;
	int iddestino=0;
	int bytesreg = sizeof(reg);
    pfich = fopen ("Compania_telefonica.txt","r");
    if (pfich == NULL)
    {
    	printf ("El fichero no abre. \n");
    	exit(1);
	}
	printf ("Empleado     Destino     Fecha\n");
	fread(bufreg,bytesreg,1,pfich);
	while (! feof(pfich))
	{
		if (reg2[iddestino].destino==reg.numero)
		{
			strcpy(reg2[iddestino].eliminado, "Si");
		}
		else
		{
			strcpy(reg2[iddestino].eliminado, "No");
		}
		
		printf ("%s     %s     %s\n\n", reg2[iddestino].empleado, reg2[iddestino].destino, reg2[iddestino].fecha);
		fread(bufreg,bytesreg,1,pfich);
	}
}

int main() {
	
	mentex reg2[100] = {};
	int ident1 = 0;
	int ident2 = 0;
	int ident4 = 0;
	char passw [10];
	int idmensaje=0;
	int opcion;
	
	do {
	
	printf ("APLICACION MENSAJES MOVILES");
	printf ("\n\n1)  Rellenar fichero de clientes");
	printf ("\n2)  Componer el mensaje de texto");
	printf ("\n3)  Formatear mensaje");
	printf ("\n4)  Introducir la clave");
	printf ("\n5)  Codificar mensaje de un envío");
	printf ("\n6)  Comprobar numero del envío");
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
				FCASO2(reg2, idmensaje);
				idmensaje++;
				ident2 = 1;
			break;
			case 3:
			break;
			case 4:
				if (ident2==1)
				{
					FCASO4 (passw);
				}
				ident4 = 1;
			break;
			case 5:
				if (ident2==1 && ident4==1)
				{
					FCASO5(reg2, passw);
				}
			break;
			case 6:
				FCASO6 (reg2);
			break;
			case 7:
			break;
		}
	}
	while (opcion != 7); {
	}
	
    return 0;
}
