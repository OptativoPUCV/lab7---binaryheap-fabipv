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
  if(pq->size == pq->capac)
  {
    int nuevaCapac = (pq->capac * 2) + 1;
    pq->heapArray = (heapElem *) realloc(pq->heapArray, nuevaCapac*sizeof(heapElem));
    pq->capac = nuevaCapac;
  }
  
  heapElem new;
  new.data = data;
  new.priority = priority;

  int pos = pq->size;
  pq->heapArray[pos] = new;
  pq->size++;

  int nuevaPos = (pos - 1) / 2;

  while(pos > 0 && (pq->heapArray[pos].priority > pq->heapArray[nuevaPos].priority))
  {
    heapElem aux = pq->heapArray[pos];
    pq->heapArray[pos] = pq->heapArray[nuevaPos];
    pq->heapArray[nuevaPos] = aux;

    pos = nuevaPos;
    nuevaPos = (pos - 1) / 2;
  }
}


void heap_pop(Heap* pq)
{
  //Si esta vacio
  if(pq->size == 0)
  {
    return;
  }
  

}

Heap* createHeap()
{
  Heap * nuevoHeap = (Heap *) malloc(sizeof(Heap));
  nuevoHeap->heapArray = (heapElem *) malloc(3 * sizeof(heapElem));
  nuevoHeap->size = 0;
  nuevoHeap->capac = 3;

   return nuevoHeap;
}
