#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14;
class chai
{
public:
	virtual void surArea() = 0;
	virtual void volume() = 0;
	static double s;
	static double v;
};
double chai::s = 0;
double chai::v = 0;
class hopCN : public chai
{
protected:
	int dai,rong,cao;
public:
	hopCN(int dai,int rong,int cao)
	{
		this->dai = dai;
		this->rong = rong;
		this->cao = cao;
	}
	virtual void surArea()
	{
		s += (double) 2 * (dai*rong + rong*cao + cao*dai);
	}
	virtual void volume()
	{
		v += (double)dai*rong*cao;
	}
};
class lapPhuong : public hopCN
{
private:
	int canh;
public:
	lapPhuong(int canh) : hopCN(canh, canh, canh){}
};
class tru : public chai
{
private:
	int r,h;
public:
	tru(int h,int r)
	{
		this->h = h;
		this->r = r;
	}
	virtual void surArea()
	{
		s += 2 * PI * r * h;
	}
	virtual void volume()
	{
		v += PI * r * r * h;
	}
};
int main()
{
	int n;
	cin>>n;
	vector<chai*> bottles(n);
	for (int i = 0; i < n; i++)
	{
		int type;
		cin>>type;
		if (type == 1)
		{
			int h,r;
			cin>>h>>r;
			bottles[i] = new tru(h,r);
		}
		else if (type == 2)
		{
			int dai,rong,cao;
			cin>>dai>>rong>>cao;
			bottles[i] = new hopCN(dai,rong,cao);
		}
		else if (type == 3)
		{
			int canh;
			cin>>canh;
			bottles[i] = new lapPhuong(canh);
		}
		bottles[i]->surArea();
		bottles[i]->volume();
	}
	cout<<"Dien tich chai vo: "<<bottles[0]->s<<'\n';
	cout<<"Luong nuoc tren mat dat: "<<bottles[0]->v * 0.1;
	for (int i = 0; i < n; ++i)
	{
		delete bottles[i];
	}
	return 0;
}