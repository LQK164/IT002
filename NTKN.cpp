#include <iostream>
#include <string>
using namespace std;
static int Luot;
class GiaSuc
{
protected:
    string tiengKeu;
    int luongSua;
    int soLuong;
public:
    GiaSuc();
    virtual void Nhap();
    virtual void TinhSoLuongVaSua() = 0;
    virtual void XuatTiengKeu() = 0;
    virtual void XuatSoLuongVaSua();
    void XuLy();
};
class Bo : public GiaSuc
{
    void Nhap();
    void TinhSoLuongVaSua();
    void XuatSoLuongVaSua();
    void XuatTiengKeu();
};
class De : public GiaSuc
{
    void Nhap();
    void TinhSoLuongVaSua();
    void XuatSoLuongVaSua();
    void XuatTiengKeu();
};
class Cuu : public GiaSuc
{
    void Nhap();
    void TinhSoLuongVaSua();
    void XuatSoLuongVaSua();
    void XuatTiengKeu();
};
class Tho : public GiaSuc
{
    void Nhap();
    void TinhSoLuongVaSua();
    void XuatSoLuongVaSua();
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
void GiaSuc::XuatSoLuongVaSua()
{
    cout << ": " << soLuong << "," << luongSua << endl;
}
void Bo::Nhap()
{
    GiaSuc::Nhap();
    tiengKeu = "Booo";
}
void Bo::TinhSoLuongVaSua()
{
    int n0 = 0, n1 = 0, n2 = 0, n3 = 0;
    for (int i = 1; i <= Luot; i++)
    {
        soLuong = n3 + soLuong;
        luongSua = luongSua + soLuong * 10;
        n3 = n2;
        n2 = n1;
        n1 = n0;
        n0 = soLuong / 2;
    }
    soLuong += n0 + n1 + n2 + n3;
}
void Bo::XuatSoLuongVaSua()
{
    cout << "Bo";
    GiaSuc::XuatSoLuongVaSua();
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
void Cuu::TinhSoLuongVaSua()
{
    int n0 = 0, n1 = 0, n2 = 0, n3 = 0;
    for (int i = 1; i <= Luot; i++)
    {
        soLuong = n3 + soLuong;
        luongSua = luongSua + soLuong * 5;
        n3 = n2;
        n2 = n1;
        n1 = n0;
        n0 = soLuong / 2;
    }
    soLuong += n0 + n1 + n2 + n3;
}
void Cuu::XuatSoLuongVaSua()
{
    cout << "Cuu";
    GiaSuc::XuatSoLuongVaSua();
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
void De::TinhSoLuongVaSua()
{
    int n0 = 0, n1 = 0, n2 = 0, n3 = 0;
    for (int i = 1; i <= Luot; i++)
    {
        soLuong = n3 + soLuong;
        luongSua = luongSua + soLuong * 8;
        n3 = n2;
        n2 = n1;
        n1 = n0;
        n0 = soLuong / 2;
    }
    soLuong += n0 + n1 + n2 + n3;
}
void De::XuatSoLuongVaSua()
{
    cout << "De";
    GiaSuc::XuatSoLuongVaSua();
}
void De::XuatTiengKeu()
{
    for (int i = 1; i < soLuong; i++)
    {
        cout << tiengKeu << ",";
    }
}
void Tho::Nhap()
{
    GiaSuc::Nhap();
    tiengKeu = " ";
}
void Tho::XuatSoLuongVaSua()
{
    cout << "Tho";
    GiaSuc::XuatSoLuongVaSua();
}
void Tho::TinhSoLuongVaSua()
{
    int n0 = 0, n1 = 0;
    for (int i = 1; i <= Luot; i++)
    {
        soLuong = n1 + soLuong;
        luongSua = luongSua + soLuong * 0;
        n1 = n0;
        n0 = soLuong / 2;
    }
    soLuong += n0 + n1;
}
void Tho::XuatSoLuongVaSua()
{
    cout << "Tho";
    GiaSuc::XuatSoLuongVaSua();
}
void Tho::XuatTiengKeu()
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
    Farmer[3] = new Tho;
    Farmer[0]->Nhap();
    Farmer[1]->Nhap();
    Farmer[2]->Nhap();
    Farmer[3]->Nhap();
    cin >> Luot;
    Farmer[0]->XuatTiengKeu();
    Farmer[1]->XuatTiengKeu();
    Farmer[2]->XuatTiengKeu();
    Farmer[3]->XuatTiengKeu();
    Farmer[0]->TinhSoLuongVaSua();
    Farmer[1]->TinhSoLuongVaSua();
    Farmer[2]->TinhSoLuongVaSua(); 
    Farmer[3]->TinhSoLuongVaSua();
    cout << endl;
    Farmer[0]->XuatSoLuongVaSua();
    Farmer[1]->XuatSoLuongVaSua();
    Farmer[2]->XuatSoLuongVaSua();
    Farmer[3]->XuatSoLuongVaSua();
    return 0;
}
