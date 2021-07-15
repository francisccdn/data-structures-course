#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "../include/graph.h"
#include "../include/stack.h"
#include "../include/queue.h"

#ifndef _GRAPH_C_
#define _GRAPH_C_

enum VertexState
{
    UNVISITED,
    VISITING,
    VISITED
};

struct graph
{
    int n;
    Vertex **v;
};

struct vertex
{
    Edge *e;
    Edge *src;
    int prev_vertex;
};

struct edge
{
    int src;
    int dest;
    Edge *next;
    float capacity;
    float flow;
};

Graph *graph_create(int n)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (!g)
        return NULL;

    g->n = n;
    g->v = (Vertex **)malloc(n * sizeof(Vertex *));
    if (!g->v)
        return NULL;

    return g;
}

Vertex *vertex_create()
{
    Vertex *v = (Vertex *)malloc(sizeof(Vertex));
    if (!v)
        return NULL;

    v->e = NULL;
    v->src = NULL;
    v->prev_vertex = -1;

    return v;
}

Edge *edge_create(int i, int j, float w)
{
    Edge *e = (Edge *)malloc(sizeof(Edge));
    if (!e)
        return NULL;
    e->next = NULL;
    e->src = i;
    e->dest = j;
    e->capacity = w;
    e->flow = 0;
    return e;
}

Graph *matrix2graph(int n, float m[][n])
{
    // Cria o grafo
    Graph *g = graph_create(n);
    if (!g)
        return NULL;

    // Percorre cada vertice
    for (int i = 0; i < n; i++)
    {
        // Cria o vertice
        g->v[i] = vertex_create();
        if (!g->v[i])
            return NULL;

        // Percorre os outros vertices para identificar ligações
        for (int j = 0; j < n; j++)
        {
            // Se não há aresta de i para j
            if (m[i][j] >= X - 1)
                continue;

            // Se é a primeira aresta da lista de arestas do vertice
            if (g->v[i]->e == NULL)
            {
                // Cria uma aresta com destino j
                g->v[i]->e = edge_create(i, j, m[i][j]);
                if (!g->v[i]->e)
                    return NULL;
                continue;
            }

            // Percorre a lista de arestas do vertice, até que e seja seu ultimo elemento
            Edge *e = g->v[i]->e;
            while (e->next != NULL)
            {
                e = e->next;
            }
            // Cria uma aresta com destino j
            e->next = edge_create(i, j, m[i][j]);
            if (!e->next)
                return NULL;
        }
    }

    return g;
}

void graph_print(Graph *g)
{
    if (g == NULL)
        return;

    for (int i = 0; i < g->n; i++)
    {
        printf("Vertice %d\n", i);

        Edge *e = g->v[i]->e;
        while (e != NULL)
        {
            printf("-> Aresta de %d ate %d - Peso: %.2f\n", i, e->dest, e->capacity);
            e = e->next;
        }
    }
}

void graph_free(Graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        Edge *e = g->v[i]->e;
        while (e != NULL)
        {
            Edge *d = e;
            e = d->next;
            free(d);
        }

        free(g->v[i]);
    }

    free(g->v);
    free(g);
}

void augment_path(Graph *g, int s, int t, float bottleneck)
{
    for (int j = t; j != s; j = g->v[j]->prev_vertex)
    {
        Edge *e = g->v[j]->src;
        e->flow += bottleneck;
    }
}

float fordFulkerson(Graph *g, int s, int t)
{
    while (find_path(g, s, t))
    {
        float bottleneck = compute_bottleneck(g, s, t);
        augment_path(g, s, t, bottleneck);
    }

    // Fluxo maximo é a soma dos fluxos que saem de S
    float flow = 0;
    for (Edge *e = g->v[s]->e; e != NULL; e = e->next)
    {
        flow += e->flow;
    }

    return flow;
}

#endif