#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>
#include <windows.h> // Cho màu sắc console
#include <limits> 

using namespace std;

// Enum cho màu console
enum Color {
    RED = 12, GREEN = 10, BLUE = 9, YELLOW = 14, 
    CYAN = 11, MAGENTA = 13, WHITE = 15, GRAY = 8
};

// Hàm thiết lập màu console
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ==================== LỚP CƠ SỞ VUKHI ====================
class VuKhi {
protected:
    string tenVuKhi;
    double satThuongCoBan;
    double tocDoRaDon;

public:
    // Constructors
    VuKhi() : tenVuKhi("Unknown"), satThuongCoBan(0), tocDoRaDon(0) {}
    
    VuKhi(string ten, double satThuong, double tocDo) 
        : tenVuKhi(ten), satThuongCoBan(satThuong), tocDoRaDon(tocDo) {}
    
    VuKhi(VuKhi& other) 
        : tenVuKhi(other.tenVuKhi), satThuongCoBan(other.satThuongCoBan), 
          tocDoRaDon(other.tocDoRaDon) {}
    
    // Destructor virtual
    virtual ~VuKhi() {}
    
    // Getters
    string getTenVuKhi() { return tenVuKhi; }
    double getSatThuongCoBan() { return satThuongCoBan; }
    double getTocDoRaDon() { return tocDoRaDon; }
    
    // Setters
    void setTenVuKhi(string& ten) { tenVuKhi = ten; }
    void setSatThuongCoBan(double satThuong) { 
        if(satThuong >= 0) satThuongCoBan = satThuong; 
    }
    void setTocDoRaDon(double tocDo) { 
        if(tocDo >= 0) tocDoRaDon = tocDo; 
    }
    
    // Phương thức ảo thuần túy (đa hình)
    virtual void TanCong() = 0;
    virtual double SatThuong(int thoiGian) = 0;
    virtual void hienThiThongTin() = 0;
    virtual bool coTheUse() { return true; }  // Mặc định vũ khí có thể sử dụng
    
    // Toán tử nhập xuất
    friend ostream& operator<<(ostream& os, VuKhi& vk) {
        os << fixed << setprecision(1);
        os << "Tên: " << vk.tenVuKhi 
           << ", Sát thương: " << vk.satThuongCoBan 
           << ", Tốc độ: " << vk.tocDoRaDon;
        return os;
    }
    
    friend istream& operator>>(istream& is, VuKhi& vk) {
        cout << "Nhập tên vũ khí: ";
        getline(is, vk.tenVuKhi);
        cout << "Nhập sát thương cơ bản: ";
        is >> vk.satThuongCoBan;
        cout << "Nhập tốc độ ra đòn: ";
        is >> vk.tocDoRaDon;
        return is;
    }
};

// ==================== LỚP SUNG ĐƯỢC CẢI TIẾN ====================
class Sung : public VuKhi {
private:
    int soDanTrongOng;
    int soDanToiDa;        // Số đạn tối đa của băng đạn
    double tocDoThayBang;
    int soBangDaThay;      // Đếm số lần đã thay băng

public:
    // Constructors
    Sung() : VuKhi(), soDanTrongOng(0), soDanToiDa(0), tocDoThayBang(0), soBangDaThay(0) {}
    
    Sung(string ten, double satThuong, double tocDo, int soDan, double tocDoThay)
        : VuKhi(ten, satThuong, tocDo), soDanTrongOng(soDan), soDanToiDa(soDan), 
          tocDoThayBang(tocDoThay), soBangDaThay(0) {}
    
    // Getters/Setters
    int getSoDanTrongOng() { return soDanTrongOng; }
    int getSoDanToiDa() { return soDanToiDa; }
    double getTocDoThayBang() { return tocDoThayBang; }
    int getSoBangDaThay() { return soBangDaThay; }
    
    void setSoDanTrongOng(int soDan) { 
        if(soDan >= 0 && soDan <= soDanToiDa) soDanTrongOng = soDan; 
    }
    void setTocDoThayBang(double tocDo) { 
        if(tocDo >= 0) tocDoThayBang = tocDo; 
    }
    
    // Phương thức thay băng đạn
    void thayBangDan() {
        soDanTrongOng = soDanToiDa;
        soBangDaThay++;
        setColor(YELLOW);
        cout << "🔄 " << tenVuKhi << " đã thay băng đạn! (Lần " << soBangDaThay << ")" << endl;
        setColor(WHITE);
    }
    
    // Phương thức bắn 1 phát
    bool ban() {
        if(soDanTrongOng > 0) {
            soDanTrongOng--;
            return true;
        }
        return false;
    }
    
    // Kiểm tra có thể sử dụng
    bool coTheUse() override {
        return soDanTrongOng > 0;
    }
    
