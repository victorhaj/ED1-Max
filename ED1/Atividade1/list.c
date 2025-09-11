#include "list.h"

#define SIZE_BUFFER 101

int get_int(const char *prompt) {
    int value = 0;
    char buffer[SIZE_BUFFER];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char *endptr;
            value = strtol(buffer, &endptr, 10);

            // let's skip whitespace
            while (*endptr == ' ' || *endptr == '\t') endptr++;
            // check for the end
            if (*endptr == '\0' || *endptr == '\n') {
                return value;  // if it is a valid integer
            } else {
                printf("Invalid input. Please enter an integer.\n");
            }
        } else {
            // EOF encountered
            printf("Error reading input.\n");
            exit(1);
        }
    }
}

float get_float(const char *prompt) {
    float value = 0.0f;
    char buffer[SIZE_BUFFER];

    while (1) {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char *endptr;
            value = strtof(buffer, &endptr);

            // skip whitespace after number
            while (*endptr == ' ' || *endptr == '\t') endptr++;

            // check if it ends cleanly
            if (*endptr == '\0' || *endptr == '\n') {
                return value;
            } else {
                printf("Invalid input. Please enter a float.\n");
            }
        } else {
            printf("Error reading input.\n");
            exit(1);
        }
    }
}

char *get_string(const char *prompt) {
    char buffer[SIZE_BUFFER];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }

    // remove trailing newline if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    // allocate memory for the string and copy
    char *result = malloc(strlen(buffer) + 1);
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(result, buffer);
    return result; // caller must free() it
}

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

void insert_end(list *l, V value) { insert_at(l, value, l->size); }

void insert_start(list *l, V value) { insert_at(l, value, 0); }

void insert_at(list *l, V value, int index) {
    if (index < 0 || index > l->size) {
        fprintf(stderr, "Invalid index %d. Valid range: 0 to %d\n", index,
                l->size);
        return;
    }

    // Block for resizing (if needed) and inserting when this happen
    if (l->size == l->capacity) {
        // gows 10% + 1(to ensure it grows at minus 10 capacity)
        int new_capacity = (int)(l->capacity * 1.1) + 1;
        V *new_array = malloc(sizeof(V) * new_capacity);
        if (new_array == NULL) {
            fprintf(stderr, "Memory allocation failed during resizing.\n");
            return;
        }

        // Now we will copy the elements and insert the new value during the
        // copying process
        for (int i = 0; i < index; i++) {
            new_array[i] = l->array[i];
        }
        new_array[index] = value;
        for (int i = index; i < l->size; i++) {
            new_array[i + 1] = l->array[i];
        }

        // now for the cleanup
        free(l->array);
        l->array = new_array;
        l->capacity = new_capacity;
        l->size++;
        return;
    }

    // if no resizing is needed, just shift to the right and insert new element
    for (int i = l->size; i > index; i--) {
        l->array[i] = l->array[i - 1];
    }
    l->array[index] = value;
    l->size++;
}

void update_at(list *l, V value, int index) {
    if (index < 0 || index >= l->size) {
        fprintf(stderr, "Invalid index %d. Valid range: 0 to %d\n", index,
                l->size);
        return;
    }
    l->array[index] = value;
}

V get_first(list *l) {
    if (l->size == 0) {
        fprintf(stderr, "List is empty\n");
        return 0;
    }
    return get_at(l, 0);
}

V get_last(list *l) {
    if (l->size == 0) {
        fprintf(stderr, "List is empty\n");
        return 0;
    }
    return get_at(l, l->size - 1);
}

V get_at(list *l, int index) {
    if (index < 0 || index >= l->size) {
        fprintf(stderr, "Invalid index %d. Valid range is 0 to %d.\n", index,
                l->size - 1);
        return 0;
    }
    return l->array[index];
}

V remove_first(list *l) {
    if (l->size == 0) {
        fprintf(stderr, "The list is empty and nothing can be removed\n");
        return 0;
    }
    return remove_at(l, 0);
}

V remove_last(list *l) {
    if (l->size == 0) {
        fprintf(stderr, "The list is empty and nothing can be removed\n");
        return 0;
    }
    return remove_at(l, l->size - 1);
}

