#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int inicializarLista(EPersona* lista);
int obtenerEspacioLibre(EPersona* lista);
int buscarEspacioLleno(EPersona* lista);
int pedirDni(void);
void pedirNombre(char nombre[]);
int pedirEdad(void);
int agregarPersona(EPersona* lista, char nombre[], int edad, int dni);
int eliminarPersona(EPersona* lista, int dni);
void ordenarPorNombre(EPersona* lista);
void graficoEdades(EPersona* lista);

#endif // FUNCIONES_H_INCLUDED