    // Cài đặt phương thức ảo
    void TanCong() override {
        if(soDanTrongOng <= 0) {
            setColor(GRAY);
            cout << "🔫 " << tenVuKhi << " đã hết đạn! Cần thay băng!" << endl;
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "🔫 " << tenVuKhi << " bắn một loạt đạn với tốc độ " 
                 << tocDoRaDon << " phát/giây!" << endl;
            cout << "💥 Tiếng súng nổ vang lên, kẻ thù bị trúng đạn!" << endl;
            cout << "📊 Còn lại " << soDanTrongOng << "/" << soDanToiDa << " viên đạn" << endl;
            setColor(WHITE);
        }
    }
    
    double SatThuong(int thoiGian) override {
        if(soDanTrongOng <= 0) {
            setColor(RED);
            cout << "❌ " << tenVuKhi << " hết đạn! Không thể gây sát thương!" << endl;
            setColor(WHITE);
            return 0;
        }
        
        double tongSatThuong = 0;
        double thoiGianConLai = thoiGian;
        int soDanHienTai = soDanTrongOng;
        int lanThayBang = 0;
        
        setColor(CYAN);
        cout << "\n📊 CHI TIẾT COMBAT SÚNG:" << endl;
        cout << "═══════════════════════════" << endl;
        setColor(WHITE);
        
        while(thoiGianConLai > 0) {
            // Tính số đạn có thể bắn với đạn hiện tại
            double thoiGianBanHetDan = soDanHienTai / tocDoRaDon;
            
            if(thoiGianConLai <= thoiGianBanHetDan) {
                // Đủ thời gian để bắn hết thời gian còn lại
                double soDanBan = tocDoRaDon * thoiGianConLai;
                tongSatThuong += soDanBan * satThuongCoBan;
                soDanHienTai -= (int)soDanBan;
                
                cout << "🔫 Bắn " << fixed << setprecision(1) << soDanBan 
                     << " viên trong " << thoiGianConLai << " giây cuối" << endl;
                
                thoiGianConLai = 0;
            } else {
                // Bắn hết đạn trong băng hiện tại
                tongSatThuong += soDanHienTai * satThuongCoBan;
                thoiGianConLai -= thoiGianBanHetDan;
                
                cout << "🔫 Bắn hết " << soDanHienTai << " viên trong " 
                     << fixed << setprecision(1) << thoiGianBanHetDan << " giây" << endl;
                
                soDanHienTai = 0;
                
                // Kiểm tra có đủ thời gian thay băng không
                if(thoiGianConLai >= tocDoThayBang) {
                    // Thay băng
                    thoiGianConLai -= tocDoThayBang;
                    soDanHienTai = soDanToiDa;
                    lanThayBang++;
                    
                    setColor(YELLOW);
                    cout << "🔄 Thay băng đạn lần " << lanThayBang 
                         << " (mất " << tocDoThayBang << " giây)" << endl;
                    setColor(WHITE);
                } else {
                    // Không đủ thời gian thay băng
                    setColor(RED);
                    cout << "⏰ Không đủ thời gian thay băng (cần " << tocDoThayBang 
                         << " giây, chỉ còn " << fixed << setprecision(1) 
                         << thoiGianConLai << " giây)" << endl;
                    setColor(WHITE);
                    break;
                }
            }
        }
        
        // Cập nhật trạng thái súng
        soDanTrongOng = soDanHienTai;
        soBangDaThay += lanThayBang;
        
        return tongSatThuong;
    }
    
    void hienThiThongTin() override {
        setColor(RED);
        cout << "=== SÚNG " << (soDanTrongOng <= 0 ? "(HẾT ĐẠN)" : "") << " ===" << endl;
        setColor(WHITE);
        
        cout << *this << endl;
        cout << "Đạn: " << soDanTrongOng << "/" << soDanToiDa;
        double phanTramDan = ((double)soDanTrongOng / soDanToiDa) * 100;
        cout << " (" << fixed << setprecision(1) << phanTramDan << "%)";
        
        if(soDanTrongOng <= 0) {
            setColor(RED);
            cout << " [HẾT ĐẠN]";
        } else if(phanTramDan > 70) {
            setColor(GREEN);
            cout << " [Đầy]";
        } else if(phanTramDan > 30) {
            setColor(YELLOW);
            cout << " [Vừa đủ]";
        } else {
            setColor(RED);
            cout << " [Sắp hết]";
        }
        
        setColor(WHITE);
        cout << endl;
        cout << "Tốc độ thay băng: " << fixed << setprecision(1) << tocDoThayBang << " giây" << endl;
        if(soBangDaThay > 0) {
            cout << "Đã thay băng: " << soBangDaThay << " lần" << endl;
        }
    }
    
