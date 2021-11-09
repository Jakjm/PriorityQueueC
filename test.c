#include <stdio.h>
#include <stdlib.h>

/**Header file for our priority queue/heap**/
#include "heap.h"

int comp(void *item, void *itemTwo){
	return ((int)item) - ((int)itemTwo);
}

void printArray(int *array, int size){
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
	int *array = malloc(sizeof(int) * 10);
	int i;

	for(i = 0;i < 10;++i){
		array[i] = i;
	}
	
	printArray(array,10);
	heap = createHeap(array,10,comp);
	printArray(array,10);
	return 0;
}
