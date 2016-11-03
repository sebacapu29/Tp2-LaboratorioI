#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Personas.h"


int menu(char* texto)
{
    int opcion;
    printf("\n ****MENU PRINCIPAL*****\n");
    printf(" _____________________\n");
    printf("%s ", texto);
    scanf("%d",&opcion);

    return opcion;
}

void cadena_limpiar(EPersona* lista, int indice)
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

void InicializarEstructura(EPersona* lista, int TAM)
{
     int i;
     for(i=0;i<TAM;i++)
     {
        lista[i].estado = VACIO;
     }
}

void OrdenarLista(EPersona* lista, int TAM)
{
    int i;
    int j;
    EPersona listaAux;

    for(i=0; i < TAM-1; i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(lista[i].estado==HABILITADO && lista[j].estado==HABILITADO)
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

void persona_mostrar(EPersona* lista, int TAM)
{
    int i;
    for(i=0; i<TAM;i++)
    {
        cadena_limpiar(lista,i);
    }
    printf("\n  **DATOS PERSONALES ACTIVAS**\n");
    printf("  ______________________________\n\n");
     for(i=0;i<TAM;i++)
        {
            if(lista[i].estado==HABILITADO)
            {
                printf("\n*Nombre:  %s", lista[i].nombre);
                printf("\n*Edad:    %d anios", lista[i].edad);
                printf("\n*Dni:     %d\n\n", lista[i].dni);
            }
        }
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
void cadena_validar(char* buffer, char* textoError, int tamDeseado)
{
    while( strlen(buffer)> tamDeseado || atoi(buffer)< 0 || atoi(buffer)>0)
        {
           printf("%s",textoError);
           fflush(stdin);
           gets(buffer);
        }
}

int esNumeroYPositivo(char* numero)
{
    int i;
    int retorno=1;

    for(i=0; i< strlen(numero); i++)
    {
        if(!isdigit(numero[i]) || atoi(numero)<0)
        {
            retorno = 0;
        }
    }
    return retorno;
}

void cadena_esNumero(char* numero, char* textoError)
{
    while(!esNumeroYPositivo(numero))
    {
        printf("%s", textoError);
        fflush(stdin);
        gets(numero);
    }
}
