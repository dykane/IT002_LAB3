#include "DaGiac.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

const double PI = 3.14159265358979323846;

// --- CÁC PHƯƠNG THỨC HỖ TRỢ (PRIVATE) ---

double cDaGiac::nhapSo(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap chu so!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double cDaGiac::nhapHeSoDuong(string prompt) {
    double val;
    while (true) {
        val = nhapSo(prompt);
        if (val > 0) return val;
        cout << "=> LOI: Gia tri phai lon hon 0!\n";
    }
}

double cDaGiac::khoangCach(Diem d1, Diem d2) {
    return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
}

// --- CONSTRUCTOR & DESTRUCTOR ---

cDaGiac::cDaGiac() {
    n = 0;
    dinh = nullptr; // Khởi tạo con trỏ rỗng
}

cDaGiac::~cDaGiac() {
    // Giải phóng bộ nhớ khi đối tượng bị hủy
    if (dinh != nullptr) {
        delete[] dinh;
        dinh = nullptr;
    }
}

// --- CÁC PHƯƠNG THỨC NHẬP XUẤT ---

void cDaGiac::nhap() {
    // Nhập số lượng đỉnh hợp lệ
    while (true) {
        n = (int)nhapSo("Nhap so luong dinh cua da giac (n >= 3): ");
        if (n >= 3) break;
        cout << "=> LOI: Da giac phai co it nhat 3 dinh!\n";
    }

    // Giải phóng mảng cũ nếu người dùng gọi hàm nhap() nhiều lần
    if (dinh != nullptr) {
        delete[] dinh;
    }

    // Cấp phát mảng động mới
    dinh = new Diem[n];

    cout << "--- Nhap toa do " << n << " dinh ---\n";
    for (int i = 0; i < n; i++) {
        cout << "- Dinh " << i + 1 << ":\n";
        dinh[i].x = nhapSo("  + Toa do x: ");
        dinh[i].y = nhapSo("  + Toa do y: ");
    }
}

void cDaGiac::xuat() {
    if (n == 0 || dinh == nullptr) {
        cout << "Da giac rong!\n";
        return;
    }
    cout << "Da giac co " << n << " dinh: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << dinh[i].x << ", " << dinh[i].y << ")";
        if (i < n - 1) cout << " - ";
    }
    cout << "\n";
}

// --- CÁC PHƯƠNG THỨC TÍNH TOÁN & XỬ LÝ ---

double cDaGiac::tinhChuVi() {
    if (n < 3) return 0;
    double chuVi = 0;
    for (int i = 0; i < n; i++) {
        // Đỉnh kế tiếp (nếu là đỉnh cuối thì nối về đỉnh 0)
        int next = (i + 1) % n;
        chuVi += khoangCach(dinh[i], dinh[next]);
    }
    return chuVi;
}

double cDaGiac::tinhDienTich() {
    if (n < 3) return 0;
    // Sử dụng công thức Shoelace (Công thức tọa độ đa giác)
    double dienTich = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        dienTich += (dinh[i].x * dinh[next].y - dinh[next].x * dinh[i].y);
    }
    return abs(dienTich) / 2.0;
}

void cDaGiac::tinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        dinh[i].x += dx;
        dinh[i].y += dy;
    }
}

void cDaGiac::quay(double gocDo) {
    double rad = gocDo * PI / 180.0;
    for (int i = 0; i < n; i++) {
        double x_moi = dinh[i].x * cos(rad) - dinh[i].y * sin(rad);
        double y_moi = dinh[i].x * sin(rad) + dinh[i].y * cos(rad);
        dinh[i].x = x_moi;
        dinh[i].y = y_moi;
    }
}

void cDaGiac::phongTo(double k) {
    if (k <= 0) return;
    for (int i = 0; i < n; i++) {
        dinh[i].x *= k;
        dinh[i].y *= k;
    }
}

void cDaGiac::thuNho(double k) {
    if (k <= 0) return;
    for (int i = 0; i < n; i++) {
        dinh[i].x /= k;
        dinh[i].y /= k;
    }
}
