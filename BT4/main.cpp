#include <iostream>
#include <limits>
#include "cArray.h"

using namespace std;

// Hàm hỗ trợ nhập số nguyên an toàn cho hàm main()
int nhapX(string prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap so nguyen!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    cArray m;

    // 1. Tạo và xuất mảng
    cout << "[1] Khoi tao mang:\n";
    m.taoNgauNhien();
    m.xuat();

    // 2. Đếm số lần xuất hiện
    cout << "\n[2] Dem gia tri:\n";
    int x = nhapX("Nhap gia tri x can dem: ");
    cout << "=> So lan xuat hien cua " << x << " la: " << m.demGiaTri(x) << " lan\n";

    // 3. Kiểm tra tăng dần
    cout << "\n[3] Kiem tra mang tang dan:\n";
    if (m.kiemTraTangDan()) {
        cout << "=> Mang hien tai DANG tang dan.\n";
    } else {
        cout << "=> Mang hien tai KHONG tang dan.\n";
    }

    // 4. Tìm số lẻ nhỏ nhất
    cout << "\n[4] Tim so le nho nhat:\n";
    bool foundLe;
    int minLe = m.timLeNhoNhat(foundLe);
    if (foundLe) {
        cout << "=> So le nho nhat trong mang la: " << minLe << "\n";
    } else {
        cout << "=> Mang khong co chua so le nao.\n";
    }

    // 5. Tìm số nguyên tố lớn nhất
    cout << "\n[5] Tim so nguyen to lon nhat:\n";
    bool foundSnt;
    int maxSnt = m.timSntLonNhat(foundSnt);
    if (foundSnt) {
        cout << "=> So nguyen to lon nhat trong mang la: " << maxSnt << "\n";
    } else {
        cout << "=> Mang khong co chua so nguyen to nao.\n";
    }

    // 6. Sắp xếp mảng
    cout << "\n[6] Sap xep mang:\n";
    m.sapXepTangDan();
    cout << "=> Mang sau khi sap xep tang dan:\n";
    m.xuat();
    m.sapXepGiamDan();
    cout << "=> Mang sau khi sap xep giam dan:\n";
    m.xuat();

    return 0;
}
