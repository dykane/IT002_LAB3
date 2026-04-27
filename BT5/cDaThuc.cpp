#include "cDaThuc.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double cDaThuc::nhapSo(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap so!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int cDaThuc::nhapBac(string prompt) {
    int val;
    while (true) {
        val = (int)nhapSo(prompt);
        if (val >= 0) return val;
        cout << "=> LOI: Bac cua da thuc phai >= 0!\n";
    }
}

cDaThuc::cDaThuc() {
    n = 0;
    heSo = new double[1];
    heSo[0] = 0;
}

cDaThuc::cDaThuc(int bac) {
    n = bac;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        heSo[i] = 0;
    }
}

// Khởi tạo sao chép (Deep Copy)
cDaThuc::cDaThuc(const cDaThuc& other) {
    n = other.n;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        heSo[i] = other.heSo[i];
    }
}

cDaThuc::~cDaThuc() {
    if (heSo != nullptr) {
        delete[] heSo;
        heSo = nullptr;
    }
}

void cDaThuc::nhap() {
    n = nhapBac("Nhap bac cua da thuc (n): ");

    // Cấp phát lại vùng nhớ
    delete[] heSo;
    heSo = new double[n + 1];

    cout << "Nhap cac he so:\n";
    for (int i = n; i >= 0; i--) {
        heSo[i] = nhapSo("  + He so cua x^" + to_string(i) + " : ");
    }
}

void cDaThuc::xuat() {
    bool isFirst = true; // Cờ kiểm tra phần tử đầu tiên in ra để xử lý dấu
    bool isAllZero = true;

    for (int i = n; i >= 0; i--) {
        if (heSo[i] == 0) continue; // Bỏ qua hệ số 0
        isAllZero = false;

        // 1. In dấu
        if (!isFirst) {
            if (heSo[i] > 0) cout << " + ";
            else cout << " - ";
        } else {
            if (heSo[i] < 0) cout << "-";
        }

        // 2. In giá trị hệ số (Lấy trị tuyệt đối vì dấu đã in ở trên)
        double val = abs(heSo[i]);
        // Không in số 1 nếu không phải là hệ số tự do (VD: x^2 thay vì 1x^2)
        if (val != 1 || i == 0) {
            cout << val;
        }

        // 3. In biến x và số mũ
        if (i > 1) cout << "x^" << i;
        else if (i == 1) cout << "x";

        isFirst = false;
    }

    if (isAllZero) cout << "0";
    cout << "\n";
}

double cDaThuc::tinhGiaTri(double x) {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        result += heSo[i] * pow(x, i);
    }
    return result;
}

cDaThuc cDaThuc::cong(const cDaThuc& dt2) {
    int maxBac = (n > dt2.n) ? n : dt2.n;
    cDaThuc ketQua(maxBac); // Tạo đa thức mới chứa kết quả

    for (int i = 0; i <= maxBac; i++) {
        double heSo1 = (i <= n) ? heSo[i] : 0;
        double heSo2 = (i <= dt2.n) ? dt2.heSo[i] : 0;
        ketQua.heSo[i] = heSo1 + heSo2;
    }
    return ketQua;
}

cDaThuc cDaThuc::tru(const cDaThuc& dt2) {
    int maxBac = (n > dt2.n) ? n : dt2.n;
    cDaThuc ketQua(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double heSo1 = (i <= n) ? heSo[i] : 0;
        double heSo2 = (i <= dt2.n) ? dt2.heSo[i] : 0;
        ketQua.heSo[i] = heSo1 - heSo2;
    }
    return ketQua;
}
