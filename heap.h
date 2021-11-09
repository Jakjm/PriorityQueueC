#include <stdint.h>
/**Definition of heap structure.**/
typedef struct Heap{
	uintptr_t *array;
	int maxSize; /**The size of the array - this should never change**/
	int size; /**The current size of the heap, which may change**/

	/**Function pointer to the comparison function that is used to determine process priority**/
	int (*compFunc)(uintptr_t ,uintptr_t );
} Heap;
Heap *createHeap(uintptr_t *array, int n, int (*compFunc)(uintptr_t ,uintptr_t ));
uintptr_t heapRemove(Heap *heap);