V remove_at(list *l, int index) {
    if (index < 0 || index >= l->size) {
        fprintf(stderr, "Invalid index %d. Valid range: 0 to %d\n", index,
                l->size - 1);
        return 0;
    }
    int value_removed = l->array[index];
    for (int i = index; i < l->size - 1; i++) {
        l->array[i] = l->array[i + 1];
    }
    l->size--;
    return value_removed;
}

int list_size(list *l) { return l->size; }

int is_empty(list *l) { return l->size == 0; }

void clear_list(list *l) {
    // I had first gone for a full wipe here, but I decided to separate
    // responsibilities, and if I want a full wipe I will use free_list
    l->size = 0;
}

void print_list(list *l) {
    if (l->size == 0) {
        fprintf(stderr, "The list is empty, there is nothing to print.\n");
        return;
    }
    for (int i = 0; i < l->size; i++) {
        printf("%d", l->array[i]);
        if (i < l->size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void print_reverse(list *l) {
    if (l->size == 0) {
        fprintf(stderr, "The list is empty, there is nothing to print.\n");
        return;
    }
    for (int i = l->size - 1; i >= 0; i--) {
        printf("%d", l->array[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("\n");
}

void insert_sorted(list *l, V value) {
    if (l->size == 0) {
        insert_at(l, value, 0);
        return;
    }
    int i = 0;
    while (i < l->size && l->array[i] < value) {
        i++;
    }
    insert_at(l, value, i);
}

int is_sorted(list *l) {
    if (l->size == 0 || l->size == 1) {
        return 1;
    }
    for (int i = 0; i < l->size - 1; i++) {
        if (l->array[i] > l->array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int is_fibonacci(list *l) {
    // if it's empty or it has only 1 element, let's consider it is fibonacci
    if (l->size == 0 || l->size == 1) {
        return 1;
    }

    for (int i = 2; i < l->size; i++) {
        if (l->array[i] != l->array[i - 1] + l->array[i - 2]) {
            return 0;
        }
    }
    return 1;
}

int find_position(list *l, V value) {
    if (l == NULL || l->size == 0) {
        return -1;
    }

    for (int i = 0; i < l->size; i++) {
        if (l->array[i] == value) {
            return i;
        }
    }
    return -1;
}

int contains_all(list *l, list *a) {
    // a nested loop in disguise. the inner loop is handled by the find_position
    // function
    for (int i = 0; i < a->size; i++) {
        int position = find_position(l, a->array[i]);
        if (position == -1) {
            return 0;
        }
    }
    return 1;
}

int lists_equal(list *l, list *a) {
    // if they don't have the same size, no need to search further
    if (l->size != a->size) {
        return 0;
    }

    // using the function contains_all to avoid rework
    if (contains_all(l, a) && contains_all(a, l)) {
        return 1;
    }
    return 0;
}

list *union_lists(list *l, list *a) {
    list *result = create_list();
    if (result == NULL) {
        fprintf(stderr, "Error allocating new list.\n");
        return NULL;
    }
    // it is guaranteed that it doesn't have repeated elements inside the same
    // list
    for (int i = 0; i < l->size; i++) {
        insert_end(result, l->array[i]);
    }
    for (int i = 0; i < a->size; i++) {
        // checking if any elements in a are not already in result
        if (find_position(result, a->array[i]) == -1) {
            insert_end(result, a->array[i]);
        }
    }
    return result;
}

list *intersection_lists(list *l, list *a) {
    list *result = create_list();
    if (result == NULL) {
        fprintf(stderr, "Error allocating new list.\n");
        return NULL;
    }

    // Checks if it exists in both lists and adds it if it does
    for (int i = 0; i < l->size; i++) {
        if (find_position(a, l->array[i]) != -1) {
            insert_end(result, l->array[i]);
        }
    }
    return result;
}

list *difference_lists(list *l, list *a) {
    list *result = create_list();
    if (result == NULL) {
        fprintf(stderr, "Error allocating new list.\n");
        return NULL;
    }

    // Checks if it exists in both lists and adds it if it doesn't (the opposite
    // of the intersection)
    for (int i = 0; i < l->size; i++) {
        if (find_position(a, l->array[i]) == -1) {
            insert_end(result, l->array[i]);
        }
    }
    return result;
}
