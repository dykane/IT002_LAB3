#include <iostream>
#include <iomanip>
#include <limits>
#include "NhanVien.h"

using namespace std;

// Hàm hỗ trợ nhập số lượng nhân viên an toàn
int nhapSoLuong(string prompt) {
    int n;
    while (true) {
        cout << prompt;
        if (cin >> n && n > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        }
        cout << "=> LOI: So luong phai la so nguyen > 0!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Hàm so sánh tuổi (người có ngày sinh nhỏ hơn -> ra đời trước -> tuổi cao hơn)
bool nhoHonTuoi(Date d1, Date d2) {
    if (d1.nam != d2.nam) return d1.nam < d2.nam;
    if (d1.thang != d2.thang) return d1.thang < d2.thang;
    return d1.ngay < d2.ngay;
}

// Hàm in tiêu đề bảng
void inTieuDe() {
    cout << left << setw(10) << "Ma NV"
         << "| " << setw(20) << "Ho Ten"
         << "| " << setw(12) << "Ngay Sinh"
         << "| " << right << setw(10) << "So SP"
         << "| " << setw(12) << "Don Gia"
         << "| " << setw(15) << "Luong (VND)" << "\n";
}

int main() {

    // 1. Nhập danh sách n nhân viên
    int n = nhapSoLuong("Nhap so luong nhan vien (n > 0): ");
    cNhanVienSX* ds = new cNhanVienSX[n];

    cout << "\nNHAP THONG TIN DANH SACH \n";
    for (int i = 0; i < n; i++) {
        cout << "\n* Nhan vien thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // 2. Xuất danh sách dạng bảng
    cout << "\nDANH SACH NHAN VIEN :\n";
    inTieuDe();
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }

    // 3 & 4 & 5: Tìm Lương thấp nhất, Tính Tổng Lương, Tìm Tuổi cao nhất
    double minLuong = ds[0].tinhLuong();
    double tongLuong = 0;
    int idxOldest = 0;

    for (int i = 0; i < n; i++) {
        double luongHT = ds[i].tinhLuong();

        // Tìm lương min
        if (luongHT < minLuong) minLuong = luongHT;

        // Cộng tổng lương
        tongLuong += luongHT;

        // Tìm người già nhất (Ngày sinh nhỏ nhất)
        if (nhoHonTuoi(ds[i].getNgaySinh(), ds[idxOldest].getNgaySinh())) {
            idxOldest = i;
        }
    }

    // Xuất nhân viên có lương thấp nhất (có thể có nhiều người cùng mức min)
    cout << "\n[!] DANH SACH NHAN VIEN CO LUONG THAP NHAT (" << fixed << setprecision(0) << minLuong << " VND):\n";
    inTieuDe();
    for (int i = 0; i < n; i++) {
        if (ds[i].tinhLuong() == minLuong) {
            ds[i].xuat();
        }
    }

    cout << "\n[!] TONG LUONG CONG TY PHAI TRA: " << tongLuong << " VND\n";

    // Xuất nhân viên tuổi cao nhất
    cout << "\n[!] NHAN VIEN CO TUOI CAO NHAT:\n";
    inTieuDe();
    ds[idxOldest].xuat();

    // 6. Sắp xếp danh sách tăng dần theo lương (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ds[j].tinhLuong() < ds[min_idx].tinhLuong()) {
                min_idx = j;
            }
        }
        // Hoán vị đối tượng
        cNhanVienSX temp = ds[i];
        ds[i] = ds[min_idx];
        ds[min_idx] = temp;
    }

    cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG :\n";
    inTieuDe();
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }

    // Giải phóng bộ nhớ động
    delete[] ds;

    return 0;
}
