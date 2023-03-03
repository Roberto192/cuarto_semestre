//			Actividad  2.1
//			Alumno:  roberto isaac arias guerrero Matricula:  1292118
/*			Descripcion: 
pilas
*/
//			Fecha:  10/02/2023
#include <stdio.h>
#include <stdlib.h>


typedef struct _tdato{
	int dato;
	struct _tdato *sig;
}sTdato;

typedef sTdato *Tdato;

void push(Tdato *pila){
	Tdato nuevo = NULL;
	nuevo = (Tdato) malloc(sizeof(sTdato));
	nuevo->dato = rand() % 100;
	nuevo->sig = (*pila);
	(*pila) = nuevo;
}

Tdato pop(Tdato *pila){
	Tdato temp = NULL;
	if(*pila){	
		temp = (*pila);
		*pila = (temp->sig);
	}

	return temp;
}

void servicio(Tdato nodo){
	system("cls");
	printf("Dato -> %d\n", nodo->dato);
	system("pause");
}

void menu(){
	int op = 0;
	Tdato pila = NULL, temp = NULL;

	while(op != 3){	
		puts("1.- POP");
		puts("2.- PUSH");
		puts("3.- SALIR");
		scanf("%d",&op);
		switch(op){
			case 1:
				temp = pop(&pila);
				if(temp){
					servicio(temp);
					free(temp);
				}else{
					puts("Pila vacia");
				}
				break;
			case 2:
				push(&pila);
				break;
		}
	}

}

int main(){

	menu();

	return 0;
}
