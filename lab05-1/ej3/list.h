#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

// Definición del tipo de elemento de la lista
typedef int list_elem;

// Definición opaca del tipo list (encapsulamiento)
typedef struct _list *list;

/**
 * Crea una lista vacía.
 * @return lista vacía.
 */
list list_init(void);

/**
 * Destruye la lista y libera toda la memoria asociada.
 * @param l lista a destruir. Pre: l != NULL
 */
void list_destroy(list l);

/**
 * Devuelve una copia profunda de la lista.
 * @param l lista a copiar. Pre: l != NULL
 * @return nueva lista copia de l.
 */
list list_copy(const list l);

/**
 * Inserta un elemento al principio de la lista.
 * @param l lista original. Pre: l != NULL
 * @param e elemento a insertar.
 * @return nueva lista con el elemento insertado.
 */
list list_insert_first(list l, list_elem e);

/**
 * Inserta un elemento al final de la lista.
 * @param l lista original. Pre: l != NULL
 * @param e elemento a insertar.
 * @return nueva lista con el elemento insertado.
 */
list list_insert_last(list l, list_elem e);

/**
 * Elimina el primer elemento de la lista.
 * @param l lista original. Pre: l != NULL && !list_is_empty(l)
 * @return nueva lista sin el primer elemento.
 */
list list_remove_first(list l);

/**
 * Elimina el último elemento de la lista.
 * @param l lista original. Pre: l != NULL && !list_is_empty(l)
 * @return nueva lista sin el último elemento.
 */
list list_remove_last(list l);

/**
 * Devuelve el primer elemento de la lista.
 * @param l lista. Pre: l != NULL && !list_is_empty(l)
 * @return primer elemento.
 */
list_elem list_first(const list l);

/**
 * Devuelve el último elemento de la lista.
 * @param l lista. Pre: l != NULL && !list_is_empty(l)
 * @return último elemento.
 */
list_elem list_last(const list l);

/**
 * Indica si la lista está vacía.
 * @param l lista. Pre: l != NULL
 * @return true si está vacía, false en caso contrario.
 */
bool list_is_empty(const list l);

/**
 * Devuelve el tamaño de la lista.
 * @param l lista. Pre: l != NULL
 * @return cantidad de elementos.
 */
size_t list_length(const list l);

#endif // LIST_H