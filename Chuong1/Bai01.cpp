#include<iostream>
using namespace std;

#define MAXR 15
#define MAXC 10

void nhapMang2D(int arr[][MAXC], int& r, int& c) {
	do {
		cout << "Nhap so dong: "; cin >> r;
		cout << "Nhap so cot: "; cin >> c;
		if (r < 1 || c < 1 || r > MAXR || c > MAXC)
			cout << "Dau vao khong hop le! Nhap lai!\n";
	} while (r < 1 || c < 1 || r > MAXR || c > MAXC);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Nhap arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
}

void xuatMang2D(const int arr[][MAXC], const int r, const int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

bool isDuong(const int n) {
	return n > 0;
}

bool isAm(const int n) {
	return n < 0;
}

bool isNguyenTo(const int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isHoanThien(const int n) {
	int tong = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0)
			tong += i;
	}
	return tong == n;
}

bool isChinhPhuong(const int n) {
	double tam = sqrt(n);
	double du = tam - floor(tam - 1);
	return du == 1;
}

bool isTangDan(const int a, const int b) {
	return a < b;
}
bool isGiamDan(const int a, const int b) {
	return a > b;
}

bool isDefault(const int n) {
	return true;
}

// Dem so luong phan tu thoa man [func]
// Tham tri [func]: isDuong, isAm, isNguyenTo, isHoanChinh, isChinhPhuong
// Tham tri [func] se mac dinh la isDefault (tinh toan bo phan tu cua ma tran) neu khong duoc truyen
int demSo(const int arr[][MAXC], const int r, const int c, bool func(int) = isDefault) {
	int dem = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (func(arr[i][j]))
				dem++;
		}
	}
	return dem;
}

// Kiem tra trong ma tran co ton tai phan tu nao thoa man [func] khong
// Tham tri [func]: isDuong, isAm, isNguyenTo, isHoanChinh, isChinhPhuong
bool kiemTraMang(const int arr[][MAXC], const int r, const int c, bool func(int)) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (func(arr[i][j]))
				return true;
		}
	}
	return false;
}

// Kiem tra cac phan tu trong 1 cot co tang dan hay giam dan khong
// Luu y: index la [cot] can kiem tra
// Tham tri [func]: isTangDan, isGiamDan
bool kiemTraCot(const int arr[][MAXC], const int r, const int index, bool func(int, int)) {
	for (int i = 0; i < r - 1; i++) {
		if (!func(arr[i][index], arr[i + 1][index]))
			return false;
	}
	return true;
}

// Kiem tra cac phan tu trong 1 dong co tang dan hay giam dan khong
// Luu y: index la [dong] can kiem tra
// Tham tri [func]: isTangDan, isGiamDan
bool kiemTraDong(const int arr[][MAXC], const int c, const int index, bool func(int, int)) {
	for (int j = 0; j < c - 1; j++) {
		if (!func(arr[index][j], arr[index][j + 1]))
			return false;
	}
	return true;
}

// Tinh tong cac phan tu cua ma tran thoa man [func]
// Tham tri [func]: isDuong, isAm, isNguyenTo, isHoanChinh, isChinhPhuong
// Tham tri [func] se mac dinh la isDefault (tinh toan bo phan tu cua ma tran) neu khong duoc truyen
int tinhTongMang(const int arr[][MAXC], const int r, const int c, bool func(int) = isDefault) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (func(arr[i][j]))
				tong += arr[i][j];
		}
	}
	return tong;
}

// Tinh tong cac phan tu trong 1 dong thoa man [func]
// Luu y: index la [dong] can kiem tra
// Tham tri [func]: isDuong, isAm, isNguyenTo, isHoanChinh, isChinhPhuong
// Tham tri [func] se mac dinh la isDefault (tinh toan bo phan tu trong 1 dong) neu khong duoc truyen
int tong1Dong(const int arr[][MAXC], const int c, const int index, bool func(int) = isDefault) {
	int tong = 0;
	for (int j = 0; j < c; j++) {
		if (func(arr[index][j]))
			tong += arr[index][j];
	}
	return tong;
}

// Tim gia tri lon nhat trong mot dong
// Luu y: index la [dong] can tim
int timMax1Dong(const int arr[][MAXC], const int c, const int index) {
	int max = INT16_MIN;
	for (int j = 0; j < c; j++) {
		if (max < arr[index][j])
			max = arr[index][j];
	}
	return max;
}

// Tim gia tri lon nhat trong mot cot
// Luu y: index la [cot] can tim
int timMax1Cot(const int arr[][MAXC], const int r, const int index) {
	int max = INT16_MIN;
	for (int i = 0; i < r; i++) {
		if (max < arr[i][index])
			max = arr[i][index];
	}
	return max;
}

// Tim gia tri nho nhat trong mot dong
// Luu y: index la [dong] can tim
int timMin1Dong(const int arr[][MAXC], const int c, const int index) {
	int min = INT16_MAX;
	for (int j = 0; j < c; j++) {
		if (min > arr[index][j])
			min = arr[index][j];
	}
	return min;
}

