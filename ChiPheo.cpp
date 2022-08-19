#include <iostream>
using namespace std;
class Hinh3D
{
protected:
	string ten_loai_chai;
	int so_luong;
	float dien_tich;
	float the_tich;
public:
	virtual void Nhap()=0;
	virtual float TinhDienTichXQ() = 0;
	virtual float TinhDienTichTP() = 0;
	virtual float TinhTheTich() = 0;
};
class ChaiHinhTruTron : public Hinh3D
{ 
public:
	int chieu_cao;
	int ban_kinh;
	float dien_tich1;
	float the_tich1;
	void Nhap();
	float TinhDienTichXQ();
	float TinhDienTichTP();
	float TinhTheTich();
};
class ChaiHinhHopCN : public Hinh3D
{
public:
	int chieu_dai;
	int chieu_rong;
	int chieu_cao;
	float dien_tich2;
	float the_tich2;
	void Nhap();
	float TinhDienTichXQ();
	float TinhDienTichTP();
	float TinhTheTich();
};
class ChaiHinhLapPhuong : public Hinh3D
{ 
public:
	int canh;
	float dien_tich3;
	float the_tich3;
	void Nhap();
	float TinhDienTichXQ();
	float TinhDienTichTP();
	float TinhTheTich();
};
int main()
{
	Hinh3D* SoChai[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int loai;
		cin >> loai;
		if (loai == 1)
		{
			SoChai[i] = new ChaiHinhTruTron;
		}
		if (loai == 2)
		{
			SoChai[i] = new ChaiHinhHopCN;
		}
		if (loai == 3)
		{
			SoChai[i] = new ChaiHinhLapPhuong;
		}
		SoChai[i]->Nhap();
	}
	float dt = 0;
	for (int i = 0; i < n; i++)
	{
		dt += SoChai[i]->TinhDienTichXQ() + SoChai[i]->TinhDienTichTP();
	}
	cout << "Dien tich chai vo: " << dt;
	float tt = 0;
	for (int i = 0; i < n; i++)
	{
		tt += SoChai[i]->TinhTheTich() * 0.1;
	}
	cout << "\nLuong nuoc tren mat dat: " << tt ;
	return 0;
}
void ChaiHinhTruTron::Nhap()
{
	cin >> chieu_cao >> ban_kinh;
}
float ChaiHinhTruTron::TinhDienTichXQ()
{
	dien_tich1 = (float)(2 * 3.14 * chieu_cao * ban_kinh);
	return dien_tich1;
}
float ChaiHinhTruTron::TinhDienTichTP()
{
	return 0;
}
float ChaiHinhTruTron::TinhTheTich()
{
	the_tich1 = (float)(3.14 * ban_kinh * ban_kinh * chieu_cao);
	return the_tich1;
}
void ChaiHinhHopCN::Nhap()
{
	cin >> chieu_cao >> chieu_rong >> chieu_dai;
}
float ChaiHinhHopCN::TinhDienTichXQ()
{
	return 0;
}
float ChaiHinhHopCN::TinhDienTichTP()
{
	dien_tich2 = (float)(2 * chieu_cao * (chieu_dai + chieu_rong) + 2 * chieu_dai * chieu_rong);
	return dien_tich2;
}
float ChaiHinhHopCN::TinhTheTich()
{
	the_tich2 = (float)(chieu_cao * chieu_dai * chieu_rong);
	return the_tich2;
}
void ChaiHinhLapPhuong::Nhap()
{
	cin >> canh;
}
float ChaiHinhLapPhuong::TinhDienTichXQ()
{
	return 0;
}
float ChaiHinhLapPhuong::TinhDienTichTP()
{
	dien_tich3 = (float)(6 * canh * canh);
	return dien_tich3;
}
float ChaiHinhLapPhuong::TinhTheTich()
{
	the_tich3 = (float)(canh * canh * canh);
	return the_tich3;
}