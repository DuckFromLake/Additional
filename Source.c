#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define K 20
#define N 10

int rand10(int mmax) {
	int n = (rand() % mmax);
	printf("%i\n", n);
}

double rand_double(double dmin, double dmax) {
	double n = 1. * (dmax - (dmin))*rand()/RAND_MAX+ (dmin);
	printf("%lf\n", n);
}

int rand10_lot(int n, int mmax) {
	for (int i = 0; i < n; i++) {
		rand10(mmax);
	}
}

double rand_double_lot(int n, double dm) {
	for (int i = 0; i < n; i++) {
		rand_double((-1)*dm, dm);
	}
}

void z1() {
	int m, n = (rand() % 10);
	printf("Угадайте число от 1 до 10\n");
	while (1) {
		scanf("%i", &m);
		if (m == n) {
			printf("YES\n");
			break;
		}
		else {
			printf("NO\n");
		}
	}
}

void z2() {
	int n, m;
	int mmax;
	double dm, dm2;
	printf("Случаенные целые числа в количестве: ");
	scanf("%i", &n);
	printf("Диапазон:");
	scanf("%i", &mmax);
	rand10_lot(n, mmax);
	printf("Случаенные вещественные числа в количестве: ");
	scanf("%i", &m);
	printf("Диапазон:");
	scanf("%lf", &dm);
	rand_double_lot(m, dm);
	printf("\n");
}

 void z3() {
	int COUNT[N];
	int A[K];
	int x = 0;

	for (int i = 0; i < K; i++) {
		A[i] = 0;
	}
	printf("Массив:\n");
	for (int i = 0; i < K; i++) {
		A[i] = (rand() % 10);
		printf("A[%i] = %i\n", i, A[i]);
	}

	printf("\nМассив c переставленными местами соседними элементами:\n");

	for (int i = 1; i < K; i= i +2) {
		x = A[i];
		A[i] = A[i-1];
		A[i - 1] = x;
	}

	for (int i = 0; i < K; i++) {
		printf("A[%i] =  %i\n", i, A[i]);
	}

	for (int i = 0; i < N; i++) {
		COUNT[i] = 0;
	}

	for (int i = 0; i < K; i++) {
		COUNT[A[i]]++;
	}

	printf("\n");
	for (int i = 0; i < N; i++) {
		if (COUNT[i] != 0) {
			printf("%i - %i штук\n", i, COUNT[i]);
		}
	}
}

void main() {
	z1();
	z2();
	z3();
}