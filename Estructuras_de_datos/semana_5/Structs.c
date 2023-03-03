#include "Structs.h"

Tdato get_nodo(){
    Tdato nodo = (Tdato) malloc(sizeof(sTdato));
    nodo->sig = NULL;
    nodo->dato = rand() % 100;
    return nodo;
}


void servicio(Tdato nodo, const char *msg){
	if(nodo){
		printf(msg, nodo->dato);
	}else{
		puts("Sin datos!!!");
	}
}

void add_list(Tdato *lista, Tdato *ultimo, Tdato *nuevo){
    Tdato temp = NULL;

    if((*lista)){

        if((*nuevo)->dato < (*lista)->dato){
            (*nuevo)->sig = (*lista);
            (*lista) = (*nuevo);
        }else{
            if((*nuevo)->dato > (*ultimo)->dato){
                (*ultimo)->sig = (*nuevo);
                (*ultimo) = (*nuevo);
            }else{
                temp = *lista;
                while((temp)->sig->dato < (*nuevo)->dato){
                    temp = (temp->sig);
                }

                (*nuevo)->sig = temp->sig;
                temp->sig = (*nuevo);
            }
        }
        /**/

    }else{

        (*lista) = (*nuevo);
        (*ultimo) = (*nuevo);

    }
}

void imprimir(Tdato lista){
    Tdato temp = NULL;
    temp = lista;

    while(temp){
        servicio(temp, "El dato es -> %d\n");
        temp = (temp->sig);
    }
}