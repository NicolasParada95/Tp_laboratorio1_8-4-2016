#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    EMovie movie[C];

    char seguir='s';
    int opcion=0;
    FILE *P;

    P=fopen("datos.dat","rb+");

    if(P==NULL)
        {
            P=fopen("datos.dat","wb+");
        }

    while(seguir=='s')
    {
        printf("1- Agregar pelicula   \n");
        printf("2- Borrar pelicula    \n");
        printf("3- modificar pelicula \n");
        printf("4- Generar pagina web \n");
        printf("5- Salir              \n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(movie,P);
                break;
            case 2:
                system("cls");
                borrarPelicula(movie,P);
                break;
            case 3:
                system("cls");
                ModificarPelicula(movie,P);
                break;
            case 4:
                system("cls");
                GenerarPagina(movie);
                break;
            case 5:
                system("cls");
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Error, reingrese un numero del 1 al 5.");
                break;
        }
    }

    fclose(P);
    return 0;
}
