#include<bits/stdc++.h>
using namespace std;

class vu_khi
{
protected:
	float satThuong;
public:
	int luot;
	vu_khi(float st, int l)
	{
		satThuong = st;
		luot = l;
	}
	virtual float tinhSatThuong() = 0;
	virtual void giamLuot() = 0;
};

class dao : public vu_khi
{
private: 
	float chieuDai;
public:
	dao(float st, int l, float d) : vu_khi(st,l)
	{
		chieuDai = d;
	}
	virtual float tinhSatThuong()
	{
		return satThuong * chieuDai;
	}
	virtual void giamLuot()
	{
		luot--;
	}
};

class cungTen : public vu_khi
{
private:
	float muiTen;
public:
	cungTen(float st, int l, float mt) : vu_khi(st,l)
	{
		muiTen = mt;
	}
	virtual float tinhSatThuong()
	{
		return satThuong * muiTen / 2;
	}
	virtual void giamLuot()
	{
		luot-=2;
	}
};

class tayKhong
{
	float satThuong;
public:
	tayKhong(float maxHP)
	{
		satThuong = maxHP * 0.1;
	}
	float tinhSatThuong()
	{
		return satThuong;
	}
};

class thuDu
{
protected:
	float HP,satThuong;
public:
	thuDu(float hp, float st)
	{
		HP = hp;
		satThuong = st;
	}
	virtual void biTanCong(float damage) = 0;
	virtual float tinhSatThuong() = 0;
	virtual bool conSong() = 0;
};

class boTot : public thuDu
{
private:
	int soLanChiuDanh;
public:
	boTot(float hp, float st, int slcd) : thuDu(hp,st)
	{
		soLanChiuDanh = slcd;
	}
	virtual void biTanCong(float damage)
	{
		HP -= damage;
		soLanChiuDanh--;
	}
	virtual float tinhSatThuong()
	{
		return satThuong;
	}
	virtual bool conSong()
	{
		return (HP > 0 && soLanChiuDanh > 0) ? true : false;
	}
};

class ho : public thuDu
{
public:
	ho(float hp, float st) : thuDu(hp,st){}
	virtual float tinhSatThuong()
	{
		return 1.5 * satThuong;
	}
	virtual bool conSong()
	{
		return (HP > 0) ? true : false;
	}
	virtual void biTanCong(float damage)
	{
		HP -= damage;
	}
};

class A_phu
{
public:
	float currentHP, maxHP;
	A_phu(float hp)
	{
		currentHP = hp;
		maxHP = hp;
	}
	bool conSong()
	{
		return (currentHP > 0) ? true : false;
	}
	void tanCongBangVuKhi(vu_khi* vk, thuDu* td)
	{
		td->biTanCong(vk->tinhSatThuong());
		vk->giamLuot();
	}
	void tanCongBangTayKhong(tayKhong* vk, thuDu* td)
	{
		td->biTanCong(vk->tinhSatThuong());
		currentHP -= 0.1 * maxHP;
	}
	void biTanCong(thuDu* td)
	{
		currentHP -= td->tinhSatThuong();
	}
};

int main()
{
	int HP;
	cin>>HP;
	A_phu* aphu = new A_phu(HP);
	int n;
	cin>>n;
	vector<vu_khi*> vk(n);
	int type;
	for (int i = 0; i < n; ++i)
	{
		cin>>type;
		if (type == 1)
		{
			float satThuong, chieuDai;
			int luot;
			cin>>satThuong>>luot>>chieuDai;
			vk[i] = new dao(satThuong,luot,chieuDai);
		}
		else if (type == 2)
		{
			float satThuong, muiTen;
			int luot;
			cin>>satThuong>>luot>>muiTen;
			vk[i] = new cungTen(satThuong, luot, muiTen);
		}
	}
	int m;
	cin>>m;
	vector<thuDu*> td(m);
	for (int i = 0; i < m; ++i)
	{
		cin>>type;
		if (type == 1)
		{
			float hp,st;
			int soLanChiuDanh;
			cin>>hp>>st>>soLanChiuDanh;
			td[i] = new boTot(hp,st,soLanChiuDanh);
		}
		else if (type == 2)
		{
			float hp,st;
			cin>>hp>>st;
			td[i] = new ho(hp,st);
		}
	}
	while (aphu->conSong())
	{
		if (td.size() == 0) break;
		if (vk.size() > 0) 
		{
			aphu->tanCongBangVuKhi(vk[0],td[0]);
			if (vk[0]->luot == 0) vk.erase(vk.begin());
			if (td[0]->conSong()) aphu->biTanCong(td[0]);
			else td.erase(td.begin());
		}
		else
		{
			tayKhong* tk = new tayKhong(aphu->maxHP);
			aphu->tanCongBangTayKhong(tk,td[0]);
			if (td[0]->conSong()) aphu->biTanCong(td[0]);
			else td.erase(td.begin());
		}
	}
	if (td.size() == 0) 
		cout<<"A Phu chien thang, hp con lai: "<<aphu->currentHP<<", so vu khi con lai: "<<vk.size();
	else if (!aphu->conSong())
		cout<<"A Phu that bai, so thu du con lai: "<<td.size();
	for (int i = 0; i < td.size(); ++i)
	{
		delete td[i];
	}
	for (int i = 0; i < vk.size(); ++i)
	{
		delete vk[i];
	}
	return 0;
}
	