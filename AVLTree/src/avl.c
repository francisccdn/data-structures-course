#include <stdio.h>
#include <stdlib.h>
#include "../include/avl.h"

#ifndef _AVL_C_
#define _AVL_C_

// Struct da arvore binaria
struct bintree
{
    int data;
    Avl *l;
    Avl *r;
};

// Cria uma nova (sub)arvore, sem especificar seus filhos
Avl *avl_create_node(int data)
{
    return avl_create(data, NULL, NULL);
}

// Cria uma nova (sub)arvore
Avl *avl_create(int data, Avl *l, Avl *r)
{
    Avl *tree = (Avl *)malloc(sizeof(Avl));

    if (tree == NULL)
    {
        return NULL;
    }

    tree->data = data;
    tree->l = l;
    tree->r = r;

    return tree;
}

// Imprime uma subarvore por um diagrama de barras
void subtree_print(Avl *tree, int parent_height)
{
    if (tree == NULL)
        return;

    int h = parent_height - 1;
    for (int i = 0; i < h; i++)
    {
        printf("-");
    }
    printf(" %d\n", tree->data);
    subtree_print(tree->l, h);
    subtree_print(tree->r, h);
}

// Imprime a arvore por um diagrama de barras
void avl_print_bars(Avl *tree)
{
    if (tree == NULL)
        return;

    int h = avl_height(tree);
    for (int i = 0; i < h; i++)
    {
        printf("-");
    }
    printf(" %d\n", tree->data);
    subtree_print(tree->l, h);
    subtree_print(tree->r, h);
}

void avl_print_parenthesis(Avl *tree)
{
    if (tree == NULL)
        return;

    printf(" (%d", tree->data);
    avl_print_parenthesis(tree->l);
    avl_print_parenthesis(tree->r);
    printf(")");
}

// Libera a memoria alocada para a arvore
void avl_free(Avl *tree)
{
    if (tree == NULL)
        return;

    avl_free(tree->l);
    avl_free(tree->r);

    free(tree);
}

// Checa se a arvore contem o dado informado
int avl_exists(Avl *tree, int data)
{
    if (tree == NULL)
        return 0;

    if (tree->data == data)
        return 1;

    return avl_exists(tree->l, data) || avl_exists(tree->r, data);
}

// Retorna a subarvore cuja raiz tem o dado
Avl *avl_find(Avl *tree, int data)
{
    if (tree == NULL)
        return NULL;

    if (tree->data == data)
        return tree;

    Avl *l = avl_find(tree->l, data);
    Avl *r = avl_find(tree->r, data);

    if (l)
        return l;
    if (r)
        return r;

    return NULL;
}

// Retorna o maior valor entre dois inteiros
int max2(int a, int b)
{
    if (a >= b)
        return a;

    return b;
}

// Retorna a altura da arvore
int avl_height(Avl *tree)
{
    if (tree == NULL)
        return -1;

    return 1 + max2(avl_height(tree->l), avl_height(tree->r));
}

// Retorna a diferença entre a altura da subarvore a direita e a esquerda
// Valores positivos indicam subavore a esquerda maior, negativos indicam subarvore a esquerda maior
int avl_balance_factor(Avl *tree)
{
    return avl_height(tree->l) - avl_height(tree->r);
}

// Operação para restabelecer regulagem: Rotação a direita
Avl *avl_rotate_right(Avl *tree)
{
    Avl *p = tree;
    Avl *u = p->l;
    Avl *t2 = u->r;

    u->r = p;
    p->l = t2;

    return u;
}

// Operação para restabelecer regulagem: Rotação a esquerda
Avl *avl_rotate_left(Avl *tree)
{
    Avl *p = tree;
    Avl *z = p->r;
    Avl *t2 = z->l;

    z->l = p;
    p->r = t2;

    return z;
}

// Operação para restabelecer regulagem: Rotação dupla a direita
Avl *avl_rotate_double_right(Avl *tree)
{
    tree->l = avl_rotate_left(tree->l);
    return avl_rotate_right(tree);
}

// Operação para restabelecer regulagem: Rotação dupla a esquerda
Avl *avl_rotate_double_left(Avl *tree)
{
    tree->r = avl_rotate_right(tree->r);
    return avl_rotate_left(tree);
}

