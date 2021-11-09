#deliverable : what you need to make deliverable
#	COMMAND to produce deliverable using what you need to produce deliverable
test : test.c heap.c heap.h
	gcc -o test heap.c test.c
