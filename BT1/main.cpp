#include <iostream>
#include "TamGiac.h"

using namespace std;
double nhapHeSo(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) break;
        cout << "=> LOI: Vui long chi nhap chu so!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return val;
}

// Hàm hỗ trợ chặn thêm lỗi nhập số <= 0 (Dùng cho phóng to, thu nhỏ)
double nhapHeSoDuong(string prompt) {
    double val;
    while (true) {
        val = nhapHeSo(prompt); // Tái sử dụng hàm nhapHeSo để chặn nhập chữ
        if (val > 0) {
            break; // Nếu số > 0 thì thoát vòng lặp, hợp lệ
        }
        cout << "=> LOI: He so phai lon hon 0! Vui long nhap lai.\n";
    }
    return val;
}

int main() {
    cTamGiac tg;

    // 1. Nhập và Xuất
    tg.nhap();
    tg.xuat();

    // 2. Tính toán cơ bản
    cout << "- Loai tam giac: " << tg.kiemTraLoai() << "\n";
    cout << "- Chu vi       : " << tg.tinhChuVi() << "\n";
    cout << "- Dien tich    : " << tg.tinhDienTich() << "\n";

    // 3. Tịnh tiến
    cout << "\n Tinh tien tam giac:\n";
    double dx = nhapHeSo("Nhap he so tinh tien Ox (dx): ");
    double dy = nhapHeSo("Nhap he so tinh tien Oy (dy): ");
    tg.tinhTien(dx, dy);
    cout << "=> Sau khi tinh tien:\n";
    tg.xuat();

    // 4. Phóng to
    cout << "\n Phong to tam giac:\n";
    // Thay nhapHeSo thanh nhapHeSoDuong de bat loi
    double k_phong = nhapHeSoDuong("Nhap he so phong to (k > 0): ");
    tg.phongTo(k_phong);
    cout << "=> Sau khi phong to:\n";
    tg.xuat();

    // 5. Thu nhỏ
    cout << "\n Thu nho tam giac:\n";
    // Thay nhapHeSo thanh nhapHeSoDuong de bat loi
    double k_thu = nhapHeSoDuong("Nhap he so thu nho (k > 0): ");
    tg.thuNho(k_thu);
    cout << "=> Sau khi thu nho:\n";
    tg.xuat();

    // 6. Quay
    cout << "\n Quay tam giac (quanh goc toa do 0,0):\n";
    double goc = nhapHeSo("Nhap goc quay (tinh bang do): ");
    tg.quay(goc);
    cout << "=> Sau khi quay:\n";
    tg.xuat();

    return 0;
}
