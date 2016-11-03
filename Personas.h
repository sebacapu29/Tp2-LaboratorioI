#ifndef FUNCIONESPERSONAS_H_INCLUDED
#define FUNCIONESPERSONAS_H_INCLUDED

#define VACIO 0
#define HABILITADO 1
#define INHABILITADO 2

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
void persona_agregar(EPersona personas[], int TAM);

/** \brief Busca la primera ubicacion libre (0) en el Array de estructuras (personas)
 *
 * \param personas Array de estructuras
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return un Entero con el indice del primer lugar libre
 *
 */

int BuscarLibre(EPersona lista[], int TAM);

/** \brief Se encarga de buscar, recorrer el Array de estructuras buscando el campo dni para ver si esta ingresado o no
 *
 * \param lista Array de estructuras de tipo EPersona
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \param dni Entero que representa el dni a buscar
 * \return un Entero que devuelve (-1) si no encontro el dni y un Indice Entero si lo encontro.
 *
 */

int persona_buscarDni(EPersona lista[], int TAM, int dni);

/** \brief Muestra por pantalla un grafico, extrayendo del Array de estructuras (personas), de edades para representarlas
 *
 * \param personas Array de estructuras de tipo EPersona
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void Graficar(EPersona personas[], int TAM);

/** \brief Se encarga de mostrar los datos del Array de estructuras (personas)
 *
 * \param lista Array de estructuras (personas)
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void persona_mostrar(EPersona* lista, int TAM);

/** \brief Se encarga de hacer una baja logica de una persona, es decir poner el estado en deshabilitado (2)
 *
 * \param lista Array de estructuras (personas)
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void persona_baja(EPersona* personas, int TAM);


#endif // FUNCIONESPERSONAS_H_INCLUDED
