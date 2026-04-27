#ifndef TAMGIAC_H
#define TAMGIAC_H

#include <string>

// Cấu trúc biểu diễn một điểm trong không gian 2D
struct Diem {
    double x;
    double y;
};

class cTamGiac {
private:
    Diem A, B, C;

    // Các phương thức hỗ trợ nội bộ (private)
    double khoangCach(Diem d1, Diem d2);
    bool kiemTraHopLe(Diem a, Diem b, Diem c);
    double nhapSo(std::string prompt); // Hàm ép nhập số hợp lệ

public:
    // Constructors & Destructor
    cTamGiac();
    cTamGiac(Diem a, Diem b, Diem c);
    ~cTamGiac();

    // Các phương thức cơ bản
    void nhap();
    void xuat();

    // Các phương thức tính toán và xử lý
    std::string kiemTraLoai();
    double tinhChuVi();
    double tinhDienTich();

    // Các phép biến đổi
    void tinhTien(double dx, double dy);
    void quay(double goc); // Xoay quanh gốc tọa độ (giao điểm trục Ox, Oy)
    void phongTo(double k);
    void thuNho(double k);
};

#endif