    // Reset trạng thái súng
    void napDanDay() {
        soDanTrongOng = soDanToiDa;
        soBangDaThay = 0;
        setColor(GREEN);
        cout << "🔋 " << tenVuKhi << " đã được nạp đạn đầy!" << endl;
        setColor(WHITE);
    }
};

// ==================== LỚP KIEM ====================
class Kiem : public VuKhi {
private:
    double doBen;
    double doBenToiDa;
    double doBenMatMoiDon; // Độ bền mất mỗi lần chém
    bool biBao; // Trạng thái vỡ

public:
    // Constructors
    Kiem() : VuKhi(), doBen(100), doBenToiDa(100), doBenMatMoiDon(1.0), biBao(false) {}
    
    Kiem(string ten, double satThuong, double tocDo, double ben, double benMat = 1.0)
        : VuKhi(ten, satThuong, tocDo), doBen(ben), doBenToiDa(ben), 
          doBenMatMoiDon(benMat), biBao(false) {}
    
    // Getters/Setters
    double getDoBen() { return doBen; }
    double getDoBenToiDa() { return doBenToiDa; }
    double getDoBenMatMoiDon() { return doBenMatMoiDon; }
    bool isBiBao() { return biBao; }
    
    void setDoBen(double ben) { 
        if(ben >= 0) {
            doBen = min(ben, doBenToiDa);
            if(doBen <= 0) {
                biBao = true;
                doBen = 0;
            } else {
                biBao = false;
            }
        }
    }
    
    void setDoBenMatMoiDon(double benMat) { 
        if(benMat >= 0) doBenMatMoiDon = benMat; 
    }
    
    // Phương thức sửa chữa kiếm
    void suaChua(double phanTramSuaChua = 100.0) {
        if(biBao && phanTramSuaChua >= 100.0) {
            // Chỉ có thể sửa lại hoàn toàn nếu vỡ
            doBen = doBenToiDa;
            biBao = false;
            setColor(GREEN);
            cout << "🔧 " << tenVuKhi << " đã được sửa chữa hoàn toàn!" << endl;
            setColor(WHITE);
        } else if(!biBao) {
            // Sửa chữa một phần nếu chưa vỡ
            double benTangThem = (doBenToiDa - doBen) * (phanTramSuaChua / 100.0);
            doBen += benTangThem;
            setColor(GREEN);
            cout << "🔧 " << tenVuKhi << " đã được sửa chữa " << phanTramSuaChua << "%!" << endl;
            setColor(WHITE);
        }
    }
    
    bool coTheUse() override {
        return !biBao;
    }
    
    // Cài đặt phương thức ảo
    void TanCong() override {
        if(biBao) {
            setColor(GRAY);
            cout << "💥 " << tenVuKhi << " đã vỡ và không thể sử dụng!" << endl;
            setColor(WHITE);
        } else {
            setColor(CYAN);
            cout << "⚔️ " << tenVuKhi << " vung lưỡi sắc bén!" << endl;
            cout << "✨ Ánh kim loại lóe sáng, chém trúng mục tiêu!" << endl;
            setColor(WHITE);
        }
    }
    
    double SatThuong(int thoiGian) override {
        if(biBao) {
            setColor(RED);
            cout << "❌ " << tenVuKhi << " đã vỡ! Không thể gây sát thương!" << endl;
            setColor(WHITE);
            return 0;
        }
        
        // Số đòn tấn công trong thời gian t
        double soDon = tocDoRaDon * thoiGian;
        double tongSatThuong = 0;
        double doBenHienTai = doBen;
        
        for(int don = 0; don < (int)soDon && !biBao; don++) {
            // Tính hệ số độ bền cho đòn này
            double heSoDoBen = max(0.1, doBenHienTai / 100.0);
            
            // Gây sát thương
            tongSatThuong += satThuongCoBan * heSoDoBen;
            
            // Giảm độ bền
            doBenHienTai -= doBenMatMoiDon;
            
            // Kiểm tra vỡ
            if(doBenHienTai <= 0) {
                doBenHienTai = 0;
                biBao = true;
                
                setColor(RED);
                cout << "💥 " << tenVuKhi << " đã vỡ sau " << (don + 1) << " đòn!" << endl;
                setColor(WHITE);
                break;
            }
        }
        
        // Cập nhật độ bền thực tế
        doBen = doBenHienTai;
        
        return tongSatThuong;
    }
    
