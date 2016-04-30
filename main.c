#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"
#define C 20
int main()
{
    EPersona lista[C];
    char seguir='s';
    int opcion=0,i;
    for(i=0; i<C; i++)
		lista[i].estado=0;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                alta(lista);
                break;
            case 2:
                system("cls");
                baja(lista);
                break;
            case 3:
                system("cls");
                listar(lista);
                getche();
                break;
            case 4:
                system("cls");
                grafico(lista);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("ingrese un numero del 1 a 5.\n");
                break;
        }
    }

    return 0;
}
