#ifndef FUNCIONESPERSONAS_H_INCLUDED
#define FUNCIONESPERSONAS_H_INCLUDED

typedef struct {

    char nombre[100];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Se encarga de agregar una persona (una estructura con esta entidad) al Array de estructuras.
 *
 * \param personas Array de estructuras
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */
void AgregarPersona(EPersona personas[], int TAM);

/** \brief Busca la primera ubicacion libre en el Array de estructuras (personas)
 *
 * \param personas Array de estructuras
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return un Entero con el indice del primer lugar libre
 *
 */


int BuscarLibre(EPersona lista[], int TAM);

/** \brief Se encarga de buscar, recorrer el Array de estructuras buscando el primer lugar libre es decir (estado=0)
 *
 * \param lista Array de estructuras de tipo EPersona
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \param dni Entero que representa el dni a buscar
 * \return un Entero que devuelve (-1) si no encontro el dni y un Indice Entero si lo encontro.
 *
 */

int BuscarPorDni(EPersona lista[], int TAM, int dni);

/** \brief Se encarga de recorrer el Array de estructuras (personas)
 *
 * \param lista Array de estructuras de tipo EPersona, es decir las personas.
 * \param indicePersona es un Entero con la ubicacion de la persona en el Array de estructuras
 * \return vacio
 *
 */

void BorrarPersona(EPersona lista[],int indicePersona);


#endif // FUNCIONESPERSONAS_H_INCLUDED
