#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "heap.h"

/**
Performs a heap-sink of the item at 'index' into the heap portion of the array, to restore max heap property
[5,8,2] - > [8,5,2] min heap = min item at top

    0
  1   2
3  4 5  6
**/
void iterativeSink(uintptr_t *array, int n, int index, int (*compFunc)(uintptr_t, uintptr_t)){
	uintptr_t swap;
	int left, right, larger;

	/**Index of index's left child is 2*(index + 1) - 1**/
	left = index * 2 + 1;

	/**Index of right child is 2*(index + 1)**/
	right = index * 2 + 2;

	/*While the node at index has two children*/
	while(right < n){
		/**Compare = value of right - value of left.**/
		int compare = compFunc(array[right],array[left]);
		if(compare >= 0)larger = right;
		else larger = left;
	
		
		/*Compare the smaller of the two children with index.*/
		int compare2 = compFunc(array[larger], array[index]);
	
		/**Need to swap to restore heap property.**/
		if(compare2 >= 0){
			/**Swap the higher value item to the top**/
			swap = array[larger];	
			array[larger] = array[index];
			array[index] = swap;

			/**Now we must restore the property at index larger within the array**/
			index = larger;

			left = 2*index + 1;
			right = 2*index + 2;
		}
		else{
			return;
		}
		
	}
	
	/*Last step once we know node at index only has a left child*/
	if(left < n){
		if(compFunc(array[left],array[index]) >= 0){
			swap = array[left];
			array[left] = array[index];
			array[index] = swap;
		}
	}
} 

/**Creates a max heap out of the array using the comparison function*/
/**
*    4              8
* 5    8    ->   5     4
*/
void heapify(uintptr_t *array,int n,int (*compFunc)(uintptr_t , uintptr_t )){
	/**Parent of the last element in the array**/
	int parent = (n >> 1) - 1;

	while(parent >= 0){
		iterativeSink(array,n,parent,compFunc);
		--parent;
	}
}

/*Creates a heap out of the given array using a comparison function.
n is the number of elements in the array/heap**/
Heap *createHeap(uintptr_t *array, int n, int (*compFunc)(uintptr_t ,uintptr_t )){
	Heap *heap = malloc(sizeof(Heap));
	
	/*Put array into a min heap.*/
	heapify(array,n,compFunc);
	
	heap->array = array;
	heap->maxSize = n;
	heap->size = n;
	heap->compFunc = compFunc;
	return heap;
}

uintptr_t heapRemove(Heap *heap){

}