    void hienThiThongTin() override {
        setColor(CYAN);
        cout << "=== KIẾM " << (biBao ? "(VỠ)" : "") << " ===" << endl;
        setColor(WHITE);
        
        cout << *this << endl;
        cout << "Độ bền: " << fixed << setprecision(1) << doBen << "/" << doBenToiDa;
        double phanTramBen = (doBen / doBenToiDa) * 100;
        cout << " (" << fixed << setprecision(1) << phanTramBen << "%)";
        
        if(biBao) {
            setColor(RED);
            cout << " [VỠ]";
        } else if(phanTramBen > 70) {
            setColor(GREEN);
            cout << " [Tốt]";
        } else if(phanTramBen > 30) {
            setColor(YELLOW);
            cout << " [Hỏng nhẹ]";
        } else {
            setColor(RED);
            cout << " [Hỏng nặng]";
        }
        
        setColor(WHITE);
        cout << endl;
        cout << "Độ bền mất mỗi đòn: " << fixed << setprecision(1) << doBenMatMoiDon << endl;
    }
};

// ==================== LỚP PHEPTHUAT ====================
class PhepThuat : public VuKhi {
private:
    string loaiPhep;
    double manaTieuThuMoiPhep; // Mana tiêu thụ mỗi phép
    double manaHienTai;        // Mana hiện tại
    double manaToiDa;          // Mana tối đa
    double tocDoHoiMana;       // Tốc độ hồi mana/giây

public:
    // Constructors
    PhepThuat() : VuKhi(), loaiPhep("Unknown"), manaTieuThuMoiPhep(10), 
                  manaHienTai(100), manaToiDa(100), tocDoHoiMana(5) {}
    
    PhepThuat(string ten, double satThuong, double tocDo, string loai, 
              double manaMoiPhep, double manaMax = 100, double tocDoHoi = 5)
        : VuKhi(ten, satThuong, tocDo), loaiPhep(loai), 
          manaTieuThuMoiPhep(manaMoiPhep), manaHienTai(manaMax), 
          manaToiDa(manaMax), tocDoHoiMana(tocDoHoi) {}
    
    // Getters/Setters
    string getLoaiPhep() { return loaiPhep; }
    double getManaTieuThuMoiPhep() { return manaTieuThuMoiPhep; }
    double getManaHienTai() { return manaHienTai; }
    double getManaToiDa() { return manaToiDa; }
    double getTocDoHoiMana() { return tocDoHoiMana; }
    
    void setLoaiPhep(string& loai) { loaiPhep = loai; }
    void setManaTieuThuMoiPhep(double mana) { 
        if(mana >= 0) manaTieuThuMoiPhep = mana; 
    }
    void setManaHienTai(double mana) { 
        if(mana >= 0) manaHienTai = min(mana, manaToiDa); 
    }
    void setTocDoHoiMana(double tocDo) { 
        if(tocDo >= 0) tocDoHoiMana = tocDo; 
    }
    
    // Phương thức hồi mana
    void hoiMana(double thoiGian) {
        double manaHoi = tocDoHoiMana * thoiGian;
        manaHienTai = min(manaHienTai + manaHoi, manaToiDa);
    }
    
    // Phương thức hồi mana hoàn toàn
    void hoiManaHoanToan() {
        manaHienTai = manaToiDa;
        setColor(BLUE);
        cout << "💙 " << tenVuKhi << " đã hồi phục hoàn toàn mana!" << endl;
        setColor(WHITE);
    }
    
    // Kiểm tra có đủ mana để cast không
    bool duMana() {
        return manaHienTai >= manaTieuThuMoiPhep;
    }
    
    bool coTheUse() override {
        return duMana();
    }
    
    // Cài đặt phương thức ảo
    void TanCong() override {
        if(!duMana()) {
            setColor(GRAY);
            cout << "💨 " << tenVuKhi << " không đủ mana để thi triển!" << endl;
            cout << "🔋 Cần " << manaTieuThuMoiPhep << " mana, chỉ còn " 
                 << fixed << setprecision(1) << manaHienTai << endl;
            setColor(YELLOW);
            cout << "💡 Sử dụng chức năng số 8 để hồi mana!" << endl;
            setColor(WHITE);
        } else {
            setColor(MAGENTA);
            cout << "🔮 Thi triển " << loaiPhep << " - " << tenVuKhi << "!" << endl;
            cout << "⚡ Ma thuật bùng nổ, năng lượng huyền bí tấn công!" << endl;
            setColor(WHITE);
        }
    }
    
