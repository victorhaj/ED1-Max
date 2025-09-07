#include "list.h"

list *create_list() {
    list *l = malloc(sizeof(list));
    if (l == NULL) {
        fprintf(stderr, "Error allocating new list.\n");
        return NULL;
    }
    l->size = 0;
    l->capacity = 5;
    l->array = malloc(sizeof(V) * l->capacity);
    if (l->array == NULL) {
        fprintf(stderr, "Error allocating new list.\n");
        free_list(l);
        return NULL;
    }

    return l;
}

void free_list(list *l) {
    if (l == NULL) {
        fprintf(stderr, "List is already NULL.\n");   
        return;     
    }
    free(l->array);
    free(l);
}

void insert_end(list *l, V value) {
    // TODO: implement
}

void insert_start(list *l, V value) {
    // TODO: implement
}

void insert_at(list *l, V value, int index) {
    // TODO: implement
}

void update_at(list *l, V value, int index) {
    // TODO: implement
}

V get_first(list *l) {
    // TODO: implement
    return 0;
}

V get_last(list *l) {
    // TODO: implement
    return 0;
}

V get_at(list *l, int index) {
    // TODO: implement
    return 0;
}

V remove_first(list *l) {
    // TODO: implement
    return 0;
}

V remove_last(list *l) {
    // TODO: implement
    return 0;
}

V remove_at(list *l, int index) {
    // TODO: implement
    return 0;
}

int list_size(list *l) {
    // TODO: implement
    return 0;
}

int is_empty(list *l) {
    // TODO: implement
    return 0;
}

void clear_list(list *l) {
    // TODO: implement
}

void print_list(list *l) {
    // TODO: implement
}

void print_reverse(list *l) {
    // TODO: implement
}

void insert_sorted(list *l, V value) {
    // TODO: implement
}

int is_sorted(list *l) {
    // TODO: implement
    return 0;
}

int is_fibonacci(list *l) {
    // TODO: implement
    return 0;
}

int find_position(list *l, V value) {
    // TODO: implement
    return -1;
}

int contains_all(list *l, list *a) {
    // TODO: implement
    return 0;
}

int lists_equal(list *l, list *a) {
    // TODO: implement
    return 0;
}

list union_lists(list *l, list *a) {
    // TODO: implement
    list result;
    return result;
}

list intersection_lists(list *l, list *a) {
    // TODO: implement
    list result;
    return result;
}

list difference_lists(list *l, list *a) {
    // TODO: implement
    list result;
    return result;
}
