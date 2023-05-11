#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  //Si esta vacio
  if(pq->size == 0)
  {
    return NULL;
  }

  //Si hay datos en el monticulo
  return pq->heapArray[0].data;
}


void heap_push(Heap* pq, void* data, int priority)
{
  //Revisar si el arreglo esta lleno
  if(pq->size > pq->capac)
  {
    int nuevaCapac = (pq->capac * 2) + 1;
  }

}


void heap_pop(Heap* pq)
{
  

}

Heap* createHeap()
{
  Heap * nuevoHeap = (Heap *) malloc(sizeof(Heap));
  nuevoHeap->heapArray = (heapElem *) malloc(3 * sizeof(heapElem));
  nuevoHeap->size = 0;
  nuevoHeap->capac = 3;

   return nuevoHeap;
}