    double SatThuong(int thoiGian) override {
        if(!duMana()) {
            setColor(RED);
            cout << "❌ " << tenVuKhi << " không đủ mana! Không thể gây sát thương!" << endl;
            setColor(YELLOW);
            cout << "💡 Hãy sử dụng chức năng số 8 để hồi mana trước!" << endl;
            setColor(WHITE);
            return 0;
        }
        
        double tongSatThuong = 0;
        double manaHienTaiTemp = manaHienTai;
        double thoiGianConLai = thoiGian;
        int soPhepDaCast = 0;
        
        // Tính số phép cast được với mana hiện tại
        while(thoiGianConLai > 0 && manaHienTaiTemp >= manaTieuThuMoiPhep) {
            // Thời gian cần để cast 1 phép
            double thoiGianCast1Phep = 1.0 / tocDoRaDon;
            
            if(thoiGianConLai >= thoiGianCast1Phep) {
                // Cast được 1 phép
                tongSatThuong += satThuongCoBan;
                manaHienTaiTemp -= manaTieuThuMoiPhep;
                thoiGianConLai -= thoiGianCast1Phep;
                soPhepDaCast++;
                
                // Hồi mana trong thời gian cast
                double manaHoi = tocDoHoiMana * thoiGianCast1Phep;
                manaHienTaiTemp = min(manaHienTaiTemp + manaHoi, manaToiDa);
            } else {
                // Không đủ thời gian cast, chỉ hồi mana
                double manaHoi = tocDoHoiMana * thoiGianConLai;
                manaHienTaiTemp = min(manaHienTaiTemp + manaHoi, manaToiDa);
                break;
            }
        }
        
        // Nếu hết mana giữa chừng
        if(thoiGianConLai > 0 && manaHienTaiTemp < manaTieuThuMoiPhep) {
            setColor(YELLOW);
            cout << "⚠️ " << tenVuKhi << " hết mana sau " << soPhepDaCast << " phép!" << endl;
            
            // Hồi mana trong thời gian còn lại
            double manaHoi = tocDoHoiMana * thoiGianConLai;
            manaHienTaiTemp = min(manaHienTaiTemp + manaHoi, manaToiDa);
            
            cout << "💡 Lần sau hãy sử dụng chức năng số 8 để hồi mana trước combat!" << endl;
            setColor(WHITE);
        }
        
        // Cập nhật mana thực tế
        manaHienTai = manaHienTaiTemp;
        
        return tongSatThuong;
    }
    
    void hienThiThongTin() override {
        setColor(MAGENTA);
        cout << "=== PHÉP THUẬT " << (!duMana() ? "(HẾT MANA)" : "") << " ===" << endl;
        setColor(WHITE);
        
        cout << *this << endl;
        cout << "Loại phép: " << loaiPhep << endl;
        cout << "Mana: " << fixed << setprecision(1) << manaHienTai << "/" << manaToiDa;
        double phanTramMana = (manaHienTai / manaToiDa) * 100;
        cout << " (" << fixed << setprecision(1) << phanTramMana << "%)";
        
        if(manaHienTai < manaTieuThuMoiPhep) {
            setColor(RED);
            cout << " [Cạn kiệt]";
        } else if(phanTramMana > 70) {
            setColor(BLUE);
            cout << " [Đầy]";
        } else if(phanTramMana > 30) {
            setColor(YELLOW);
            cout << " [Vừa đủ]";
        } else {
            setColor(RED);
            cout << " [Thấp]";
        }
        
        setColor(WHITE);
        cout << endl;
        cout << "Mana/phép: " << fixed << setprecision(1) << manaTieuThuMoiPhep << endl;
        cout << "Hồi mana: " << fixed << setprecision(1) << tocDoHoiMana << " mana/s" << endl;
        
        if(!duMana()) {
            setColor(YELLOW);
            cout << "💡 Sử dụng chức năng số 8 để hồi mana!" << endl;
            setColor(WHITE);
        }
    }
};

// ==================== HÀM TIỆN ÍCH ====================
void hienThiTieuDe() {
    setColor(YELLOW);
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║           🎮 HỆ THỐNG COMBAT VŨ KHÍ 🎮             ║\n";
    cout << "║             Lập Trình Hướng Đối Tượng              ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
    setColor(WHITE);
}

void hienThiMenu() {
    setColor(GREEN);
    cout << "\n📋 MENU CHÍNH:\n";
    cout << "1. 🔫 Tạo súng\n";
    cout << "2. ⚔️ Tạo kiếm\n";
    cout << "3. 🔮 Tạo phép thuật\n";
    cout << "4. ⚔️ Mô phỏng combat\n";
    cout << "5. 📊 Hiển thị kho vũ khí\n";
    cout << "6. 🔧 Sửa chữa kiếm\n";
    cout << "7. 🔋 Nạp đạn cho súng\n";
    cout << "8. 💙 Hồi mana cho phép thuật\n";
    cout << "0. 🚪 Thoát\n";
    cout << "Chọn: ";
    setColor(WHITE);
}

