#include <stdio.h>
#include <stdlib.h>

#include "../include/linkedlist.h"

#ifndef _LINKED_LIST_C_
#define _LINKED_LIST_C_

// Struct da lista duplamente encadeada.
// Armazena um ponteiro para o primeiro e ultimo nó da lista.
struct linkedlist
{
    ListNode *head;
};

// Struct de nó da lista.
// Armazena o dado informado de tipo real, e um ponteiro para o próximo nó da lista.
struct listnode
{
    float data;
    ListNode *next;
};

// Cria uma nova lista encadeada, retornando seu endereço de memória.
LinkedList *ll_create_list()
{
    // Alocar memória necessária para a lista.
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

    // Se a memória foi alocada sem erros, definir seu primeiro nó como nulo.
    if (list)
        list->head = NULL;

    return list;
}

// Cria um nó da lista, retornando seu endereço de memória.
ListNode *ll_create_node(float data)
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
int ll_is_empty(LinkedList *list)
{
    // Quando ela está vazia, seu primeiro elemento é nulo.
    return list->head == NULL;
}

// Retorna o tamanho da lista.
int ll_size(LinkedList *list)
{
    int counter = 0;
    // Percorre a lista inteira.
    for (ListNode *node = list->head; node != NULL; node = node->next)
    {
        // Incrementa o contador para cada nó da lista.
        counter++;
    }
    return counter;
}

// Insere um elemento no começo da lista.
int ll_insert_first(LinkedList *list, float data)
{
    ListNode *newnode = ll_create_node(data);
    // Se a memória não foi alocada, saí da função retornando erro.
    if (newnode == NULL)
        return 0;

    // Define o atual primeiro nó como próximo do novo.
    newnode->next = list->head;
    // Define o primeiro nó como o novo.
    list->head = newnode;
    return 1;
}

// Insere um elemento no fim da lista.
int ll_insert_last(LinkedList *list, float data)
{
    // Percorre a lista inteira.
    ListNode *node = list->head;
    while (node->next != NULL)
    {
        node = node->next;
    }

    // Cria um novo nó e o define próximo nó do último.
    node->next = ll_create_node(data);

    // Retorna erro se nó não pode ser criado.
    return node->next != NULL;
}

// Checa se existe um elemento na lista com esse dado.
int ll_exists(LinkedList *list, float data)
{
    // Percorre a lista inteira.
    for (ListNode *node = list->head; node != NULL; node = node->next)
    {
        // Se algum elemento tiver aquele dado, retorna verdadeiro.
        if (node->data == data)
            return 1;
    }

    // Se percorrer a lista inteira e não tiver retornado nada, é porque o elemento não existe.
    return 0;
}

// Imprime a lista no terminal.
void ll_print(LinkedList *list, char *message)
{
    printf("%s", message);
    // Imprime cada elemento.
    for (ListNode *node = list->head; node != NULL; node = node->next)
    {
        printf("%f ", node->data);
    }
    printf("\n");
}

// Libera a memória alocada para todos os elementos da lista, tornando-a vazia.
void ll_clear(LinkedList *list)
{
    // Começando do primeiro elemento da lista.
    ListNode *next = list->head;
    
    while (next != NULL)
    {
        // Endereço do nó que será liberado nessa iteração.
        ListNode *current = next;
        // Endereço do nó que será liberado na próxima iteração é guardado em outra variavel para que não se perca quando o atual for liberado.
        next = current->next;

        // Libera nó atual.
        free(current);
    }

    // Volta a lista para o seu estado inicial.
    list->head = NULL;
}

// Libera a memória alocada para a lista.
void ll_free(LinkedList *list)
{
    // Libera a memória alocada para cada elemento.
    ll_clear(list);
    // Libera a memória alocada para a estrutura da lista.
    free(list);
}

// Remove o nó com o dado informado da lista.
int ll_remove(LinkedList *list, float data)
{
    // Se o elemento a ser removido é o primeiro da lista
    if (data == list->head->data)
    {
        ListNode *removal = list->head;
        // Define o segundo nó da lista como novo primeiro nó.
        list->head = removal->next;
        // Libera a memória alocada para o nó removido.
        free(removal);
        return 1;
    }

    // Percorre a lista inteira.
    for (ListNode *node = list->head; node != NULL; node = node->next)
    {
        ListNode *removal = node->next;

        // Se não chegou ao fim da lista, e o dado foi encontrado.
        if (removal != NULL && removal->data == data)
        {
            // Conecta o nó anterior ao removido com o próximo ao removido.
            node->next = removal->next;
            // Libera a memória alocada para o nó removido.
            free(removal);

            return 1;
        }
    }
    return 0;
}

// Insere um elemento na lista em ordem crescente.
int ll_insert_sorted(LinkedList *list, float data)
{
    // Se a lista está vazia, ou se o elemento for menor que o primeiro da lista, insere elemento no começo.
    if (list->head == NULL || list->head->data > data)
    {
        return ll_insert_first(list, data);
    }

    // Cria o novo nó.
    ListNode *newnode = ll_create_node(data);
    if (newnode == NULL)
        return 0;
    
    ListNode *last = list->head;
    ListNode *node = last->next;
    
    // Percorre a lista inteira.
    while (node != NULL)
    {   
        // Se o elemento atual é maior do que o novo
        if (node->data > data)
        {
            // Insere o novo atrás do atual
            newnode->next = node;
            last->next = newnode;

            // E retorna sucesso.
            return 1;
        }

        last = node;
        node = node->next;
    }

    // Se a lista inteira foi percorrida, insere o novo elemento no final da lista e retorna sucesso.
    last->next = newnode;
    return 1;
}

// Retorna o valor do primeiro elemento da lista.
float ll_first(LinkedList *list)
{
    return list->head->data;
}

// Remove o primeiro nó da lista.
int ll_remove_first(LinkedList *list)
{
    ListNode *node = list->head;

    // Define o primeiro nó da lista como o atual segundo.
    list->head = node->next;

    // Libera a memória alocada para o nó removido.
    free(node);
    return 1;
}

// Retorna o valor armazenado no nó de dada posição.
float ll_get(LinkedList *list, int pos)
{
    // Se a posição não existe, ou é a primeira, retorna o primeiro valor.
    if (pos >= ll_size(list) || pos <= 0)
        return list->head->data;

    // Percorre a lista até o nó da posição desejada.
    ListNode *node = list->head;
    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }
    
    // Retorna o conteúdo daquele nó.
    return node->data;
}


#endif
