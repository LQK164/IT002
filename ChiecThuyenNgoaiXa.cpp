#include <iostream>
using namespace std;
class Thuyen
{
protected:
	string so_hieu;
	int so_thuyen_vien;
public:
	virtual void Nhap();
	virtual void Xuat() = 0;
};
class Ghe :public Thuyen
{
private:
	int loai;
public:
	void Nhap();
	void Xuat();
};
class Thuyen_Thuong :public Thuyen
{
private:
	string hang_dong;
public:
	void Nhap();
	void Xuat();
};
class Thuyen_Lon :public Thuyen
{
private:
	string hang_dong;
	int pham_vi;
public:
	void Nhap();
	void Xuat();
};
int main()
{
	Thuyen* Ship[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int loai_tau;
		cin >> loai_tau;
		if (loai_tau == 1)
		{
			Ship[i] = new Ghe;
		}
		if (loai_tau == 2)
		{
			Ship[i] = new Thuyen_Thuong;
		}
		if (loai_tau == 3)
		{
			Ship[i] = new Thuyen_Lon;
		}
		Ship[i]->Nhap();
	}
	for (int i = 0; i < n; i++)
	{
		Ship[i]->Xuat();
	}
	return 0;
}
void Thuyen::Nhap()
{
	cin >> so_hieu >> so_thuyen_vien;
}
void Ghe::Nhap()
{
	Thuyen::Nhap();
	cin >> loai;
}
void Ghe::Xuat()
{
	cout << so_hieu << " - " << "Ghe" << " - " << so_thuyen_vien << " thuyen vien" << " - ";
	if (loai == 1)
	{
		cout << "Co Dong Co" << endl;
	}
	else cout << "Khong Co Dong Co" << endl;
}
void Thuyen_Thuong::Nhap()
{
	Thuyen::Nhap();
	cin >> hang_dong;
}
void Thuyen_Thuong::Xuat()
{
	cout << so_hieu << " - " << "Thuyen thuong" << " - " << so_thuyen_vien << " thuyen vien" << " - " << hang_dong << endl;
}
void Thuyen_Lon::Nhap()
{
	Thuyen::Nhap();
	cin >> hang_dong >> pham_vi;
}
void Thuyen_Lon::Xuat()
{
	cout << so_hieu << " - " << "Thuyen lon" << " - " << so_thuyen_vien << " thuyen vien" << " - " << hang_dong << " - " << pham_vi << "m" << endl;
}