// Se estiver desbalanceada, faz operações para restabelecer a regulagem
void avl_balance(Avl **tree)
{
    // Após inserção, confere balanceamento da arvore
    int balance = avl_balance_factor(*tree);

    if (abs(balance) > 1)
    {
        // Se o filho a esquerda é maior do que o a direita
        if (balance > 0)
        {
            // Se o neto esquerda-direita é maior do que o esquerda-esquerda
            if (avl_balance_factor((*tree)->l) < 0)
                // Rotação dupla direita
                *tree = avl_rotate_double_right(*tree);
            else
                // Rotação direita
                *tree = avl_rotate_right(*tree);
        }

        // Se o filho a direita é maior do que o a esquerda
        if (balance < 0)
        {
            // Se o neto direita-esquerda é maior do que o direita-direita
            if (avl_balance_factor((*tree)->r) > 0)
                // Rotação dupla esquerda
                *tree = avl_rotate_double_left(*tree);
            else
                // Rotação direita
                *tree = avl_rotate_left(*tree);
        }
    }
}

// Insere um novo dado na arvore
Avl *avl_insert(Avl **tree, int data)
{
    // Não permite dados duplicados na arvore
    if (avl_exists(*tree, data))
        return NULL;

    // Se a arvore não tem raiz, torna ela a raiz
    if (*tree == NULL)
    {
        *tree = avl_create_node(data);
        return *tree;
    }

    Avl *inserted_node = NULL;

    // Se o dado é menor do que a raiz da arvore, insere ele na subarvore da esquerda
    if (data < (*tree)->data)
        inserted_node = avl_insert(&((*tree)->l), data);

    // Se o dado é maior do que a raiz da arvore, insere ele na subarvore da direita
    if (data > (*tree)->data)
        inserted_node = avl_insert(&((*tree)->r), data);

    // Se necessário, rebalança a arvore
    avl_balance(tree);

    return inserted_node;
}

int avl_find_parent(Avl *tree, int data, Avl **parent)
{
    if (tree == NULL || tree->data == data)
        return 0;

    if (tree->l != NULL && tree->l->data == data)
    {
        *parent = tree;
        return -1;
    }
    if (tree->r != NULL && tree->r->data == data)
    {
        *parent = tree;
        return 1;
    }

    int l = avl_find_parent(tree->l, data, parent);
    int r = avl_find_parent(tree->r, data, parent);

    if (l != 0)
        return l;
    if (r != 0)
        return r;

    return 0;
}

// Remove um nó de acordo com o dado que ele armazena
int avl_remove(Avl **tree, int data)
{
    if (tree == NULL || !avl_exists(*tree, data))
        return 0;

    Avl *node = avl_find(*tree, data);

    // Se nó tem filho a direita e a esquerda
    if (node->r != NULL && node->l != NULL)
    {
        // Encontrar o sucessor
        Avl *sucessor = node->r;
        while (sucessor->l != NULL)
            sucessor = sucessor->l;

        int sucessor_data = sucessor->data;

        if (!avl_remove(tree, sucessor_data))
            return 0;
        
        node->data = sucessor_data;
    }
    else
    {
        Avl *subtitute;

        // Se nó é uma folha
        if (node->r == NULL && node->l == NULL)
            subtitute = NULL;
        // Se nó só tem filho a direita
        else if (node->r != NULL && node->l == NULL)
            subtitute = node->r;
        // Se nó só tem filho a esquerda
        else if (node->r == NULL && node->l != NULL)
            subtitute = node->l;

        Avl *parent = NULL;
        int dir = 0;
        if ((*tree)->data != data)
            dir = avl_find_parent(*tree, data, &parent);

        if (dir == -1)
        {
            free(parent->l);
            parent->l = subtitute;
        }
        else if (dir == 1)
        {
            free(parent->r);
            parent->r = subtitute;
        }
        else if (dir == 0)
        {
            free(tree);
            *tree = subtitute;
        }
    }

    avl_balance(tree);
    return 1;
}

// Retorna o numero de folhas da arvore
int avl_num_leaves(Avl *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->l == NULL && tree->r == NULL)
        return 1;

    return avl_num_leaves(tree->r) + avl_num_leaves(tree->l);
}

#endif