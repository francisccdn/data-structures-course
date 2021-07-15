#include <stdio.h>
#include <stdlib.h>

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
    int state;
};

struct edge
{
    int dest;
    Edge *next;
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
    v->state = UNVISITED;

    return v;
}

Edge *edge_create(int j)
{
    Edge *e = (Edge *)malloc(sizeof(Edge));
    if (!e)
        return NULL;
    e->next = NULL;
    e->dest = j;
    return e;
}

Graph *matrix2graph(int n, int m[][n])
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
            if (m[i][j] == 0)
                continue;

            // Se é a primeira aresta da lista de arestas do vertice
            if (g->v[i]->e == NULL)
            {
                // Cria uma aresta com destino j
                g->v[i]->e = edge_create(j);
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
            e->next = edge_create(j);
            if (!e->next)
                return NULL;
        }
    }

    return g;
}

void parse_vertex(Vertex *v, int i)
{
    printf("Visitado: vertice %d\n", i);
}

void breadth_first_search(Graph *g)
{
    for (int i = 0; i < g->n; i++)
        g->v[i]->state = UNVISITED;

    Queue *q = q_create();

    q_enqueue(q, 0);
    g->v[0]->state = VISITING;

    while (!q_is_empty(q))
    {
        // Desenfileirar vertice atual
        int i = -1;
        if (!q_dequeue(q, &i))
        {
            printf("Falha na busca por largura.\n");
            return;
        }

        Edge *e = g->v[i]->e;
        while (e != NULL)
        {
            int j = e->dest;
            if (g->v[j]->state == UNVISITED)
            {
                q_enqueue(q, j);
                g->v[j]->state = VISITING;
            }
            e = e->next;
        }

        parse_vertex(g->v[i], i);
        g->v[i]->state = VISITED;
    }

    q_free(q);
}

void depth_first_search(Graph *g)
{
    for (int i = 0; i < g->n; i++)
        g->v[i]->state = UNVISITED;

    Stack *st = stack_create();

    int i = 0;

    do
    {
        if (g->v[i]->state == UNVISITED)
        {
            parse_vertex(g->v[i], i);
            g->v[i]->state = VISITING;
        }

        Edge *e = g->v[i]->e;
        while (g->v[e->dest]->state != UNVISITED)
        {
            e = e->next;

            if (e == NULL)
                break;
        }

        if (e == NULL)
        {
            g->v[i]->state = VISITED;
            if (!stack_pop(st, &i))
            {
                printf("Falha na busca por profundidade.\n");
                return;
            }
            continue;
        }

        stack_push(st, i);
        i = e->dest;
    } while (!stack_is_empty(st));

    stack_free(st);
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
            printf("-- Aresta de %d ate %d\n", i, e->dest);
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

#endif