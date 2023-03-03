#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define MIN 0

typedef struct _tdato{

    int dato;
    struct _tdato *sig;

}sTdato;

typedef sTdato * Tdato;

Tdato get_nodo();
void PUSH(Tdato *, Tdato *, int);
Tdato POP(Tdato *, Tdato *);
void servicio(Tdato , const char *);
void add_list(Tdato *lista, Tdato *ultimo, Tdato *nuevo);
void imprimir(Tdato lista);