// Tim gia tri nho nhat trong mot cot
// Luu y: index la [cot] can tim
int timMin1Cot(const int arr[][MAXC], const int r, const int index) {
	int min = INT16_MAX;
	for (int i = 0; i < r; i++) {
		if (min > arr[i][index])
			min = arr[i][index];
	}
	return min;
}

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

// Sap xep cac phan tu trong 1 dong thoa man [func]
// Luu y: index la [dong] can kiem tra
// Tham tri [func]: isTangDan, isGiamDan
void sapXep1Dong(int arr[][MAXC], const int c, const int index, bool func(int, int)) {
	for (int j = 0; j < c - 1; j++) {
		for (int k = j + 1; k < c; k++) {
			if (!func(arr[index][j], arr[index][k]))
				swap(arr[index][j], arr[index][k]);
		}
	}
}

// Sap xep cac phan tu trong 1 cot thoa man [func]
// Luu y: index la [cot] can kiem tra
// Tham tri [func]: isTangDan, isGiamDan
void sapXep1Cot(int arr[][MAXC], const int r, const int index, bool func(int, int)) {
	for (int i = 0; i < r - 1; i++) {
		for (int k = i + 1; k < r; k++) {
			if (!func(arr[i][index], arr[k][index]))
				swap(arr[i][index], arr[k][index]);
		}
	}
}

// Tinh tong cac phan tu tren duong cheo chinh cua ma tran vuong
// Luu y: Chi co the dung voi [Ma tran Vuong] (so cot = so hang)
int tongCheoChinh(const int arr[][MAXC], const int r, const int c) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j)
				tong += arr[i][j];
		}
	}
	return tong;
}

// Tinh tong cac phan tu tren duong cheo phu cua ma tran vuong
// Luu y: Chi co the dung voi [Ma tran Vuong] (so cot = so hang)
int tongCheoPhu(const int arr[][MAXC], const int r, const int c) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		tong += arr[i][c - i - 1];
	}
	return tong;
}

// Tinh tong cac phan tu nam tren bien cua ma tran
// VD:
// 1 2 3
// 4 5 6
// 7 8 9
// Ket qua: 1 + 2 + 3 + 4 + 6 + 7 + 8 + 9 = 40
int tongBien(const int arr[][MAXC], const int r, const int c) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 || j == 0 || j == c - 1 || i == r - 1)
				tong += arr[i][j];
		}
	}
	return tong;
}

int tong(const int a, const int b) {
	return a + b;
}

int hieu(const int a, const int b) {
	return a - b;
}

int tich(const int a, const int b) {
	return a * b;
}

// Thuc hien tinh toan tung cap phan tu giua 2 mang
// arr1 la mang thu nhat, arr2 la mang thu 2
// ketQua la mang dung de luu gia tri tinh toan
// Tham tri [func]: tong, hieu, tich
// Luu y: 3 ma tran duoc truyen vao phai co cung kich thuoc
// VD:
// Mang 1:		Mang 2:		Ket qua:
// 1 2 3	+	2 3 4	=	3  5  7
// 4 5 6		5 6 7		9 11 13
void tinh2MaTran(const int arr1[][MAXC], const int arr2[][MAXC], int ketQua[][MAXC], const int r, const int c, int func(int, int)) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ketQua[i][j] = func(arr1[i][j], arr2[i][j]);
		}
	}
}

// Kiem tra phan tu arr[i][j] duoc truyen vao co phai la phan tu cuc dai khong
bool isCucDai(int arr[][MAXC], const int r, const int c, const int i, const int j) {
	int di[] = { -1, -1, -1,  0, +1, +1, +1,  0 };
	int dj[] = { -1,  0, +1, +1, +1,  0, -1, -1 };

	for (int d = 0; d < 8; d++) {
		int ni = i + di[d];
		int nj = j + di[d];
		if (ni >= 0 && nj >= 0 && ni < r && j + nj < c) {
			if (arr[i][j] <= arr[ni][nj])
				return false;
		}
	}
	return true;
}

// Kiem tra phan tu arr[i][j] duoc truyen vao co phai la phan tu cuc tieu khong
bool isCucTieu(int arr[][MAXC], const int r, const int c, const int i, const int j) {
	int di[] = { -1, -1, -1,  0, +1, +1, +1,  0 };
	int dj[] = { -1,  0, +1, +1, +1,  0, -1, -1 };

	for (int d = 0; d < 8; d++) {
		int ni = i + di[d];
		int nj = j + di[d];
		if (ni >= 0 && nj >= 0 && ni < r && j + nj < c) {
			if (arr[i][j] >= arr[ni][nj])
				return false;
		}
	}
	return true;
}

