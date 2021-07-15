#ifndef _BINTREE_H_
#define _BINTREE_H_

typedef struct bintree Tree;

Tree *tree_create_node(int data);
Tree *tree_create(int data, Tree *l, Tree *r);
void tree_print_bars(Tree *tree);
void tree_print_parenthesis(Tree *tree);
void tree_free(Tree *tree);
int tree_exists(Tree *tree, int data);
Tree *tree_find(Tree *tree, int data);
int tree_height(Tree *tree);
Tree *tree_insert(Tree *tree, int data);
int tree_remove(Tree *tree, int data);
int tree_num_leaves(Tree *tree);

#endif
