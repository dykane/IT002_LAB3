#include "cArray.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int cArray::nhapSoNguyen(string prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap so nguyen!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int cArray::nhapSoNguyenDuong(string prompt) {
    int val;
    while (true) {
        val = nhapSoNguyen(prompt);
        if (val > 0) return val;
        cout << "=> LOI: Vui long nhap so nguyen lon hon 0!\n";
    }
}

bool cArray::isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

cArray::cArray() {
    n = 0;
    arr = nullptr;
    srand(time(0)); // Khởi tạo seed cho hàm random dựa trên thời gian thực
}

cArray::~cArray() {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

void cArray::taoNgauNhien() {
    n = nhapSoNguyenDuong("Nhap so luong phan tu cua mang (n > 0): ");

    // Giải phóng vùng nhớ cũ nếu có
    if (arr != nullptr) {
        delete[] arr;
    }
    arr = new int[n];
    cout << "Da tao mang ngau nhien voi cac gia tri tu 0 den 99.\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Sinh số từ 0 -> 99
    }
}

void cArray::xuat() {
    if (n == 0 || arr == nullptr) {
        cout << "Mang rong!\n";
        return;
    }
    cout << "Mang (" << n << " phan tu): [ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int cArray::demGiaTri(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}

bool cArray::kiemTraTangDan() {
    if (n <= 1) return true;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int cArray::timLeNhoNhat(bool& found) {
    int minLe = 0;
    found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) { // Nếu là số lẻ (kể cả âm)
            if (!found) { // Tìm thấy số lẻ đầu tiên
                minLe = arr[i];
                found = true;
            } else if (arr[i] < minLe) { // Các số lẻ tiếp theo
                minLe = arr[i];
            }
        }
    }
    return minLe;
}

int cArray::timSntLonNhat(bool& found) {
    int maxSnt = 0;
    found = false;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            if (!found) {
                maxSnt = arr[i];
                found = true;
            } else if (arr[i] > maxSnt) {
                maxSnt = arr[i];
            }
        }
    }
    return maxSnt;
}

void cArray::sapXepTangDan() {
    // Thuật toán Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Hoán vị
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void cArray::sapXepGiamDan() {
    // Thuật toán Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        // Hoán vị
        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}
