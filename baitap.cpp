#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Lớp cơ sở Phong (Room)
class Phong {
protected:
    string ma_phong;
    double don_gia;

public:
    Phong(string ma = "", double gia = 0) {
        ma_phong = ma;
        don_gia = gia;
    }

    virtual ~Phong() {}

    // Getter và Setter
    void ganMaPhong(string ma) { ma_phong = ma; }
    string layMaPhong() const { return ma_phong; }

    void ganDonGia(double gia) { don_gia = gia; }
    double layDonGia() const { return don_gia; }

    // Phương thức thuần ảo tính tiền phòng
    virtual double tinhTienPhong() = 0;
    virtual void hienThiThongTin() = 0;
};

// 2. Lớp StandardRoom (Phòng tiêu chuẩn)
class StandardRoom : public Phong {
private:
    int so_nguoi_lon;
    int so_tre_em;

public:
    StandardRoom(string ma = "STD", double gia = 500000, int nl = 2, int te = 1) 
        : Phong(ma, gia) {
        so_nguoi_lon = nl;
        so_tre_em = te;
    }

    double tinhTienPhong() override {
        return don_gia;
    }

    void hienThiThongTin() override {
        cout << "[Standard Room] Ma: " << ma_phong 
             << " | Nguoi lon: " << so_nguoi_lon 
             << " | Tre em: " << so_tre_em 
             << " | Don gia: " << don_gia << "\n";
    }
};

// 3. Lớp DeluxeRoom (Phòng Deluxe)
class DeluxeRoom : public Phong {
private:
    int so_giuong_don_lon;
    int so_giuong_doi;

public:
    DeluxeRoom(string ma = "DLX", double gia = 1000000, int gdl = 1, int gd = 2) 
        : Phong(ma, gia) {
        so_giuong_don_lon = gdl;
        so_giuong_doi = gd;
    }

    double tinhTienPhong() override {
        return don_gia;
    }

    void hienThiThongTin() override {
        cout << "[Deluxe Room] Ma: " << ma_phong 
             << " | Giuong don lon: " << so_giuong_don_lon 
             << " | Giuong doi: " << so_giuong_doi 
             << " | Don gia: " << don_gia << "\n";
    }
};

// 4. Lớp LuxuryRoom (Phòng Luxury)
class LuxuryRoom : public Phong {
private:
    bool co_phong_tam_rieng;

public:
    LuxuryRoom(string ma = "LUX", double gia = 2000000, bool pt_rieng = true) 
        : Phong(ma, gia) {
        co_phong_tam_rieng = pt_rieng;
    }

    double tinhTienPhong() override {
        // Luxury có thể cộng thêm phí dịch vụ phòng tắm riêng
        return don_gia + (co_phong_tam_rieng ? 200000 : 0);
    }

    void hienThiThongTin() override {
        cout << "[Luxury Room] Ma: " << ma_phong 
             << " | Phong tam rieng: " << (co_phong_tam_rieng ? "Co" : "Khong") 
             << " | Don gia: " << don_gia << "\n";
    }
};

// 5. Hàm main quản lý đoàn khách và 3 options
int main() {
    cout << "=== QUAN LY KHACH SAN CHO DOAN 50 KHACH ===\n";
    cout << "- Tong so nguoi lon (>6 tuoi): 30\n";
    cout << "- Tong so tre em (0-6 tuoi): 20\n\n";

    // Khởi tạo 3 options sắp xếp phòng cho đoàn khách
    cout << "--- TINH TOAN 3 OPTIONS SAP XEP PHONG ---;\n";

    // Option 1: Toàn bộ dùng Standard Room
    double chi_phi_option_1 = (30 / 2) * 500000 + (20 / 1) * 200000; 

    // Option 2: Kết hợp Standard và Deluxe Room
    double chi_phi_option_2 = 15 * 800000 + 10 * 1200000;

    // Option 3: Kết hợp Deluxe và Luxury Room cho toàn đoàn
    double chi_phi_option_3 = 10 * 1500000 + 5 * 2500000;

    cout << "1. Option 1 (Chủ yếu phòng Standard): Tong chi phi du kiến = " << chi_phi_option_1 << " VND\n";
    cout << "2. Option 2 (Phối hợp Standard & Deluxe): Tong chi phi du kiến = " << chi_phi_option_2 << " VND\n";
    cout << "3. Option 3 (Phối hợp Deluxe & Luxury cao cấp): Tong chi phi du kiến = " << chi_phi_option_3 << " VND\n";

    return 0;
}
