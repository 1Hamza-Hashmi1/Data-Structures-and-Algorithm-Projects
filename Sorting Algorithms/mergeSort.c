#include "mySort.h"

void merge(int array[], int first, int mid, int last) {
	int i, j, k;
	int l = mid - first + 1;
	int r = last - mid;

	int left[l];
	int right[r];

	for (i = 0; i < l; i++)
		myCopy(&array[first + i], &left[i]);
	for (j = 0; j < r; j++)
		myCopy(&array[mid + 1 + j], &right[j]);

	i = 0;
	j = 0;
	k = first;

	while (i < l && j < r) {
		if (myCompare(left[i],right[j]) <= 0) {
			myCopy(&left[i], &array[k]);
			i++;
		} else {
			myCopy(&right[j], &array[k]);
			j++;
		}
		k++;
	}

	while (i < l) {
		myCopy(&left[i], &array[k]);
		i++;
		k++;
	}

	while (j < r) {
		myCopy(&right[j], &array[k]);
		j++;
		k++;
	}
}

void mySort(int array[], int first, int last) {
	if (first < last) {
		int mid = first + (last - first) / 2;
		mySort(array, first, mid);
		mySort(array, mid + 1, last);

		merge(array, first, mid, last);
	}
}