void napDanChoSung(vector<unique_ptr<VuKhi>>& khoVuKhi) {
    // Tìm các súng trong kho
    vector<int> viTriSung;
    for(size_t i = 0; i < khoVuKhi.size(); i++) {
        if(dynamic_cast<Sung*>(khoVuKhi[i].get())) {
            viTriSung.push_back(i);
        }
    }
    
    if(viTriSung.empty()) {
        setColor(RED);
        cout << "❌ Không có súng nào trong kho!\n";
        setColor(WHITE);
        return;
    }
    
    setColor(RED);
    cout << "\n🔋 NẠP ĐẠN CHO SÚNG\n";
    cout << "═══════════════════\n";
    setColor(WHITE);
    
    cout << "Chọn súng cần nạp đạn:\n";
    for(size_t i = 0; i < viTriSung.size(); i++) {
        cout << i + 1 << ". ";
        khoVuKhi[viTriSung[i]]->hienThiThongTin();
        cout << endl;
    }
    
    int luaChon;
    cout << "Súng số: ";
    cin >> luaChon;
    
    if(luaChon < 1 || luaChon > (int)viTriSung.size()) {
        setColor(RED);
        cout << "❌ Lựa chọn không hợp lệ!\n";
        setColor(WHITE);
        return;
    }
    
    Sung* sung = dynamic_cast<Sung*>(khoVuKhi[viTriSung[luaChon-1]].get());
    sung->napDanDay();
}

void hoiManaChoPhepThuat(vector<unique_ptr<VuKhi>>& khoVuKhi) {
    // Tìm các phép thuật trong kho
    vector<int> viTriPhepThuat;
    for(size_t i = 0; i < khoVuKhi.size(); i++) {
        if(dynamic_cast<PhepThuat*>(khoVuKhi[i].get())) {
            viTriPhepThuat.push_back(i);
        }
    }
    
    if(viTriPhepThuat.empty()) {
        setColor(RED);
        cout << "❌ Không có phép thuật nào trong kho!\n";
        setColor(WHITE);
        return;
    }
    
    setColor(MAGENTA);
    cout << "\n💙 HỒI MANA CHO PHÉP THUẬT\n";
    cout << "══════════════════════════\n";
    setColor(WHITE);
    
    cout << "Chọn phép thuật cần hồi mana:\n";
    for(size_t i = 0; i < viTriPhepThuat.size(); i++) {
        cout << i + 1 << ". ";
        khoVuKhi[viTriPhepThuat[i]]->hienThiThongTin();
        cout << endl;
    }
    
    int luaChon;
    cout << "Phép thuật số: ";
    cin >> luaChon;
    
    if(luaChon < 1 || luaChon > (int)viTriPhepThuat.size()) {
        setColor(RED);
        cout << "❌ Lựa chọn không hợp lệ!\n";
        setColor(WHITE);
        return;
    }
    
    PhepThuat* phep = dynamic_cast<PhepThuat*>(khoVuKhi[viTriPhepThuat[luaChon-1]].get());
    phep->hoiManaHoanToan();
}

void suaChuaKiem(vector<unique_ptr<VuKhi>>& khoVuKhi) {
    // Tìm các kiếm trong kho
    vector<int> viTriKiem;
    for(size_t i = 0; i < khoVuKhi.size(); i++) {
        if(dynamic_cast<Kiem*>(khoVuKhi[i].get())) {
            viTriKiem.push_back(i);
        }
    }
    
    if(viTriKiem.empty()) {
        setColor(RED);
        cout << "❌ Không có kiếm nào trong kho!\n";
        setColor(WHITE);
        return;
    }
    
    setColor(CYAN);
    cout << "\n🔧 SỬA CHỮA KIẾM\n";
    cout << "═══════════════\n";
    setColor(WHITE);
    
    cout << "Chọn kiếm cần sửa:\n";
    for(size_t i = 0; i < viTriKiem.size(); i++) {
        cout << i + 1 << ". ";
        khoVuKhi[viTriKiem[i]]->hienThiThongTin();
        cout << endl;
    }
    
    int luaChon;
    cout << "Kiếm số: ";
    cin >> luaChon;
    
    if(luaChon < 1 || luaChon > (int)viTriKiem.size()) {
        setColor(RED);
        cout << "❌ Lựa chọn không hợp lệ!\n";
        setColor(WHITE);
        return;
    }
    
    Kiem* kiem = dynamic_cast<Kiem*>(khoVuKhi[viTriKiem[luaChon-1]].get());
    
    if(kiem->isBiBao()) {
        cout << "Kiếm đã vỡ. Sửa chữa hoàn toàn? (y/n): ";
        char xacNhan;
        cin >> xacNhan;
        if(xacNhan == 'y' || xacNhan == 'Y') {
            kiem->setDoBen(kiem->getDoBenToiDa());
            setColor(GREEN);
            cout << "🔧 " << kiem->getTenVuKhi() << " đã được sửa chữa hoàn toàn!" << endl;
            setColor(WHITE);
        }
    } else {
        cout << "Số độ bền cần thêm: ";
        double doBenThem;
        cin >> doBenThem;
        if(doBenThem >= 0) {
            double doBenHienTai = kiem->getDoBen();
            kiem->setDoBen(doBenHienTai + doBenThem);
            setColor(GREEN);
            cout << "🔧 " << kiem->getTenVuKhi() << " đã được sửa chữa thêm " << doBenThem << " độ bền!" << endl;
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "❌ Số độ bền không hợp lệ!\n";
            setColor(WHITE);
        }
    }
}

