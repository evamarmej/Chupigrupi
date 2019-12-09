#include "Funcion4.h"


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
	
	printf ("\nIntroduce el codigo del mensaje que quieres codificar: ");
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
