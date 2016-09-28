#ifndef FUNCIONESESTRUCTURAS_H_INCLUDED
#define FUNCIONESESTRUCTURAS_H_INCLUDED
#include "Personas.h"


/** \brief Verifica la opcion comprendida en el vector rango
 *
 * \param opcion Entero a validar
 * \param rango Array de enteros
 * \return un Entero, 1 si es un valor correcto - 0 si no lo es.
 *
 */

int validaOpcion(int opcion, int rango[]);

/** \brief Muestra el mennu de opciones
 *
 * \param texto Array con la cadena de texto para mostrarle al usuario
 * \return Un entero ingresado por el usuario
 *
 */

int Menu(char texto[]);

/** \brief Se encarga de dejar mas prolija la cadena ingresada por el usuario.
 *
 * \param lista Array de estructuras (personas)
 * \param indice Entero con la ubicacion de la persona para modificar su nombre.
 * \return vacio
 *
 */

void LimpiaCadena(EPersona lista[], int indice);

/** \brief Se encarga de precargar valores iniciales al Array de estructuras (personas) poniendo si estado en 0 (0=vacio)
 *
 * \param persona Array de estructuras
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void InicializarEstructura(EPersona lista[], int TAM);

/** \brief Se encarga de ordenar por orden alfabetico el Array de estructuras (personas) por nombre
 *
 * \param lista Array de estructuras (personas)
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void OrdenarLista(EPersona lista[], int TAM);

/** \brief Se encarga de mostrar los datos del Array de estructuras (personas)
 *
 * \param lista Array de estructuras (personas)
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void MostrarLista(EPersona lista[], int TAM);

/** \brief Se encarga de validar la cadena que se ingresa, si es mayor a la logintud pretendida se ingresan
 *
 * \param buffer Array cadena a validar
 * \param maxCadena Entero que representa la cantidad de caracteres del Array a validar (en este caso el nombre)
 * \return un Entero indicando si la cadena es valida = 1 o 0 si no lo es.
 *
 */

int validaCadena(char buffer[], int maxCadena); ///MAL no pude encontrar el error al validar.

/** \brief Verifica si el valor ingresado esta comprendido en el Array de enteros rango[]
 *
 * \param buffer Entero ingresado para la validacion
 * \param rango Array de enteros
 * \return un Entero 1 si el valor ingresado es valido, 0 si no lo es.
 *
 */


int validaRango(int buffer, int rango[]);


#endif // FUNCIONESESTRUCTURAS_H_INCLUDED
