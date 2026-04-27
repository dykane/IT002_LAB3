#include "NhanVien.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

bool cNhanVienSX::kiemTraNgayHopLe(int d, int m, int y) {
    if (y < 1900 || y > 2100 || m < 1 || m > 12 || d < 1) return false;
    int maxDays = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) maxDays = 30;
    else if (m == 2) {
        bool isLeap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
        maxDays = isLeap ? 29 : 28;
    }
    return d <= maxDays;
}

int cNhanVienSX::nhapSoNguyenDuong(string prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm
            return val;
        }
        cout << "=> LOI: Vui long nhap so nguyen >= 0!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double cNhanVienSX::nhapSoThucDuong(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
        cout << "=> LOI: Vui long nhap so thuc > 0!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// --- CONSTRUCTORS ---

cNhanVienSX::cNhanVienSX() {
    maNV = "Chua_Co";
    hoTen = "Chua_Co";
    ngaySinh = {1, 1, 2000};
    soSanPham = 0;
    donGia = 0.0;
}

cNhanVienSX::cNhanVienSX(string ma, string ten, Date ns, int sp, double gia) {
    maNV = ma;
    hoTen = ten;
    ngaySinh = ns;
    soSanPham = sp;
    donGia = gia;
}

string cNhanVienSX::getMaNV() { return maNV; }
string cNhanVienSX::getHoTen() { return hoTen; }
Date cNhanVienSX::getNgaySinh() { return ngaySinh; }
int cNhanVienSX::getSoSanPham() { return soSanPham; }
double cNhanVienSX::getDonGia() { return donGia; }

void cNhanVienSX::setMaNV(string ma) { maNV = ma; }
void cNhanVienSX::setHoTen(string ten) { hoTen = ten; }
void cNhanVienSX::setNgaySinh(Date ns) { ngaySinh = ns; }
void cNhanVienSX::setSoSanPham(int sp) { soSanPham = (sp >= 0) ? sp : 0; }
void cNhanVienSX::setDonGia(double gia) { donGia = (gia > 0) ? gia : 0; }


void cNhanVienSX::nhap() {
    cout << "Nhap Ma NV: ";
    getline(cin, maNV);

    cout << "Nhap Ho Ten: ";
    getline(cin, hoTen);

    // Nhập ngày sinh có bẫy lỗi
    while (true) {
        cout << "Nhap Ngay Sinh (ngay thang nam cach nhau boi khoang trang): ";
        if (cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam) {
            if (kiemTraNgayHopLe(ngaySinh.ngay, ngaySinh.thang, ngaySinh.nam)) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            } else {
                cout << "=> LOI: Ngay sinh khong hop le (Vd: 31 2 2000 la sai)!\n";
            }
        } else {
            cout << "=> LOI: Vui long chi nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    soSanPham = nhapSoNguyenDuong("Nhap So san pham: ");
    donGia = nhapSoThucDuong("Nhap Don gia (VND): ");
}

void cNhanVienSX::xuat() {
    // Ép định dạng ngày: DD/MM/YYYY
    string strNgaySinh = to_string(ngaySinh.ngay) + "/" +
                         to_string(ngaySinh.thang) + "/" +
                         to_string(ngaySinh.nam);

    cout << left << setw(10) << maNV
         << "| " << setw(20) << hoTen
         << "| " << setw(12) << strNgaySinh
         << "| " << right << setw(10) << soSanPham
         << "| " << setw(12) << fixed << setprecision(0) << donGia
         << "| " << setw(15) << tinhLuong() << "\n";
}

double cNhanVienSX::tinhLuong() {
    return soSanPham * donGia;
}
