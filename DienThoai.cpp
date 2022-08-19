#include <iostream>
#include <string>
using namespace std;
string MaMH;
string HangSX;
class CPU
{
protected:
    string MaCPU;
    string LoaiCPU;
    string HangCPU;
    int so_core;
    float gia_ban_CPU;
    float xung_nhip;
public:
    void NhapCPU();
    string get_ma_CPU();
    string get_Loai();
    string get_Hang();
    int get_so_core();
    float get_gia_ban_CPU();
    float get_xung_nhip();
    void XuatCPU();
};
class Alpha : public CPU
{
public:
    Alpha();
    void NhapCPU();
    void XuatCPU();
};
class Beta : public CPU
{
public:
    Beta();
    void NhapCPU();
    void XuatCPU();
};
class Gamma : public CPU
{
public:
    Gamma();
    void NhapCPU();
    void XuatCPU();
};
class ManHinh
{
protected:
    string DoPhanGiai;
    float gia_ban_MH;
public:
    virtual void NhapManHinh();
    string get_MaMH();
    string get_HangSX();
    string get_DoPhanGiai();
    float get_gia_ban_MH();
    virtual void XuatManHinh();
};
class HD :public ManHinh
{
public:
    HD();
    void NhapManHinh();
    void XuatManHinh();
};
class FullHD : public ManHinh
{
private:
    bool ChongLoa;
public:
    FullHD();
    void NhapManHinh();
    void XuatManHinh();
};
class Vo_DT
{
protected:
    string Ma_vo;
    string Loai_vo;
    string Hang;
    string mau_sac;
    float gia_ban_Vo;
    int loai_mau_sac;
public:
    virtual void NhapVo();
    string get_Ma_vo();
    string get_Loai_vo();
    string get_Hang();
    string get_mau_sac();
    int getloaiMauSac();
    float get_gia_ban_Vo();
    void XuatVo();
};
class Vo_nhom : public Vo_DT
{
public:
    Vo_nhom();
    void NhapVo();
    void XuatVo();
};
class Vo_nhua : public Vo_DT
{
public:
    Vo_nhua();
    void NhapVo();
    void XuatVo();
};
class SmartPhone
{
protected:
    CPU* cpu;
    ManHinh* mh;
    Vo_DT* Vo;
    int loai_CPU;
    int loai_MH;
    int loai_vo;
    string Ma_DT;
    string Hang_DT;
    float heso;
    float gia_DT;
public:
    virtual void NhapThongTinDT();
    string get_Ma_DT();
    string get_Hang_DT();
    float get_gia_DT();
    virtual float TinhGiaDT() = 0;
    void XuatThongTinDT();
};
class Venus :public SmartPhone
{
public:
    Venus();
    void NhapThongTinDT();
    float TinhGiaDT();
    void XuatThongTinDT();
};
class Mars :public SmartPhone
{
public:
    Mars();
    void NhapThongTinDT();
    float TinhGiaDT();
    void XuatThongTinDT();

};
class Jupiter :public SmartPhone
{
public:
    Jupiter();
    void NhapThongTinDT();
    float TinhGiaDT();
    void XuatThongTinDT();
};
int main()
{
    SmartPhone* SP[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
        {
            SP[i] = new Venus;
        }
        if (loai == 2)
        {
            SP[i] = new Mars;
        }
        if (loai == 3)
        {
            SP[i] = new Jupiter;
        }
        SP[i]->NhapThongTinDT();
    }
    for (int i = 0; i < n; i++)
    {
        SP[i]->XuatThongTinDT();
    }
    return 0;
}
void CPU::NhapCPU()
{
    cin >> MaCPU;
}
float CPU::get_gia_ban_CPU()
{
    return gia_ban_CPU;
}
void CPU::XuatCPU()
{
    cout << "CPU: " << MaCPU << " " << LoaiCPU << " " << HangCPU << " " << so_core << " " << xung_nhip << " " << get_gia_ban_CPU() << endl;
}
Alpha::Alpha()
{
    gia_ban_CPU = 200;
    so_core = 2;
    xung_nhip = 1.8;
    HangCPU = "Black";
    LoaiCPU = "Alpha";
}
void Alpha::NhapCPU()
{
    CPU::NhapCPU();
}
void Alpha::XuatCPU()
{
    CPU::XuatCPU();
}
Beta::Beta()
{
    gia_ban_CPU = 400;
    so_core = 4;
    xung_nhip = 2.46;
    HangCPU = "Black";
    LoaiCPU = "Beta";
}
void Beta::NhapCPU()
{
    CPU::NhapCPU();
}
void Beta::XuatCPU()
{
    CPU::XuatCPU();
}
Gamma::Gamma()
{
    gia_ban_CPU = 600;
    so_core = 4;
    xung_nhip = 2.6;
    HangCPU = "White";
    LoaiCPU = "Gamma";
}

