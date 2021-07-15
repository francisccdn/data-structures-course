#ifndef _GRAPH_H_
#define _GRAPH_H_

#define X FLT_MAX

typedef struct graph Graph;
typedef struct vertex Vertex;
typedef struct edge Edge;

void breadth_first_search(Graph *g);
void depth_first_search(Graph *g);
Graph *matrix2graph(int n, float m[][n]);
void graph_print(Graph *g);

void bellmanFord(Graph *g, int s);
void dijkstra(Graph *g, int s, int t);
void graph_print_minpath_costs(Graph *g);
void graph_print_minpath(Graph *g, int i);

void graph_free(Graph *g);

#endif