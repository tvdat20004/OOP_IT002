#include<bits/stdc++.h>
using namespace std;
class gate
{
public:
	virtual void input() = 0;
	virtual bool condition (int &money, int &wisdom, int &power) = 0;
};
class business_gate : public gate
{
private:
	int don_gia,so_hang;
public:
	void input()
	{
		cin>>don_gia>>so_hang;
	}
	virtual bool condition(int &money, int &wisdom, int &power)
	{
		money -= don_gia * so_hang;
		if (money < 0) return false;
		else return true;
	}
};
class academic_gate : public gate
{
private: 
	int tri_tue_cau_hoi;
public:
	void input()
	{
		cin>>tri_tue_cau_hoi;
	}
	virtual bool condition(int &money, int &wisdom, int &power)
	{
		if (wisdom >= tri_tue_cau_hoi) return true;
		else return false;
	}
};
class power_gate : public gate
{
private:
	int power;
public:
	void input()
	{
		cin>>power;
	}
	virtual bool condition(int &money, int &wisdom, int &power)
	{
		power -= this->power;
		if (power < 0) return false;
		else return true;
	}
};
// class prince
// {
// private:
// 	int money, int wisdom, int power;
// public:
// 	prince(int money, int wisdom, int power)
// 	{
// 		this->money = money;
// 		this->wisdom = wisdom;
// 		this-> power = power;
// 	}
// 	bool challenge(int type)
// 	{
// 		if (type == 1)

// 	}
// };
int main()
{
	int n;
	cin>>n;
	vector<gate*> chall(n);
	for (int i = 0; i < n; ++i)
	{
		int type;
		cin>>type;
		if (type == 1)
		{
			chall[i] = new business_gate();
			chall[i]->input();
		}
		else if (type == 2)
		{
			chall[i] = new academic_gate();
			chall[i]->input();
		}
		else if (type == 3)
		{
			chall[i] = new power_gate();
			chall[i]->input();
		}
	}
	int money,wisdom,power;
	cin>>money>>wisdom>>power; 
	for (int i = 0; i < n; ++i)
	{
		if (!chall[i]->condition(money,wisdom,power)) 
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<money<<' '<<wisdom<<' '<<power;
	for (int i = 0; i < n; ++i)
	{
	 	delete chall[i];
	}
	return 0; 
}