#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Personas.h"

int validaOpcion(int opcion, int rango[])
{
    int opcionValida = 1;
    if(opcion < rango[0] || opcion > rango[1])
    {
       opcionValida = 0;
    }
    return opcionValida;
}

int Menu(char texto[])
{
    int opcion;
    printf("\n ****MENU PRINCIPAL*****\n");
    printf(" _____________________\n");
    printf("%s ", texto);
    scanf("%d",&opcion);

    return opcion;
}

void LimpiaCadena(EPersona lista[], int indice)
{
    char aux;
    int i;
    strlwr(lista[indice].nombre);
    aux = toupper(lista[indice].nombre[0]);
    lista[indice].nombre[0]=aux;
    for(i=0;i<strlen(lista[indice].nombre);i++)
    {
        if(lista[indice].nombre[i]==' ')
        {
            aux = toupper(lista[indice].nombre[i+1]);
            lista[indice].nombre[i+1]=aux;
        }
    }
}

void InicializarEstructura(EPersona lista[], int TAM)
{
     int i;
     for(i=0;i<TAM;i++)
     {
        lista[i].estado = 0;
     }
}

void OrdenarLista(EPersona lista[], int TAM)
{
    int i;
    int j;
    EPersona listaAux;

    for(i=0; i < TAM-1; i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(lista[i].estado==1 && lista[j].estado==1)
            {
                 if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    listaAux = lista[j];
                    lista[j] = lista[i];
                    lista[i]=listaAux;
                }

            }

        }
    }
}

void MostrarLista(EPersona lista[], int TAM)
{
    int i;
    for(i=0; i<TAM;i++)
    {
        LimpiaCadena(lista,i);
    }
    printf("\n  **IMPRIMIENDO DATOS PERSONALES ACTIVAS**\n");
    printf("   ____________________________________\n\n");
     for(i=0;i<TAM;i++)
        {
            if(lista[i].estado==1)
            {
                printf("\n*Nombre:  %s", lista[i].nombre);
                printf("\n*Edad:    %d anios", lista[i].edad);
                printf("\n*Dni:     %d\n\n", lista[i].dni);
            }
        }
}

int validaCadena(char buffer[], int maxCadena)
{
    int longitud = strlen(buffer);
    int cadValida = 1;
    if(longitud > maxCadena)
        {
            cadValida =0;
        }
    return cadValida;
}

int validaRango(int buffer, int rango[])
{
    int valido = 1;
    if(buffer <= rango[0] || buffer > rango[1])
    {
        valido = 0;
    }
    return valido;
}
