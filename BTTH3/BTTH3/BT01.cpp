#include<iostream>
using namespace std;

////Tinh tong cac so tu 1 toi n
////TH co so: n = 1
//int tinhTong(int n) {
//	if (n == 1)
//		return 1;
//	return n + tinhTong(n - 1);
//}

//int tinhTong(int n, int tong = 0) {
//	if (n == 0) {
//		return tong;
//	}
//	return tinhTong(n - 1, tong + n);
//}

//int tinhTong(int n) {
//	//THCS
//	if (n == 1) {
//		return pow(1, 2);
//	}
//	return pow(n, 2) + tinhTong(n - 1);
//}

//int tinhTong(int n, int sum = 0) {
//	if (n == 0) {
//		return sum;
//	}
//	return tinhTong(n - 1, sum + pow(n, 2));
//}

//double tinhTong(int n) {
//	if (n == 1)
//		return 1;
//	if (n % 2 == 0) {
//		return tinhTong(n - 1);
//	}
//	return 1.0 / n + tinhTong(n - 2);
//}

//double tinhTong(int n, double sum = 0) {
//	if (n == 0) {
//		return sum;
//	}
//	if (n % 2 == 0) {
//		return tinhTong(n - 1, sum);
//	}
//	return tinhTong(n - 1, sum + 1.0 / n);
//}

int tinhGT(int n, int res = 1) {
	if (n <= 0) {
		return res;
	}
	return tinhGT(n - 1, res * n);
}

int tinhTongGT(int n, int sum = 0) {
	if (n <= 0) {
		return sum;
	}
	return tinhTongGT(n - 1, sum + tinhGT(n));
}

int tinhFibo(int n) {
	if (n <= 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return tinhFibo(n - 2) + tinhFibo(n - 1);
}

double tinhLuyThua(int x, int n, double res = 1) {
	if (n == 0) {
		return res;
	}
	if (n > 0) {
		return tinhLuyThua(x, n - 1, res * x);
	}
	return tinhLuyThua(x, n + 1, res / (x * 1.0));
}

int demChuSo(int n, int dem = 0) {
	if (n == 0) {
		return dem;
	}
	return demChuSo(n / 10, dem + 1);
}

int timSoDaoNguoc(int n, int soDaoNguoc = 0) {
	if (n == 0) {
		return soDaoNguoc;
	}
	return timSoDaoNguoc(n / 10, soDaoNguoc * 10 + n % 10);
}

bool tinhChan(int n) {
	return n % 2 != 0;
}

bool tinhLe(int n) {
	return n % 2 == 0;
}

int tinhTongChuSo(int n, bool func(int), int tong = 0) {
	if (n <= 0) {
		return tong;
	}
	if (func(n)) {
		return tinhTongChuSo(n / 10, func, tong);
	} //Neu la so le thi ko tinh
	return tinhTongChuSo(n / 10, func, tong + n % 10);
}

void inNhiPhan(int n) {
	if (n <= 0) {
		return;
	}

	inNhiPhan(n / 2);
	cout << n % 2;
}

int timUCLN(int a, int b) {
	if (a == b) {
		return a;
	}
	if (a > b) {
		return timUCLN(a - b, b);
	}
	return timUCLN(a, b - a);
}

int tinhTgPascal(int i, int j) {
	if (i == j || j == 1) {
		return 1;
	}
	return tinhTgPascal(i - 1, j - 1) + tinhTgPascal(i - 1, j);
}

int tinhTongMang(int a[], int n, int sum = 0) {
	if (n == 0) {
		return sum;
	}
	return tinhTongMang(a, n - 1, sum + a[n - 1]);
}

int main() {
	cout << tinhTongGT(3) << endl;
	cout << tinhFibo(4) << endl;
	cout << tinhLuyThua(2, 3) << endl;
	cout << demChuSo(2456) << endl;
	cout << timSoDaoNguoc(2456) << endl;
	cout << tinhTongChuSo(2456, tinhChan) << endl;
	inNhiPhan(4);
	cout << endl;
	cout << timUCLN(8, 6) << endl;
	int h = 5;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << tinhTgPascal(i, j) << " ";
		}
		cout << endl;
	}

	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << tinhTongMang(a, n) << endl;

	return 0;
}