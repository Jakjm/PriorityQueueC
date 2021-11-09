#include <stdio.h>
#include <stdlib.h>

/**Header file for our priority queue/heap**/
#include "heap.h"

int comp(uintptr_t item, uintptr_t itemTwo){
	return item - itemTwo;
}

void printArray(uintptr_t *array, int size){
	int i;
	for(i = 0;i < size;++i){
		printf("%d ",((int)array[i]));
	}
	printf("\n");
}

/**Testing program for priority queue**/
int main(int argc, char **argv){
	/*Make an array of 0 .. 9*/
	Heap *heap;
	
	uintptr_t *array = malloc(sizeof(uintptr_t) * 10);
	int i;

	for(i = 0;i < 10;++i){
		array[i] = i;
	}
	
	printArray(array,10);
	heap = createHeap(array,10,comp);
	printArray(array,10);

	for(i = 0;i < 10;++i){
		printf("%d ",heapRemove(heap));
	}
	putchar('\n');
	return 0;
}
