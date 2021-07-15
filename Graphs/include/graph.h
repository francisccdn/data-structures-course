#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct graph Graph;
typedef struct vertex Vertex;
typedef struct edge Edge;

void breadth_first_search(Graph *g);
void depth_first_search(Graph *g);
Graph *matrix2graph(int n, int m[][n]);
void graph_print(Graph *g);

void graph_free(Graph *g);

#endif