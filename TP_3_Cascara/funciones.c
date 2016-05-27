#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void estado(EMovie movie[])
{
    int i;

    for(i=0;i<C;i++)
        {
            movie[i].estado=0;
        }
}


int agregarPelicula(EMovie movie[],FILE* P)
{
    int i;

    estado(movie);

    for(i=0;i<C;i++)
    {
        if(movie[i].estado==0)
        {
                printf("Ingrese titulo de la pelicula: ");
                fflush(stdin);
                gets(movie[i].titulo);
                strlwr(movie[i].titulo);

                printf("Ingrese genero  de la pelicula: ");
                fflush(stdin);
                gets(movie[i].genero);

                printf("Ingrese duracion de la pelicula: ");
                scanf("%d",&movie[i].duracion);

                printf("Ingrese descripcion de la pelicula: ");
                fflush(stdin);
                gets(movie[i].descripcion);

                printf("Ingrese puntaje de la pelicula: ");
                scanf("%d",&movie[i].puntaje);

                printf("Link de imagen de la pelicula: ");
                fflush(stdin);
                gets(movie[i].linkImagen);

                movie[i].estado=1;

                fseek(P,0l,SEEK_END);
                fwrite(&movie,sizeof(EMovie),1,P);
                break;
        }
    }
    return 0;
}


void borrarPelicula(EMovie movie[],FILE *P)
{
    int i=0;
    char AuxPeli[50];

        printf("Titulo de Pelicula a eliminar: ");
        fflush(stdin);
        gets(AuxPeli);
        strlwr(AuxPeli);

        rewind(P);

            while(!feof(P))
                {
                    fread(&movie,sizeof(movie),1,P);

                        if(strcmp(AuxPeli,movie[i].titulo)==0 && movie[i].estado==1)
                            {
                                movie[i].estado=0;
                                fseek(P,(-1)*sizeof(movie),SEEK_CUR);
                                fwrite(&movie,sizeof(movie),1,P);
                                break;
                            }
                }
}


void ModificarPelicula(EMovie movie[],FILE *p)
{
    int i=0;
    char AuxPeli[50];

        printf("Ingrese titulo de Pelicula a modificar: ");
        fflush(stdin);
        gets(AuxPeli);
        strlwr(AuxPeli);

        rewind(p);

            while(!feof(p))
                {
                    fread(&movie,sizeof(movie),1,p);
                        if(strcmp(AuxPeli,movie[i].titulo)==0 && movie[i].estado==1)
                            {
                                printf("Ingrese genero a modificar: ");
                                fflush(stdin);
                                gets(movie[i].genero);

                                printf("Ingrese duracion a modificar: ");
                                scanf("%d",&movie[i].duracion);

                                printf("Ingrese descripcion a modificar: ");
                                fflush(stdin);
                                gets(movie[i].descripcion);

                                printf("Ingrese puntaje a modificar: ");
                                scanf("%d",&movie[i].puntaje);

                                printf("Link de imagen a modificar: ");
                                fflush(stdin);
                                gets(movie[i].linkImagen);

                                fseek(p,(-1)*sizeof(movie),SEEK_CUR);
                                fwrite(&movie,sizeof(movie),1,p);
                                break;
                            }
                }

}


void GenerarPagina(EMovie movie[])
{
    FILE *P;
    int i;

    char bloque1[]="<!DOCTYPE html><html><head><title>Example</title></head><body>";
    char bloque3[]="</html></body>";

    P = fopen("peliculas.html", "w");

        if(P==NULL)
        {
            printf("No se puede abrir el archivo.");
        }
        else
        {
            rewind(P);
        }

    fprintf(P,"<!DOCTYPE html><html><head><title>Example</title></head><body>\n");

    for(i=0; i<C; i++)
        {
            if(movie[i].estado==1)
            {
                fprintf(P, "<article class='col-md-4 article-intro'><a href='#'><img class='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul><p>%s</p></article>\n",movie[i].linkImagen,movie[i].titulo,movie[i].genero,movie[i].puntaje,movie[i].duracion,movie[i].descripcion);
            }
        }

    fprintf(P, "</html></body>");

}
