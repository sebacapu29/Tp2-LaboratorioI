#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Personas.h"
#include "Validacion.h"



int BuscarLibre(EPersona* lista, int TAM)
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

void persona_agregar(EPersona* personas, int TAM)
{
    char buffer[5000];
    int indiceDisponible;
    int indiceHabilitado;

    indiceDisponible = BuscarLibre(personas, TAM);

    if(indiceDisponible!=-1)
    {
        printf("\nIngresar DNI: ");
        fflush(stdin);
        gets(buffer);
        cadena_esNumero(buffer,"Error. Ingrese dni valido: ");

        indiceHabilitado = persona_buscarDni(personas, TAM,atoi(buffer));

         if(indiceHabilitado!=-1)
            {
             printf("\nPersona ya ingresada previamente. Estado: HABILITADA\n\n");
            }
            else
            {
                ///************asigno dni nuevo************////
                personas[indiceDisponible].dni = atoi(buffer);
                ///***************************************////

                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(buffer);
                cadena_validar(buffer,"Error. Ingrese nombre valido: ",TAM_CADENA);

                ///************* asigno nombre *************//////
                strcpy(personas[indiceDisponible].nombre, buffer);
                ///*****************************************/////

                printf("\nIngresar edad: ");
                fflush(stdin);
                gets(buffer);
                cadena_esNumero(buffer,"Error. Ingrese edad valida: ");

                ///************asigno edad ****************/////
                personas[indiceDisponible].edad = atoi(buffer);
                ///*************************************///////

                personas[indiceDisponible].estado =HABILITADO;

                printf("\nOperacion exitosa!\n\n");
            }
    }
    else
    {
        printf("\nATENCION! No hay lugar disponible.\n");
    }
}

int persona_buscarDni(EPersona* lista, int TAM, int dni)
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

void Graficar(EPersona* personas, int TAM)
{
    int menores=0;
    int intermedios=0;
    int mayores=0;
    int i;
    int j;

    /////hacer en funcion aparte////
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
    //////////hacer en funcion a parte ///////
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

void persona_baja(EPersona* personas, int TAM)
{
    int dni;
    char confirma;
    int indiceEncontrado;
    system("cls");
    printf("\n|****BAJA DE PERSONAS****|\n\n");

    persona_mostrar(personas,TAM);
    printf("\n->Ingrese el dni de la Persona: ");
    scanf("%d", &dni);
    indiceEncontrado = persona_buscarDni(personas,TAM,dni);

    if(indiceEncontrado!=-1)
    {
        printf("\nDesea dar de baja a esta persona? [s] - [n]: ");
        confirma = tolower(getche());
        if(confirma=='s')
        {
            personas[indiceEncontrado].estado=INHABILITADO;
            printf("\nOperacion realizada con Exito!\n\n");
        }
        else
        {
            printf("\nOperacion candelada por el usuario\n");
        }
    }
    else
    {
        printf("\nNo se encontro abonado solicitado\n");
    }
}


