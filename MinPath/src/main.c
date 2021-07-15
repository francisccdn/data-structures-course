#include <stdio.h>
#include <float.h>
#include "../include/graph.h"

int main(void)
{
    printf("Grafo 1:\n");

    // Matriz adjacencia
    int n = 6;
    float m[6][6] = {
        //S A  B  C  D  E
        //0 1  2  3  4  5
        {X, 10, X, X, X, 8},
        {X, X, X, 2, X, X},
        {X, 1, X, X, X, X},
        {X, X, -2, X, X, X},
        {X, -4, X, -1, X, X},
        {X, X, X, X, 1, X},
    };

    Graph *g = matrix2graph(n, m);

    graph_print(g);

    //bellmanFord(g, 0);
    dijkstra(g, 0, -1);

    printf("\n");
    //graph_print_minpath_costs(g);
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        graph_print_minpath(g, i);
    }

    graph_free(g);

    return 0;
}