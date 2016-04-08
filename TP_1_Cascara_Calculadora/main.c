#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    double operadorUno=0,operadorDos=0;
    double resultado;
    int band=0,band1=0;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%0.Lf)         \n",operadorUno);
        printf("2- Ingresar 2do operando (B=%0.Lf)         \n",operadorDos);
        printf("-------------------------------------------\n");
        printf("3- Calcular la suma (A+B)                  \n");
        printf("4- Calcular la resta (A-B)                 \n");
        printf("5- Calcular la division (A/B)              \n");
        printf("6- Calcular la multiplicacion (A*B)        \n");
        printf("7- Calcular el factorial (A!)              \n");
        printf("8- Calcular todas las operacione           \n");
        printf("-------------------------------------------\n");
        printf("9- Salir                                   \n");
        printf("-------------------------------------------\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("Ingrese operador uno: ");
                scanf("%Lf",&operadorUno);
                band=1;
                system("cls");
                break;
            case 2:
                printf("Ingrese operador dos: ");
                scanf("%Lf",&operadorDos);
                band1=1;
                system("cls");
                break;
            case 3:
                    if(band==1&&band1==1)
                        {
                            resultado=suma(operadorUno,operadorDos);
                            printf("La suma es: %.2Lf\n",resultado);
                        }
                    else
                            printf("Error, ingrese los operadores.\n");
                        system("pause");
                        system("cls");
                    break;
            case 4:
                    if(band==1&&band1==1)
                        {
                            resultado=resta(operadorUno,operadorDos);
                            printf("La resta es: %.2Lf\n",resultado);
                        }
                    else
                            printf("Error, ingrese los operadores.\n");
                        system("pause");
                        system("cls");
                    break;
            case 5:
                    if(band==1&&band==1)
                        {
                            if(operadorDos<0||operadorDos>0)
                                {
                                    resultado=division(operadorUno,operadorDos);
                                    printf("La division es: %.2Lf\n",resultado);
                                }
                            else
                                    printf("Error, no se puede dividir por cero\n");
                        }
                    else
                            printf("Error, ingrese los operadores.\n");
                        system("pause");
                        system("cls");
                    break;
            case 6:
                    if(band=1&&band1==1)
                        {
                            resultado=multiplicacion(operadorUno,operadorDos);
                            printf("La multiplicacion es: %.2Lf\n",resultado);
                        }
                    else
                            printf("Error, ingrese los operadores.\n");
                    system("pause");
                    system("cls");
                break;
            case 7:
                    if(band==1)
                        {
                            resultado=factorial(operadorUno);
                            printf("El resultado del factoreo del operador uno es: %.2Lf\n",resultado);
                        }
                    else
                            printf("Error, ingrese operador uno.\n");
                    system("pause");
                    system("cls");
                break;
            case 8:
                    if(band==1&&band1==1)
                        {
                            resultado=suma(operadorUno,operadorDos);
                                printf("\nLa suma es: %.2Lf\n",resultado);
                            resultado=resta(operadorUno,operadorDos);
                                printf("\nLa resta es: %.2Lf\n",resultado);
                            if(operadorDos<0||operadorDos>0)
                                {
                                    resultado=division(operadorUno,operadorDos);
                                    printf("\nLa division es: %.2Lf\n",resultado);
                                }
                            else
                                    printf("\nError, no se puede dividir por cero\n");

                            resultado=multiplicacion(operadorUno,operadorDos);
                                printf("\nLa multiplicacion es: %.2Lf\n",resultado);
                            resultado=factorial(operadorUno);
                                printf("\nEl resultado del factoreo del operador uno es: %.2Lf\n",resultado);
                        }
                        else
                                printf("Error, ingrese los operadores.\n");
                        system("pause");
                        system("cls");
                break;
            case 9:
                seguir = 'n';
                break;
        }//swich
    }//while
    return 0;
    }//main
