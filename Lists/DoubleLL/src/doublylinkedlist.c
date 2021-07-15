#include <stdio.h>
#include <stdlib.h>

#include "../include/doublylinkedlist.h"

#ifndef _DOUBLY_LINKED_LIST_C_
#define _DOUBLY_LINKED_LIST_C_

// Struct da lista duplamente encadeada.
// Armazena um ponteiro para o primeiro e ultimo nó da lista.
struct doublylinkedlist
{
    ListNode *head;
    ListNode *tail;
};

// Struct de nó da lista.
// Armazena o dado informado de tipo inteiro, um ponteiro para o próximo nó da lista, e um ponteiro para o nó anterior.
struct listnode
{
    int data;
    ListNode *next;
    ListNode *prev;
};

// Cria uma nova lista duplamente encadeada, retornando seu endereço de memória.
DLinkedList *dll_create_list()
{
    // Alocar memória necessária para a lista.
    DLinkedList *list = (DLinkedList *)malloc(sizeof(DLinkedList));
    
    // Se a memória foi alocada sem erros, definir seu primeiro e ultimo nós como nulo.
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }

    return list;
}

// Cria um nó da lista, retornando seu endereço de memória.
ListNode *dll_create_node(int data)
{
    // Alocar memória necessária para um nó.
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    // Se a memória foi alocada sem erros, definir o dado armazenado, e o próximo e ultimo nós como nulo.
    if (node)
    {
        node->data = data;
        node->next = NULL;
        node->prev = NULL;
    }

    return node;
}

// Checa se a lista está vazia.
int dll_is_empty(DLinkedList *list)
{
    // Quando ela está vazia, seu primeiro elemento é nulo.
    return list->head == NULL;
}

// Retorna o tamanho da lista.
int dll_size(DLinkedList *list)
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
int dll_insert_first(DLinkedList *list, int data)
{
    ListNode *newnode = dll_create_node(data);
    // Se a memória não foi alocada, saí da função retornando erro.
    if (newnode == NULL)
        return 0;

    if (dll_is_empty(list))
    {
        // Se a lista está vazia, o primeiro e ultimo nó da lista são o novo nó.
        list->head = newnode;
        list->tail = newnode;
    }
    else
    {
        // Define o próximo nó do novo nó como o atual primeiro
        newnode->next = list->head;
        // Define o nó anterior do atual primeiro nó como o novo nó
        newnode->next->prev = newnode;
        // Define o novo nó como primeiro da lista
        list->head = newnode;
    }

    return 1;
}

// Insere um elemento no fim da lista.
int dll_insert_last(DLinkedList *list, int data)
{
    ListNode *newnode = dll_create_node(data);
    // Se a memória não foi alocada, saí da função retornando erro.
    if (newnode == NULL)
        return 0;

    if (dll_is_empty(list))
    {
        // Se a lista está vazia, o primeiro e ultimo nó da lista são o novo nó.
        list->head = newnode;
        list->tail = newnode;
    }
    else
    {
        // Define o nó anterior do novo nó como o atual ultimo
        newnode->prev = list->tail;
        // Define o próximo nó do atual ultimo como o novo nó
        list->tail->next = newnode;
        // Define o novo nó como ultimo da lista
        list->tail = newnode;
    }

    return 1;
}

// Insere um elemento na lista, na posição definida.
int dll_insert(DLinkedList *list, int pos, int data)
{
    // Se a posição for a primeira, ou se a lista está vazia, insere no começo da lista.
    if (pos == 0 || dll_is_empty(list))
        return dll_insert_first(list, data);
    // Se a posição for a ultima, insere no final da lista.
    else if (pos == dll_size(list))
        return dll_insert_last(list, data);

    // Se a posição não existir, retorna erro.
    if (pos > dll_size(list) || pos < 0)
        return 0;

    // Percorre a lista até o nó que está na posição definida.
    ListNode *node = list->head;
    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }

    ListNode *newnode = dll_create_node(data);
    if (newnode == NULL)
        return 0;

    // Conecta o nó anterior ao da posição desejada com o novo nó como próximo
    node->prev->next = newnode;
    // Conecta o novo nó com o nó anterior ao da posição desejada como anterior
    newnode->prev = node->prev;

    // Conecta o novo nó com o nó da posição desejada como próximo
    newnode->next = node;
    // Conecta  o nó da posição desejada com o novo nó como anterior
    node->prev = newnode;

    return 1;
}

// Checa se existe um elemento na lista com esse dado.
int dll_exists(DLinkedList *list, int data)
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
void dll_print(DLinkedList *list, char *message)
{
    printf("%s", message);
    // Imprime cada elemento.
    for (ListNode *node = list->head; node != NULL; node = node->next)
    {
        printf("%d ", node->data);
    }
    printf("\n");
}

// Libera a memória alocada para todos os elementos da lista, tornando-a vazia.
void dll_clear(DLinkedList *list)
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
    list->tail = NULL;
}

// Libera a memória alocada para a lista.
void dll_free(DLinkedList *list)
{
    // Libera a memória alocada para cada elemento.
    dll_clear(list);
    // Libera a memória alocada para a estrutura da lista.
    free(list);
}

// Remove o nó com o dado informado da lista.
int dll_erase(DLinkedList *list, int data)
{
    // Se o dado é o que está no primeiro nó, chama a função de remover primeiro elemento.
    if (list->head->data == data)
        return dll_remove_first(list);
    
    // Percorre a lista inteira.
    for (ListNode *node = list->head; node != NULL; node = node->next)
    {
        ListNode *removal = node->next;

        // Se não chegou ao fim da lista, e o dado foi encontrado.
        if (removal != NULL && removal->data == data)
        {
            // Conecta o nó anterior ao removido com o próximo ao removido.
            node->next = removal->next;
            node->next->prev = node;

            // Libera a memória alocada para o nó removido.
            free(removal);

            return 1;
        }
    }
    return 0;
}

// Remove o nó na posição informada da lista.
int dll_remove(DLinkedList *list, int pos)
{
    // Se a posição não existe, retorna erro.
    if (pos >= dll_size(list) || pos < 0)
        return 0;

    // Se a posição é a primeira, chama a função de remover primeiro elemento.
    if (pos == 0)
        return dll_remove_first(list);

    // Percorre a lista até o nó da posição desejada.
    ListNode *node = list->head;
    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }

    // Conecta o nó anterior ao removido com o próximo ao removido.
    node->prev->next = node->next;
    node->next->prev = node->prev;

    // Se o nó removido é o primeiro da lista, define o novo primeiro da lista como seu próximo.
    if (list->head == node)
        list->head = node->next;

    // Se o nó removido é o ultimo da lista, define o novo ultimo da lista como seu anterior.
    if (list->tail == node)
        list->tail = node->prev;

    // Libera a memória alocada para o nó removido.
    free(node);
    return 1;
}

// Remove o primeiro nó da lista.
int dll_remove_first(DLinkedList *list)
{
    ListNode *node = list->head;

    // Define o nó anterior ao segundo nó da lista como nulo.
    node->next->prev = NULL;
    // Define o primeiro nó da lista como o atual segundo.
    list->head = node->next;

    // Libera a memória alocada para o nó removido.
    free(node);
    return 1;
}

// Remove o ultimo nó da lista.
int dll_remove_last(DLinkedList *list)
{
    ListNode *node = list->tail;

    // Define o próximo nó do penultimo nó da lista como nulo.
    node->prev->next = NULL;
    // Define o ultimo nó da lista como o atual penultimo.
    list->tail = node->prev;

    // Libera a memória alocada para o nó removido.
    free(node);
    return 1;
}

#endif
