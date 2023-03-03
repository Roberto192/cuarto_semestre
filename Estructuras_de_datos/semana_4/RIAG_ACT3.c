//			Actividad  3
//			Alumno:  roberto isaac arias guerrero Matricula:  1292118
/*			Descripcion:
			Crear una estructura de dato llamada colas Dinamica/Estatica
*/
//			Fecha:  17/2/23
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"

//#define MEM 8
#define ref(x) (&x)
#define inc(x) ((*x)++)
#define dec(x) ((*x)--)

int readInt(const char *msg){
	int i = 0;
	char c;
	char buff[30];

	puts(msg);
	while((c = getc(stdin)) != '\n')
		buff[i++] = c;

	buff[i] = '\0';
	return atoi(buff);
}

int menu(){
	puts("1.- PUSH");
	puts("2.- POP");
	puts("3.- SALIR");
	return readInt("Ingrese la opcion:");
}

void colaDinamica(){
	Tdato cola, ultimo, temp;
	cola = ultimo = NULL;
	int opc = 0;

	while(opc != 3){
		system("cls");
		opc = menu();
		switch(opc){
			case 1:
				PUSH(ref(cola), ref(ultimo), readInt("Ingrese un entero:"));
				break;
			case 2:
				temp = POP(ref(cola), ref(ultimo));
				servicio(ref(temp), "Servicio dado a -> %d\n");
				break;
			case 3:
				while(ultimo){
					temp = POP(ref(cola), ref(ultimo));
					servicio(ref(temp), "Cerrando el proceso -> %d\n");
				}
				break;
		}
		system("pause");
	}

}

void push(int cola[], int *cantidad, int *ultimo, int dato){
	if((*cantidad) < MAX){
		if((*ultimo) == MAX){
			(*ultimo) = 0;
		}
		cola[(*ultimo)] = dato;
		inc(cantidad);
		inc(ultimo);
	}else{
		puts("Cola llena libere datos!!!");
	}
}

int *pop(int cola[], int *cantidad, int *cabeza, int *temp){
	
	if((*cantidad) != 0){
		temp = &cola[(*cabeza)];
		dec(cantidad);
		inc(cabeza);
	}

	return temp;
}

void multiservicio(void **pointer, const char *msg){
	if((*pointer)){
		int *p = (int *) (*pointer);
		printf(msg, *p);
		(*pointer) = NULL;
	}else{
		puts("Sin datos!!!");
	}
}

void colaEstatica(){
	int micola[MAX];
	int cantidad;
	int cabeza, ultimo;
	int *temp = NULL;

	cantidad = cabeza = ultimo = 0;
	//------------------------------------------------------
	int opc = 0;

	while(opc != 3){
		system("cls");
		opc = menu();
		switch(opc){
			case 1:	
				push(micola, ref(cantidad), ref(ultimo), readInt("Ingrese un entero:"));
				break;
			case 2:			
				temp = pop(micola, ref(cantidad), ref(cabeza), temp);
				multiservicio((void **)ref(temp), "DatOwO -> %d\n");
				break;
			case 3:
				while(cantidad){				
					temp = pop(micola, ref(cantidad), ref(cabeza), temp);
					multiservicio((void **)ref(temp), "Cerrando dato -> %d\n");
				}
				break;
		}
		system("pause");
	}
}

int main()
{
	int opc = 0;

	while(opc != 3){
		system("cls");
		opc = readInt("1.- Cola dinamica\n2.- Cola estatica\n3.- Salir\n");
		switch(opc){
			case 1:
				colaDinamica();
				break;
			case 2:
				colaEstatica();
				break;
		}
	}
	return 0;
}

//		cola -> NULL <- ultimo
//		cola -> 7 <- ultimo

void PUSH(Tdato *cola, Tdato *ultimo, int dato)
{
	Tdato nuevaCola = (Tdato)malloc(sizeof(sTdato));

	nuevaCola->dato = dato;
	nuevaCola->sig = NULL;

	if((*cola)){

		(*ultimo)->sig = nuevaCola;
		(*ultimo) = nuevaCola;

	}else{
		(*cola) = (*ultimo) = nuevaCola;
	}
}

Tdato POP(Tdato *cola, Tdato *ultimo){
	Tdato temp = NULL;

	if((*cola)){
		if((*cola) == (*ultimo)){
			(*ultimo) = NULL;	
		}

		temp = (*cola);
		(*cola) = (*cola)->sig;
	}

	return temp;
}

void servicio(Tdato *nodo, const char *msg){
	if(*nodo){
		printf(msg, (*nodo)->dato);
		free(*nodo);
		*nodo = NULL;
	}else{
		puts("Sin datos!!!");
	}
}