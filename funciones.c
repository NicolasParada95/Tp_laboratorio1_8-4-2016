#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"
#define C 20
int obtenerEspacioLibre(EPersona lista[])
{
    int i;
    for(i=0;i<C;i++)
    {
        lista[i].estado=0;
        lista[i].edad=0;
        lista[i].dni=0;
    }
}

void alta (EPersona lista[])
{
    int i,j;
    long int auxdni;

        for(i=0;i<C;i++)
        {
            if(lista[i].estado==0)
                {
                printf("ingrese nombre: ");
                fflush(stdin);
                gets(lista[i].nombre);
                printf("ingrese edad: ");
                fflush(stdin);
                scanf("%d",&lista[i].edad);
                while(lista[i].edad<1||lista[i].edad>99)
                {
                    printf("Error, reingrese la edad: ");
                    scanf("%d",&lista[i].edad);
                }
                printf("ingrese dni: ");
                fflush(stdin);
                scanf("%ld",&auxdni);
                while(auxdni<1000000||auxdni>99999999)
                    {
                    printf("DNI invalido. Reingrese DNI: ");
                    scanf("%ld",&auxdni);
                    }
                for(j=0;j<C;j++)
                {
                    while(auxdni==lista[j].dni)
                    {
                        printf("Error, DNI existente. Reingrese DNI: ");
                        scanf("%ld",&auxdni);
                    }
                }
                lista[i].dni=auxdni;
                lista[i].estado=1;
                break;
                }
        }
         if(i==C)
                {
                    printf("espacio agotado.\n");
                }

}

int buscarPorDni(EPersona lista[])
{
    int indice,i;
    long int auxdni;
    printf("Ingrese DNI a dar de baja: ");
    scanf("%ld",&auxdni);
    for(i=0;i<C;i++)
    {
        if(auxdni==lista[i].dni)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void baja (EPersona lista[])
{
    int i,auxindice;
    char opcion;

    auxindice=buscarPorDni(lista);

    for(i=0;i<C;i++)
    {
        if(auxindice==i && lista[auxindice].estado==1)
        {
            printf("Persona encontrada. Desea dar de baja? S/N \n");
                opcion=getche();
                if(opcion=='s')
                    {
                            lista[i].estado=0;
                            lista[i].edad=0;
                            lista[i].dni=0;
                            printf("Datos eliminados.\n");
                            break;
                    }
                else
                    {
                        printf("No se eliminaron datos.\n");
                    }
        }
    }
       if(i==C)
        {
            printf("persona no encontrada.\n");
        }
}
void listar (EPersona lista[])
{
    int i,j;
    EPersona auxNombre;

        if(lista[i].estado==0)
            {
                printf("Error, no hay datos cargados.\n");
            }
        else
        {
                for(i=0;i<C-1;i++)
                    {
                    for(j=i+1;j<C;j++)
                        {
                        if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                            {
                                auxNombre=lista[i];
                                lista[i]=lista[j];
                                lista[j]=auxNombre;
                            }
                        }
                    }
                        printf("Nombre   Edad   DNI\n");
                for(i=0;i<C;i++)
                    {
                    if(lista[i].estado==1)
                        {
                            printf("%s %d %ld\n",lista[i].nombre,lista[i].edad,lista[i].dni);
                        }
                    }
    }
}
void grafico (EPersona lista[])
{
    int menor_18=0,entre_18y35=0,mayor_35=0,i,mayor=0,bandera=0;

            for(i=0;i<C;i++)
            {
                if(lista[i].estado==1)
                {
                    if(lista[i].edad<19)
                    {
                        menor_18++;
                    }
                    if(lista[i].edad>18&&lista[i].edad<36)
                    {
                        entre_18y35++;
                    }
                    if(lista[i].edad>35)
                    {
                        mayor_35++;
                    }
                }
            }
            if(menor_18>entre_18y35&&menor_18>mayor_35)
            {
                mayor=menor_18;
            }
                    else
                    {
                      if(entre_18y35>menor_18&&entre_18y35>mayor_35)
                      {
                          mayor=entre_18y35;
                      }
                    else
                        {
                            mayor=mayor_35;
                        }
                    }
                for(i=mayor;i>0;i--)
                {
                    if(menor_18>=mayor)
                    {
                        printf("*");
                    }
                    if(entre_18y35>=mayor)
                    {
                        bandera=1;
                        printf("\t*");
                    }
                    if(mayor_35>=mayor)
                    {
                        if(bandera==0)
                            printf("\t\t*");
                        if(bandera==1)
                            printf("\t*");
                    }
                    printf("\n");
                }
                printf("<18\t19-35\t>35\n");
}
