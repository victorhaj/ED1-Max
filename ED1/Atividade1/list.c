#include "list.h"

//Eu estive aqui =)

#define SIZE_BUFFER 101

list *create_list() {
    list *l = malloc(sizeof(list));
    if (l == NULL) {
        fprintf(stderr, "Error allocating new list.\n");
        return NULL;
    }
    l->size = 0;
    l->capacity = 5;
    l->array = malloc(sizeof(tarefa) * l->capacity);
    if (l->array == NULL) {
        fprintf(stderr, "Error allocating new list.\n");
        free_list(&l);
        return NULL;
    }

    return l;
}

// When debugging this function It was apparent that I wan't actually acessing
// the point to free it, and It seems like I need to use a pointer to pointer to
// properly acess it and free it
void free_list(list **l) {
    if (l == NULL || *l == NULL) {
        fprintf(stderr, "List is already NULL.\n");
        return;
    }
    free((*l)->array);
    free((*l));
    // avoid dangling pointer. Not really a problem here, but it's good
    // practice, and if I understood it right, the way I implement with full
    // freedom to choose functions can actually cause the dangling pointer. Must
    // remember to ask Max
    *l = NULL;
}

void insert_end(list *l) { insert_at(l, 0); }

void insert_start(list *l) { insert_at(l, 1); }

void insert_at(list *l, int index) {
    // Block for resizing (if needed) and inserting when this happen
    if (l->size == l->capacity) {
        // gows 10% + 1(to ensure it grows at minus 10 capacity)
        int new_capacity = (int)(l->capacity * 1.1) + 1;
        tarefa *new_array = malloc(sizeof(tarefa) * new_capacity);
        if (new_array == NULL) {
            fprintf(stderr, "Memory allocation failed during resizing.\n");
            return;
        }
        for (int i = 0; i < l->size; i++) {
            new_array[i] = l->array[i];
        }

        // now for the cleanup
        free(l->array);
        l->array = new_array;
        l->capacity = new_capacity;
        l->size++;
        return;
    }

    char nome_temporario1[TAM_NOME];
    char descricao_temporario1[TAM_NOME];

    printf("Digite o nome da tarefa: ");
    scanf("%[^\n]",nome_temporario1);
    printf("Digite o nome da tarefa: ");
    scanf("%[^\n]",descricao_temporario1);
    if(index == 1){
        for(int i = l->size;i>0;i--){
        l->array[i]=l->array[i-1];
    }
    strcpy(l->array[0].nome, nome_temporario1);
    strcpy(l->array[0].descr, descricao_temporario1);
    l->size++;
    }else{
        strcpy(l->array[l->size].nome, nome_temporario1);
        strcpy(l->array[l->size].descr, descricao_temporario1);
        l->size++;
    }
    

    // if no resizing is needed, just shift to the right and insert new element
    for (int i = l->size; i > index; i--) {
        l->array[i] = l->array[i - 1];
    }
    l->size++;
}

void remove_at(list *l) {
    printf("Digite o nome da tarefa: ");
    char nome_delete[TAM_NOME];
    
    for (int i = 0; i < l->size; i++) {
        if (strcmp(l->array->nome, nome_delete) == 0) {
            
        }
    }
    l->size--;
}

void clear_list(list *l) {
    // I had first gone for a full wipe here, but I decided to separate
    // responsibilities, and if I want a full wipe I will use free_list
    l->size = 0;
}

void imprimir(list *l) {
    if (l->size == 0) {
        printf("\nLista vazia.\n");
        return;
    }

    printf("\n--- Lista de Tarefas ---\n");
    for (int i = 0; i < l->size; i++) {
        printf("[%d] Nome: %s\n", i + 1, l->array[i].nome);
        printf("    Descrição: %s\n", l->array[i].descr);
        printf("    Complexidade: %s\n\n", l->array[i].complexidade ? "Urgente" : "Normal");
    }
}

void invert_list(list *l) {
    

}


