#include "list.h"
// #include <stdlib.h>
#include <stdbool.h>    
#include <stdio.h>
#include <stdlib.h>

typedef struct _list * list;
typedef int list_element;
struct _list {
    struct _list_node *head;
    struct _list_node *tail;
    size_t size;
};
typedef struct _list_node {
    list_element element;
    struct _list_node *next;
} list_node;

list list_init(void) {
    list l = malloc(sizeof(struct _list));
    if (l == NULL) {
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void list_destroy(list l) {
    if (l == NULL) {
        return; // No action needed for null pointer
    }
    list_node *current = l->head;
    while (current != NULL) {
        list_node *next = current->next;
        free(current);
        current = next;
    }
    free(l);
}

list list_copy(const list l) {
    if (l == NULL) {
        return NULL; // Handle null pointer access
    }
    list new_list = list_init();
    list_node *current = l->head;
    while (current != NULL) {
        new_list = list_insert_last(new_list, current->element);
        current = current->next;
    }
    return new_list;
}

list list_insert_first(list l, list_element e) {
    if (l == NULL) {
        return NULL; // Handle null pointer access
    }
    list_node *new_node = malloc(sizeof(list_node));
    if (new_node == NULL) {
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    new_node->element = e;
    new_node->next = l->head;
    l->head = new_node;
    if (l->tail == NULL) {
        l->tail = new_node; // If the list was empty, set tail to the new node
    }
    l->size++;
    return l;
}   

list list_insert_last(list l, list_element e) {
    if (l == NULL) {
        return NULL; // Handle null pointer access
    }
    list_node *new_node = malloc(sizeof(list_node));
    if (new_node == NULL) {
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    new_node->element = e;
    new_node->next = NULL;
    if (l->tail != NULL) {
        l->tail->next = new_node; // Link the new node to the end of the list
    } else {
        l->head = new_node; // If the list was empty, set head to the new node
    }
    l->tail = new_node; // Update tail to the new node
    l->size++;
    return l;
}

list list_remove_first(list l) {
    if (l == NULL || l->head == NULL) {
        return NULL; // Handle null pointer or empty list
    }
    list_node *to_remove = l->head;
    l->head = to_remove->next;
    if (l->head == NULL) {
        l->tail = NULL; // If the list is now empty, set tail to NULL
    }
    free(to_remove);
    l->size--;
    return l;
}

list list_remove_last(list l) {
    if (l == NULL || l->head == NULL) {
        return NULL; // Handle null pointer or empty list
    }
    if (l->head == l->tail) { // Only one element in the list
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    } else {
        list_node *current = l->head;
        while (current->next != l->tail) {
            current = current->next; // Find the second last node
        }
        free(l->tail);
        l->tail = current; // Update tail to the second last node
        l->tail->next = NULL; // Set next of new tail to NULL
    }
    l->size--;
    return l;
}

list_element list_first(const list l) {
    if (l == NULL || l->head == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer or empty list
    }
    return l->head->element;
}

list_element list_last(const list l) {
    if (l == NULL || l->tail == NULL) {
        exit(EXIT_FAILURE); // Handle null pointer or empty list
    }
    return l->tail->element;
}

bool list_is_empty(const list l) {
    if (l == NULL) {
        return true; // Handle null pointer
    }
    return l->size == 0; // Return true if size is zero
}

size_t list_length(const list l) {
    if (l == NULL) {
        return 0; // Handle null pointer
    }
    return l->size; // Return the size of the list
}

list list_from_array(const int array[], unsigned int length) {
    list l = list_init();
    for (unsigned int i = 0; i < length; ++i) {
        l = list_insert_last(l, array[i]);
    }
    return l;
}

float average(const list l) {
    if (l == NULL || list_is_empty(l)) {
        exit(EXIT_FAILURE); // Handle null pointer or empty list
    }
    float sum = 0.0f;
    list_node *current = l->head;
    while (current != NULL) {
        sum += current->element; // Accumulate the sum of elements
        current = current->next; // Move to the next node
    }
    return sum / l->size; // Return the average
}

void list_dump(const list l) {
    if (l == NULL) {
        printf("List is NULL\n");
        return;
    }
    if (list_is_empty(l)) {
        printf("List is empty\n");
        return;
    }
    list_node *current = l->head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->element);
        current = current->next;
    }
    printf("\n");
}   

