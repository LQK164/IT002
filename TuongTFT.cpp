#include <iostream>
#include <string>
using namespace std;
class Tuong
{
protected:
	string ten;
	int luot, SatThuong;
public:
	Tuong();
	string getTen();
	void setLuot(int);
	virtual void Nhap();
	virtual void TinhSatThuong() = 0;
	void TangDameHe();
	void Xuat();
};
class Shaco : public Tuong
{
public:
	void Nhap();
	void TinhSatThuong();
};
class Zed : public Tuong
{
public:
	void Nhap();
	void TinhSatThuong();
};
void TinhDameHe(Tuong* a[], int SoLuong)
{
    int ShacoX = 0;
    int ZedX = 0;
    for (int i = 0; i < SoLuong; i++)
    {
        if (a[i]->getTen() == "Shaco")
        {
            ShacoX += 1;
        }
        if (a[i]->getTen() == "Zed")
        {
            ZedX += 1;
        }
    }
    if (ShacoX > 0 and ZedX > 0)
    {
        for (int i = 0; i < SoLuong; i++)
        {
            a[i]->TangDameHe();
        }
    }
}
Tuong::Tuong()
{
    luot = 0;
    SatThuong = 0;
}
string Tuong::getTen()
{
    return ten;
}
void Tuong::setLuot(int turn)
{
    luot = turn;
}
void Tuong::TangDameHe()
{
    SatThuong += 10;
}
void Tuong::Nhap()
{
    cin >> SatThuong;
}
void Tuong::Xuat()
{
    cout << ten << " - Sat thuong gay ra: " << SatThuong << endl;
}
void Zed::Nhap()
{
    Tuong::Nhap();
    ten = "Zed";
}
void Zed::TinhSatThuong()
{
    int Luotx1 = 0, Luotx3 = 0;
    Luotx3 = luot / 3;
    Luotx1 = luot - Luotx3;
    SatThuong = SatThuong * Luotx1 + SatThuong * Luotx3 * 3;
}
void Shaco::Nhap()
{
    Tuong::Nhap();
    ten = "Shaco";
}
void Shaco::TinhSatThuong()
{
    SatThuong = SatThuong * 2 * luot;
}
int main()
{
    Tuong* MatTham[100];
    int SoLuong, SoLuot;
    cin >> SoLuong;
    for (int i = 0; i < SoLuong; i++)
    {
        int Loai;
        cin >> Loai;
        if (Loai == 1)
        {
            MatTham[i] = new Shaco;
        }
        if (Loai == 2)
        {
            MatTham[i] = new Zed;
        }
        MatTham[i]->Nhap();
    }
    cin >> SoLuot;
    for (int i = 0; i < SoLuong; i++)
    {
        MatTham[i]->setLuot(SoLuot);
    }
    TinhDameHe(MatTham, SoLuong);
    for (int i = 0; i < SoLuong; i++)
    {
        MatTham[i]->TinhSatThuong();
    }
    for (int i = 0; i < SoLuong; i++)
    {
        MatTham[i]->Xuat();
    }
	return 0;
}