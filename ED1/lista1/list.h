#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define V int

// Declares the existence of the struct
struct _list;

// Define a type alias that is the same type _list
typedef struct _list list;

// Definition of the struct
struct _list {
    V *array;      // Array storing the elements
    int capacity;  // Capacity of the array
    int size;      // Number of elements in the list
};

// === Function Prototypes ===

// helper function so I can avoid scanf shenanigans and can get something like CS50 get_int
int get_int(const char *prompt);

// Base functions
list *create_list();
void free_list(list **l);
void insert_end(list *l, V value);
void insert_start(list *l, V value);
void insert_at(list *l, V value, int index);
void update_at(list *l, V value, int index);
V get_first(list *l);
V get_last(list *l);
V get_at(list *l, int index);
V remove_first(list *l);
V remove_last(list *l);
V remove_at(list *l, int index);
int list_size(list *l);
int is_empty(list *l);
void clear_list(list *l);

// Extra functions
void print_list(list *l);
void print_reverse(list *l);
void insert_sorted(list *l, V value);
int is_sorted(list *l);
int is_fibonacci(list *l);
int find_position(list *l, V value);
int contains_all(list *l, list *a);
int lists_equal(list *l, list *a);
list *union_lists(list *l, list *a);
list *intersection_lists(list *l, list *a);
list *difference_lists(list *l, list *a);

#endif
