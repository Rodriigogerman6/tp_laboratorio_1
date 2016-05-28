#ifndef __EMOVIE
#define __EMOVIE

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[50];
    int estado;
}eMovie;
#endif // __EMOVIE

#ifndef FUNCIONES_H_CLUDED
#define FUNCIONES_H_INCLUDED

int inicializarLista(eMovie* movie, int cantidad);
int obtenerEspacioLibre(eMovie* movie, int cantidad);
int buscarEspacioLleno(eMovie* movie, int cantidad);
int cargarBin(eMovie* movie, int cantidad);
int guardarBin(eMovie* movie, int canidad);
int agregarPelicula(eMovie* movie, int cantidad);
int borrarPelicula(eMovie* movie, char* titulo);
int modificarPelicula(eMovie* movie,int cant);
int generarPagina(eMovie* movie, int cantidad);
int getString(char *input,char* message,int intMin,int intMax );
int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange);


#endif // FUNCIONES_H_INCLUDED
