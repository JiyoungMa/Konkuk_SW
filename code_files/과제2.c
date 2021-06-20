#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TOTAL 100000
#define DIVISION 10000

typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode;

int* InsertArray() {
	clock_t start;
	clock_t end;
	float time_count;
	float* time_list = (float*)malloc(sizeof(float) * 10);
	int time_index = 0;

	int* arr = (int*)malloc(sizeof(int) * TOTAL);
	start = clock();
	for (int i = 0; i < TOTAL; i++) {
		if (i != 0 && i % DIVISION == 0) {
			end = clock();
			time_list[time_index] = (float)(end - start) / DIVISION;
			time_index++;
			////Sleep(1000);
			start = clock();
		}
		arr[i] = i;
	}
	end = clock();
	time_list[time_index] = (float)(end - start) / DIVISION;

	for (int i = 0; i < 10; i++) {
		printf("%f ", time_list[i]);
	}
	printf("\n");
	return arr;
}

void InsertLinkedList(ListNode* h){
	clock_t start;
	clock_t end;
	float time_count;
	float* time_list = (float*)malloc(sizeof(float) * 10);
	int time_index = 0;

	start = clock();
	for (int i = 0; i < TOTAL; i++) {
		if (i != 0 && i % DIVISION == 0) {
			end = clock();
			time_list[time_index] = (float)(end - start) / DIVISION;
			time_index++;
			////Sleep(1000);
			start = clock();
		}
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->data = i;
		newNode->next = h->next;
		h->next = newNode;
	}
	end = clock();
	time_list[time_index] = (float)(end - start) / DIVISION;

	for (int i = 0; i < 10; i++) {
		printf("%f ", time_list[i]);
	}
	printf("\n");
}

long long int ReadArray(int* arr) {
	long long int result = 0;
	int index;

	for (int i = 0; i < TOTAL; i++) {
		index = rand() % TOTAL;
		result += arr[index];
	}
	return result;
}

long long int ReadLinkedList(ListNode* h) {
	long long int result = 0;
	int index;
	for (int i = 0; i < TOTAL; i++) {
		index = rand() % TOTAL;
		ListNode* now = h;
		for (int j = 0; j <= index; j++) {
			now = now->next;
		}
		result += now->data;
	}
	return result;
}

void DeleteArray(int* arr) {
	clock_t start;
	clock_t end;
	float time_count;
	float* time_list = (float*)malloc(sizeof(float) * 10);
	int time_index = 0;

	int index;
	int now_size = TOTAL;
	start = clock();
	for (int i = 0; i < TOTAL; i++) {
		if (i != 0 && i % DIVISION == 0) {
			end = clock();
			time_list[time_index] = (float)(end - start) / DIVISION;
			time_index++;
			////Sleep(1000);
			start = clock();
		}
		srand(time(NULL));
		index = rand() % now_size;
		for (int j = index; j < now_size; j++) {
			arr[j] = arr[j + 1];
		}
		now_size--;
	}
	end = clock();
	time_list[time_index] = (float)(end - start) / DIVISION;

	for (int i = 0; i < 10; i++) {
		printf("%f ", time_list[i]);
	}
	printf("\n");
}

void DeleteLinkedList(ListNode* h) {
	clock_t start;
	clock_t end;
	float time_count;
	float* time_list = (float*)malloc(sizeof(float) * 10);
	int time_index = 0;

	int index;
	int now_size = TOTAL;
	start = clock();
	for (int i = 0; i < TOTAL; i++) {
		if (i != 0 && i % DIVISION == 0) {
			end = clock();
			time_list[time_index] = (float)(end - start) / DIVISION;
			time_index++;
			////Sleep(1000);
			start = clock();
		}
		index = rand()*10 % now_size;
		ListNode* now = h;
		ListNode* prev = h;
		for (int j = 0; j <= index; j++) {
			prev = now;
			now = now->next;
		}
		prev->next = now->next;
		free(now);
		now_size--;
	}
	end = clock();
	time_list[time_index] = (float)(end - start) / DIVISION;

	for (int i = 0; i < 10; i++) {
		printf("%f ", time_list[i]);
	}
	printf("\n");
}

int main() {

	int* arr = InsertArray();

	ListNode* h = (ListNode*)malloc(sizeof(ListNode));
	h->data = NULL;
	h->next = NULL;

	InsertLinkedList(h);

//	ReadArray(arr);
//	ReadLinkedList(h);

	DeleteArray(arr);
	DeleteLinkedList(h);
}