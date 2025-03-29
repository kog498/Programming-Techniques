#include<iostream>
using namespace std;

int tinhTongMang(int a[], int n, int sum = 0) {
	if (n == 0) {
		return sum;
	}
	return tinhTongMang(a, n - 1, sum + a[n - 1]);
}

int main() {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << tinhTongMang(a, n) << endl;
	return 0;
}