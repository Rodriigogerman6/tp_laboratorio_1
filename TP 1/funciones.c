#include <stdio.h>
#include <stdlib.h>
/** \brief recibe dos n�meros y los suma
* \param x primer n�mero ingresado
* \param y segundo n�mero ingresado
* \param suma almacena el resultado de la operacion
*/
void sumar(int x, int y)
{
     int suma;
     suma=x+y;
     printf("El resultado de la suma es: %d\n", suma);
}
/** \brief recibe dos n�meros y los resta
* \param x primer n�mero ingresado
* \param y segundo n�mero ingresado
* \param resta almacena el resultado de la operacion
*/
void restar(int x, int y)
{
    int resta;
    resta=x-y;
    printf("El resultado de la resta es: %d\n", resta);
}
/** \brief recibe dos n�meros y los multiplica
* \param x primer n�mero ingresado
* \param y segundo n�mero ingresado
* \param multiplicacion almacena el resultado de la operacion
*/
void multiplicar(int x, int y)
{
    int multiplicacion;
    multiplicacion=x*y;
    printf("El resultado de la multiplicacion es: %d\n", multiplicacion);
}
/** \brief recibe dos n�meros y los divide
* \param x primer n�mero ingresado
* \param y segundo n�mero ingresado
* \param division almacena el resultado de la operacion
*/
void dividir(int x, int y)
{
    float division;
    while(y==0)
    {
        printf("No puede dividir por 0, modifique el 2do operando");
        scanf("%d", &y);
    }
    division=(float)x/y;
    printf("El resultado de la division es: %.2f\n", division);
}

/** \brief recibe un n�mero y calcula su factorial usando recursividad
* \return 1 inicia la recursividad multiplicando x por x-1 hasta que el valor de x sea 1
* \return 2 cuando la funcion devuelve 1 se inicia la funcion inversamente ( x * factorial(x-1) )
*/
int factorial(int x)
{
   if(x>1)
   {
       return x * factorial(x-1);
   }
   return 1;
}