void Gamma::NhapCPU()
{
    CPU::NhapCPU();
}
void Gamma::XuatCPU()
{
    CPU::XuatCPU();
}

void ManHinh::NhapManHinh()
{
    cin >> MaMH;
    cin >> HangSX;
}
string ManHinh::get_MaMH()
{
    return MaMH;
}
string ManHinh::get_HangSX()
{
    return HangSX;
}
string ManHinh::get_DoPhanGiai()
{
    return DoPhanGiai;
}
float ManHinh::get_gia_ban_MH()
{
    return gia_ban_MH;
}
void ManHinh::XuatManHinh()
{
    cout << "Man hinh: " << MaMH << " " << HangSX << " " << DoPhanGiai << " " << get_gia_ban_MH() << endl;
}
HD::HD()
{
    DoPhanGiai = "HD";
    gia_ban_MH = 200;
}
void HD::NhapManHinh()
{
    ManHinh::NhapManHinh();
}
void HD::XuatManHinh()
{
    ManHinh::XuatManHinh();
}
FullHD::FullHD()
{
    DoPhanGiai = "FullHD";
}
void FullHD::NhapManHinh()
{
    ManHinh::NhapManHinh();
    cin >> ChongLoa;
    if (ChongLoa == 1)
    {
        gia_ban_MH = 500;
    }
    else
    {
        gia_ban_MH = 300;
    }
}
void FullHD::XuatManHinh()
{
    ManHinh::XuatManHinh();
    if (ChongLoa == 1)
    {
        cout << " Chong Loa " << endl;
    }
    else
    {
        cout << " " << endl;
    }
}
void Vo_DT::NhapVo()
{
    int loai;
    cin >> Ma_vo;
    cin >> loai_mau_sac;
    cin >> loai;
    if (loai == 1)
    {
        Loai_vo = "Nhom";
    }
    if (loai == 2)
    {
        Loai_vo = "Nhua";
    }
}
string Vo_DT::get_Ma_vo()
{
    return Ma_vo;
}
string Vo_DT::get_Loai_vo()
{
    return Loai_vo;
}
string Vo_DT::get_Hang()
{
    return Hang;
}
string Vo_DT::get_mau_sac()
{
    return mau_sac;
}

