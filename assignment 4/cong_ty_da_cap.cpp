#include<bits/stdc++.h>
using namespace std;

class nhanvien
{
protected: 
	string hoten;
public:
	static int tong_sp;
	static int tong_soNgayLamViec;
	nhanvien(string hoten)
	{
		this->hoten = hoten;
	}
	virtual double tinhLuong() = 0;
	string getHoten()
	{
		return hoten;
	}
	void inThongTin()
	{
		cout<<hoten<<": "<<tinhLuong()<<endl;
	}
};
int nhanvien::tong_sp = 0;
int nhanvien::tong_soNgayLamViec = 0;
class nvsx : public nhanvien
{
private:
	float luongcb;
	int sp;
public:
	nvsx(string hoten, float luongcb, int sp) : nhanvien(hoten)
	{
		this->luongcb = luongcb;
		this->sp = sp;
		tong_sp += sp;
	}
	virtual double tinhLuong()
	{
		return luongcb + sp * 5;
	}
};

class nvvp : public nhanvien
{
private:
	int soNgayLamViec;
public:
	nvvp(string hoten, int soNgayLamViec) : nhanvien(hoten)
	{
		this->soNgayLamViec = soNgayLamViec;
		tong_soNgayLamViec += soNgayLamViec;
	}
	virtual double tinhLuong()
	{
		return soNgayLamViec * 100;
	}
	int getSoNgayLamViec()
	{
		return soNgayLamViec;
	}
};

class Sep : public nhanvien
{
public:
	Sep(string hoten) : nhanvien(hoten){}
	virtual double tinhLuong()
	{
		return 100 + tong_sp*2 + tong_soNgayLamViec*40;
	}
};
int main()
{
	int n;
	cin>>n;
	vector<nhanvien*> nv(n);
	for (int i = 0; i < n; i++)
	{
		int type;
		cin>>type;
		string ht;
		// cin.ignore();
		// getline(cin,ht);
		cin>>ht;
		if (type == 1)
		{
			int _luongcb,_sp;
			cin>>_luongcb>>_sp;
			nv[i] = new nvsx(ht, _luongcb, _sp);
		}
		else if (type == 2)
		{
			int _soNgayLamViec;
			cin>>_soNgayLamViec;
			nv[i] = new nvvp(ht, _soNgayLamViec);
		}
		else if (type == 3)
		{
			nv[i] = new Sep(ht);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		nv[i]->inThongTin();
	}
	for (int i = 0; i < n; ++i)
	{
		delete nv[i];
	}
}