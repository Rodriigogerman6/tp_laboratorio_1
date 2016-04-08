#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int opcionValida;
    signed int x=0;
    signed int y=0;
    int factorialFinal;
    int esNumero;
    int flagPrimerOperando=0;
    int flagSegundoOperando=0;

    while(seguir=='s')
    {
        system("cls");
        fflush(stdin);
        printf("                                     CALCULADORA\n");
        printf("\n");
        printf("                              Seleccione la opcion deseada\n");
        printf("\n");
        printf("\n");
        printf("   1- Ingresar 1er operando (A=%i)\n",x);
        printf("\n");
        printf("   2- Ingresar 2do operando (B=%i)\n",y);
        printf("\n");
        printf("   3- Calcular la suma (A+B)\n");
        printf("\n");
        printf("   4- Calcular la resta (A-B)\n");
        printf("\n");
        printf("   5- Calcular la division (A/B)\n");
        printf("\n");
        printf("   6- Calcular la multiplicacion (A*B)\n");
        printf("\n");
        printf("   7- Calcular el factorial (A!)\n");
        printf("\n");
        printf("   8- Calcular todas las operaciones\n");
        printf("\n");
        printf("   9- Salir\n");
        printf("\n");
        printf("Opcion seleccionada: ");
        opcionValida = scanf("%d",&opcion);
        if(!opcionValida || opcion<1 || opcion>9)
            {
             printf("\nERROR. La opcion seleccionada no es valida\n\n");
             system("pause");
            }

            switch(opcion)
            {
                case 1:
                    system("cls");
                    printf("Ingrese el primer operando ");
                    esNumero = scanf("%d", &x);
                    while(!esNumero)
                    {
                        printf("Reingrese el primer operando ");
                        esNumero = scanf("%d", &x);
                    }
                    flagPrimerOperando=1;
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("Ingrese el segundo operando ");
                    esNumero = scanf("%d", &y);
                    while(!esNumero)
                    {
                        printf("Reingrese el segundo operando ");
                        esNumero = scanf("%d", &y);
                    }
                    flagSegundoOperando=1;
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    if(flagPrimerOperando && flagSegundoOperando)
                    {
                        sumar(x, y);
                    }
                    else
                    {
                        printf("ERROR. Ingrese ambos operandos\n");
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    if(flagPrimerOperando && flagSegundoOperando)
                    {
                        restar(x, y);
                    }
                    else
                    {
                        printf("ERROR. Ingrese ambos operandos\n");
                    }
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    if(flagPrimerOperando && flagSegundoOperando)
                    {
                        dividir(x, y);
                    }
                    else
                    {
                        printf("ERROR. Ingrese ambos operandos\n");
                    }
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    if(flagPrimerOperando && flagSegundoOperando)
                    {
                        multiplicar(x, y);
                    }
                    else
                    {
                        printf("ERROR. Ingrese ambos operandos\n");
                    }
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    if(flagPrimerOperando && flagSegundoOperando)
                    {
                        factorialFinal = factorial(x)+factorial(y);
                        printf("El factorial de %d es: %d\n", x, factorial(x));
                        printf("El factorial de %d es: %d\n", y, factorial(y));
                        printf("El factorial de %d mas el de %d es: %d\n", x, y, factorialFinal);
                    }
                    else
                    {
                        printf("ERROR. Ingrese ambos operandos\n");
                    }
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    if(flagPrimerOperando && flagSegundoOperando)
                    {
                        sumar(x, y);
                        restar(x, y);
                        dividir(x, y);
                        multiplicar(x, y);
                        printf("El factorial de %d es: %d\n", x, factorial(x));
                        printf("El factorial de %d es: %d\n", y, factorial(y));
                        printf("El factorial de %d mas el de %d es: %d\n", factorial(x), factorial(y), factorialFinal);
                    }
                    else
                    {
                        printf("ERROR. Ingrese ambos operandos\n");
                    }
                    system("pause");
                    break;
                case 9:
                    seguir = 'n';
                    break;
            }
    }
    return 0;

}
