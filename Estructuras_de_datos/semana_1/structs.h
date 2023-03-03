#include <stdio.h>
#include <stdlib.h>
#include "validar.h"

#define sizeofTnombre 50
#define TRUE 1
#define FALSE 0

typedef unsigned long Tmatricula;
typedef char Tnombre[sizeofTnombre];
typedef unsigned short Tedad;
typedef short Tbool;

enum SEXO {
    HOMBRE,
    MUJER,
    NO_ESPECIFICADO
};

typedef struct _talumno{    //( status, Matricula, ApPat, ApMat, Nombre, Edad, Sexo )

    Tbool status;
    Tmatricula matricula;    
    Tnombre nombre, apellido_paterno, apellido_materno;
    Tedad edad;
    enum SEXO sexo;

}Talumno;

Tmatricula leerMatricula();
char *TmatriculaAcadena(char *cadena, int size_cadena, Tmatricula matricula);
char *getSexo(enum SEXO sexo);
void printAlumno(Talumno alumno);
void printAlumnos(FILE *file, Talumno *alumnos, int size_alumnos);
Talumno getRandomAlumno();
void generarAlumnos(Talumno *alumnos, int size_alumnos, int desde, int hasta);
Talumno generaManualmenteAlumno();
Talumno buscarAlumno(Talumno *alumnos, int size_alumnos, Tbool eliminar);
void ordenar(Talumno *alumnos, int size_alumnos, Tbool ordenado);
void guardarAlumnosTxt(Talumno *alumnos, int size_alumnos);
void verArchivoTxt();
void guardarAlumnosBinario(Talumno *alumnos, int size_alumnos);
int cargarAlumnosBinario(Talumno *alumnos, int size_alumnos);
int cargarAlumnosBinarioXnombre(Talumno *alumnos, int size_alumnos, char *nombreArchivo);