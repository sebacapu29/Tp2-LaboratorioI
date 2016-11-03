#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Personas.h"
#include "Validacion.h"

//Aclaracion lugar vacio (estado = 0) - ocupado (estado = 1) inhabilitado (estado = 2)


int main()
{
    char seguir='s';
    int TAM=20;
    int opcion;
    EPersona personas[TAM];

    InicializarEstructura(personas, TAM);

    do{
        opcion = menu("\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por nombre\n4- Imprimir grafico de edades\n\n5- Salir : ");
        switch(opcion)
        {
            case 1:
                persona_agregar(personas, TAM);
                break;
            case 2:
                persona_baja(personas,TAM);
                break;
            case 3:
                OrdenarLista(personas, TAM);
                persona_mostrar(personas, TAM);
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
