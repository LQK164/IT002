#include <iostream>
#include <string>
using namespace std;
static int Luot;
class GiaSuc
{
protected:
    int luongSua;
    int soLuong;
    string tiengKeu;
public:
    GiaSuc();
    virtual void Nhap();
    virtual void TinhLuongSua() = 0;
    virtual void XuatLuongSua();
    virtual void XuatTiengKeu() = 0;
};
class Bo : public GiaSuc
{
    void Nhap();
    void TinhLuongSua();
    void XuatLuongSua();
    void XuatTiengKeu();
};
class De : public GiaSuc
{
    void Nhap();
    void TinhLuongSua();
    void XuatLuongSua();
    void XuatTiengKeu();
};
class Cuu : public GiaSuc
{
    void Nhap();
    void TinhLuongSua();
    void XuatLuongSua();
    void XuatTiengKeu();
};
GiaSuc::GiaSuc()
{
    luongSua = 0;
    soLuong = 0;
    tiengKeu = " ";
}
void GiaSuc::Nhap()
{
    cin >> soLuong;
}
void GiaSuc::XuatLuongSua()
{
    cout << luongSua << endl;
}
void Bo::Nhap()
{
    GiaSuc::Nhap();
    tiengKeu = "Booo";
}
void Bo::TinhLuongSua()
{
    luongSua = 10 * Luot * soLuong;
}
void Bo::XuatLuongSua()
{
    cout << "Bo: ";
    GiaSuc::XuatLuongSua();
}
void Bo::XuatTiengKeu()
{
    for (int i = 0; i < soLuong; i++)
    {
        cout << tiengKeu << ",";
    }
}
void Cuu::Nhap()
{
    GiaSuc::Nhap();
    tiengKeu = "Beee";
}
void Cuu::TinhLuongSua()
{
    luongSua = 5 * Luot * soLuong;
}
void Cuu::XuatLuongSua()
{
    cout << "Cuu: ";
    GiaSuc::XuatLuongSua();
}
void Cuu::XuatTiengKeu()
{
    for (int i = 0; i < soLuong; i++)
    {
        cout << tiengKeu << ",";
    }
}
void De::Nhap()
{
    GiaSuc::Nhap();
    tiengKeu = "Eeee";
}
void De::TinhLuongSua()
{
    luongSua = 8 * Luot * soLuong;
}
void De::XuatLuongSua()
{
    cout << "De: ";
    GiaSuc::XuatLuongSua();
}
void De::XuatTiengKeu()
{
    for (int i = 1; i < soLuong; i++)
    {
        cout << tiengKeu << ",";
    }
    cout << tiengKeu;
}
int main()
{
    GiaSuc* Farmer[100];
    Farmer[0] = new Bo;
    Farmer[1] = new Cuu;
    Farmer[2] = new De;
    Farmer[0]->Nhap();
    Farmer[1]->Nhap();
    Farmer[2]->Nhap();
    cin >> Luot;
    Farmer[0]->TinhLuongSua();
    Farmer[1]->TinhLuongSua();
    Farmer[2]->TinhLuongSua();
    Farmer[0]->XuatTiengKeu();
    Farmer[1]->XuatTiengKeu();
    Farmer[2]->XuatTiengKeu();
    cout << endl;
    Farmer[0]->XuatLuongSua();
    Farmer[1]->XuatLuongSua();
    Farmer[2]->XuatLuongSua();
    return 0;
}
