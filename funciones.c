#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int inicializarLista(EPersona* lista)
{
    int retorno = -1;
    if(lista!=NULL)
    {
        retorno = 0;
        for(int i=0;i<20;i++)
        {
            lista[i].estado = 0;
        }

    }
    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona* lista)
{
    int indice = -1;

    for(int i=0;i<20;i++)
    {
        if(lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEspacioLleno(EPersona* lista)
{
    int retorno = 0;

    for(int i=0;i<20;i++)
    {
        if(lista[i].estado == 1)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}
int pedirDni(void)
{
    int dni;
    system("cls");
    fflush(stdin);
    printf("Ingrese DNI: \n");
    while(!scanf("%d", &dni) || dni<1 || dni>999999990)
    {
        fflush(stdin);
        printf("ERROR. Vuelva a ingresar DNI: \n");
    }
    return dni;
}

void pedirNombre(char nombre[])
{
    char aux[70];

    fflush(stdin);
    printf("Ingrese nombre: \n");
    scanf("%s", aux);
    while(strlen(aux)>50)
    {
        fflush(stdin);
        printf("ERROR. Vuelva a ingresar nombre: \n");
        scanf("%s", aux);
    }
    strcpy(nombre, aux);
}

int pedirEdad(void)
{
    int edad;

    fflush(stdin);
    printf("Ingrese edad: \n");
    while(!scanf("%d", &edad) || edad<0 || edad>100)
    {
        fflush(stdin);
        printf("ERROR. Vuelva a ingresar edad: \n");
    }
    return edad;
}

/**
 * Agrega a una persona a la lista realizada.
 * @param lista el array se pasa como parametro.
 * @param nombre el nombre de la persona ingresada.
 * @param edad la edad de la persona ingresada.
 * @param estado el estado del indice ingresado.
 * @param dni el dni de la persona ingresada.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int agregarPersona(EPersona* lista, char nombre[], int edad, int dni)
{
  int retorno = -1;
  int indice;

    if(lista!=NULL)
    {
        indice = obtenerEspacioLibre(lista);

        if(indice!=-1)
        {
            lista[indice].dni = dni;
            strcpy(lista[indice].nombre, nombre);
            lista[indice].edad = edad;
            lista[indice].estado = 1;
            retorno = 0;
        }

    }
    return retorno;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int eliminarPersona(EPersona* lista, int dni)
{
    int retorno = -1;
    system("cls");

    if(lista!=NULL)
    {
        for(int i=0;i<20;i++)
        {
            if(lista[i].estado == 1 && lista[i].dni == dni)
            {
                lista[i].estado = 0;
                retorno = 0;
                printf("El borrado fue exitoso\n");
                break;
            }
        }
    }
    return retorno;
}

/**
 * Ordena un array por nombre, que puede ser tanto ascendente como descendente.
 * @param lista el array se pasa como parametro.
 * @param cuando la variable orden esta en 0 la lista sera ordenada de forma ascendente.
 * @param cuando la variable orden esta en 1 la lista sera ordenada de forma descendente.
 * @return el array lista ordenado de la forma deseada.
 */

 void ordenarPorNombre(EPersona* lista)
 {
     int i;
     int j;
     EPersona aux;;

     for(i=0;i<19;i++)
     {
         for(j=i+1;j<20;j++)
         {
             if(strcmp(lista[i].nombre, lista[j].nombre)>0)
             {
                 aux = lista[i];
                 lista[i] = lista[j];
                 lista[j] = aux;
             }
         }
     }
      printf("\n DNI  -  Nombre          - Edad \n");
     for(i=0; i<20; i++)
     {
         if(lista[i].estado)
         {
             printf(" %d  - %s          -  %d\n", lista[i].dni, lista[i].nombre, lista[i].edad);
         }
     }
 }

/**
 * Realiza un grafico entre las personas menores a 18 años, las que estan entre 19 y 35 y las mayores a 35
 * @param contador utilizado para las personas menores a 18 años
 * @param contador utilizado para las personas entre 19 y 35 años
 * @param contador utilizado para las personas mayores a 35 años
 * @param la primera barra estadistica indica la cantidad de personas menores a 18 años con un asterisco (*)
 * @param la segunda barra estadistica indica la cantidad de personas de entre 19 a 35 años con un asterisco (*)
 * @param la tercera barra estadistica indica la cantidad de personas mayores a 35 años con un asterisco (*)
 */
void graficoEdades(EPersona* lista)
{
    int i;
    int contadorMenores = 0;
    int contadorMedios = 0;
    int contadorMayores = 0;
    char barraMenores[20];
    char barraMedios[20];
    char barraMayores[20];

    for(i=0;i<20;i++)
    {
        if(lista[i].estado)
        {
            if(lista[i].edad<18)
            {
                contadorMenores++;
            }
            else
            if(lista[i].edad>=18 && lista[i].edad<=35)
            {
                contadorMedios++;
            }
            else
            {
                contadorMayores++;
            }
        }
    }
    for(i=0;i<20;i++)
    {
        if(i<contadorMenores)
        {
            barraMenores[i]='*';
        }
        else
        {
            barraMenores[i]=' ';
        }
        if(i<contadorMedios)
        {
            barraMedios[i]='*';
        }
        else
        {
            barraMedios[i]=' ';
        }
        if(i<contadorMayores)
        {
            barraMayores[i]='*';
        }
        else
        {
            barraMayores[i]=' ';
        }
    }
        for(i = 20;i>0;i--)
        {
            printf("   |%c|   |%c|   |%c|\n", barraMenores[i-1], barraMedios[i-1], barraMayores[i-1]);
        }
        printf(" |<18| |18-35| |>35|\n");
}


