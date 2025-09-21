#ifndef LIST_H
#define LIST_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define V int
#define TAM_NOME 101
#define TAM_DESCR 201

struct _tarefa;

typedef struct _tarefa tarefa;

struct _tarefa {
    char nome[TAM_NOME];
    char descr[TAM_DESCR];
    int complexidade; // 1 = urgente, 0 = normal
};

// Declares the existence of the struct
struct _list;

// Define a type alias that is the same type _list
typedef struct _list list;

// Definition of the struct
struct _list {
    tarefa *array;      // Array storing the elements
    int capacity;  // Capacity of the array
    int size;      // Number of elements in the list
};

// === Function Prototypes ===

// Base functions
list *create_list();
void free_list(list **l);
void insert_end(list *l);
void insert_start(list *l);
void insert_at(list *l, int index);
void remove_at(list *l);

// Extra functions
void print_list(list *l);
void invert_list(list *l);

int get_int(const char *prompt);

#endif
