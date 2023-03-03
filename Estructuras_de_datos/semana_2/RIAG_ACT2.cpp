//			Actividad  2
//			Alumno:  Roberto isaac arias guerrero Matricula:  1292118
/*			Descripcion: 
			Laboratorio tama�os de variables
*/
//			Fecha:  10/02/2023
#include <stdio.h>
#include <stdlib.h>

int main(){
	int vect[10];
	char cod[30] = "Hola mundo";

	printf("bool: %d\n", sizeof(bool));
	printf("short: %d\n", sizeof(short));
	printf("char: %d\n", sizeof(char));
	printf("int: %d\n", sizeof(int));
	printf("float: %d\n", sizeof(float));
	printf("long: %d\n", sizeof(long));
	printf("double: %d\n", sizeof(double));
	printf("long int: %d\n", sizeof(long int));
	printf("long long: %d\n", sizeof(long long));
	printf("long double: %d\n", sizeof(long double));
	printf("long long int: %d\n", sizeof(long long int));
	printf("vect: %d\n", sizeof(vect));
	printf("cadena: %d\n", sizeof(cod));

	return 0;
}
