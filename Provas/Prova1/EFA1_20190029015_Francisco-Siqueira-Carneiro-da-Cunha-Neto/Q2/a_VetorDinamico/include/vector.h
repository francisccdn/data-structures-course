#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct vector DynVector;

DynVector *dv_create(int dim);
int dv_push_back(DynVector *vec, float x);
int dv_size(DynVector *vec);
int dv_get(DynVector *vec, int pos, float *v);
void dv_free(DynVector *vec);

#endif