#ifndef FUNCIONESESTRUCTURAS_H_INCLUDED
#define FUNCIONESESTRUCTURAS_H_INCLUDED
#include "Personas.h"

#define TAM_CADENA 100
#define TAM_BUFFER 5000

/** \brief Muestra el menu de opciones
 *
 * \param texto Array con la cadena de texto para mostrarle al usuario
 * \return Un entero ingresado por el usuario
 *
 */

int menu(char* texto);

/** \brief Se encarga de poner la primera letra en mayuscula y el resto en minuscula de la cadena ingresada por el usuario.
 *
 * \param lista Array de estructuras (personas)
 * \param indice Entero con la ubicacion de la persona para modificar su nombre.
 * \return vacio
 *
 */

void cadena_limpiar(EPersona* lista, int indice);

/** \brief Se encarga de precargar valores iniciales al Array de estructuras (personas) poniendo si estado en 0 (0=vacio)
 *
 * \param persona Array de estructuras
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void InicializarEstructura(EPersona* lista, int TAM);

/** \brief Se encarga de ordenar por orden alfabetico el Array de estructuras (personas) por nombre
 *
 * \param lista Array de estructuras (personas)
 * \param TAM Entero que representa el tamaño del Array de estructuras (personas)
 * \return vacio
 *
 */

void OrdenarLista(EPersona* lista, int TAM);

/** \brief Evalua cual de los valores es el mayor
 *
 * \param valorUno Entero a verificar
 * \param valorDos Entero a verificar
 * \param valorTres Entero a verificar
 * \return un Entero
 *
 */

int calcularMayor(int valorUno, int valorDos, int valorTres);

/** \brief Se encarga de validar si la cadena se compone solo de letras y que no se pase del tamaño deseado
 *
 * \param buffer, Array de caracteres a validar
 * \param textoError, Array de caracteres que representa el texto de error
 * \param tamDeseado, Entero que representa el tamaño a validar
 * \return Vacio.
 *
 */

void cadena_validar(char* buffer, char* textoError, int tamDeseado);

/** \brief Se encarga de verificar si lo ingresado esta compuesto por letras o solo numeros
 *
 * \param numero, Array de caracteres a validar
 * \return Entero, 1 si esta bien y 0 si da un error.
 *
 */

int esNumeroYPositivo(char* numero);

/** \brief Se encarga de verificar si el numero ingresado es correcto o sino, nos vuelve a pedir que se ingrese un numero
 *
 * \param numero, Array de caracteres a tomar como numero
 * \param textoError, Array de caracteres que muestra mensaje de error.
 * \return Vacio.
 *
 */

void cadena_esNumero(char* numero, char* textoError);

#endif // FUNCIONESESTRUCTURAS_H_INCLUDED
