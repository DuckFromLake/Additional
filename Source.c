#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>

////////////////////////// FUNCTION LIST //////////////////////////

int plus(int* num1, int* num2, int* num3, char* str3);
int minus(int* num1, int* num2, int* num3);
int vardec(char* numstr, int* numint);
int sort(char* numstr1, char* numstr2, char* numstrsort);
int chekeq(char* numstr1, char* numstr2, char* numstrsort);

///////////////////////// MAIN /////////////////////////

void main() {
	char numstr1[2501], numstr11[2501], numstr2[2501], numstr22[2501], numstr3[50001], numstrsort[2501];
	int numint1[2502], numint2[2502], numint3[50002];
	int sizeplus, sizeminus, flag;
	int opp1 = 1, opp2 = 1, opp3 = 1, opp123, oppsort;
	char opper;

	printf("Введите выражение из 2 чисел до 2500 символов!\n\n(Числа от оператора отделять пробелом. Доступны операции сложения и вычетания)\n\n");

	while (1) {
		scanf("%s %c %s", &numstr1, &opper, &numstr2);

		strncpy(numstr11, numstr1, 2501);
		strncpy(numstr22, numstr2, 2501);

		flag = 0;

		if (opper == '-') opp2 = -1;

		if (numstr1[0] == '-') {
			for (int i = 0; i < 2500; i++) {
				numstr1[i] = numstr1[i + 1];
			}
			opp1 = -1;
		}

		if (numstr2[0] == '-') {
			for (int i = 0; i < 2500; i++) {
				numstr2[i] = numstr2[i + 1];
			}
			opp3 = -1;
		}

		opp123 = opp1 * opp2 * opp3;

		if (strlen(numstr1) == strlen(numstr2)) {
			if ((chekeq(numstr1, numstr2, numstrsort) == 1) || (chekeq(numstr1, numstr2, numstrsort) == 2)) {
				sort(numstr1, numstr2, numstrsort);
				oppsort = opp1;
				opp1 = opp3;
				opp3 = opp1;
				flag = 1;
			}
		}
		if (strlen(numstr1) < strlen(numstr2)) {
			sort(numstr1, numstr2, numstrsort);
			oppsort = opp1;
			opp1 = opp3;
			opp3 = opp1;
			flag = 1;
		}
		 
		if ((opp2 == -1) && (flag == 1)) {
			opp1 = opp1 * (-1);
		}

		vardec(numstr1, numint1);
		vardec(numstr2, numint2);

		switch (opp123) {
		case (1):
			system("cls");
			sizeplus = plus(numint1, numint2, numint3, numstr3);
			if (opp1 == 1) {
				printf("%s %c %s = ", numstr11, opper, numstr22);
			}
			else {
				printf("%s %c %s = -", numstr11, opper, numstr22);
			}
				for (int i = sizeplus; i >= 0; i--) {
					printf("%i", numint3[i]);
				}
			printf("\n\n");
			break;
		case (-1):
			system("cls");
				sizeminus = minus(numint1, numint2, numint3, numstr3);
				if (opp1 == 1) {
					printf("%s %c %s = ", numstr11, opper, numstr22);
				}
				else {
					printf("%s %c %s = -", numstr11, opper, numstr22);
				}
			for (int i = sizeminus; i >= 0; i--) {
				printf("%i", numint3[i]);
			}
			printf("\n\n");
			break;
		}
	}

}

////////////////////////// FUNCTIONS //////////////////////////

int plus(int* num1, int* num2, int* num3, char* str3) {
	int size3 = 0, extra = 0;

	for (int i = 0; i < 2501; i++) {
		num3[i] = num1[i] + num2[i] + extra;
		if (num3[i] > 9) {
			extra = num3[i] / 10;
	        num3[i] = num3[i] - (num3[i] / 10) * 10;
		}
		else {
			extra = 0;
		}
	}

	for (int i = 2500; i >= 0; i--) {
		if (num3[i] != 0) {
			size3 = i;
			break;
		}
	}
	return size3;
}

int minus(int* num1, int* num2, int* num3) {
	int size3 = 0, extra = 0;

	for (int i = 0; i < 2501; i++) {
		num3[i] = num1[i] - num2[i] - extra;
		if (num3[i] < 0) {
			extra = 1;
			num3[i] = 10 - fabs(num3[i]);
		}
		else {
			extra = 0;
		}
	}
	for (int i = 2500; i >= 0; i--) {
		if (num3[i] != 0) {
			size3 = i;
			break;
		}
	}
	return size3;
}

int vardec(char* numstr, int* numint) {
	int size = 0;

	for (int i = 0; numstr[i] != '\0'; i++) {
		size = i;
	}

	for (int i = 0; i != 2501; i++) {
		if (i > size) {
			numint[i] = 0;
		}
		else {
			numint[i] = numstr[size - i] - '0';
		}
	}
	return size;
}

int sort(char* numstr1, char* numstr2,char* numstrsort) {

		for (int i = 0; i < 2502; i++) {
			numstrsort[i] = numstr1[i];
			numstr1[i] = numstr2[i];
			numstr2[i] = numstrsort[i];
		}
}

int chekeq(char* numstr1, char* numstr2, char* numstrsort) {
	int chek = 2;
	for (int i = 0; i < 2501; i++) {
		if (numstr1[i] - '0' > numstr2[i] - '0') {
			chek = 0;
			break;
		}
		if (numstr1[i] - '0' < numstr2[i] - '0') {
			chek = 1;
			break;
		}
	}
	return chek;
}