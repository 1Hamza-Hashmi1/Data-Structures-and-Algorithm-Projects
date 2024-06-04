#include "mySort.h"

void mySort(int array[], int first, int last) {
	int k;
	for (int i = first + 1; i <= last; i++) {
		myCopy(&array[i], &k);
		int j = i - 1;

		while (myCompare(k, array[j]) < 0 && myCompare(-1, j) < 0) {
			mySwap(&array[j], &array[j+1]);
			--j;
		}
	}
}


