#include <stdio.h>
#include <stdlib.h>
#include ""
#include <string.h>
#define TAM 5

int main()
{
    char seguir='s';
    int opcion=0;
    int flagEstado = 0;
    eMovie* movie[TAM];

    inicializarLista(movie, TAM);
    cargarBin(movie, TAM);
    while(seguir=='s')
    {
        printf("---------MENU----------");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
                case 1:
                        agregarPelicula(movie, TAM);
                        break;
                case 2:
                        borrarPelicula(movie, TAM);
                        break;
                case 3:
                        modificarPelicula(movie, TAM);
                        break;
                case 4:
                        generarPagina(movie, TAM);
                        break;
                case 5:
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
