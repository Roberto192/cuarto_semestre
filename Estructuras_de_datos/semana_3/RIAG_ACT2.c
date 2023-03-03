//			Actividad  2
//			Alumno:  Roberto isaac arias guerrero Matricula:  1292118
/*			Descripcion: 
				Estructuras LIFO - PILAS realizar 2 menus de pilas uno de forma dinamica y otra estatica
				realizar un programa que calcule el factorial con el uso de pilas
*/
//			Fecha:  12/02/2023
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 10
#define MIN_INDEX -1

typedef struct _tdato{
	int dato;
	struct _tdato *sig;
}sTdato;

typedef struct _tReg{
	int dato;
}Treg;

typedef sTdato *Tdato;

Tdato reservarMem(){
	return (Tdato) malloc(sizeof(sTdato));
}

void push(Tdato *pila, int n){
	Tdato nuevo = NULL;
	nuevo = reservarMem();
	nuevo->dato = n;
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

void pushE(Treg *reg, int dato, int *index){
	int i = (*index);
	if((*index) < MAX_INDEX){
		if((*index) >= MIN_INDEX){
			(*index) = i + 1;
			reg[i + 1].dato = dato;
		}else{
			puts("Pila corrupta");
		}
	}else{
		puts("Pila llena dato no guardado haga un pop!!!");
	}
}

int popE(Treg *reg, int *index){
	int valor = MIN_INDEX;
	int i = (*index);
	
	if((*index) > valor){
		(*index) = i - 1;
		valor = reg[i].dato;
	}else{
		puts("Pila vacia!!!");
	}

	return valor;
}

void servicio(Tdato nodo){
	system("cls");
	printf("Dato -> %d\n", nodo->dato);
	system("pause");
}

int readInt(){
	int i = 0;
	char c;
	char buff[30];

	puts("Ingrese el numero:");
	while((c = getc(stdin)) != '\n')
		buff[i++] = c;

	buff[i] = '\0';
	return atoi(buff);
}

void factorial(){
	Tdato pila = NULL, temp = NULL;
	int i, fac;
	int res = 1;

	fac = readInt();

	puts("Agregando dato");
	printf("NULL ");
	for(i = 0; i < fac; i++){
		push(&pila, fac - i);
		printf("<- [%d] ", fac - i);
	}

	putchar('\n');
	puts("Resolviendo");
	while(pila){
		temp = pop(&pila);
		res *= temp->dato;
		printf("[%d] * "  , temp->dato);
		free(temp);
	}
	printf("= [%d]\n",res);
	
}

int menu(){
	puts("1.- POP");
	puts("2.- PUSH");
	puts("3.- SALIR");
	return readInt();
}

int menuwu(){
	puts("1.- DINAMICA");
	puts("2.- FACTORIAL");
	puts("3.- ESTATICA");
	puts("4.- SALIR");
	return readInt();
}

void menuPilaDinamica(){
	int op = 0;
	Tdato pila = NULL, temp = NULL;

	while(op != 3){	
		op = menu();
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
				push(&pila, rand() % 100);
				break;
		}
	}

	while(pila){
		temp = pop(&pila);
		servicio(temp);
		free(temp);
	}

}

void menuPilaEstatica(){
	int opcion = 0;
	Treg reg[10];
	int index = -1;

	while(opcion != 3){
		printf("Index: %d\n",index);
		opcion = menu();
		switch (opcion)
		{
		case 1:
			printf("Dato -> [%d]\n", popE(reg, &index));
			break;
		case 2:
			puts("Ingrese el valor a guardad");
			pushE(reg, readInt(), &index);
			break;
		
		}
		system("pause");
		system("cls");
	}
}

int main(){

	//
	//menuPilaEstatica();

	int opcion = 0;
	Treg reg[10];
	int index = -1;

	while(opcion != 4){
		opcion = menuwu();
		switch (opcion)
		{
		case 1:
			menuPilaDinamica();
			break;
		case 2:
			factorial();
			break;
		case 3:
			menuPilaEstatica();
			break;
		
		}
		system("pause");
		system("cls");
	}


	return 0;
}
