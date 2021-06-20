#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <Windows.h>

void BubbleSort(int A[], int n) {
	int swapped = 1;
	for (int pass = n-1; pass > 0 && swapped; pass--) {
		swapped = 0;
		for (int i = 0; i < pass; i++) {
			if (A[i] > A[i + 1]) {
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				swapped = 1;
			}
		}
	}
}

void SelectionSort(int A[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (A[j] < A[min])	min = j;
		}
		temp = A[min];
		A[min] = A[i];
		A[i] = temp;
	}

}

void InsertionSort(int A[], int n) {
	int i, j, key;
	for (i = 1; i <= n - 1; i++) {
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}

		A[j + 1] = key;
	}
}

void Merge(int A[], int temp[], int left, int right, int right_end) {
	int i, j, left_end, size, temp_pos;
	left_end = right - 1;
	size = right_end - left + 1;
	i = left;
	j = right;
	temp_pos = left;

	while ((i <= left_end) && (j <= right_end)) { 
		if (A[i] <= A[j]) {
			temp[temp_pos] = A[i];
			temp_pos = temp_pos + 1;
			i = i + 1;
		}
		else {
			temp[temp_pos] = A[j];
			temp_pos = temp_pos + 1;
			j = j + 1;
		}
	}
	while (i <= left_end) {  
		temp[temp_pos] = A[i];
		temp_pos = temp_pos + 1;
		i = i + 1;
	}
	while (j <= right_end) {     
		temp[temp_pos] = A[j];
		temp_pos = temp_pos + 1;
		j = j + 1;
	}
	for (i = left; i <= right_end; i++) 
		A[i] = temp[i];

}

void MergeSort(int A[], int temp[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(A, temp, left, mid);
		MergeSort(A, temp, mid + 1, right);
		Merge(A, temp, left, mid + 1, right);
	}
}


int Partition(int* A, int left, int right) {
	int low, high, pivot_item = A[left];
	low = left;
	high = right;
	while (low < high) {
		while (low <= right && A[low] <= pivot_item)
			low++;
		while (left <= high && A[high] > pivot_item)
			high--;
		if (low < high) {
			int temp = A[low];
			A[low] = A[high];
			A[high] = temp;
		}
	}


	A[left] = A[high];
	A[high] = pivot_item;
	return high;
}

void QuickSort(int A[], int left, int right) {
	int pivot;
	if (left < right) {
		pivot = Partition(A, left, right);
		QuickSort(A, left, pivot - 1);
		QuickSort(A, pivot + 1, right);
	}
}

int RandomPartition(int* A, int left, int right) {
	int low, high, pivot_index = rand() % (right - left) + left;
	low = left;
	high = right;

	int pivot_item = A[pivot_index];

	int temp = A[left];
	A[left] = A[pivot_index];
	A[pivot_index] = temp;

	while (low < high) {
		while (low <= right && A[low] <= pivot_item)
			low++;
		while (left <= high && A[high] > pivot_item)
			high--;
		if (low < high) {
			int temp = A[low];
			A[low] = A[high];
			A[high] = temp;
		}
	}


	A[left] = A[high];
	A[high] = pivot_item;
	return high;
}

void RandomQuickSort(int A[], int left, int right) {
	int pivot;
	if (left < right) {
		pivot = RandomPartition(A,left,right);
		RandomQuickSort(A, left, pivot - 1);
		RandomQuickSort(A, pivot + 1, right);
	}
}

int main() {
	clock_t start, end;
	
	for (int size = 2000; size <= 10000; size += 2000) {
		printf("<%d>\n", size);
		int* arr = (int*)malloc(sizeof(int) * size);

		for (int i = 0; i < size; i++) {
			arr[i] = rand();
		}

		//Bubble Sort
		int* copiedarr = (int*)malloc(sizeof(int) * size);
		memcpy(copiedarr, arr, sizeof(int) * size);
		
		start = clock();
		BubbleSort(copiedarr, size);
		end = clock();
		printf("Bubble Sort : %d\n", (int)(end - start));

		if (size == 2000) {
			for (int j = 0; j < 20; j++) {
				printf("%d ", copiedarr[j]);
			}
			printf("\n");
		}
		free(copiedarr);

		//Selection Sort
		copiedarr = (int*)malloc(sizeof(int) * size);
		memcpy(copiedarr, arr, sizeof(int) * size);

		start = clock();
		SelectionSort(copiedarr, size);
		end = clock();
		printf("Selection Sort : %d\n", (int)(end - start));

		if (size == 2000) {
			for (int j = 0; j < 20; j++) {
				printf("%d ", copiedarr[j]);
			}
			printf("\n");
		}

		free(copiedarr);

		//Insertion Sort
		copiedarr = (int*)malloc(sizeof(int) * size);
		memcpy(copiedarr, arr, sizeof(int) * size);

		start = clock();
		InsertionSort(copiedarr, size);
		end = clock();
		printf("Insertion Sort : %d\n", (int)(end - start));

		if (size == 2000) {
			for (int j = 0; j < 20; j++) {
				printf("%d ", copiedarr[j]);
			}
			printf("\n");
		}

		free(copiedarr);

		//Merge Sort
		copiedarr = (int*)malloc(sizeof(int) * size);
		memcpy(copiedarr, arr, sizeof(int) * size);
		int* temp = (int*)malloc(sizeof(int) * size);

		start = clock();
		MergeSort(copiedarr, temp, 0, size-1);
		end = clock();
		printf("Merge Sort : %d\n", (int)(end - start));

		if (size == 2000) {
			for (int j = 0; j < 20; j++) {
				printf("%d ", copiedarr[j]);
			}
			printf("\n");
		}

		free(copiedarr);

		//Quick Sort
		copiedarr = (int*)malloc(sizeof(int) * size);
		memcpy(copiedarr, arr, sizeof(int) * size);

		start = clock();
		QuickSort(copiedarr, 0, size-1);
		end = clock();
		printf("Quick Sort : %d\n", (int)(end - start));

		if (size == 2000) {
			for (int j = 0; j < 20; j++) {
				printf("%d ", copiedarr[j]);
			}
			printf("\n");
		}

		free(copiedarr);
		free(arr);
	}
	

	printf("<2¹ø ¹®Á¦>\n");
	for (int size = 2000; size <= 10000; size += 2000) {
		printf("<%d>\n", size);
		int* arr = (int*)malloc(sizeof(int) * size);

		for (int i = 0; i < size; i++) {
			arr[i] = rand();
		}

		QuickSort(arr, 0, size - 1);


		start = clock();
		BubbleSort(arr, size);
		end = clock();
		printf("Bubble Sort : %d\n", (int)(end - start));
		
		start = clock();
		InsertionSort(arr, size);
		end = clock();
		printf("Insertion Sort : %d\n", (int)(end - start));

		start = clock();
		QuickSort(arr, 0, size - 1);
		end = clock();
		printf("Quick Sort : %d\n", (int)(end - start));

		start = clock();
		RandomQuickSort(arr, 0, size - 1);
		end = clock();
		printf("Random Quick Sort : %d\n", (int)(end - start));

	}

}