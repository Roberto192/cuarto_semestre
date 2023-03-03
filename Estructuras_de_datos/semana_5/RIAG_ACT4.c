//			Actividad  4
//			Alumno:  Roberto isaac arias guerrero Matricula:  1292118
/*			Descripcion: 
Lista dinamica ordenada, y no repetidos
*/
//			Fecha:  3/3/2023
#include "Structs.h"
#include "menu.h"

int main(){

	srand(time(NULL));

	Tdato lista = NULL, nodo = NULL, ultimo = NULL;
	int op = 0;

	while((op = menu()) != 3){

		switch (op)
		{
		case 1:
			nodo = get_nodo();
			add_list(&lista, &ultimo, &nodo);
			break;
		
		case 2:
			imprimir(lista);
			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}
