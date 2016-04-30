#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define C 20
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[]);
void alta (EPersona lista[]);
void baja(EPersona lista[]);
void listar(EPersona lista[]);
void grafico(EPersona lista []);


#endif // FUNCIONES_H_INCLUDED