// Dem so luong phan tu cuc tri (cuc dai hay cuc tieu) trong ma tran
// Mot phan tu duoc goi la cuc dai khi no lon hon cac phan tu xung quanh (nam tren cot, hang, duong cheo), nguoc lai la cuc tieu
// Tham tri [func]: isCucDai, isCucTieu
int demCucTri(int arr[][MAXC], const int r, const int c, bool func(int[][MAXC], int r, int c, int i, int j)) {
	int dem = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (func(arr, r, c, i, j)) {
				dem++;
			}
		}
	}
	return dem;
}

// So tri = so luong phan tu cuc dai + so luong phan tu cuc tieu
int demSoTri(int arr[][MAXC], const int r, const int c) {
	return demCucTri(arr, r, c, isCucDai) + demCucTri(arr, r, c, isCucTieu);
}

// Phan tu yen ngua la phan tu lon nhat trong mot cot va nho nhat trong mot hang
// hoac la phan tu nho nhat trong mot cot va lon nhat trong mot hang
int demPTYenNgua(const int arr[][MAXC], const int r, const int c) {
	int dem = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((arr[i][j] == timMax1Cot(arr, r, j) && arr[i][j] == timMin1Dong(arr, c, i))
				|| (arr[i][j] == timMin1Cot(arr, r, j) && arr[i][j] == timMax1Dong(arr, c, i))) {
				dem++;
			}
		}
	}
	return dem;
}

// Tim gia tri dau tien thoa man [func] xuat hien tren [dong]
// Tham tri [func]: isDuong, isAm, isNguyenTo, isHoanChinh, isChinhPhuong
// Luu y 1: index la [dong] can kiem tra
// Luu y 2: Neu khong tim duoc gia tri nao thoa man [func] thi ham tra ve -1
int timGTDauTien(const int arr[][MAXC], const int c, const int index, bool func(int)) {
	for (int j = 0; j < c; j++) {
		if (func(arr[index][j]))
			return arr[index][j];
	}
	return -1;
}

int main() {
	int arr[MAXR][MAXC];
	int arr2[MAXR][MAXC];
	int ketQua[MAXR][MAXC];
	int r, c;
	int index;

	nhapMang2D(arr, r, c);
	xuatMang2D(arr, r, c);

	//Test case 1: 1 -> 5
	cout << demSo(arr, r, c, isChinhPhuong) << endl;

	//Test case 2: 6 - 7
	cout << demCucTri(arr, r, c, isCucDai) << endl;

	//Test case 3: 8 - 9
	cout << demSoTri(arr, r, c) << endl;
	cout << demPTYenNgua(arr, r, c) << endl;

	//Test case 4: 10 -> 13
	cout << kiemTraMang(arr, r, c, isHoanThien) << endl;

	//Test case 5: 14 - 15
	cout << "Nhap cot can kiem tra: "; cin >> index;
	cout << kiemTraCot(arr, r, index - 1, isTangDan) << endl;

	//Test case 6: 16 - 17
	cout << "Nhap dong can kiem tra: "; cin >> index;
	cout << kiemTraDong(arr, r, index - 1, isGiamDan) << endl;

	//Test case 7: 18 -> 20
	cout << tinhTongMang(arr, r, c, isNguyenTo) << endl;

	//Test case 8: 21 - 22
	cout << "Nhap dong can tinh: "; cin >> index;
	cout << tong1Dong(arr, c, index - 1, isHoanThien) << endl;

	//Test case 9: 23 - 24
	cout << "Nhap dong can tim: "; cin >> index;
	cout << timMax1Dong(arr, c, index - 1) << endl;

	cout << "Nhap cot can tim: "; cin >> index;
	cout << timMin1Cot(arr, r, index - 1) << endl;

	//Test case 10: 25
	cout << "Nhap dong can tim: "; cin >> index;
	cout << timGTDauTien(arr, c, index - 1, isNguyenTo) << endl;

	//Test case 11: 26 - 27
	cout << "Nhap dong can sap xep: "; cin >> index;
	sapXep1Dong(arr, c, index - 1, isTangDan);
	xuatMang2D(arr, r, c);

	//Test case 12: 28 - 29
	cout << "Nhap cot can sap xep: "; cin >> index;
	sapXep1Cot(arr, r, index - 1, isGiamDan);
	xuatMang2D(arr, r, c);

	//Test case 13: 30 -> 32
	while (r != c) {
		cout << "r != c\n";
		nhapMang2D(arr, r, c);
	}
	cout << tongCheoChinh(arr, r, c) << endl;
	cout << tongCheoPhu(arr, r, c) << endl;

	//Test case 14: 33 -> 35
	cout << "Luu y 2 mang phai cung mot kich thuoc!\n";
	cout << "Nhap mang 1:\n";
	nhapMang2D(arr, r, c);
	cout << "Nhap mang 2:\n";
	nhapMang2D(arr2, r, c);
	tinh2MaTran(arr, arr2, ketQua, r, c, tong);
	cout << "Mang ket qua:\n";
	xuatMang2D(ketQua, r, c);
	return 0;
}
