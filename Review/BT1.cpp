#include<iostream>
using namespace std;

#define MAX 10

void input(int arr[], int& n) {
	do {
		cout << "Nhap n: "; cin >> n;
		if (n < 1 || n > MAX)
			cout << "n khong hop le!\n";
	} while (n < 1 || n > MAX);

	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu " << i + 1 << ": ";
		cin >> arr[i];
	}
}

int findMax(const int a, const int b) {
	return a < b ? b : a;
}

int findMin(const int a, const int b) {
	return a > b ? b : a;
}

int findValue(const int arr[], const int n, int func(int a, int b)) {
	int result = arr[0];
	for (int i = 1; i < n; i++) {
		result = func(result, arr[i]);
	}
	return result;
}

int findPosition(const int arr[], const int n, int func(int a, int b)) {
	int result = 0;
	for (int i = 1; i < n; i++) {
		if (func(arr[result], arr[i]) != arr[result])
			result = i;
	}
	return result;
}

bool isPositive(const int n) {
	return n > 0;
}

bool isNegative(const int n) {
	return n < 0;
}

bool isPrime(const int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isSquare(const int n) {
	/*
	Case 1: temp = sqrt(4) = 2
	Case 2: temp = sqrt(5) = 2,236
	*/
	double temp = sqrt(n);
	/*
	Case 1: real = 2 - floor(2 - 1) = 1
	Case 2: real = 2,236 - floor(2,236 - 1) = 0,236
	*/
	double real = temp - floor(temp - 1);
	if (real != 1)
		return false;
	return true;
}

int sum(const int arr[], const int n, bool func(int n)) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (func(arr[i]))
			result += arr[i];
	}
	return result;
}

int main() {
	int arr[MAX];
	int n;
	int max;
	int minPos;
	int result;

	input(arr, n);
	max = findValue(arr, n, findMax);
	minPos = findPosition(arr, n, findMin);
	result = sum(arr, n, isSquare);

	cout << "Max value: " << max << endl;
	cout << "Min position: " << minPos + 1 << endl;
	cout << "Sum: " << result << endl;

	return 1;
}
