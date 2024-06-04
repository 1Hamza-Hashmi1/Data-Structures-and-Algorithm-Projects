#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 8

struct node {
    char identifier;
    int deleteBool;
    struct node *next;
    struct node *prev;
};

struct node nodes[n];

int findNodeIndex(char a);

int * findReachable();

int main(int argc, char * argv[])
{
	// nodes to be used in the lab
	nodes[0].identifier = 'A';
	nodes[1].identifier = 'B';
	nodes[2].identifier = 'C';
	nodes[3].identifier = 'D';
	nodes[4].identifier = 'E';
	nodes[5].identifier = 'F';
	nodes[6].identifier = 'G';
	nodes[7].identifier = 'H';
	
	nodes[0].prev = &nodes[5];
	nodes[0].next = &nodes[7];
	nodes[0].deleteBool = 1;

	nodes[1].prev = &nodes[4];
	nodes[1].next = &nodes[2];
	nodes[1].deleteBool = 1;

	nodes[2].prev = &nodes[4];
	nodes[2].next = &nodes[5];
	nodes[2].deleteBool = 1;

	nodes[3].prev = &nodes[0];
	nodes[3].next = &nodes[1];
	nodes[3].deleteBool = 1;

	nodes[4].prev = &nodes[7];
	nodes[4].next = &nodes[3];
	nodes[4].deleteBool = 1;

	nodes[5].prev = &nodes[6];
	nodes[5].next = &nodes[5];
	nodes[5].deleteBool = 1;

	nodes[6].prev = &nodes[3];
	nodes[6].next = &nodes[1];
	nodes[6].deleteBool = 1;

	nodes[7].prev = &nodes[2];
	nodes[7].next = &nodes[0];
	nodes[7].deleteBool = 1;
	
	struct node* curr;
	curr = &nodes[0];
	
	char str[10];
	char inputA;
	char inputB;
	char inputC;
	int x = 1;
	// array that contains the indexes of nodes to be deleted
	int deleteArr[] = {1, 1, 1, 1, 1, 1, 1, 1};
	
	while ((x) == 1) {
		// Prints current node identifier
		printf("%c\n", curr->identifier);

		// Allows user to input command
		fgets(str, sizeof str, stdin);
		sscanf(str,"%c %c %c", &inputA, &inputB, &inputC);
		
		// If user inputs 'x' exits program
		if (inputA == 'x') {
			x = 0;
		}
		// If user inputs '0' goes to state0 of current node
		else if (inputA == '0') {
			curr = curr->prev;
		}
		// If user inputs '1' goes to state1 of current node
		else if (inputA == '1') {
			curr = curr->next;
		}
		// If user inputs 'c' followed by either '0' or '1' and the name of a node changes current node
		else if (inputA == 'c') {
			if (inputB == '0') {
				curr->prev = &nodes[findNodeIndex(inputC)];
			}
			else if (inputB == '1') {
				curr->next = &nodes[findNodeIndex(inputC)];
			}
		}
		// If user inputs 'p' prints non-deleted values in FSM	
		else if (inputA == 'p') {
			for (int i=0; i<8; i++) {
				if (nodes[i].deleteBool != 0) {
					printf("%c %c %c\n",nodes[i].identifier,
					nodes[i].prev->identifier,
					nodes[i].next->identifier);
				}
			}
		}	
		// If user inputs 'g' identifies non-reachable values       // done wrong
		else if (inputA == 'g') {
			for (int i=0; i<8; i++) {
				deleteArr[i] = 0;
			}

			int j;
			
			// See if a node appears as a next or prev of a node
			for (int i=0; i<8; i++) {
				j = findNodeIndex(nodes[i].next->identifier);
				if (deleteArr[j] == 0 && nodes[i].deleteBool != 0) deleteArr[j]++;
				j = findNodeIndex(nodes[i].prev->identifier);
				if (deleteArr[j] == 0 && nodes[i].deleteBool != 0) deleteArr[j]++;
			}
			
			int garbageExistBool = 0;

			char garbageString[100] = "Garbage: ";

			for (int i=0; i<8; i++) {
				char concatString[3] = {nodes[i].identifier,' ','\0'};
				
				// If a node has not appeared as a next or prev of a node show that it is a garbage value
				if (deleteArr[i] == 0 && nodes[i].deleteBool != 0) {
					strncat(garbageString, concatString, 10);
					garbageExistBool = 1;
				}
			}

			// If no unreachable values are found say 'No garbage', if not then print what nodes are not reachable
			if (garbageExistBool == 0) printf("No garbage.\n");
			else {
				printf(garbageString);
				printf("\n");
			}
		}
		// If user inputs 'd' deletes non-reachable values identified by the 'g' command		
		else if (inputA == 'd') {
			// If a user explains what node to delete checks if node has not been deleted and if the node is unreachable if so deletes the node
			if (inputB == 'A' || inputB == 'B' || inputB == 'C' || inputB == 'D' || inputB == 'E' || inputB == 'F' || inputB == 'G' || inputB == 'H') {
				if (deleteArr[findNodeIndex(inputB)] == 0 && nodes[findNodeIndex(inputB)].deleteBool != 0) {				
					nodes[findNodeIndex(inputB)].deleteBool = 0;
					printf("Deleted.\n");
				}
				else printf("Not deleted.\n");
			}
			// If user does not specify which node to deleted delete all unreachable states that are not deleted
			else {
				int deleteBoolCheck = 0;

				for (int i=0; i<8; i++) {
					if (deleteArr[i] == 0 && nodes[i].deleteBool != 0) deleteBoolCheck = 1;
				}

				if (deleteBoolCheck == 0) {
					printf("No states deleted\n");
				}
				else {
					char deletionString[100] = "Deleted: ";

					for (int i=0; i<8; i++) {
						char concatString[3] = {nodes[i].identifier,' ','\0'};

						if (deleteArr[i] == 0 && nodes[i].deleteBool != 0) {
							strncat(deletionString, concatString, 10);

							nodes[i].deleteBool = 0;
						}
					}

					printf(deletionString);
					printf("\n");
				}

			}
		}		
	}

	exit(1);
}

// Allows the input of a identifier for a node, and outputs the index of that character
int findNodeIndex(char a) {
	for (int i=0; i<8; i++) {
		if (nodes[i].identifier == a) return i;
	}

	return 0;
}

