#include "stdafx.h"
#include <iostream>
#include <cstdarg>
using namespace std;

static int counter = 0;

int power(int a, int n) {
	counter++;
	if (n == 0) return 1;
	if (n == 1) return a;
	else {
		if (n % 2 == 0) {
			return power(a * a, n / 2);
		}
		else {
			return a * power(a, n - 1);
		}
	}
}


void print(int* list) {
	cout << "[";
	int n = _msize(list) / sizeof(int);	// ��� ����� ������ ������ �������
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << (i == n - 1 ? "" : ", ");  // ��������� ��������
	}
	cout << "]\n";
}

/*��������������� ������� ����������� ������� � ������������ ������*/
int* add(int* source, int m) {
	int size = _msize(source) / sizeof(int);	// ��� ����� ������ ������ �������
	int* dest = new int[size + 1];
	for (int i = 0; i < size; i++)
		dest[i] = source[i];
	dest[size] = m;
	delete[] source;
	return dest;
}

/*��������������� ������� ��������� ������� � ������������ ������� ��� ������� pos*/
int* remove(int* source, int pos) {
	int size = _msize(source) / sizeof(int);	// ��� ����� ������ ������ �������
	int* dest = new int[size - 1];
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (pos != i) {
			dest[k] = source[i];
			k++;
		}
	}
	delete[] source;
	return dest;
}

void diceRoll(int count, int*& list) {
	if (count == 0) {		// ���������� ������. ���� ������� ������ �� ��������, ������� ���������� �� �����.
		print(list);
	}
	else {
		for (int i = 1; i <= 6; i++) {     // for all possible choices  
			list = add(list, i);					// ��������� � ������ �������� ����� ������
			diceRoll(count - 1, list);				// �������� � �����, �������� ���������� �������
			int size = _msize(list) / sizeof(int);  // ��������� ������ �������
			list = remove(list, size - 1);			// ������� ��������� ������� �������
		}
	}

}

void diceRoll(int count) {
	int* list = new int[0]; // ������� ������ ������������ ������
	diceRoll(count, list);
}


void diceSum(int count, int*& list, int sum, int currentSum) {
	if (count == 0) {		// ���������� ������. ���� ������� ������ �� ��������, ������� ���������� �� �����.
		print(list);
	}
	else {
		for (int i = 1; i <= 6; i++) {     // for all possible choices  
			list = add(list, i);					// ��������� � ������ �������� ����� ������
			diceRoll(count - 1, list);				// �������� � �����, �������� ���������� �������
			int size = _msize(list) / sizeof(int);  // ��������� ������ �������
			list = remove(list, size - 1);			// ������� ��������� ������� �������
		}
	}

}


void diceSum(int count, int sum) {
	int* list = new int[0]; // ������� ������ ������������ ������
	diceSum(count, list, sum, 0);
}



int main() {
	cout << power(3, 12) << endl;
	cout << counter << endl;
	diceRoll(2);
}