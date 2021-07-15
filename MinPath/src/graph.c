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
    int state;
    float cost;
    int prev_vertex;
};

struct edge
{
    int dest;
    Edge *next;
    float cost;
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
    v->cost = FLT_MAX;
    v->prev_vertex = -1;

    return v;
}

Edge *edge_create(int j, float w)
{
    Edge *e = (Edge *)malloc(sizeof(Edge));
    if (!e)
        return NULL;
    e->next = NULL;
    e->dest = j;
    e->cost = w;
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
                g->v[i]->e = edge_create(j, m[i][j]);
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
            e->next = edge_create(j, m[i][j]);
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
            printf("-> Aresta de %d ate %d - Peso: %.2f\n", i, e->dest, e->cost);
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

int edge_relaxation(Graph *g, int i, int j, float cost_i_to_j)
{
    if (g->v[j]->cost > g->v[i]->cost + cost_i_to_j)
    {
        g->v[j]->cost = g->v[i]->cost + cost_i_to_j;
        g->v[j]->prev_vertex = i;
        return 1;
    }
    return 0;
}

void reset_vertex_path(Graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        g->v[i]->cost = FLT_MAX;
        g->v[i]->prev_vertex = -1;
        g->v[i]->state = UNVISITED;
    }
}

void bellmanFord(Graph *g, int s)
{
    reset_vertex_path(g);
    g->v[s]->cost = 0;

    // Iteração do algoritmo
    for (int k = 0; k < g->n - 1; k++)
    {
        int improvement = 0; // Monitora se há melhoria numa iteração

        // Passa por cada um dos vértices
        for (int i = 0; i < g->n; i++)
        {
            // Passa pelas arestas do vertice i
            for (Edge *e = g->v[i]->e; e != NULL; e = e->next)
            {
                if (edge_relaxation(g, i, e->dest, e->cost))
                    improvement = 1;
            }
        }

        if (!improvement)
            break;
    }
}

int dijkstra_find_min(Graph *g)
{
    int min = -1;
    for (int i = 0; i < g->n; i++)
    {
        if (g->v[i]->state != VISITING)
            continue;

        if (min < 0 || g->v[i]->cost < g->v[min]->cost)
            min = i;
    }
    return min;
}

void dijkstra(Graph *g, int s, int t)
{
    reset_vertex_path(g);
    g->v[s]->cost = 0;
    g->v[s]->state = VISITING;

    while (1)
    {
        int i = dijkstra_find_min(g);

        if (i == t || i == -1)
            break;

        g->v[i]->state = VISITED;

        // Passa pelas arestas do vertice i
        for (Edge *e = g->v[i]->e; e != NULL; e = e->next)
        {
            if (g->v[e->dest]->state == VISITED)
                continue;

            edge_relaxation(g, i, e->dest, e->cost);
            g->v[e->dest]->state = VISITING;
        }
    }
}

void graph_print_minpath_costs(Graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        printf("Custo do caminho minimo ate %d: %f\n", i, g->v[i]->cost);
    }
}

void vertex_print_minpath(Graph *g, int i)
{
    printf(" <- %d", i);
    if (g->v[i]->prev_vertex >= 0)
        vertex_print_minpath(g, g->v[i]->prev_vertex);
}

void graph_print_minpath(Graph *g, int i)
{
    printf("Caminho de custo minimo até %d:\n", i);
    printf("Custo: %.2f\n", g->v[i]->cost);
    printf("Caminho: %d", i);
    if (g->v[i]->prev_vertex >= 0)
        vertex_print_minpath(g, g->v[i]->prev_vertex);
    printf("\n");
}

#endif