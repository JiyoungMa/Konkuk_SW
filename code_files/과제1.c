#include <stdio.h>
#include <time.h>

int factorial(int result, int i) { //Recursion Factorial
	if (i == 1) {
		return result;
	}
	else {
		return factorial(result * i, i - 1);
	}
}

int factorial2(int i) { //iteration Factorial
	int result = 1;
	int n = 1;
	while (n<=i) {
		result = result * n;
		n += 1;
	}
	return result;
}

int fibonacci(int n) { //Recursion Fibonacci
	if (n <= 1) {
		return n;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int fibonacci2(int n) { //Iteration Fibonacci
	int result = NULL;
	int a = 0;
	int b = 1;
	int now = 1;

	while (now < n) {
		result = a + b;
		a = b;
		b = result;
		now += 1;
	}
	return result;
}
int main() {
	clock_t start;
	clock_t end;

	start = clock();
	printf("%d\n", factorial(1, 4500));
	end = clock();
	printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	printf("%d\n", factorial2(4500));
	end = clock();
	printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	printf("%d\n", fibonacci(40));
	end = clock();
	printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	printf("%d\n", fibonacci2(40));
	end = clock();
	printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);
}