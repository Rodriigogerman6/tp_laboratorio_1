#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define TAM 5

int main()
{
    char seguir='s';
    int opcion=0;
    int flagEstado = 0;
    eMovie movie[TAM];

    inicializarLista(movie, TAM);
    cargarBin(movie, TAM);
    while(seguir=='s')
    {
        printf("---------MENU----------\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
                case 1:
                        system("cls");
                        agregarPelicula(movie, TAM);
                        break;
                case 2:
                        system("cls");
                        borrarPelicula(movie, TAM);
                        break;
                case 3:
                        system("cls");
                        modificarPelicula(movie, TAM);
                        break;
                case 4:
                        system("cls");
                        generarPagina(movie, TAM);
                        break;
                case 5:
                        guardarBin(movie,TAM);
                        seguir = 'n';
                        break;
                default:
                        system("cls");
                        printf("ERROR. Reingrese opcion valida\n");
                        system("pause");
        }
    }

    return 0;
}
