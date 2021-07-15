#include <stdio.h>
#include <stdlib.h>
#include "../include/bintree.h"

#ifndef _BINTREE_C_
#define _BINTREE_C_

// Struct da arvore binaria
struct bintree
{
    int data;
    Tree *l;
    Tree *r;
};

// Cria uma nova (sub)arvore, sem especificar seus filhos
Tree *tree_create_node(int data)
{
    return tree_create(data, NULL, NULL);
}

// Cria uma nova (sub)arvore
Tree *tree_create(int data, Tree *l, Tree *r)
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));

    if (tree == NULL)
    {
        return NULL;
    }

    tree->data = data;
    tree->l = l;
    tree->r = r;

    return tree;
}

// Imprime uma subarvore por diagrama de barras
void subtree_print(Tree *tree, int parent_height)
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
void tree_print_bars(Tree *tree)
{
    if (tree == NULL)
        return;

    int h = tree_height(tree);
    for (int i = 0; i < h; i++)
    {
        printf("-");
    }
    printf(" %d\n", tree->data);
    subtree_print(tree->l, h);
    subtree_print(tree->r, h);
}

void tree_print_parenthesis(Tree *tree)
{
    if (tree == NULL)
        return;

    printf(" (%d", tree->data);
    tree_print_parenthesis(tree->l);
    tree_print_parenthesis(tree->r);
    printf(")");
}

// Libera a memoria alocada para a arvore
void tree_free(Tree *tree)
{
    if (tree == NULL)
        return;

    tree_free(tree->l);
    tree_free(tree->r);

    free(tree);
}

// Checa se a arvore contem o dado informado
int tree_exists(Tree *tree, int data)
{
    if (tree == NULL)
        return 0;

    if (tree->data == data)
        return 1;

    return tree_exists(tree->l, data) || tree_exists(tree->r, data);
}

// Retorna a subarvore cuja raiz tem o dado
Tree *tree_find(Tree *tree, int data)
{
    if (tree == NULL)
        return NULL;

    if (tree->data == data)
        return tree;

    Tree *l = tree_find(tree->l, data);
    Tree *r = tree_find(tree->r, data);

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
int tree_height(Tree *tree)
{
    if (tree == NULL)
        return -1;

    return 1 + max2(tree_height(tree->l), tree_height(tree->r));
}

// Insere um novo no na arvore com o dado informado
Tree *tree_insert(Tree *tree, int data)
{
    // Não permite dados duplicados na arvore
    if (tree_exists(tree, data))
        return NULL;

    // Se a arvore é nula, insere nela mesma
    if (tree == NULL)
    {
        tree = tree_create_node(data);
        return tree;
    }

    // Se não tem filho a esquerda, insere a esquerda
    if (tree->l == NULL)
    {
        tree->l = tree_create_node(data);
        return tree->l;
    }

    // Se não tem filho a direita, insere a direita
    if (tree->r == NULL)
    {
        tree->r = tree_create_node(data);
        return tree->r;
    }

    // Se tem filhos nos dois lados, faz a inserção na subarvore do filho com menos altura
    if (tree_height(tree->l) <= tree_height(tree->r))
        return tree_insert(tree->l, data);
    else
        return tree_insert(tree->r, data);
}

// Remove um nó de acordo com o dado que ele armazena
int tree_remove(Tree *tree, int data)
{
    return 0;
}

// Retorna o numero de folhas da arvore
int tree_num_leaves(Tree *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->l == NULL && tree->r == NULL)
        return 1;

    return tree_num_leaves(tree->r) + tree_num_leaves(tree->l);
}

#endif