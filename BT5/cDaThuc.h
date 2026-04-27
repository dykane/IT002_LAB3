#ifndef CDATHUC_H
#define CDATHUC_H

#include <string>

class cDaThuc {
private:
    int n;          // Bậc của đa thức
    double* heSo;   // Mảng động lưu hệ số, heSo[i] là hệ số của x^i

    // Các hàm hỗ trợ bẫy lỗi nhập liệu
    double nhapSo(std::string prompt);
    int nhapBac(std::string prompt);

public:
    // Các hàm thiết lập & hủy
    cDaThuc();                          // Mặc định bậc 0
    cDaThuc(int bac);                   // Khởi tạo với bậc chỉ định
    cDaThuc(const cDaThuc& other);      // Copy Constructor (Quan trọng để không rò rỉ bộ nhớ)
    ~cDaThuc();                         // Destructor

    // Các phương thức chính
    void nhap();
    void xuat();
    double tinhGiaTri(double x);

    // Tính toán đa thức
    cDaThuc cong(const cDaThuc& dt2);
    cDaThuc tru(const cDaThuc& dt2);
};

#endif
