#include <bits/stdc++.h>
using namespace std;
const float PI = 3.14;
class point
{
private:
	float x,y;
public:
	point(){};
	void Set(float temp_x, float temp_y)
	{
		x =temp_x;
		y = temp_y;
	}
	void tinhTien(float radian, float length)
	{
		x += length * cos(radian);
		y += length * sin(radian);
	}
	void print()
	{
		cout<<"("<<x<<','<<y<<")"<<endl;
	}
	~point(){};
};
class triangle
{
private:
	point A,B,C;
public:
	triangle(){};
	void input()
	{
		float xA,yA,xB,yB,xC,yC;
		cin>>xA>>yA>>xB>>yB>>xC>>yC;
		A.Set(xA,yA);
		B.Set(xB,yB);
		C.Set(xC,yC);
	}
	void tinhTien(float radian, float length)
	{
		A.tinhTien(radian,length);
		B.tinhTien(radian,length);
		C.tinhTien(radian,length);
	}
	void print()
	{
		A.print();
		B.print();
		C.print();
	}
	~triangle(){};
};
int main()
{
	triangle ABC;
	ABC.input();
	float degree, length;
	cin>>degree>>length;
	float radian = degree * PI / 180;
	ABC.tinhTien(radian,length);
	ABC.print();
	return 0;
}