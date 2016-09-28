#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Personas.h"
#include "Validacion.h"
#define MAX 99



int BuscarLibre(EPersona lista[], int TAM)
{
    int i;
    int indiceEncontrado=-1;

    for(i=0; i<TAM; i++)
    {
        if(lista[i].estado==0)
        {
            indiceEncontrado = i;
            break;
        }
    }
    return indiceEncontrado;
}

void AgregarPersona(EPersona personas[], int TAM)
{
    char buffer[5000];
    int auxDni;
    int auxEdad;
    int rangoEdad[2] = {1,100};
    int rangoDni[2]= {1,90000000};
    int indiceDisponible;
    int indiceHabilitado;

    indiceDisponible = BuscarLibre(personas, TAM);

    if(indiceDisponible!=-1)
    {
        printf("\nIngresar DNI: ");
        scanf("%d", &auxDni);
        while(!validaRango(auxDni, rangoDni))
        {
            printf("Error. Ingrese DNI valido");
            scanf("%d", &auxDni);
        }

        indiceHabilitado = BuscarPorDni(personas, TAM,auxDni);

         if(indiceHabilitado!=-1)
            {
             printf("\nPersona ya ingresada previamente. Estado: HABILITADA\n\n");
            }
            else
            {
                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(buffer);

                while(!validaCadena(buffer, MAX))
                {
                    printf("Cadena muy larga, reingresar por favor: ");
                    fflush(stdin);
                    gets(buffer);
                }

                printf("\nIngresar edad: ");
                scanf("%d", &auxEdad);
                while(!validaRango(auxEdad, rangoEdad))
                {
                    printf("\nError. Ingrese edad comprendida entre (1-100)");
                    scanf("%d", &auxEdad);
                }

                personas[indiceDisponible].dni = auxDni;
                strcpy(personas[indiceDisponible].nombre, buffer);
                personas[indiceDisponible].edad = auxEdad;
                personas[indiceDisponible].estado =1;

                printf("\nOperacion exitosa!\n\n");
            }
    }
    else
    {
        printf("\nATENCION! No hay lugar disponible.\n");
    }
}

int BuscarPorDni(EPersona lista[], int TAM, int dni)
{
    int i;
    int dniEncontrado=-1;
    for(i=0;i<TAM;i++)
    {
        if(dni==lista[i].dni)
        {
            dniEncontrado = i;
            break;
        }
    }
    return dniEncontrado;
}


void BorrarPersona(EPersona lista[],int indicePersona)
{
    char confirma;
    printf("\nDesea dar de baja a esta persona? [s] - [n]: ");
    confirma = tolower(getche());
    if(confirma=='s')
    {
         lista[indicePersona].estado=2;
        printf("\nOperacion Realizada con Exito!\n\n");
    }
    else
    {
        printf("\nOperacion cancelada por el usuario.\n\n");
    }

}

