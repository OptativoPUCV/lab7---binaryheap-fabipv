#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
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
  if(pq->size == 0)
  {
    return;
  }

  heapElem mayor = pq->heapArray[0];

  //mover el ultimo al primero
  pq->heapArray[0] = pq->heapArray[pq->size-1];

  //eliminar
  pq->size--;

  //reordenar 

  int actual = 0;
  int hijoIzq = (2 * actual)+ 1;
  int hijoDer = (2 * actual)+ 2;

  while(true)
  {
    // no tiene hijo izquierdo ni derecho
    if(hijoIzq >= pq->size && hijoDer >= pq->size)
    {
      break;
    }

    
    if(hijoDer < pq->size && pq->heapArray[hijoDer].priority > pq->heapArray[hijoIzq].priority)
    {
      actual = hijoDer;
    }

    if(hijoIzq < pq->size && pq->heapArray[hijoIzq].priority > pq->heapArray[actual].priority)
    {
      if(hijoDer >= pq->size)
      {
        break;
      }
      else if (pq->heapArray[hijoDer].priority <= pq->heapArray[hijoIzq].priority)
      {
        break;
      }
      else
      {
        heapElem aux = pq->heapArray[hijoIzq];
        pq->heapArray[hijoIzq] = pq->heapArray[actual];
        pq->heapArray[actual] = aux;
        actual = hijoIzq;
        
      }  
    }
    else if(pq->heapArray[hijoIzq].priority > pq->heapArray[actual].priority)
    {
      heapElem aux = pq->heapArray[hijoIzq];
      pq->heapArray[hijoIzq] = pq->heapArray[actual];
      pq->heapArray[actual] = aux;
      actual = hijoIzq;
      
    }
    else
    {
      break,
    }
    
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
