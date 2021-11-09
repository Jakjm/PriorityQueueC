/**Definition of heap structure.**/
typedef struct Heap{
	void *array;
	int maxSize; /**The size of the array - this should never change**/
	int size; /**The current size of the heap, which may change**/

	/**Function pointer to the comparison function that is used to determine process priority**/
	int (*compFunc)(void *,void *);
} Heap;
Heap *createHeap(void **array, int n, int (*compFunc)(void *,void *));
void *heapRemove(Heap *heap);