void moPhongCombat(vector<unique_ptr<VuKhi>>& khoVuKhi) {
    if(khoVuKhi.empty()) {
        setColor(RED);
        cout << "❌ Kho vũ khí trống! Hãy tạo vũ khí trước.\n";
        setColor(WHITE);
        return;
    }
    
    setColor(YELLOW);
    cout << "\n🏟️  MÔ PHỎNG COMBAT\n";
    cout << "══════════════════════\n";
    setColor(WHITE);
    
    // Hiển thị danh sách vũ khí có thể sử dụng
    vector<int> vuKhiCoTheSuDung;
    cout << "Chọn vũ khí:\n";
    for(size_t i = 0; i < khoVuKhi.size(); i++) {
        if(khoVuKhi[i]->coTheUse()) {
            vuKhiCoTheSuDung.push_back(i);
            cout << vuKhiCoTheSuDung.size() << ". " << khoVuKhi[i]->getTenVuKhi();
            
            // Hiển thị trạng thái đặc biệt cho kiếm
            Kiem* kiem = dynamic_cast<Kiem*>(khoVuKhi[i].get());
            if(kiem) {
                double phanTramBen = (kiem->getDoBen() / kiem->getDoBenToiDa()) * 100;
                if(phanTramBen <= 30) {
                    setColor(RED);
                    cout << " (Hỏng nặng)";
                    setColor(WHITE);
                } else if(phanTramBen <= 70) {
                    setColor(YELLOW);
                    cout << " (Hỏng nhẹ)";
                    setColor(WHITE);
                }
            }
            
            // Hiển thị trạng thái đặc biệt cho phép thuật
            PhepThuat* phep = dynamic_cast<PhepThuat*>(khoVuKhi[i].get());
            if(phep) {
                if(!phep->duMana()) {
                    setColor(RED);
                    cout << " (Hết mana - Cần chức năng 8)";
                    setColor(WHITE);
                }
            }
            cout << endl;
        }
    }
    
    if(vuKhiCoTheSuDung.empty()) {
        setColor(RED);
        cout << "❌ Không có vũ khí nào có thể sử dụng!\n";
        cout << "💡 Hãy sử dụng chức năng 6, 7, hoặc 8 để sửa chữa/nạp đạn/hồi mana!\n";
        setColor(WHITE);
        return;
    }
    
    int luaChon;
    cout << "Vũ khí số: ";
    cin >> luaChon;
    
    if(luaChon < 1 || luaChon > (int)vuKhiCoTheSuDung.size()) {
        setColor(RED);
        cout << "❌ Lựa chọn không hợp lệ!\n";
        setColor(WHITE);
        return;
    }
    
    int thoiGian;
    cout << "Thời gian combat (giây): ";
    cin >> thoiGian;
    
    if(thoiGian <= 0) {
        setColor(RED);
        cout << "❌ Thời gian phải > 0!\n";
        setColor(WHITE);
        return;
    }
    
    // Mô phỏng combat
    int viTriVuKhi = vuKhiCoTheSuDung[luaChon - 1];
    auto& vuKhi = khoVuKhi[viTriVuKhi];
    
    setColor(YELLOW);
    cout << "\n🎬 BẮT ĐẦU COMBAT!\n";
    cout << "═══════════════════\n";
    setColor(WHITE);
    
    cout << "Trước combat:\n";
    vuKhi->hienThiThongTin();
    cout << "\n";
    
    // Tấn công
    vuKhi->TanCong();
    
    // Tính sát thương
    double tongSatThuong = vuKhi->SatThuong(thoiGian);
    
    setColor(GREEN);
    cout << "\n📊 KẾT QUẢ COMBAT:\n";
    cout << "Thời gian: " << thoiGian << " giây\n";
    cout << "Tổng sát thương: " << fixed << setprecision(2) << tongSatThuong << " HP\n";
    if(tongSatThuong > 0) {
        cout << "Sát thương trung bình/giây: " << tongSatThuong/thoiGian << " DPS\n";
    }
    setColor(WHITE);
    
    cout << "\nSau combat:\n";
    vuKhi->hienThiThongTin();
}

