#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Personas.h"
#include "Validacion.h"

//Aclaracion lugar vacio (estado = 0) - ocupado (estado = 1) inhabilitado (estado = 2)

/** \brief Evalua cual de los valores es el mayor
 *
 * \param valorUno Entero a verificar
 * \param valorDos Entero a verificar
 * \param valorTres Entero a verificar
 * \return un Entero
 *
 */

int calcularMayor(int valorUno, int valorDos, int valorTres);


/** \brief Muestra por pantalla un grafico, extrayendo del Array de estructuras (personas), de edades para representarlas
 *
 * \param personas Array de estructuras de tipo EPersona
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void Graficar(EPersona personas[], int TAM);



int main()
{
    char seguir='s';
    int TAM=20;
    int opcion;
    int DNI;
    int dniEncontrado;
    char textoBaja[500]="\nBaja de persona\n---------------\n\nIngrese DNI de la persona: ";
    EPersona personas[TAM];

    InicializarEstructura(personas, TAM);

    do{
        opcion = Menu("\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir : ");
        switch(opcion)
        {
            case 1:
               AgregarPersona(personas, TAM);
                break;
            case 2:
                fflush(stdin);
                printf("%s", textoBaja);
                scanf("%d", &DNI);
                dniEncontrado = BuscarPorDni(personas,TAM, DNI);
               if(dniEncontrado!=-1)
               {
                   BorrarPersona(personas,dniEncontrado);
               }
               else
               {
                   printf("\nError. No se encontro persona!\n");
               }
                break;
            case 3:
                OrdenarLista(personas, TAM);
                MostrarLista(personas, TAM);
                break;
            case 4:
                Graficar(personas,TAM);
                break;
            case 5:
                printf("\nSaliendo de la aplicacion...\n\n");
                seguir = 'n';
                break;
            default:
                printf("\n%d No es una opcion valida\n\n", opcion);
                break;
        }
        system("\npause");
        system("cls");

    }while(seguir=='s');

    return 0;
}

void Graficar(EPersona personas[], int TAM)
{
    int menores=0;
    int intermedios=0;
    int mayores=0;
    int i;
    int j;

     for(i=0; i<TAM; i++)
    {
        if(personas[i].estado==1)
        {
             if(personas[i].edad<=18)
            {
                menores++;
            }
            else if(personas[i].edad >= 19 && personas[i].edad <=35)
            {
                intermedios++;
            }
            else if(personas[i].edad>35)
            {
                mayores++;
            }
        }
    }
    int mayor= calcularMayor(menores,intermedios,mayores);
    char matriz[mayor][3];



    printf("\n****GRAFICO DE EDADES****\n\n");

    for(j=0; j<mayor; j++)
       {
        for(i=0; i<3; i++)
        {
            switch(i)
            {
          case 0:
              if(menores > j)
                matriz[j][i]='*';
            else
                matriz[j][i]=' ';
                break;
          case 1:
              if(intermedios > j)
                matriz[j][i]='*';
            else
                matriz[j][i]=' ';
                break;
            case 2:
              if(mayores> j)
                matriz[j][i]='*';
            else
                matriz[j][i]=' ';
                break;
            }
          }
       }

        for(j=mayor-1; j>=0; j--)
            {
                printf(" |%c      %c      %c \n", matriz[j][0], matriz[j][1], matriz[j][2]);
            }
            printf("\n ___________________\n");
            printf("\n <18   19-35     >35\n\n");
}

int calcularMayor(int valorUno, int valorDos, int valorTres)
{
    int mayor;

    if(valorUno > valorDos && valorUno > valorTres)
    {
        mayor = valorUno;
    }
    else
        {
            if( valorDos > valorUno && valorDos >= valorTres)
        {
            mayor = valorDos;
        }
            else
            {
                mayor = valorTres;
            }
        }
    return mayor;
}
