#include <stdio.h>
#include <stdlib.h>

void qsort_(int Arr[7][10], short start, short stop, short col) {
	int p = Arr[(start + stop) / 2][col], temp;
	short l = start, r = stop;

	while (l <= r) {
		while (Arr[l][col] > p) l++;
		while (Arr[r][col] < p) r--;

		if (l <= r) {
			temp = Arr[l][col];
			Arr[l][col] = Arr[r][col];
			Arr[r][col] = temp;
			l++;
			r--;
		}
	}

	if (r > start) qsort_(Arr, start, r, col);
	if (l < stop) qsort_(Arr, l, stop, col);
}

void printm(int Arr[][10]) {
	for (int i = 0; i <= 10 - 1; i++) {
		for (int j = 0; j <= 10 - 1; j++) printf("%2i ", Arr[i][j]);
		printf("\n");
	}
}
void fill_1(int Arr[][10]) {
	for (short j = 0; j <= 10 - 1; j++)
		for (short i = 0; i <= 10 - 1; i++) Arr[i][j] = i + j + 1;
}
void fill_2(int Arr[][10]) {
	for (short j = 0; j <= 10 - 1; j++)
		for (short i = 0; i <= 10 - 1; i++) Arr[i][j] = 16 - i - j;
}
void fill_3(int Arr[][10]) {
	srand(23);
	for (short j = 0; j <= 10 - 1; j++)
		for (short i = 0; i <= 10 - 1; i++) Arr[i][j] = -9 + rand() % 29;
}


int main() {
	int A[7][10], j;

	printf("Case 1:\n");
	fill_1(A);
	printm(A);
	printf("\nSorted:\n");
	for (j = 0; j <= 10 - 1; j++) qsort_(A, 0, 10 - 1, j);
	printm(A);

	printf("\nCase 2:\n");
	fill_2(A);
	printm(A);
	printf("\nSorted:\n");
	for (j = 0; j <= 10 - 1; j++) qsort_(A, 0, 10 - 1, j);
	printm(A);

	printf("\nCase 3:\n");
	fill_3(A);
	printm(A);
	printf("\nSorted:\n");
	for (j = 0; j <= 10 - 1; j++) qsort_(A, 0, 10 - 1, j);
	printm(A);
}