// ==================== HÀM MAIN ====================
int main() {
    // Thiết lập console UTF-8 cho tiếng Việt
    system("chcp 65001 > nul");
    
    vector<unique_ptr<VuKhi>> khoVuKhi;
    int luaChon;
    
    hienThiTieuDe();
    
    do {
        hienThiMenu();
        cin >> luaChon;
        cin.ignore(1000, '\n'); // Changed to clear up to 1000 characters or until newline

        switch(luaChon) {
            case 1: {
                setColor(RED);
                cout << "\n🔫 TẠO SÚNG MỚI\n";
                cout << "═══════════════\n";
                setColor(WHITE);
                
                string ten;
                double satThuong, tocDo, tocDoThay;
                int soDan;
                
                cout << "Tên súng: "; getline(cin, ten);
                cout << "Sát thương cơ bản: "; cin >> satThuong; cin.ignore();
                cout << "Tốc độ bắn (phát/giây): "; cin >> tocDo; cin.ignore();
                cout << "Số đạn trong ống: "; cin >> soDan; cin.ignore();
                cout << "Tốc độ thay băng (giây): "; cin >> tocDoThay; cin.ignore();
                
                khoVuKhi.push_back(make_unique<Sung>(ten, satThuong, tocDo, soDan, tocDoThay));
                
                setColor(GREEN);
                cout << "✅ Đã tạo súng thành công!\n";
                setColor(WHITE);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 2: {
                setColor(CYAN);
                cout << "\n⚔️ TẠO KIẾM MỚI\n";
                cout << "══════════════\n";
                setColor(WHITE);
                
                string ten;
                double satThuong, tocDo, doBen, doBenMat;
                
                cout << "Tên kiếm: "; getline(cin, ten);
                cout << "Sát thương cơ bản: "; cin >> satThuong; cin.ignore();
                cout << "Tốc độ chém (đòn/giây): "; cin >> tocDo; cin.ignore();
                cout << "Độ bền tối đa: "; cin >> doBen; cin.ignore();
                cout << "Độ bền mất mỗi đòn (mặc định 1.0): ";
                cin >> doBenMat; cin.ignore();
                if(doBenMat <= 0) doBenMat = 1.0;
                
                khoVuKhi.push_back(make_unique<Kiem>(ten, satThuong, tocDo, doBen, doBenMat));
                
                setColor(GREEN);
                cout << "✅ Đã tạo kiếm thành công!\n";
                setColor(WHITE);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 3: {
                setColor(MAGENTA);
                cout << "\n🔮 TẠO PHÉP THUẬT MỚI\n";
                cout << "══════════════════\n";
                setColor(WHITE);
                
                string ten, loaiPhep;
                double satThuong, tocDo, mana;
                
                cout << "Tên phép thuật: "; getline(cin, ten);
                cout << "Sát thương cơ bản: "; cin >> satThuong; cin.ignore();
                cout << "Tốc độ cast (phép/giây): "; cin >> tocDo; cin.ignore();
                cout << "Loại phép: "; getline(cin, loaiPhep);
                cout << "Mana tiêu thụ/phép: "; cin >> mana; cin.ignore();
                
                khoVuKhi.push_back(make_unique<PhepThuat>(ten, satThuong, tocDo, loaiPhep, mana));
                
                setColor(GREEN);
                cout << "✅ Đã tạo phép thuật thành công!\n";
                setColor(WHITE);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 4: {
                moPhongCombat(khoVuKhi);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 5: {
                setColor(BLUE);
                cout << "\n📦 KHO VŨ KHÍ\n";
                cout << "═══════════════\n";
                setColor(WHITE);
                
                if(khoVuKhi.empty()) {
                    setColor(GRAY);
                    cout << "Kho vũ khí trống.\n";
                    setColor(WHITE);
                } else {
                    for(size_t i = 0; i < khoVuKhi.size(); i++) {
                        cout << "\n" << (i + 1) << ". ";
                        khoVuKhi[i]->hienThiThongTin();
                        cout << "───────────────────" << endl;
                    }
                }
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 6: {
                suaChuaKiem(khoVuKhi);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 7: {
                napDanChoSung(khoVuKhi);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 8: {
                hoiManaChoPhepThuat(khoVuKhi);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
            
            case 0: {
                setColor(YELLOW);
                cout << "\n👋 Cảm ơn bạn đã sử dụng hệ thống combat!\n";
                setColor(WHITE);
                break;
            }
            
            default: {
                setColor(RED);
                cout << "❌ Lựa chọn không hợp lệ!\n";
                setColor(WHITE);
                cout << "\nNhấn Enter để tiếp tục...";
                cin.get();
                break;
            }
        }
    } while(luaChon != 0);
    
    return 0;
}
// ==================== KẾT THÚC CHƯƠNG TRÌNH ====================