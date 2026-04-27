#ifndef CARRAY_H
#define CARRAY_H

#include <string>

class cArray {
private:
    int n;       // Số lượng phần tử
    int* arr;    // Con trỏ mảng động

    // Các hàm hỗ trợ nội bộ
    bool isPrime(int x);
    int nhapSoNguyen(std::string prompt);
    int nhapSoNguyenDuong(std::string prompt);

public:
    cArray();
    ~cArray();

    void taoNgauNhien();
    void xuat();

    int demGiaTri(int x);
    bool kiemTraTangDan();

    int timLeNhoNhat(bool& found);
    int timSntLonNhat(bool& found);

    void sapXepTangDan();
    void sapXepGiamDan();
};

#endif