int Vo_DT::getloaiMauSac()
{
    return loai_mau_sac;
}
float Vo_DT::get_gia_ban_Vo()
{
    return gia_ban_Vo;
}
void Vo_DT::XuatVo()
{
    cout << "Vo smartphone: " << Ma_vo << " " << Loai_vo << " " << Hang << " " << mau_sac << " " << get_gia_ban_Vo() << endl;
}
Vo_nhom::Vo_nhom()
{
    gia_ban_Vo = 400;
    Hang = "Black";
    Loai_vo = "Nhom";

}
void Vo_nhom::NhapVo()
{
    Vo_DT::NhapVo();
    if (getloaiMauSac() == 1) mau_sac = "Do";
    else mau_sac = "Den";
}
void Vo_nhom::XuatVo()
{
    Vo_DT::XuatVo();
}
Vo_nhua::Vo_nhua()
{
    gia_ban_Vo = 200;
    Hang = "White";
    Loai_vo = "Nhua";
}
void Vo_nhua::NhapVo()
{
    Vo_DT::NhapVo();
    if (getloaiMauSac() == 1) mau_sac = "Do";
    else if (getloaiMauSac() == 2) mau_sac = "Den";
    else if (getloaiMauSac() == 3) mau_sac = "Xanh";
}
void Vo_nhua::XuatVo()
{
    Vo_DT::XuatVo();
}
void SmartPhone::NhapThongTinDT()
{
    cin >> Ma_DT;
}
string SmartPhone::get_Ma_DT()
{
    return Ma_DT;
}
string SmartPhone::get_Hang_DT()
{
    return Hang_DT;
}
float SmartPhone::get_gia_DT()
{
    return (cpu->get_gia_ban_CPU() + mh->get_gia_ban_MH() + Vo->get_gia_ban_Vo()) * heso;
}
void SmartPhone::XuatThongTinDT()
{
    cout << "Smartphone: " << Ma_DT << " " << Hang_DT << " " << get_gia_DT() << endl;
    cpu->XuatCPU();
    mh->XuatManHinh();
    Vo->XuatVo();
}
Venus::Venus()
{
    Hang_DT = "Venus";
    heso = 1.3;
}
void Venus::NhapThongTinDT()
{
    SmartPhone::NhapThongTinDT();
    cpu = new CPU;
    cin >> loai_CPU;
    if (loai_CPU == 1)
    {
        cpu = new Alpha;
    }
    else if (loai_CPU == 2)
    {
        cpu = new Beta;
    }
    cpu->NhapCPU();

    mh = new ManHinh;
    mh->NhapManHinh();
    cin >> loai_MH;
    if (loai_MH == 1)
    {
        mh = new HD;
    }
    else if (loai_MH == 2)
    {
        mh = new FullHD;
    }
    Vo = new Vo_DT;
    cin >> loai_vo;
    if (loai_vo == 1)
    {
        Vo = new Vo_nhom;
    }
    else if (loai_vo == 2)
    {
        Vo = new Vo_nhua;
    }
    Vo->NhapVo();
}
float Venus::TinhGiaDT()
{
    gia_DT = (float)(cpu->get_gia_ban_CPU() + mh->get_gia_ban_MH() + Vo->get_gia_ban_Vo()) * 1.3;
    return gia_DT;
}
void Venus::XuatThongTinDT()
{
    SmartPhone::XuatThongTinDT();
    cout << TinhGiaDT() << endl;
    cpu->XuatCPU();
    cout << endl;
    mh->XuatManHinh();
    cout << endl;
    Vo->XuatVo();
    cout << endl;
}
Mars::Mars()
{
    Hang_DT = "Mars";
    heso = 1.5;
}
void Mars::NhapThongTinDT()
{
    SmartPhone::NhapThongTinDT();
    cpu = new CPU;
    cin >> loai_CPU;
    if (loai_CPU == 1)
    {
        cpu = new Alpha;
    }
    if (loai_CPU == 2)
    {
        cpu = new Beta;
    }
    if (loai_CPU == 3)
    {
        cpu = new Gamma;
    }
    cpu->NhapCPU();
    mh = new ManHinh;
    cin >> loai_MH;
    if (loai_MH == 2)
    {
        mh = new FullHD;
    }
    mh->NhapManHinh();
    Vo = new Vo_DT;
    cin >> loai_vo;
    if (loai_vo == 1)
    {
        Vo = new Vo_nhom;
    }
    Vo->NhapVo();
}
float Mars::TinhGiaDT()
{
    gia_DT = (float)(cpu->get_gia_ban_CPU() + mh->get_gia_ban_MH() + Vo->get_gia_ban_Vo()) * 1.5;
    return gia_DT;
}
void Mars::XuatThongTinDT()
{
    SmartPhone::XuatThongTinDT();
    cout << TinhGiaDT() << endl;
    cpu->XuatCPU();
    cout << endl;
    mh->XuatManHinh();
    cout << endl;
    Vo->XuatVo();
    cout << endl;
}
Jupiter::Jupiter()
{
    Hang_DT = "Jupiter";
    heso = 1.8;
}
void Jupiter::NhapThongTinDT()
{
    SmartPhone::NhapThongTinDT();
    cpu = new CPU;
    cin >> loai_CPU;
    if (loai_CPU == 3)
    {
        cpu = new Gamma;
    }
    cpu = new Gamma;
    cpu->NhapCPU();
    mh = new ManHinh;
    cin >> loai_MH;
    if (loai_MH == 2)
    {
        mh = new FullHD;
    }
    mh = new FullHD;
    mh->NhapManHinh();

    Vo = new Vo_DT;
    cin >> loai_vo;
    if (loai_vo == 1)
    {
        Vo = new Vo_nhom;
    }
    Vo = new Vo_nhom;
    Vo->NhapVo();
}
float Jupiter::TinhGiaDT()
{
    gia_DT = (float)(cpu->get_gia_ban_CPU() + mh->get_gia_ban_MH() + Vo->get_gia_ban_Vo()) * 1.8;
    return gia_DT;
}
void Jupiter::XuatThongTinDT()
{
    SmartPhone::XuatThongTinDT();
    cout << TinhGiaDT() << endl;
    cpu->XuatCPU();
    cout << endl;
    mh->XuatManHinh();
    cout << endl;
    Vo->XuatVo();
    cout << endl;
}