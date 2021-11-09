#include <stdlib.h>
#include "heap.h"

/**Creates a min heap out of the array using the comparison function*/
void heapify(void *array,int n,int (*compFunc)(void *, void *)){

}

/*Creates a heap out of the given array using a comparison function.
n is the number of elements in the array/heap**/
Heap *createHeap(void *array, int n, int (*compFunc)(void *,void *)){
	Heap *heap = malloc(sizeof(Heap));
	
	/*Put array into a min heap.*/
	heapify(array,n,compFunc);
	
	heap->array = array;
	heap->maxSize = n;
	heap->size = n;
	heap->compFunc = compFunc;
	return heap;
}

void *heapRemove(Heap *heap){

}
