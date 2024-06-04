#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
extern int heapSize();
extern int heapDelete();
extern void addHeap();

//updated

void printHeap(int parent, int numItems, int heap[]) {
	printf("<node id=\"%d\">", heap[parent]); //printing the parent
	if (2 * parent + 1 < numItems) {
		printHeap(2 * parent + 1, numItems, heap); //calling function for left child if it exists
		printf("</node>");
	}
	if (2 * parent + 2 < numItems) {
		printHeap(2 * parent + 2, numItems, heap); //calling function for right child if it exists
		printf("</node>");
	}
}

int main(int argc, char * argv[]) {
	int value;
	int heap[100];
	int numItems = 0;
	while (scanf("%d", &value) != EOF) {
		fprintf(stderr, "READING INPUT: %d\n", value);
		//
		heap[numItems] = value;
		numItems++;
	}

	for (int i = 1; i < numItems; i++) {
		int key = heap[i];
		int j = i - 1;
		while (j >= 0 && heap[j] < key) {
			heap[j + 1] = heap[j];
			j = j - 1;
		}
		heap[j + 1] = key;
	}
	
	for(int i = numItems; i >= 0; i--)
		addHeap(heap[i]);

	printf("Printing XML expression for the heap:\n");
	printHeap(0, numItems, heap);
	printf("</node>\n"); //printing final closing node
	
	printf("Printing forward sorted heap:\n");
	for(int i = 0; i < numItems; i++){
		int temp = heapDelete();
		printf("%d\n" , temp);
		push(temp);
	}
	
	printf("Printing reverse sorted heap:\n");
	for(int i = 0; i < numItems; i++){
		printf("%d\n", pop());
	}
	exit(0);
}
