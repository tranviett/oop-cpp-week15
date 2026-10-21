#include <iostream>
#include <cmath>

using namespace std;

// 1. Lớp cơ sở PT (Phương trình)
class PT {
public:
    // Constructor mặc định
    PT() {}

    // Destructor ảo để hỗ trợ đa hình
    virtual ~PT() {}

    // Phương thức ảo giải phương trình
    virtual void giai() {
        cout << "Giai phuong trinh tong quat.\n";
    }
};

// 2. Lớp PTB2 kế thừa từ PT (Phương trình bậc 2: ax^2 + bx + c = 0)
class PTB2 : public PT {
private:
    double he_so_a, he_so_b, he_so_c;

public:
    // Constructor có tham số
    PTB2(double a = 0, double b = 0, double c = 0) {
        he_so_a = a;
        he_so_b = b;
        he_so_c = c;
    }

    // Setter (Hàm thiết lập)
    void ganHeSoA(double a) { he_so_a = a; }
    void ganHeSoB(double b) { he_so_b = b; }
    void ganHeSoC(double c) { he_so_c = c; }

    // Getter (Hàm lấy giá trị)
    double layHeSoA() const { return he_so_a; }
    double layHeSoB() const { return he_so_b; }
    double layHeSoC() const { return he_so_c; }

    // Phương thức giải phương trình bậc 2
    void giai() override {
        cout << "Giai PTB2: " << he_so_a << "x^2 + " << he_so_b << "x + " << he_so_c << " = 0\n";
        if (he_so_a == 0) {
            if (he_so_b == 0) {
                if (he_so_c == 0) cout << "Phuong trinh co vo so nghiem.\n";
                else cout << "Phuong trinh vo nghiem.\n";
            } else {
                cout << "Phuong trinh co 1 nghiem: x = " << -he_so_c / he_so_b << "\n";
            }
        } else {
            double delta = he_so_b * he_so_b - 4 * he_so_a * he_so_c;
            if (delta < 0) {
                cout << "Phuong trinh vo nghiem thuc.\n";
            } else if (delta == 0) {
                cout << "Phuong trinh co nghiem kep: x1 = x2 = " << -he_so_b / (2 * he_so_a) << "\n";
            } else {
                double nghiem_1 = (-he_so_b + sqrt(delta)) / (2 * he_so_a);
                double nghiem_2 = (-he_so_b - sqrt(delta)) / (2 * he_so_a);
                cout << "Phuong trinh co 2 nghiem phan biet:\n";
                cout << "x1 = " << nghiem_1 << "\n";
                cout << "x2 = " << nghiem_2 << "\n";
            }
        }
    }
};

// 3. Lớp PTB3 kế thừa từ PT (Phương trình bậc 3: ax^3 + bx^2 + cx + d = 0)
class PTB3 : public PT {
private:
    double he_so_a, he_so_b, he_so_c, he_so_d;

public:
    // Constructor có tham số
    PTB3(double a = 0, double b = 0, double c = 0, double d = 0) {
        he_so_a = a;
        he_so_b = b;
        he_so_c = c;
        he_so_d = d;
    }

    // Setter (Hàm thiết lập)
    void ganHeSoA(double a) { he_so_a = a; }
    void ganHeSoB(double b) { he_so_b = b; }
    void ganHeSoC(double c) { he_so_c = c; }
    void ganHeSoD(double d) { he_so_d = d; }

    // Getter (Hàm lấy giá trị)
    double layHeSoA() const { return he_so_a; }
    double layHeSoB() const { return he_so_b; }
    double layHeSoC() const { return he_so_c; }
    double layHeSoD() const { return he_so_d; }

    // Phương thức giải phương trình bậc 3
    void giai() override {
        cout << "Giai PTB3: " << he_so_a << "x^3 + " << he_so_b << "x^2 + " << he_so_c << "x + " << he_so_d << " = 0\n";
        if (he_so_a == 0) {
            // Nếu hệ số a = 0, chuyển về giải phương trình bậc 2
            PTB2 phuong_trinh_bac_hai(he_so_b, he_so_c, he_so_d);
            phuong_trinh_bac_hai.giai();
        } else {
            cout << "Thuc hien giai phuong trinh bac 3...\n";
            // Logic giải phương trình bậc 3 chi tiết có thể đặt ở đây
        }
    }
};

// 4. Hàm main kiểm thử chương trình
int main() {
    cout << "=== CHUONG TRINH GIAI PHUONG TRINH (OOP) ===\n\n";

    // Sử dụng tính đa hình thông qua con trỏ lớp cơ sở
    PT* danh_sach_phuong_trinh[2];
    danh_sach_phuong_trinh[0] = new PTB2(1, -3, 2);       // x^2 - 3x + 2 = 0
    danh_sach_phuong_trinh[1] = new PTB3(1, -6, 11, -6); // x^3 - 6x^2 + 11x - 6 = 0

    for (int i = 0; i < 2; i++) {
        danh_sach_phuong_trinh[i]->giai();
        cout << "----------------------------------------\n";
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 2; i++) {
        delete danh_sach_phuong_trinh[i];
    }

    return 0;
}