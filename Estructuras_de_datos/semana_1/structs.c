#include "structs.h"

Tmatricula leerMatricula(){
    return (Tmatricula) validarNumeroLCR("Ingrese el numero de la matricula: ", "Ingrese una matricula correcta", 1, 100000, 99999999);
}

char *TmatriculaAcadena(char *cadena, int size_cadena, Tmatricula matricula){

    snprintf(cadena, size_cadena, "%lu", matricula);

    return cadena;
}

char *getSexo(enum SEXO sexo){
    static Tnombre sexoString;
    if(sexo == HOMBRE){
        return strcpy(sexoString, "HOMBRE");
    }

    if(sexo == MUJER){
        return strcpy(sexoString, "MUJER");
    }

    if(sexo == NO_ESPECIFICADO){
        return strcpy(sexoString, "NO_ESPECIFICADO");
    }
}

void printAlumno(Talumno alumno){
   if(alumno.status){
        system("cls");
        printf("Nombre Completo: %s %s %s\n", alumno.nombre, alumno.apellido_paterno, alumno.apellido_materno);
        printf("Matricula: %012lu\n",alumno.matricula);
        printf("Edad: %d\n", alumno.edad);
        printf("Sexo: %s\n", getSexo(alumno.sexo));
        printf("Status: %s\n", (alumno.status == 1)? "Activo" : "Inactivo");
   }
}

void printAlumnos( FILE *file, Talumno *alumnos, int size_alumnos){
    int i;
    fprintf(file, "| INDEX | MATRICULA    | %-20s %-20s %-20s | EDAD | %15s |\n", "Nombre/s", "Apellido Paterno", "Apellido Materno", "SEXO");
    for(i = 0; i < size_alumnos; i++){
        if(alumnos[i].status)
            fprintf(file,"| %05d | %012lu | %-20s %-20s %-20s | %04d | %15s |\n", i, alumnos[i].matricula, alumnos[i].nombre, alumnos[i].apellido_paterno, alumnos[i].apellido_materno, alumnos[i].edad, getSexo(alumnos[i].sexo));
    }
}

Talumno getRandomAlumno(){
    Tnombre nombresDeHombre[9] = {"Roberto\0", "Azael\0", "Gonzalo\0", "Pedro\0", "Armando\0", "Martin\0", "Angel\0", "Gabriel\0"};
    Tnombre nombresDeMujer[9] = {"Roberta\0", "Azaela\0", "Gonzala\0", "Pedra\0", "Armanda\0", "Martina\0", "Angela\0", "Gabriela\0"};
    Tnombre nombresDeBinarie[9] = {"Roberte\0", "Azaele\0", "Gonzale\0", "Pedre\0", "Armande\0", "Martine\0", "Angele\0", "Gabriele\0"};
    Tnombre apellidos[9] = {"Guerrero\0", "Banda\0", "Hernandez\0", "Sanchez\0", "Gonzales\0", "Ramirez\0", "Espinoza\0", "Paz\0"};
    
    Talumno alumno;

    alumno.sexo = rand() % 3;

    if(alumno.sexo == HOMBRE){
        strcpy(alumno.nombre, nombresDeHombre[rand() % 8]);
    }else{
        if(alumno.sexo == MUJER){
            strcpy(alumno.nombre, nombresDeMujer[rand() % 8]);
        }else{
            strcpy(alumno.nombre, nombresDeBinarie[rand() % 8]);
        }
    }

    strcpy(alumno.apellido_paterno, apellidos[rand() % 8]);
    strcpy(alumno.apellido_materno, apellidos[rand() % 8]);
    
    alumno.edad = (rand() % 20) + 18;
    alumno.matricula = ((rand() % 10) * 1000000) + ((rand() % 10) * 100000) + ((rand() % 10) * 10000) + ((rand() % 10) * 1000) + (rand() % 1000);

    alumno.status = TRUE;

    return alumno;
}

void generarAlumnos(Talumno *alumnos, int size_alumnos, int desde, int hasta){
    int i;
    if(alumnos != NULL){
        if(hasta < size_alumnos){
            for (i = desde; i < hasta; i++)
            {
                alumnos[i] = getRandomAlumno();
            }    
        }
    }
}

