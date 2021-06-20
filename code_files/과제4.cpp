#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int UnsortedLinearSearch(int A[], int n, int data) {
	for (int i = 0; i < n; i++) {
		if (A[i] == data) return i;
	}
	return -1;
}

int BinarySearch(int A[], int n, int data) {
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (A[mid] == data) {
			return mid;
		}
		else if (A[mid] < data) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int main() {
	int* arr = (int*)malloc(sizeof(int) * 100000000);

	for (int i = 0; i < 100000000; i++) {
		arr[i] = i * 2;
	}

	clock_t start, end;
	/*
	for (int j = 10000000; j < 50000000; j += 10000000) {
		start = clock();
		for (int i = 0; i < 1000; i++) {
			int index = rand() * 10000 % j;
			UnsortedLinearSearch(arr, j, index);
		}
		end = clock();
		printf("%d : %lf\n", j,(float)(end - start) / 1000);
	}
	*/

	for (int j = 10000000; j < 50000000; j += 10000000) {
		start = clock();
		for (int i = 0; i < 100000; i++) {
			int index = rand() * 10000 % j;
			BinarySearch(arr, j, index);
		}
		end = clock();
		printf("%d : %lf\n", j, (float)(end - start) / 100000);
	}
}