#include <stdio.h>
#include <stdlib.h>

#include "../include/circularlist.h"

#ifndef _CIRCULAR_LIST_C_
#define _CIRCULAR_LIST_C_

// Struct da lista circular.
// Armazena um ponteiro para o primeiro nó da lista.
struct circularlist
{
    ListNode *head;
};

// Struct de nó da lista.
// Armazena o dado informado de tipo inteiro, e um ponteiro para o próximo nó da lista.
struct listnode
{
    int data;
    ListNode *next;
};

// Cria uma nova lista circular, retornando seu endereço de memória.
CircularList *cl_create_list()
{
    // Alocar memória necessária para uma lista circular.
    CircularList *list = (CircularList *)malloc(sizeof(CircularList));

    // Se a memória foi alocada sem erros, definir seu primeiro nó como nulo.
    if (list)
        list->head = NULL;

    return list;
}

// Cria um nó da lista, retornando seu endereço de memória.
ListNode *cl_create_node(int data)
{
    // Alocar memória necessária para um nó.
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    // Se a memória foi alocada sem erros, definir o dado armazenado, e o próximo nó como nulo.
    if (node)
    {
        node->data = data;
        node->next = NULL;
    }

    return node;
}

// Checa se a lista está vazia.
int cl_is_empty(CircularList *list)
{
    // Quando ela está vazia, seu primeiro elemento é nulo.
    return list->head == NULL;
}

// Retorna o tamanho da lista circular.
int cl_size(CircularList *list)
{
    // Se seu primeiro elemento for nulo, o tamanho é 0.
    if (list->head == NULL)
        return 0;

    // Contador de elementos.
    int counter = 0;

    // Incrementar o contador uma vez para cada elemento da lista.
    ListNode *node = list->head;
    do
    {
        counter++;
        node = node->next;

        // Determinamos o fim da lista quando o próximo elemento for o primeiro elemento da lista.
    } while (node != list->head);

    return counter;
}

// Retorna o endereço de memória do último nó da lista
ListNode *cl_get_last_node(CircularList *list)
{
    ListNode *node = list->head;

    // Se a lista está vazia, retorna nulo.
    if (node == NULL)
        return NULL;

    // Percorre a lista inteira, de forma que ao sair do loop, node será o último elemento da lista.
    while (node->next != list->head)
    {
        node = node->next;
    }

    return node;
}

// Insere um elemento no começo da lista.
int cl_insert_first(CircularList *list, int data)
{
    ListNode *newnode = cl_create_node(data);
    // Se a memória não foi alocada, saí da função retornando erro.
    if (!newnode)
        return 0;

    // Se a lista está vazia
    if (list->head == NULL)
    {
        // O primeiro elemento é o novo elemento, e o próximo é ele mesmo.
        list->head = newnode;
        list->head->next = list->head;

        // Sai da função retornando sucesso.
        return 1;
    }

    ListNode *lastnode = cl_get_last_node(list);
    if (!lastnode)
        return 0;
    // Define o próximo nó do novo elemento como o atual primeiro elemento.
    newnode->next = list->head;
    lastnode->next = newnode;

    list->head = newnode;

    return 1;
}

// Insere um elemento na lista, na posição definida.
int cl_insert(CircularList *list, int pos, int data)
{
    // Se a posição for a primeira, ou se a lista está vazia, insere no começo da lista.
    if (pos == 0 || list->head == NULL)
        return cl_insert_first(list, data);

    if (pos < 0)
        return 0;

    ListNode *newnode = cl_create_node(data);
    if (!newnode)
        return 0;

    // Percorre a lista até o nó que está na posição anterior à desejada.
    ListNode *node = list->head;
    for (int i = 0; i < pos - 1; i++)
    {
        node = node->next;
    }

    // Insere novo nó na posição desejada.
    newnode->next = node->next;
    node->next = newnode;

    return 1;
}

// Checa se existe um elemento na lista com esse dado.
int cl_exists(CircularList *list, int data)
{
    ListNode *node = list->head;

    // Se a lista está vazia, retorna falso.
    if (node == NULL)
        return 0;

    // Percorre a lista inteira.
    do
    {
        // Se algum elemento tiver aquele dado, retorna verdadeiro.
        if (node->data == data)
        {
            return 1;
        }

        node = node->next;
    } while (node != list->head);

    // Se percorrer a lista inteira e não tiver retornado nada, é porque o elemento não existe.
    return 0;
}

// Imprime a lista no terminal.
void cl_print(CircularList *list, char *message)
{
    printf("%s", message);
    // Imprime cada elemento.
    ListNode *node = list->head;
    do
    {
        printf("%d ", node->data);
        node = node->next;
    } while (node != list->head);
    printf("\n");
}

// Libera a memória alocada para todos os elementos da lista, tornando-a vazia.
void cl_clear(CircularList *list)
{
    // Começando do segundo elemento, para não perder a referência ao primeiro e poder determinar o fim da lista.
    ListNode *next = list->head->next;

    while (next != list->head)
    {
        // Endereço do nó que será liberado nessa iteração.
        ListNode *current = next;
        // Endereço do nó que será liberado na próxima iteração é guardado em outra variavel para que não se perca quando o atual for liberado.
        next = current->next;

        // Libera nó atual.
        free(current);
    }
    // Libera primeiro elemento da lista, que foi pulado no loop.
    free(list->head);

    // Volta a lista para o seu estado inicial.
    list->head = NULL;
}

// Libera a memória alocada para a lista.
void cl_free(CircularList *list)
{
    // Libera a memória alocada para cada elemento.
    cl_clear(list);
    // Libera a memória alocada para a estrutura da lista.
    free(list);
}

// Remove o nó com o dado informado da lista.
int cl_erase(CircularList *list, int data)
{
    // Nó anterior começa como o último nó da lista, já após ele vem o primeiro
    ListNode *previous = cl_get_last_node(list);
    if (!previous)
        return 0;

    // Percorre a lista
    for (ListNode *node = list->head; node->next != list->head; node = node->next)
    {
        // Se o dado informado é armazenado naquele nó
        if (node->data == data)
        {
            // Conecta o nó anterior ao removido com próximo
            previous->next = node->next;

            // Se nó for o primeiro da lista, atualiza qual é o primeiro da lista
            if (node == list->head)
                list->head = node->next;

            // Libera a memória alocada para o nó removido
            free(node);

            return 1;
        }

        previous = node;
    }

    return 0;
}

// Remove o nó na posição informada da lista.
int cl_remove(CircularList *list, int pos)
{
    if (pos < 0)
        return 0;

    if (pos == 0)
        return cl_remove_first(list);

    // Percorre a lista té o nó anterior a posição informada
    ListNode *node = list->head;
    for (int i = 0; i < pos - 1; i++)
    {
        node = node->next;
    }
    ListNode *removal = node->next;

    // Conecta o nó anterior ao removido com o próximo
    node->next = removal->next;
    // Libera a memória alocada para o nó removido
    free(removal);

    return 1;
}

// Remove o primeiro nó da lista.
int cl_remove_first(CircularList *list)
{
    ListNode *lastnode = cl_get_last_node(list);
    if (!lastnode)
        return 0;

    // Conecta o último nó da lista com o segundo
    lastnode->next = list->head->next;
    // Libera a memória alocada para o primeiro nó
    free(list->head);
    // Define o segundo nó como novo primeiro
    list->head = lastnode->next;

    return 1;
}

#endif