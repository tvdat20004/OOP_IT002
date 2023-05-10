#include<bits/stdc++.h>
using namespace std;

class CPU
{
public:
	int gia_nhap, core;
	float xung_nhip;
	string ma_cpu, hang, loai_cpu;
	void nhap_cpu()
	{
		cin>>loai_cpu>>ma_cpu;
		if (loai_cpu == "1")
		{
			loai_cpu = "Alpha";
			gia_nhap = 200;
			core = 2;
			xung_nhip = 1.8;
			hang = "Black";
		}
		else if (loai_cpu == "2") 
		{
			loai_cpu = "Beta";
			gia_nhap = 400;
			core = 4;
			xung_nhip = 2.46;
			hang = "Black";
		}
		else if (loai_cpu == "3")
		{
			loai_cpu = "Gamma";
			gia_nhap = 600;
			core = 4;
			xung_nhip = 2.6;
			hang = "White";
		}
 	}
 	void print()
 	{
 		cout<<"CPU: "<<ma_cpu<<' '<<loai_cpu<<' '<<hang<<' '<<core<<' '<<xung_nhip<<' '<<gia_nhap<<"\n";
 	}
};
class vo_smartphone
{
public:
	string ma_vo, hang, mau, loai_vo;
	int gia_vo,gia_nhap;
	void nhap_vo()
	{
		cin>>loai_vo>>ma_vo>>mau;
		if (mau == "1") mau = "Do";
		else if (mau == "2") mau = "Den";
		else mau = "Xanh";
		if (loai_vo == "1") 
		{
			loai_vo = "Nhom";
			gia_nhap = 400;
			hang = "Black";
		}
		else if (loai_vo == "2") 
		{
			loai_vo = "Nhua";
			gia_nhap = 200;
			hang = "White";
		}
	}
	void print()
	{
		cout<<"Vo smartphone: "<<ma_vo<<' '<<loai_vo<<' '<<hang<<' '<<mau<<' '<<gia_nhap<<"\n";
	}
};

class man_hinh
{
public:
	string ma_mh, do_phan_giai, hangsx;
	bool chong_loa;
	int gia_nhap;
	void nhap_mh()
	{
		cin>>ma_mh>>hangsx>>do_phan_giai;
		if (do_phan_giai == "1") 
		{
			do_phan_giai = "HD";
			gia_nhap = 200;
		}
		else if (do_phan_giai == "2")
		{
			do_phan_giai = "FullHD";
			cin>>chong_loa;
			if (chong_loa) gia_nhap = 500;
			else gia_nhap = 300;
		}
	}
	void print()
	{
		cout<<"Man hinh: "<<ma_mh<<' '<<hangsx<<' '<<do_phan_giai<<' '<<gia_nhap<<' ';
		if (do_phan_giai == "FullHD") cout<<(chong_loa) ? "Chong_loa = 1\n" : "Chong_loa = 0\n";
		else cout<<"\n";
	}
};
class smartphone
{
protected:
	string ma_sp, dong_sp;
	man_hinh mh;
	CPU cpu;
	vo_smartphone vo;
public:
	void nhap_smartphone()
	{
		cin>>ma_sp;
		cpu.nhap_cpu();
		mh.nhap_mh();
		vo.nhap_vo();
	}
	int getTong_gia_nhap()
	{
		return vo.gia_nhap + mh.gia_nhap + cpu.gia_nhap;
	}
	virtual double tinh_gia() = 0;
	void print()
	{
		cout<<"Smartphone: "<<ma_sp<<' '<<dong_sp<<' '<<tinh_gia()<<'\n';
		cpu.print();
		mh.print();
		vo.print();
	}
};
class Venus : public smartphone
{
public:
	Venus()
	{
		dong_sp = "Venus";
	}
	virtual double tinh_gia()
	{
		return getTong_gia_nhap() * 1.3;
	}
};
class Mars : public smartphone
{
public:
	Mars()
	{
		dong_sp = "Mars";
		vo.loai_vo = "Nhom";
		mh.do_phan_giai = "FullHD";
	}
	virtual double tinh_gia()
	{
		return getTong_gia_nhap() * 1.5;
	}
};
class Jupiter : public smartphone
{
public:
	Jupiter()
	{
		dong_sp = "Jupiter";
		cpu.loai_cpu = "Gamma";
		mh.do_phan_giai = "FullHD";
		mh.chong_loa = 1;
		vo.loai_vo = "Nhom";
	}
	virtual double tinh_gia()
	{
		return getTong_gia_nhap() * 1.8;
	}
};
int main()
{
	int n;
	cin>>n;
	vector<smartphone*> sp(n);
	for (int i = 0; i < n; ++i)
	{
		int type;
		cin>>type;
		if (type == 1)
		{
			sp[i] = new Venus();
			sp[i]->nhap_smartphone();
		}
		if (type == 2)
		{
			sp[i] = new Mars();
			sp[i]->nhap_smartphone();
		}
		if (type == 3)
		{
			sp[i] = new Jupiter();
			sp[i]->nhap_smartphone();
		}
	}
	for (int i = 0; i < n; ++i)
	{
		sp[i]->print();
		delete sp[i];
	}
	return 0;
}