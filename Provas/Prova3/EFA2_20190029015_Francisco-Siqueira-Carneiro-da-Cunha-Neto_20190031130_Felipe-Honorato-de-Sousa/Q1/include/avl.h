#ifndef _AVL_H_
#define _AVL_H_

typedef struct bintree Avl;

Avl *avl_create_node(int data);
Avl *avl_create(int data, Avl *l, Avl *r);
void avl_print_bars(Avl *tree);
void avl_print_parenthesis(Avl *tree);
void avl_free(Avl *tree);
int avl_exists(Avl *tree, int data);
Avl *avl_find(Avl *tree, int data);
int avl_height(Avl *tree);
Avl *avl_insert(Avl **tree, int data);
int avl_remove(Avl **tree, int data);
int avl_num_leaves(Avl *tree);

#endif