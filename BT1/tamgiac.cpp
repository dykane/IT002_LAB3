#include "TamGiac.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Hằng số Pi và sai số dùng trong so sánh số thực
const double PI = 3.14159265358979323846;
const double EPSILON = 1e-6;

double cTamGiac::nhapSo(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) {
            break; // Nhập đúng số thì thoát vòng lặp
        } else {
            cout << "=> LOI: Vui long chi nhap chu so!\n";
            cin.clear(); // Xóa cờ lỗi của cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua bộ đệm rác
        }
    }
    return val;
}

double cTamGiac::khoangCach(Diem d1, Diem d2) {
    return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
}

bool cTamGiac::kiemTraHopLe(Diem a, Diem b, Diem c) {
    double ab = khoangCach(a, b);
    double bc = khoangCach(b, c);
    double ca = khoangCach(c, a);
    return (ab + bc > ca) && (ab + ca > bc) && (bc + ca > ab);
}
cTamGiac::cTamGiac() {
    A = {0, 0}; B = {3, 0}; C = {0, 4}; // Tam giác vuông mặc định (3,4,5)
}
cTamGiac::cTamGiac(Diem a, Diem b, Diem c) {
    if (kiemTraHopLe(a, b, c)) {
        A = a; B = b; C = c;
    } else {
        cout << "Toa do khong hop le, gan ve tam giac mac dinh (0,0)-(3,0)-(0,4).\n";
        A = {0, 0}; B = {3, 0}; C = {0, 4};
    }
}
cTamGiac::~cTamGiac() {
}
void cTamGiac::nhap() {
    Diem tempA, tempB, tempC;
    do {
        cout << "Nhap toa do 3 dinh cua Tam Giac\n";
        tempA.x = nhapSo("Dinh A - Toa do x: ");
        tempA.y = nhapSo("Dinh A - Toa do y: ");
        tempB.x = nhapSo("Dinh B - Toa do x: ");
        tempB.y = nhapSo("Dinh B - Toa do y: ");
        tempC.x = nhapSo("Dinh C - Toa do x: ");
        tempC.y = nhapSo("Dinh C - Toa do y: ");
        if (!kiemTraHopLe(tempA, tempB, tempC)) {
            cout << "=> LOI: 3 diem khong tao thanh tam giac (thang hang hoac trung nhau). Vui long nhap lai!\n\n";
        } else {
            A = tempA; B = tempB; C = tempC;
            break;
        }
    } while (true);
}
void cTamGiac::xuat() {
    cout << "Tam giac: A(" << A.x << ", " << A.y << "), "
         << "B(" << B.x << ", " << B.y << "), "
         << "C(" << C.x << ", " << C.y << ")\n";
}
double cTamGiac::tinhChuVi() {
    return khoangCach(A, B) + khoangCach(B, C) + khoangCach(C, A);
}
double cTamGiac::tinhDienTich() {
    double a = khoangCach(B, C);
    double b = khoangCach(A, C);
    double c = khoangCach(A, B);
    double p = (a + b + c) / 2.0; // Nửa chu vi
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
string cTamGiac::kiemTraLoai() {
    double a = khoangCach(B, C);
    double b = khoangCach(A, C);
    double c = khoangCach(A, B);
    // Dùng Epsilon để so sánh số thực
    bool vuong = (abs(a*a + b*b - c*c) < EPSILON) ||
                 (abs(a*a + c*c - b*b) < EPSILON) ||
                 (abs(b*b + c*c - a*a) < EPSILON);
    bool can = (abs(a - b) < EPSILON) ||
               (abs(b - c) < EPSILON) ||
               (abs(c - a) < EPSILON);
    bool deu = (abs(a - b) < EPSILON) && (abs(b - c) < EPSILON);
    if (deu) return "Tam giac Deu";
    if (vuong && can) return "Tam giac Vuong Can";
    if (vuong) return "Tam giac Vuong";
    if (can) return "Tam giac Can";
    return "Tam giac Thuong";
}
void cTamGiac::tinhTien(double dx, double dy) {
    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}
void cTamGiac::quay(double gocDo) {
    // Chuyển góc từ Độ sang Radian
    double rad = gocDo * PI / 180.0;
    // Tạo mảng tạm để lặp cho code gọn
    Diem* dinh[] = {&A, &B, &C};
    for (int i = 0; i < 3; i++) {
        double x_moi = dinh[i]->x * cos(rad) - dinh[i]->y * sin(rad);
        double y_moi = dinh[i]->x * sin(rad) + dinh[i]->y * cos(rad);
        dinh[i]->x = x_moi;
        dinh[i]->y = y_moi;
    }
}
void cTamGiac::phongTo(double k) {
    if (k <= 0) {
        return;
    }; // Hệ số phóng to phải dương
    A.x *= k; A.y *= k;
    B.x *= k; B.y *= k;
    C.x *= k; C.y *= k;
}
void cTamGiac::thuNho(double k) {
    if (k <= 0) {
        return;
    }; // Hệ số thu nhỏ phải dương
    A.x /= k; A.y /= k;
    B.x /= k; B.y /= k;
    C.x /= k; C.y /= k;
}
