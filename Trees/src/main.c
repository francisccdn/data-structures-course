#include <stdio.h>
#include "../include/bintree.h"

int main(void)
{
    int data = 0;
    printf("Digite o primeiro valor para sua árvore: ");
    scanf("%d", &data);
    Tree *t = tree_create(data, NULL, NULL);

    while (1)
    {
        printf("\nArvore binaria\n");
        printf("Representação de parentese: ");
        tree_print_parenthesis(t);
        printf("\nRepresentação de barras:\n");
        tree_print_bars(t);

        int op = 0;

        printf("\nQue operação você quer fazer? (0 para sair, 1 para inserir novo no, 2 para remover um no, 3 para buscar um no, 4 para ver o numero de folhas da arvore): ");
        scanf("%d", &op);

        if (op == 0 || op > 4)
        {
            break;
        }

        if (op == 4)
        {
            int num_leaves = tree_num_leaves(t);
            printf("A arvore tem %d folha(s).\n", num_leaves);
            continue;
        }

        printf("\nDigite um valor: ");
        scanf("%d", &data);

        if (op == 1)
        {
            if (!tree_insert(t, data))
            {
                printf("Erro ao inserir %d\n", data);
            }
        }
        if (op == 2)
        {
            if (!tree_remove(t, data))
            {
                printf("Erro ao remover %d\n", data);
            }
        }
        if (op == 3)
        {
            Tree *node = tree_find(t, data);
            if (!node)
            {
                printf("No %d nao foi encontrado\n", data);
            }
            else
            {
                printf("No %d encontrado!\nSubarvore que tem no %d como raiz: ", data, data);
                tree_print_parenthesis(node);
                printf("\n");
            }
        }
    }

    tree_free(t);

    return 0;
}