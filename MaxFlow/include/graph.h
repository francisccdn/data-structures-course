#ifndef _GRAPH_H_
#define _GRAPH_H_

#define X FLT_MAX

typedef struct graph Graph;
typedef struct vertex Vertex;
typedef struct edge Edge;

Graph *matrix2graph(int n, float m[][n]);
void graph_print(Graph *g);

float fordFulkerson(Graph *g, int s, int t);

void graph_free(Graph *g);

#endif