Talumno generaManualmenteAlumno(){
    Talumno alumno;

    validarTexto("Ingrese el nombre del alumno: ", (char *) alumno.nombre, sizeofTnombre, 2);
    validarTexto("Ingrese el apellido paterno: ", (char *) alumno.apellido_paterno, sizeofTnombre, 2);
    validarTexto("Ingrese el apellido materno: ", (char *) alumno.apellido_materno, sizeofTnombre, 2);
    alumno.edad = validarNumeroICR("Ingrese la edad del alumno: ", "Ingrese una edad correcta!!!", 1, 0, 110);
    alumno.matricula = leerMatricula();
    alumno.sexo = validarNumeroICR("Ingrese el sexo:\n0.- HOMBRE\n1.- MUJER\n2.- NO DEFINIDO\n", "Ingrese una opcion valida", 1, 0, 2);
    alumno.status = 1;

    return alumno;
}

Talumno buscarAlumno(Talumno *alumnos, int size_alumnos, Tbool eliminar){
    Tmatricula matricula;
    int i;

    matricula = leerMatricula();
    for(i = 0; i < size_alumnos; i++){
        if(alumnos[i].matricula == matricula){
            printAlumno(alumnos[i]);
            if(eliminar){
                printf("Desea eliminar al alumno: %s %s %s con matricula: %lu (Y/n): ", alumnos[i].nombre, alumnos[i].apellido_paterno, alumnos[i].apellido_materno, matricula);
                if(validarDosCaracteres('y', 'n') != 'n'){
                    alumnos[i].status = FALSE;
                }
            }
            return alumnos[i];
        }
    }
}

void ordenar(Talumno *alumnos, int size_alumnos, Tbool ordenado){
    Talumno alumno;
    int i;
    int j;
    int aux = 0;
    // 5 7 4 2 6 8
    // 2 4 5 6 7 8
    if(!ordenado){
        for(i = 0; i < size_alumnos-1; i++){
            for(j = i+1; j < size_alumnos; j++){
                if(alumnos[i].matricula < alumnos[j].matricula){
                    alumno = alumnos[i];
                    alumnos[i] = alumnos[j];
                    alumnos[j] = alumno;
                }
            }
        }
    }
}

void guardarAlumnosTxt(Talumno *alumnos, int size_alumnos){
    Tnombre nombreArchivo;
    FILE *file;

    validarTexto("Ingrese el nombre del archivo sin la extension: ", nombreArchivo, sizeofTnombre, 2);
    strcat(nombreArchivo, ".txt\0");

    file = fopen(nombreArchivo, "w");

    if(file){
        printAlumnos(file, alumnos, size_alumnos);
    }

    fclose(file);
}

void verArchivoTxt(){
    
    Tnombre nombreArchivo;
    FILE *file;
    char c;

    system("cls");
    system("dir");
    system("pause");
    validarTexto("Ingrese el nombre del archivo sin la extension: ", nombreArchivo, sizeofTnombre, 2);
    strcat(nombreArchivo, ".txt\0");

    file = fopen(nombreArchivo, "r");

    while((c = getc(file)) != EOF)
        putch(c);
    
    fclose(file);
}

void guardarAlumnosBinario(Talumno *alumnos, int size_alumnos){
    Tnombre nombreArchivo;
    FILE *file;
    int i = 0;

    validarTexto("Ingrese el nombre del archivo sin la extension: ", nombreArchivo, sizeofTnombre, 2);
    strcat(nombreArchivo, ".data\0");

    file = fopen(nombreArchivo, "wb");

    if(file){
        while(fwrite(&alumnos[i], sizeof(Talumno), 1, file)){
            i++;
            if(i > size_alumnos){
                break;
            }
        }
    }

    fclose(file);
}

int cargarAlumnosBinario(Talumno *alumnos, int size_alumnos){
    Tnombre nombreArchivo;
    FILE *file;
    int i = 0;

    system("cls");
    system("dir");
    system("pause");
    validarTexto("Ingrese el nombre del archivo sin la extension: ", nombreArchivo, sizeofTnombre, 2);
    strcat(nombreArchivo, ".data\0");

    file = fopen(nombreArchivo, "rb");

    if(file){
        while(fread(&alumnos[i], sizeof(Talumno), 1, file)){
            i++;
            if(i > size_alumnos){
                break;
            }
        }
    }

    fclose(file);
    return i - 1;
}

int cargarAlumnosBinarioXnombre(Talumno *alumnos, int size_alumnos, char *nombreArchivo){
    //Tnombre nombreArchivo;
    FILE *file;
    int i = 0;

    system("cls");
    //system("dir");
    //system("pause");
    //validarTexto("Ingrese el nombre del archivo sin la extension: ", nombreArchivo, sizeofTnombre, 2);
    //strcat(nombreArchivo, ".data\0");

    file = fopen(nombreArchivo, "rb");

    if(file){
        while(fread(&alumnos[i], sizeof(Talumno), 1, file)){
            i++;
            if(i > size_alumnos){
                break;
            }
        }
    }

    fclose(file);
    return i - 1;
}