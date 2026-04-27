#ifndef DAGIAC_H
#define DAGIAC_H

#include <string>

struct Diem {
    double x;
    double y;
};

class cDaGiac {
private:
    int n;          // Số lượng đỉnh
    Diem* dinh;     // Con trỏ quản lý mảng động chứa các đỉnh

    // Các hàm hỗ trợ nội bộ
    double khoangCach(Diem d1, Diem d2);
    double nhapSo(std::string prompt);
    double nhapHeSoDuong(std::string prompt);

public:
    cDaGiac();
    ~cDaGiac(); // Cần Destructor để giải phóng mảng động

    void nhap();
    void xuat();

    double tinhChuVi();
    double tinhDienTich();

    void tinhTien(double dx, double dy);
    void quay(double gocDo);
    void phongTo(double k);
    void thuNho(double k);
};

#endif
