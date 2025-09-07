#include "list.h"

void print_main_menu();
void print_insert_menu();
void print_remove_menu();
void print_get_update_menu();
void print_check_menu();
void print_print_menu();
void print_advanced_menu();

int main() {
    list *l = create_list();
    int main_option = -1;

    while (main_option != 0) {
        print_main_menu();
        scanf("%d", &main_option);

        switch (main_option) {
            // INSERT OPERATIONS
            case 1: {
                int sub_option = -1;
                while (sub_option != 0) {
                    print_insert_menu();
                    scanf("%d", &sub_option);
                    if (sub_option == 0) {
                        break;
                    }

                    V value;
                    int index;
                    switch (sub_option) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            insert_end(l, value);
                            break;
                        case 2:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            insert_start(l, value);
                            break;
                        case 3:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            printf("Enter index: ");
                            scanf("%d", &index);
                            insert_at(l, value, index);
                            break;
                        case 4:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            insert_sorted(l, value);
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                }
                break;
            }

            // REMOVE OPERATIONS
            case 2: {
                int sub_option = -1;
                while (sub_option != 0) {
                    print_remove_menu();
                    scanf("%d", &sub_option);
                    if (sub_option == 0) {
                        break;
                    }

                    int index;
                    switch (sub_option) {
                        case 1:
                            remove_first(l);
                            break;
                        case 2:
                            remove_last(l);
                            break;
                        case 3:
                            printf("Enter index: ");
                            scanf("%d", &index);
                            remove_at(l, index);
                            break;
                        case 4:
                            clear_list(l);
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                }
                break;
            }

            // GET / UPDATE OPERATIONS
            case 3: {
                int sub_option = -1;
                while (sub_option != 0) {
                    print_get_update_menu();
                    scanf("%d", &sub_option);
                    if (sub_option == 0) {
                        break;
                    }

                    V value;
                    int index;
                    switch (sub_option) {
                        case 1:
                            value = get_first(l);
                            printf("First value: %d\n", value);
                            break;
                        case 2:
                            value = get_last(l);
                            printf("Last value: %d\n", value);
                            break;
                        case 3:
                            printf("Enter index: ");
                            scanf("%d", &index);
                            value = get_at(l, index);
                            printf("Value at index %d: %d\n", index, value);
                            break;
                        case 4:
                            printf("Enter new value: ");
                            scanf("%d", &value);
                            printf("Enter index: ");
                            scanf("%d", &index);
                            update_at(l, value, index);
                            break;
                        case 5:
                            printf("Enter value to search: ");
                            scanf("%d", &value);
                            index = find_position(l, value);
                            if (index == -1) {
                                printf("Value %d not found in the list.\n", value);
                            } else {
                                printf("First occurrence of %d is at position %d.\n", value, index);
                            }
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                }
                break;
            }

            // CHECK PROPERTIES
            case 4: {
                int sub_option = -1;
                while (sub_option != 0) {
                    print_check_menu();
                    scanf("%d", &sub_option);
                    if (sub_option == 0) {
                        break;
                    }

                    int result;
                    switch (sub_option) {
                        case 1:
                            printf("List size: %d\n", list_size(l));
                            break;
                        case 2:
                            printf("Is empty: %d\n", is_empty(l));
                            break;
                        case 3:
                            result = is_sorted(l);
                            printf("Is sorted: %d\n", result);
                            break;
                        case 4:
                            result = is_fibonacci(l);
                            printf("Is Fibonacci: %d\n", result);
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                }
                break;
            }

            // PRINT OPERATIONS
            case 5: {
                int sub_option = -1;
                while (sub_option != 0) {
                    print_print_menu();
                    scanf("%d", &sub_option);
                    if (sub_option == 0) {
                        break;
                    }

                    switch (sub_option) {
                        case 1:
                            print_list(l);
                            break;
                        case 2:
                            print_reverse(l);
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                }
                break;
            }

            // ADVANCED OPERATIONS
            case 6: {
                int sub_option = -1;
                while (sub_option != 0) {
                    print_advanced_menu();
                    scanf("%d", &sub_option);
                    if (sub_option == 0) {
                        break;
                    }

                    list *a = create_list();  // a second list to test operations
                    // it will be local to this suboption and list l must be
                    // already handled and filled before entering here Must
                    // remember when creating the functios to actually fill the
                    // second functions somehow Maybe call repeatedly the insert
                    // function?

                    switch (sub_option) {
                        case 1:
                            printf("Contains all: %d\n", contains_all(l, a));
                            break;
                        case 2:
                            printf("Lists equal: %d\n", lists_equal(l, a));
                            break;
                        case 3: {
                            list *result = union_lists(l, a);
                            print_list(result);
                            free_list(result);
                            break;
                        }
                        case 4: {
                            list *result = intersection_lists(l, a);
                            print_list(result);
                            free_list(result);
                            break;
                        }
                        case 5: {
                            list *result = difference_lists(l, a);
                            print_list(result);
                            free_list(result);
                            break;
                        }
                        default:
                            printf("Invalid option.\n");
                    }
                    // Forgot this part at first, must free the list when
                    // getting out of this submenu
                    free_list(a);
                }
                break;
            }

            case 0:
                // Freeing the list before exiting
                free_list(l);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}

void print_main_menu() {
    printf("\n=== Main Menu ===\n");
    printf("1 - Insert operations\n");
    printf("2 - Remove operations\n");
    printf("3 - Get / Update operations\n");
    printf("4 - Check properties\n");
    printf("5 - Print operations\n");
    printf("6 - Advanced operations (compare / combine)\n");
    printf("0 - Exit\n");
    printf("Choose an option: ");
}

void print_insert_menu() {
    printf("\n--- Insert Operations ---\n");
    printf("1 - Insert at end\n");
    printf("2 - Insert at start\n");
    printf("3 - Insert at position\n");
    printf("4 - Insert sorted\n");
    printf("0 - Back\n");
    printf("Choose an option: ");
}

void print_remove_menu() {
    printf("\n--- Remove Operations ---\n");
    printf("1 - Remove first\n");
    printf("2 - Remove last\n");
    printf("3 - Remove at position\n");
    printf("4 - Clear list\n");
    printf("0 - Back\n");
    printf("Choose an option: ");
}

void print_get_update_menu() {
    printf("\n--- Get / Update Operations ---\n");
    printf("1 - Get first\n");
    printf("2 - Get last\n");
    printf("3 - Get at position\n");
    printf("4 - Update at position\n");
    printf("5 - Find position by value\n");
    printf("0 - Back\n");
    printf("Choose an option: ");
}

void print_check_menu() {
    printf("\n--- Check Properties ---\n");
    printf("1 - List size\n");
    printf("2 - Is empty\n");
    printf("3 - Is sorted\n");
    printf("4 - Is Fibonacci\n");
    printf("0 - Back\n");
    printf("Choose an option: ");
}

void print_print_menu() {
    printf("\n--- Print Operations ---\n");
    printf("1 - Print list\n");
    printf("2 - Print list reversed\n");
    printf("0 - Back\n");
    printf("Choose an option: ");
}

void print_advanced_menu() {
    printf("\n--- Advanced Operations ---\n");
    printf("1 - Contains all (list vs another)\n");
    printf("2 - Lists equal\n");
    printf("3 - Union of two lists\n");
    printf("4 - Intersection of two lists\n");
    printf("5 - Difference of two lists\n");
    printf("0 - Back\n");
    printf("Choose an option: ");
}