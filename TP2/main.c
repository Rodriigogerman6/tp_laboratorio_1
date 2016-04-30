#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{

    EPersona lista[20];
    char nombre[50];
    int edad;
    int dni;
    char seguir = 's';
    int opcion = 0;
    int flagEstado = 0;

    fflush(stdin);
    inicializarLista(lista);

    while(seguir=='s')
    {
        system("cls");
        fflush(stdin);
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        printf("Ingrese opcion: ");
        scanf("%d",&opcion);

                switch(opcion)
                {

                    case 1:
                        system("cls");
                        dni = pedirDni();
                        pedirNombre(nombre);
                        edad = pedirEdad();
                        agregarPersona(lista, nombre, edad, dni);
                        flagEstado = 1;
                        break;
                    case 2:
                        system("cls");
                        if(flagEstado)
                        {
                            dni = pedirDni();
                            while(eliminarPersona(lista, dni)==1)
                            {
                              printf("No hay persona con ese DNI\n");
                              system("pause");
                              dni = pedirDni();
                            }
                            flagEstado = buscarEspacioLleno(lista);
                        }
                        else
                        {
                            printf("Lista vacia\n");
                        }
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        if(flagEstado)
                        {
                            ordenarPorNombre(lista);
                        }
                        else
                        {
                            printf("Lista vacia\n");
                        }
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        if(flagEstado)
                        {
                            graficoEdades(lista);
                        }
                        else
                        {
                            printf("Lista vacia\n");
                        }
                        system("pause");
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
