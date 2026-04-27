#include <iostream>
#include "DaGiac.h"

using namespace std;

// Hàm hỗ trợ chống nhập lỗi dành cho main()
double nhapHeSoMain(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap chu so!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

double nhapHeSoDuongMain(string prompt) {
    double val;
    while (true) {
        val = nhapHeSoMain(prompt);
        if (val > 0) return val;
        cout << "=> LOI: He so phai lon hon 0! Vui long nhap lai.\n";
    }
}

int main() {
    cout << "========== CHUONG TRINH QUAN LY DA GIAC ==========\n\n";

    cDaGiac dg;

    // 1. Nhập và Xuất
    dg.nhap();
    cout << "\nThong tin da giac ban dau:\n";
    dg.xuat();

    // 2. Tính toán cơ bản
    cout << "\nTinh toan dac diem:\n";
    cout << "- Chu vi       : " << dg.tinhChuVi() << "\n";
    cout << "- Dien tich    : " << dg.tinhDienTich() << " (Ap dung cho da giac khong tu cat)\n";

    // 3. Tịnh tiến
    cout << "\nTinh tien da giac:\n";
    double dx = nhapHeSoMain("Nhap he so tinh tien Ox (dx): ");
    double dy = nhapHeSoMain("Nhap he so tinh tien Oy (dy): ");
    dg.tinhTien(dx, dy);
    cout << "=> Sau khi tinh tien:\n";
    dg.xuat();

    // 4. Phóng to
    cout << "\nPhong to da giac:\n";
    double k_phong = nhapHeSoDuongMain("Nhap he so phong to (k > 0): ");
    dg.phongTo(k_phong);
    cout << "=> Sau khi phong to:\n";
    dg.xuat();

    // 5. Thu nhỏ
    cout << "\n Thu nho da giac:\n";
    double k_thu = nhapHeSoDuongMain("Nhap he so thu nho (k > 0): ");
    dg.thuNho(k_thu);
    cout << "=> Sau khi thu nho:\n";
    dg.xuat();

    // 6. Quay
    cout << "\nQuay da giac (quanh goc toa do 0,0):\n";
    double goc = nhapHeSoMain("Nhap goc quay (tinh bang do): ");
    dg.quay(goc);
    cout << "=> Sau khi quay:\n";
    dg.xuat();
    return 0;
}
