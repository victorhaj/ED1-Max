#include "list.h"

int main() {
    list *l = create_list();
    int opcao = -1;

    while(opcao != 6){
        printf("\n=== Main Menu ===\n");
        opcao = get_int("Choose an option: ");
        printf("1 - Adicionar tarefa urgente\n");
        printf("2 - Adicionar tarefa normal\n");
        printf("3 - Remover tarefa pelo nome\n");
        printf("4 - Inverter Lista\n");
        printf("5 - Listar todas as tarefas\n");
        printf("6 - Sair\n");
        printf("\n\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: //tarefa urgente
                insert_start(&l);
                break;
            case 2: //tarefa normal
                insert_end(&l);
                break;
            case 3: //remove tarefa
                remove_at(&l);
                break;
            case 4: //inverte a ordem
                invert_list(&l);
                break;
            case 5: //imprime
                print_list(l);
                break;
            case 6: //encerra
                free_list(&l);
                break;

            default: printf("Opcao invalida!\n");
        
        }
    }

    return 0;
}
