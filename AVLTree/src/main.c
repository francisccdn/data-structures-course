#include <stdio.h>
#include "../include/avl.h"

int main(void)
{
    int data = 0;
    printf("Digite o primeiro valor para sua árvore: ");
    scanf("%d", &data);
    Avl *t = avl_create(data, NULL, NULL);

    while (1)
    {
        printf("\nArvore binaria de busca\n");
        printf("Representação de parentese: ");
        avl_print_parenthesis(t);
        printf("\nRepresentação de barras:\n");
        avl_print_bars(t);

        int op = 0;

        printf("\nQue operação você quer fazer? (0 para sair, 1 para inserir novo no, 2 para remover um no, 3 para buscar um no, 4 para ver o numero de folhas da arvore): ");
        scanf("%d", &op);

        if (op == 0 || op > 4)
        {
            break;
        }

        if (op == 4)
        {
            int num_leaves = avl_num_leaves(t);
            printf("A arvore tem %d folha(s).\n", num_leaves);
            continue;
        }

        printf("\nDigite um valor: ");
        scanf("%d", &data);

        if (op == 1)
        {
            if (!avl_insert(&t, data))
            {
                printf("Erro ao inserir %d\n", data);
            }
        }
        if (op == 2)
        {
            if (!avl_remove(&t, data))
            {
                printf("Erro ao remover %d\n", data);
            }
        }
        if (op == 3)
        {
            Avl *node = avl_find(t, data);
            if (!node)
            {
                printf("No %d nao foi encontrado\n", data);
            }
            else
            {
                printf("No %d encontrado!\nSubarvore que tem no %d como raiz: ", data, data);
                avl_print_parenthesis(node);
                printf("\n");
            }
        }
    }

    avl_free(t);

    return 0;
}