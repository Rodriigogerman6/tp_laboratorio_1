#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
/**
 * Inicializa el array lista con todos los espacios vacios.
 * @param lista el array se pasa como parametro.
 */
int inicializarLista(eMovie* movie, int cantidad)
{
    int retorno = -1;
    int i;
    if(movie!=NULL)
    {
        retorno = 0;
        for(i=0;i<cantidad;i++)
        {
            movie[i].estado = 0;
        }

    }
    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(eMovie* movie, int cantidad)
{
    int indice = -1;

    for(int i=0;i<cantidad;i++)
    {
        if(movie[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/**
 * Obtiene el indice del titulo que fue buscado.
 * @param lista el array se pasa como parametro.
 * @return el indice ocupado.
 */
int buscarPorTitulo(eMovie* movie, int cantidad, char* titulo)
{
    int retorno = -1;

   for(int i=0;i<cantidad;i++)
        {

            if(movie[i].estado == 1 && strcmp(movie[i].titulo, titulo)==0)
            {
                retorno = i;
                break;
            }
        }
    return retorno;
}
/**
 * Inicializa el archivo binario.
 * @param movie el array se pasa como parametro.
 * @param cantidad se pasa como parametro
 */
int cargarBin(eMovie* movie, int cantidad)
{
    FILE* bin;
    int retorno = -1;
    bin = fopen("bin.dat", "r");

    if(bin == NULL)
    {
        printf("No se puede abrir el fichero\n");
        //exit(1);
    }
    else
    {
        if(fread(movie, sizeof(eMovie), cantidad, bin))
        {
            retorno = 0;
            fclose(bin);
        }
    }
    return retorno;
}
/**
 * Cierra el archivo binario.
 * @param movie el array se pasa como parametro.
 * @param cantidad se pasa como parametro
 */
int guardarBin(eMovie* movie, int cantidad)
{
    FILE* bin;
    int retorno= -1;
    bin = fopen("bin.dat", "wb");
    if(bin!=NULL)
    {
    fwrite(movie, sizeof(eMovie), cantidad, bin);
    retorno=0;
    fclose(bin);
    printf("Fichero guardado");
    }
    return retorno;
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie* movie, int cantidad)
{
    int retorno = -1;
    int indice;
    char titulo[100];
    char genero[100];
    int duracion;
    int puntaje;
    char descripcion[4096];
    char linkImagen[100];

    if(movie!=NULL)
    { indice = obtenerEspacioLibre(movie, cantidad);
        if(indice!= -1)
        {
            getString(titulo, "Ingrese titulo: ", 1, 50);
            strcpy(movie[indice].titulo, titulo);
            getString(genero, "Ingrese genero: ", 1, 20);
            strcpy(movie[indice].genero, genero);
            getInt(&duracion, "Ingrese duracion: ","Error. Reingrese duracion", 1, 500);
            movie[indice].duracion = duracion;
            getString(descripcion, "Ingrese descripcion: ", 1, 5000);
            strcpy(movie[indice].descripcion, descripcion);
            getInt(&puntaje, "Ingrese puntaje: ", "ERROR. Reingrese puntaje", 1, 10);
            movie[indice].puntaje = puntaje;
            getString(linkImagen, "Ingrese link: ", 1, 500);
            strcpy(movie[indice].linkImagen, linkImagen);
            movie[indice].estado = 1;
            retorno = 0;
            printf("Pelicula cargada");
        }
        else
        {
             printf("Pelicula ya cargada o inexistente\n");
        }


    }
    return retorno;
}
/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie* movie, int cantidad)
{
    int retorno = -1;
    int indice;
    char titulo[50];
    system("cls");
    if(movie!=NULL)
    {
        getString(titulo,"Pelicula a borrar:",1,50);

        indice = buscarPorTitulo(movie, cantidad, titulo);
            if(indice != -1)
            {
                movie[indice].estado = 0;
                retorno = 0;
                printf("El borrado fue exitoso\n");
            }
    }
    return retorno;
}

/**
 *\brief busca una pelicula por nombre para modificarla
 *\param movie array a utilizar
 *\param Largo del array
 *\return -1 si fallo algo 0=OK.
 */
int modificarPelicula(eMovie* movie,int cantidad)
{
    int retorno=-1;
    int opcion;
    int indice;
    char auxChar[50];

    if(movie!=NULL&& cantidad >0)
    {
        getString(auxChar,"Ingrese el titulo a modificar:",1,50);
        indice = buscarPorTitulo(movie, cantidad, auxChar);
        if(indice!=-1)
        {
            do
            {
                getInt(&opcion,"Opciones a modificar:\n1-Titulo\n2-Genero\n3-Duracion\n4-Descripcion\n5-Puntaje\n6-Imagen\n7-SALIR\nOpcion:","Opcion no valida 1-7\n",1,7);
                switch(opcion)
                {
                case 1:
                    printf("Titulo actual: %s\n",movie[indice].titulo);
                    getString(movie[indice].titulo,"Nuevo titulo:",1,50);
                    break;
                case 2:
                    printf("Genero actual: %s\n",movie[indice].genero);
                    getString(movie[indice].genero,"Nuevo genero:",1,16);
                    break;
                case 3:
                    printf("Duracion actual:%d\n",movie[indice].duracion);
                    getInt(&movie[indice].duracion,"Nueva duracion:","1-10000",1,10000);
                    break;
                case 4:
                    printf("Descripcion actual: %s\n",movie[indice].descripcion);
                    getString(movie[indice].descripcion,"Nueva descripcion:",1,9000);
                    break;
                case 5:
                    printf("Puntaje actual:%d\n",movie[indice].puntaje);
                    getInt(&movie[indice].puntaje,"Nuevo puntaje:","1-10",1,10);
                    break;
                case 6:
                    printf("Imagen actual: %s\n",movie[indice].linkImagen);
                    getString(movie[indice].linkImagen,"Nueva Imagen(Link):",1,200);
                    break;
                }
            }
            while(opcion!=7);
        }
        else
        {
            printf("No esta registrada esa pelicula\n");
        }
    }
   return retorno;
}


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
int generarPagina(eMovie* movie, int cantidad)
{
     FILE* html;
     html=fopen("Movies.html","w");
     int i;
     int retorno=-1;

     if(html!=NULL)
     {
         fprintf(html,"\n<!DOCTYPE html>");
         fprintf(html,"\n<!-- Template by Quackit.com -->");
         fprintf(html,"\n<html lang='en'>");
         fprintf(html,"\n<head>");
         fprintf(html,"\n    <meta charset='utf-8'>");
         fprintf(html,"\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>");
         fprintf(html,"\n    <meta name='viewport' content='width=device-width, initial-scale=1'>");
         fprintf(html,"\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->");
         fprintf(html,"\n    <title>Lista peliculas</title>");
         fprintf(html,"\n    <!-- Bootstrap Core CSS -->");
         fprintf(html,"\n    <link href='css/bootstrap.min.css' rel='stylesheet'>");
         fprintf(html,"\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->");
         fprintf(html,"\n    <link href='css/custom.css' rel='stylesheet'>");
         fprintf(html,"\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->");
         fprintf(html,"\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->");
         fprintf(html,"\n    <!--[if lt IE 9]>");
         fprintf(html,"\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>");
         fprintf(html,"\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>");
         fprintf(html,"\n    <![endif]-->");
         fprintf(html,"\n</head>");
         fprintf(html,"\n<body>");
         fprintf(html,"\n    <div class='container'>");
         fprintf(html,"\n        <div class='row'>");
         for(i=0; i<cantidad; i++)
         {
             if(movie[i].estado==1)
             {
                 fprintf(html,"\n			<!-- Repetir esto para cada pelicula -->");
                 fprintf(html,"\n            <article class='col-md-4 article-intro'>");
                 fprintf(html,"\n                <a href='#'>");
                 fprintf(html,"\n                    <img class='img-responsive img-rounded' src='%s' alt=''>",movie[i].linkImagen);
                 fprintf(html,"\n                </a>");
                 fprintf(html,"\n                <h3>");
                 fprintf(html,"\n                    <a href='#'>%s</a>",movie[i].titulo);
                 fprintf(html,"\n                </h3>");
                 fprintf(html,"\n				<ul>");
                 fprintf(html,"\n					<li>Genero:%s</li>",movie[i].genero);
                 fprintf(html,"\n					<li>Puntaje:%d</li>",movie[i].puntaje);
                 fprintf(html,"\n					<li>Duracion:%d</li>	",movie[i].duracion);
                 fprintf(html,"\n				</ul>");
                 fprintf(html,"\n                <p>%s</p>",movie[i].descripcion);
                 fprintf(html," \n          </article>");
                 fprintf(html,"	\n		<!-- Repetir esto para cada pelicula -->");
             }
         }
         fprintf(html,"    </div>");
         fprintf(html,"        <!-- /.row -->");
         fprintf(html,"    </div>");
         fprintf(html,"    <!-- /.container -->");
         fprintf(html,"    <!-- jQuery -->");
         fprintf(html,"    <script src='js/jquery-1.11.3.min.js'></script>");
         fprintf(html,"    <!-- Bootstrap Core JavaScript -->");
         fprintf(html,"    <script src='js/bootstrap.min.js'></script>");
         fprintf(html,"	<!-- IE10 viewport bug workaround -->");
         fprintf(html,"	<script src='js/ie10-viewport-bug-workaround.js'></script>");
         fprintf(html,"	<!-- Placeholder Images -->");
         fprintf(html,"	<script src='js/holder.min.js'></script>");
         fprintf(html,"</body>");
         fprintf(html,"</html>");
         retorno=0;
     }
     fclose(html);
     return retorno;
}
/**
*
*\brief Solicita un string que sea solo letras
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* message Mensaje de solicitud para la cadena
*\param int lengthMin Minimo de caracteres que debe poseer la cadena
*\param int lengthMax maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/

int getString(char *input,char* message,int intMin,int intMax )
{
     char auxChar[4096];
     int retorno=-1;

     if(input!=NULL&& intMin>=0)
     {
         printf("%s",message);
         setbuf(stdin,NULL);
         gets(auxChar);
         if(strlen(auxChar)<intMax &&strlen(auxChar)>intMin )
         {
             strcpy(input,auxChar);
             retorno=0;
         }
         else
         {
             if(strlen(auxChar)<intMin || strlen(auxChar)>intMax)
             {
                 printf("La cadena es demasiado larga o demasiado corta\n");
             }

         }
     }
     return retorno;
}
/**
*\brief Solicita un string que sea solo numeros
*\param char* input Puntero pasado por parametro donde guardar la cadena despues de validada
*\param char* message Mensaje de solicitud para la cadena
*\param char* errorMessage Mensaje en caso de error
*\param int lengthMin Limite minimo de caracteres que debe poseer la cadena
*\param int lengthMax Limite maximo de acaracteres que debe poseer la cadena
*\return int  0 si OK -1 si no se pudo realizar
*/
int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange)
{
     char aux[500];
     int retorno=-1;
     int intAux;

     printf("%s", message);
     gets(aux);

     if ( strcmp(aux,"0\0")==0)
     {
         intAux = atoi(aux);
         retorno = 0;
         *input = intAux;
     }
     else
     {
         intAux = atoi(aux);
         if(intAux != 0)
         {
             if(intAux >= lowLimitRange && intAux <= hiLimitRange )
             {
                 retorno = 0;
                 *input = intAux;
             }
             else
             {
                 printf("%s", errorMessage);
             }
         }
         else
         {
             printf("%s", errorMessage);
         }


     }
    return retorno;
}

