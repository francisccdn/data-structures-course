#include <stdio.h>
#include "../include/graph.h"

int main(void)
{
    printf("Grafo 1:\n");

    // Matriz adjacencia
    int n = 8;
    int m[8][8] = {
        //0 1  2  3  4  5  6  7
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
    };

    Graph *g = matrix2graph(n, m);

    graph_print(g);

    printf("\n\nBusca por largura:\n");
    breadth_first_search(g);

    printf("\n\nBusca por profundidade:\n");
    depth_first_search(g);

    graph_free(g);

    printf("\n--------------\n");

    printf("Grafo 2:\n");

    // Matriz adjacencia
    int n2 = 9;
    int m2[9][9] = {
        {0, 1, 1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 0},
    };

    Graph *g2 = matrix2graph(n2, m2);

    graph_print(g2);

    printf("\n\nBusca por largura:\n");
    breadth_first_search(g2);

    printf("\n\nBusca por profundidade:\n");
    depth_first_search(g2);

    graph_free(g2);

    return 0;
}