#include <stdlib.h>
#include <time.h>
#include <stdio.h> 

struct DynArrayStack {
	int top;
	int capacity;
	int* array;
};

struct DynArrayStack* CreateStack(int cap) {
	struct DynArrayStack* S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
	if (!S) return NULL;
	S->capacity = cap;
	S->top = -1;
	S->array = (int*)malloc(S->capacity * sizeof(int));
	if (!S->array)
		return NULL;
	return S;
}
int IsFullStack(struct DynArrayStack* S) {
	return (S->top == S->capacity - 1);
}

void DoubleStack(struct DynArrayStack* S) {
	//clock_t start, end;
	//start = clock();
	S->capacity *= 2;
	S->array = (struct DynArrayStack*)realloc(S->array, S->capacity * sizeof(int));
	//end = clock();
	//printf("%f\n", (float)(end - start));
}

void Push(struct DynArrayStack* S, int x) {
	if (IsFullStack(S))
		DoubleStack(S);
	S->array[++S->top] = x;
}

int IsEmptyStack(struct DynArrayStack* S) {
	return (S->top == -1);
}

int Pop(struct DynArrayStack* S) {
	if (IsEmptyStack(S))
		return INT_MIN;
	return S->array[S->top--];
}


struct ListNode {
	int data;
	struct ListNode* next;
};

struct Stack {
	struct ListNode* top;
};

struct Stack* NCreateStack() {
	struct Stack* stk;
	stk = (struct Stack*)malloc(sizeof(struct Stack));
	stk->top = NULL;
	return stk;
}

int NIsEmptyStack(struct Stack* stk) {
	return (stk->top == NULL);
}

void NPush(struct Stack* stk, int data) {
	struct ListNode* temp;
	temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (!temp)
		return;
	temp->data = data;
	temp->next = stk->top;
	stk->top = temp;
}

int NPop(struct Stack* stk) {
	int data;
	struct ListNode* temp;
	if (NIsEmptyStack(stk))
		return INT_MIN;
	temp = stk->top;
	stk->top = stk->top->next;
	data = temp->data;
	free(temp);
	return data;
}

int main() {
	clock_t start, end;
	
	printf("(1)번\n");
	for (int j = 1000000; j <= 10000000; j += 1000000) {
		struct DynArrayStack* S = CreateStack(1);
		start = clock();
		for (int i = 0; i < j; i++) {
			Push(S, i);
		}
		for (int i = 0; i < j; i++) {
			Pop(S);
		}
		end = clock();
		printf("DynArrayStack %d번 : %d\n", j, (end - start));
	}

	for (int j = 1000000; j <= 10000000; j += 1000000) {
		struct Stack* stk = NCreateStack();
		start = clock();
		for (int i = 0; i < j; i++) {
			NPush(stk, i);
		}
		for (int i = 0; i < j; i++) {
			NPop(stk);
		}
		end = clock();
		printf("LinkedListStack %d번 : %d\n", j, (end - start));
	}
	
	
	printf("(2)번\n");
	for (int j = 1000000; j <= 10000000; j += 1000000) {
		struct DynArrayStack* S = CreateStack(1);
		start = clock();
		for (int i = 0; i < j; i++) {
			Push(S, i);
		}
		end = clock();
		printf("DynArrayStack Push %d번의 평균 1회 실행시간: %f\t", j, (float)(end - start) / j);
		start = clock();
		for (int i = 0; i < j; i++) {
			Pop(S);
		}
		end = clock();
		printf("DynArrayStack Pop %d번의 평균 1회 실행시간: %f\n", j, (float)(end - start)/j);
	}

	for (int j = 1000000; j <= 10000000; j += 1000000) {
		struct Stack* stk = NCreateStack();
		start = clock();
		for (int i = 0; i < j; i++) {
			NPush(stk, i);
		}
		end = clock();
		printf("LinkedListStack Push %d번의 평균 1회 실행시간: %f\t", j, (float)(end - start) / j);
		start = clock();
		for (int i = 0; i < j; i++) {
			NPop(stk);
		}
		end = clock();
		printf("LinkedListStack Pop %d번의 평균 1회 실행시간: %f\n", j, (float)(end - start)/j);
	}
	

	/*
	printf("(3)번\n");

	struct DynArrayStack* S = CreateStack(1);
	for (int i = 0; i < 10000000; i++) {
		if (IsFullStack(S)) {
			start = clock();
			Push(S, i);
			end = clock();
			if ((float)(end - start) != 0.00)
				printf("Array 두 배 증가시키는 경우 %d : %d\n", i, (end - start));
		}
		else {
			start = clock();
			Push(S, i);
			end = clock();
			if ((float)(end - start) != 0.00) {
				printf("Array 그대로인 경우 %d : %d\n", i,(end - start));
			}
		}
	}
	*/

	printf("(4)번\n");
	for (int j = 1000000; j <= 10000000; j += 1000000) {
		struct DynArrayStack* S = CreateStack(1);
		start = clock();
		for (int i = 0; i < j; i++) {
			Push(S, i);
			Pop(S);
		}
		end = clock();
		printf("DynArrayStack %d번 : %d\n", j, (end - start));
	}

	for (int j = 1000000; j <= 10000000; j += 1000000) {
		struct Stack* stk = NCreateStack();
		start = clock();
		for (int i = 0; i < j; i++) {
			NPush(stk, i);
			NPop(stk);
		}
		end = clock();
		printf("LinkedListStack %d번 : %d\n", j, (end - start));
	}
}