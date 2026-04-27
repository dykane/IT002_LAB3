#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>

struct Date {
    int ngay;
    int thang;
    int nam;
};

class cNhanVienSX {
private:
    std::string maNV;
    std::string hoTen;
    Date ngaySinh;
    int soSanPham;
    double donGia;

    // Các hàm hỗ trợ kiểm tra dữ liệu nội bộ
    int nhapSoNguyenDuong(std::string prompt);
    double nhapSoThucDuong(std::string prompt);
    bool kiemTraNgayHopLe(int d, int m, int y);

public:
    // Constructors
    cNhanVienSX();
    cNhanVienSX(std::string ma, std::string ten, Date ns, int sp, double gia);

    // Getters
    std::string getMaNV();
    std::string getHoTen();
    Date getNgaySinh();
    int getSoSanPham();
    double getDonGia();

    // Setters
    void setMaNV(std::string ma);
    void setHoTen(std::string ten);
    void setNgaySinh(Date ns);
    void setSoSanPham(int sp);
    void setDonGia(double gia);

    // Các phương thức xử lý chính
    void nhap();
    void xuat();
    double tinhLuong();
};

#endif
