#include <iostream>
#include <string.h>
using namespace std;
static int TongSoSanPham = 0;
static int TongSoNgayLamViec = 0;
class NhanVien
{
protected:
	string hoten;
	float luong;
public:
	virtual void Nhap()
	{
		cin >> hoten;
	}
	void Xuat()
	{
		cout << hoten << ":" << luong;
	}
	virtual void TinhLuong() = 0;
};
class NhanVienSanXuat : public NhanVien
{
public:
	float luongcanban;
	int sosanpham;
	void Nhap()
	{
		NhanVien::Nhap();
		cin >> luongcanban >> sosanpham;
		TongSoSanPham += sosanpham;
	}
	void TinhLuong()
	{
		luong = luongcanban + sosanpham * 5;
	}
};
class NhanVienVanPhong : public NhanVien
{
public:
	int songaylamviec;
	void Nhap()
	{
		NhanVien::Nhap();
		cin >> songaylamviec;
		TongSoNgayLamViec += songaylamviec;
	}
	void TinhLuong()
	{
		luong = songaylamviec * 100;
	}
};
class Sep : public NhanVien
{
	void TinhLuong()
	{
		luong = TongSoSanPham * 2 + TongSoNgayLamViec * 40 +100;
	}
};
int main()
{
	int n;
	cin >> n;
	NhanVien* DSNhanVien[100];
	for (int i = 0; i < n; i++)
	{
		int loai;
		cin >> loai;
		if (loai == 1)
		{
			DSNhanVien[i] = new NhanVienSanXuat;
		}
		if (loai == 2)
		{
			DSNhanVien[i] = new NhanVienVanPhong;
		}
		if (loai == 3)
		{
			DSNhanVien[i] = new Sep;
		}
		DSNhanVien[i]->Nhap();
	}
	for (int i = 0; i < n; i++)
	{
		DSNhanVien[i]->TinhLuong();
		DSNhanVien[i]->Xuat();
	}
	return 1;
}