#include "menu.h"


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
	puts("1.- Agregar");
	puts("2.- Imprimir");
	puts("3.- SALIR");
	return readInt("Ingrese la opcion:");
}