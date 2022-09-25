#include <iostream>
#include <string>
using namespace std;
int NamHienTai;

class NguoiSuHuu
{
private:
    string ho_ten;
    string CMND;
    string dia_chi_thuong_tru;
    int NamSinh;
public:
    void NhapThongTinNguoiSoHuu();
    void XuatThongTinNguoiSoHuu();
};
class DatDai
{
protected:
    string so_giay_chung_nhan;
    string dia_chi_thua_dat;
    string ngay_cap;
    int so_thua_dat, so_to_ban_do, so_nguoi_su_dung;
    long long dien_tich, don_gia_thue;
    NguoiSuHuu DanhSachNguoiSuHuu[100];
public:
    virtual void Nhap();
    virtual void Xuat();
    long long TinhTienThue();
    virtual int Kt_Han() = 0;
};
class DatNongNghiep : public DatDai
{
protected:
    int HanSuDung;
public:
    void NhapDatNN();
    void XuatDatNN();
    int Kt_Han();
};
class DatPhiNongNghiep : public DatDai
{
public:
    void NhapDatPNN();
    void XuatDatPNN();
    int Kt_Han();
};
void DatDai::Nhap()
{
    cout << "Nhap so giay chung nhan: ";
    cin >> so_giay_chung_nhan;
    cout << "\nNhap so thua dat: ";
    cin >> so_thua_dat;
    cout << "\nNhap so to ban do: ";
    cin >> so_to_ban_do;
    cin.ignore();
    cout << "\nNhap dia chi thua dat: ";
    getline(cin, dia_chi_thua_dat);
    cout << "\nNhap dien tich: ";
    cin >> dien_tich;
    cout << "\nNhap ngay cap: ";
    cin >> ngay_cap;
    cout << "\nNhap don gia thue: ";
    cin >> don_gia_thue;
    cout << "\nNhap so nguoi su dung: ";
    cin >> so_nguoi_su_dung;
    cout << "\nNhap so nam hien tai: ";
    cin >> NamHienTai;
    for (int i = 0; i < so_nguoi_su_dung; i++)
    {
        DanhSachNguoiSuHuu[i].NhapThongTinNguoiSoHuu();
    }
}
void DatDai::Xuat()
{
    cout << "So giay chung nhan: " << so_giay_chung_nhan << endl
        << "So thua dat: " << so_thua_dat << endl
        << "So to ban do: " << so_to_ban_do << endl
        << "Dia chi thua dat: " << dia_chi_thua_dat << endl
        << "Dien tich: " << dien_tich << " m^2" << endl
        << "Ngay cap: " << ngay_cap << endl
        << "Don gia thue: " << don_gia_thue << " dong" << endl
        << "Tien thue 1 nam: " << TinhTienThue() << " dong" << endl
        << "So nguoi su dung: " << so_nguoi_su_dung << " nguoi" << endl;
    for (int i = 0; i < so_nguoi_su_dung; i++)
    {
        cout << "Nguoi su dung thu " << i + 1 << ":" << endl;
        DanhSachNguoiSuHuu[i].XuatThongTinNguoiSoHuu();
    }
}
long long DatDai::TinhTienThue()
{
    return (don_gia_thue * dien_tich);
}
void DatNongNghiep::NhapDatNN()
{

    cout << "Nhap so giay chung nhan: ";
    cin >> so_giay_chung_nhan;
    cout << "\nNhap so thua dat: ";
    cin >> so_thua_dat;
    cout << "\nNhap so to ban do: ";
    cin >> so_to_ban_do;
    cin.ignore();
    cout << "\nNhap dia chi thua dat: ";
    getline(cin, dia_chi_thua_dat);
    cout << "\nNhap dien tich: ";
    cin >> dien_tich;
    cout << "\nNhap han su dung: ";
    cin >> HanSuDung;
    cout << "\nNhap ngay cap: ";
    cin >> ngay_cap;
    cout << "\nNhap don gia thue: ";
    cin >> don_gia_thue;
    cout << "\nNhap so nguoi su dung: ";
    cin >> so_nguoi_su_dung;
    for (int i = 0; i < so_nguoi_su_dung; i++)
    {
        DanhSachNguoiSuHuu[i].NhapThongTinNguoiSoHuu();
    }
}
void DatNongNghiep::XuatDatNN()
{
    cout << "So giay chung nhan: " << so_giay_chung_nhan;
    cout << "\nSo thua dat: " << so_thua_dat;
    cout << "\nSo to ban do: " << so_to_ban_do;
    cout << "\nDia chi thua dat: " << dia_chi_thua_dat;
    cout << "\nDien tich: " << dien_tich << " m^2";
    cout << "\nHan su dung: Nam " << HanSuDung;
    cout << "\nNgay cap: " << ngay_cap;
    cout << "\nDon gia thue: " << don_gia_thue << " dong";
    cout << "\nTien thue 1 nam: " << TinhTienThue() << " dong";
    cout << "\nSo nguoi su dung: " << so_nguoi_su_dung << " nguoi" << endl;
    for (int i = 0; i < so_nguoi_su_dung; i++)
    {
        cout << "Nguoi su dung thu " << i + 1 << ":" << endl;
        DanhSachNguoiSuHuu[i].XuatThongTinNguoiSoHuu();
    }
}
int DatNongNghiep::Kt_Han()
{
    if (HanSuDung < NamHienTai)
        return 1;
    else
        return 0;
}
void DatPhiNongNghiep::NhapDatPNN()
{
    DatDai::Nhap();
}
void DatPhiNongNghiep::XuatDatPNN()
{
    DatDai::Xuat();
}
int DatPhiNongNghiep::Kt_Han()
{
    return 0;
}
void NguoiSuHuu::NhapThongTinNguoiSoHuu()
{
    cin.ignore();
    cout << "\nNhap ho va ten: ";
    getline(cin, ho_ten);
    cout << "\nNhap dia chi thuong tru: ";
    getline(cin, dia_chi_thuong_tru);
    cout << "\nNhap so CMND: ";
    cin >> CMND;
    cout << "\nNhap nam sinh:";
    cin >> NamSinh;
}
void NguoiSuHuu::XuatThongTinNguoiSoHuu()
{
    cout << "Xuat ho va ten: " << ho_ten << endl;
    cout << "\nXuat so CMND: " << CMND;
    cout << "\nXuat nam sinh: " << NamSinh;
    cout << "\nXuat dia chi thuong tru: " << dia_chi_thuong_tru << endl;
}
int main()
{
    DatDai* DanhSachDatDai[100];
    int so_luong_so_hong;
    cout << "Nhap so luong so hong: " << endl;
    cin >> so_luong_so_hong;
    for (int i = 0; i < so_luong_so_hong; i++)
    {
        int LoaiDatDai;
        cout << "Nhap loai dat dai: " << endl;
        cin >> LoaiDatDai;
        if (LoaiDatDai == 1)
        {
            DanhSachDatDai[i] = new DatNongNghiep;
        }
        if (LoaiDatDai == 2)
        {
            DanhSachDatDai[i] = new DatPhiNongNghiep;
        }
        DanhSachDatDai[i]->Nhap();
    }
    long long TienThueLonNhat = DanhSachDatDai[0]->TinhTienThue();
    long long TongTienThue = 0;
    int MaxPosition = 0, SoLuongThuaDatQuaHan = 0;
    for (int i = 0; i < so_luong_so_hong; i++)
    {
        TongTienThue += DanhSachDatDai[i]->TinhTienThue();
        if (TienThueLonNhat < DanhSachDatDai[i]->TinhTienThue())
        {
            TienThueLonNhat = DanhSachDatDai[i]->TinhTienThue();
            MaxPosition = i;
        }
    }
    cout << "Tong so tien thue la: " << TongTienThue << endl;
    cout << "Thua dat dong nhieu tien nhat la: " << endl;
    DanhSachDatDai[MaxPosition]->Xuat();
    cout << "Danh sach thua dat qua han: " << endl;
    for (int i = 0; i < so_luong_so_hong; i++)
    {
        if (DanhSachDatDai[i]->Kt_Han())
        {
            DanhSachDatDai[i]->Xuat();
            SoLuongThuaDatQuaHan++;
        }
    }
    if (SoLuongThuaDatQuaHan == 0)
    {
        cout << "Khong co thua dat qua han." << endl;
    }
    return 0;
}