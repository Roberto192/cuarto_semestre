#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_INT 10
#define MAX_DATE 11
#define MAX_LONG 200

typedef struct _fecha{
  int d;//dia
  int m;//mes
  int a;//año -> years
}TSfecha;

int leerEntero();

unsigned int leerEnteroPositivo();

long leerLargo();

unsigned long leerLargoPositivo();

/*
  0 solo minusculas
  1 solo mayusculas
  2 ambos
*/
void validar(char cadena[], int n, int m);

int validarNumeroISR(char msg[], int positivo);

int validarNumeroICR(char msg[], char msgError[], int positivo, int r1, int r2);

long validarNumeroLCR(char msg[], char msgError[], int positivo, long r1, long r2);

void validarTexto(char msg[], char variable[], int n, int t);

char validarUnCaracter(char valido);

char validarDosCaracteres(char v1, char v2);

//Rango A es la representacion de la fecha minima y Rango B es la maxima
TSfecha validarFecha(TSfecha rangoA, TSfecha rangoB);

TSfecha verificarFecha(TSfecha fecha);

char* obtenerFecha(char fechaCadena[], int t,TSfecha fecha);

char* obtenerMes(char fechaCadena[], int t, TSfecha fecha);

char* obtenerDia(char fechaCadena[], int t, TSfecha fecha);

char* obtenerAnio(char fechaCadena[], int t, TSfecha fecha);

TSfecha obtenerFechaAleatoria(TSfecha rango);