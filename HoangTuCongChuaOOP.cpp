#include <iostream>
using namespace std;
class gate
{
protected:
    int loai_cong;
public:
    virtual void Nhap() = 0;
    virtual int TraVeGiaTri() = 0;
    int GetLoai();
};
class Business_Gate : public gate
{
    int don_gia;
    int so_hang;
    void Nhap();
    int TraVeGiaTri();
};
class Academy_Gate : public gate
{
    int tri_tue;
    void Nhap();
    int TraVeGiaTri();
};
class Power_Gate : public gate
{
    int suc_manh;
    void Nhap();
    int TraVeGiaTri();
};
int main()
{
    gate* Cong[1000];
    int so_luong;
    int i = 0;
    cin >> so_luong;
    for (i = 0; i < so_luong; i++)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
        {
            Cong[i] = new Business_Gate();
        }
        if (loai == 2)
        {
            Cong[i] = new Academy_Gate();
        }
        if (loai == 3)
        {
            Cong[i] = new Power_Gate();
        }
        Cong[i]->Nhap();
    }
    int Tien, TriTue, SucManh, count = 0;
    cin >> Tien >> TriTue >> SucManh;
    for (int i = 0; i < so_luong; i++)
    {
        if (Cong[i]->GetLoai() == 1)
        {
            Tien -= Cong[i]->TraVeGiaTri();
            if (Tien >= 0)
            {
                count++;
            }
        }
        if (Cong[i]->GetLoai() == 2)
        {
            if (Cong[i]->TraVeGiaTri() <= TriTue)
            {
                count++;
            }
        }
        if (Cong[i]->GetLoai() == 3)
        {
            SucManh -= Cong[i]->TraVeGiaTri();
            if (SucManh >= 0)
            {
                count++;
            }
        }
    }
    if (count == so_luong)
        cout << Tien << " " << TriTue << " " << SucManh;
    else
        cout << -1;
    return 0;
}
int gate::GetLoai()
{
    return loai_cong;
}
void Business_Gate::Nhap()
{
    cin >> don_gia >> so_hang;
    loai_cong = 1;
}
int Business_Gate::TraVeGiaTri()
{
    return don_gia * so_hang;
}
void Academy_Gate::Nhap()
{
    cin >> tri_tue;
    loai_cong = 2;
}
int Academy_Gate::TraVeGiaTri()
{
    return tri_tue;
}
void Power_Gate::Nhap()
{
    cin >> suc_manh;
    loai_cong = 3;
}
int Power_Gate::TraVeGiaTri()
{
    return suc_manh;
}