#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include "Funcion1.h"
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


int main() {
	
	mentex reg2[100] = {};
	int ident2 = 0;
	int ident4 = 0;
	int ident6 = 0;
	char passw [10];
	int idmensaje=0;
	int opcion;
	
	do {
	
	printf ("APLICACION MENSAJES MOVILES");
	printf ("\n\n1)  Rellenar fichero de clientes");
	printf ("\n2)  Componer el mensaje de texto");
	printf ("\n3)  Formatear mensaje");
	printf ("\n4)  Introducir la clave");
	printf ("\n5)  Codificar mensaje de un envio");
	printf ("\n6)  Comprobar numero del envio");
	printf ("\n7)  Salir");
	printf ("\n\nOpcion: ");
	scanf ("%d", &opcion);
	fflush(stdin);
	
		switch (opcion){
			case 1:
				FCASO1();
			break;
			case 2:
				FCASO2(reg2, idmensaje);
				idmensaje++;
				ident2 = 1;
			break;
			case 3:
				printf ("\nEsta opcion no esta disponible\n\n");
			break;
			case 4:
				if (ident2==1)
				{
					FCASO4 (passw);
					ident4 = 1;
				}
				else
				{
					printf("\nAntes tienes que componer algun mensaje (opcion 2)\n\n");
				}
			break;
			case 5:
				if (ident2==1 && ident4==1)
				{
					FCASO5(reg2, passw);
				}
				else 
				{
					printf("\nAntes tienes que componer algun mensaje (opcion 2) y haber introducido una clave (opcion 4)\n\n");
				}
			break;
			case 6:
				if (ident2 == 1)
				{
					FCASO6 (reg2, idmensaje);
					ident6 = 1;
				}
				else
				{
					printf("\nAntes tienes que componer algun mensaje (opcion 2)\n\n");
				}
			break;
			case 7:
				if (ident2 == 1 && ident6 == 1)
				{
					FCASO7 (reg2, idmensaje);
					opcion = 150;
				}
				else
				{
					printf("\nAntes tienes que componer algun mensaje (opcion 2) y haber comprobado sus destinatarios (opcion 6)\n\n");
				}	
			break;
		}
	}
	while (opcion != 150); {
	}
	
    return 0;
}
