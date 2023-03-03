//      Actividad 1
//      Author: Roberto Isaac Arias Guerrero Matricula: 1292118
/*
            REALICE EL SIGUIENTE PROGRAMA QUE CONTENGA UN MENÚ.
                MENÚ
                1.- AGREGAR (AUTOM 10 REGISTROS)
                2.- AGREGAR MANUAL
                3.- ELIMINAR REGISTRO (lógico)
                4.- BUSCAR
                5.- ORDENAR
                6- IMPRIMIR
                7.- SALIDA ARCHIVO TEXTO
                8.- CARGAR ARCHIVO TEXTO
                9.- CREAR ARCH BINARIO
                10- CARGAR ARCH BINARIO
                0.- SALIR
            UTILIZAR UN ARREGLO DE 1500 REGISTROS
            SE DEBERÁ UTILIZAR ESTRUCTURAS CON LOS DATOS BÁSICOS DE UN ALUMNO (
            status, Matricula, ApPat, ApMat, Nombre, Edad, Sexo )
            preguntar nombre de archivo binario o de archivo texto
            Busqueda y Ordenacion por campo MATRICULA

*/
//      Fecha: 06/02/2023

#include <stdio.h>
#include <time.h>
#include "structs.h"

#define MAX_ALUMNOS 1500

void printMenu();

int main(int argc, char *argv[])
{

    Talumno alumnos[MAX_ALUMNOS] = {0};
    Tbool ordenado = FALSE;
    int run = TRUE;
    int indice = 0;

    if(argc == 2){
        indice = cargarAlumnosBinarioXnombre(alumnos, MAX_ALUMNOS, argv[1]);
    }

    srand(time(NULL));

    while(run){

        printMenu();
        run = leerEnteroPositivo();
        
        switch (run)
        {
        case 1:
            generarAlumnos(alumnos, MAX_ALUMNOS, indice, indice + 10);
            indice += 10;
            ordenado = FALSE;
            break;
        case 2:
            alumnos[indice++] = generaManualmenteAlumno();
            ordenado = FALSE;
            break;
        case 3:
            buscarAlumno(alumnos, indice, TRUE);
            break;
        case 4:
            buscarAlumno(alumnos, indice, FALSE);
            break;
        case 5:
            ordenar(alumnos, indice, ordenado);
            ordenado = TRUE;
            break;
        case 6:
            printAlumnos(stdout, alumnos, indice);
            break;
        case 7:
            guardarAlumnosTxt(alumnos, indice);
            break;
        case 8:
            verArchivoTxt();
            break;
        case 9:
            guardarAlumnosBinario(alumnos, indice);
            break;
        case 10:
            indice = cargarAlumnosBinario(alumnos, MAX_ALUMNOS);
            break;
        
        }

        puts("Operacion exitosa...");
        system("pause");

    }

    return 0;
}

void printMenu(){

    system("cls");
    puts(   "MENÚ\n"
            "1.- AGREGAR\n"
            "2.- AGREGAR MANUAL\n"
            "3.- ELIMINAR REGISTRO\n"
            "4.- BUSCAR\n"
            "5.- ORDENAR\n"
            "6- IMPRIMIR\n"
            "7.- SALIDA ARCHIVO TEXTO\n"
            "8.- CARGAR ARCHIVO TEXTO\n"
            "9.- CREAR ARCH BINARIO\n"
            "10- CARGAR ARCH BINARIO\n"
            "0.- SALIR\n"
        );
}
