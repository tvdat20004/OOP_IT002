#include<bits/stdc++.h>
using namespace std;

class General
{
protected:
	string name;
	int attack, defend;
	bool isFighter,isAtk,isTech;
public:
	static int sumPrice;
	General(int atk, int def): attack(atk), defend(def) {}
	void upgradeFighter(int numOfFighter = 0)
	{
		if (isFighter)
		{
			if (numOfFighter == 2) defend += 15;
			if (numOfFighter == 3) defend += 30;
		}
	}
	void upgradeAtk()
	{
		if (isAtk) attack += 30;
	}
	void upgradeTech()
	{
		if (isTech) 
		{
			attack += 15;
			defend += 15;
		}
	}	
	int getAttack()
	{
		return attack;
	}
	void print(int slot)
	{
		cout<<name<<" - sat thuong gay ra: "<<damage(slot)<<endl;
	}
	virtual float damage(int slot) = 0;
};
int General::sumPrice = 0;
class Jarvan : public General
{
public:
	Jarvan(int atk, int def) : General(atk, def)
	{
		name = "Jarvan";
		isFighter = 1;
		isAtk = 0;
		isTech = 1;
		sumPrice += 1; 
	}
	virtual float damage(int slot)
	{
		return defend*2*slot;
	}
};
class Reksai: public General
{
public:
	Reksai(int atk, int def) : General(atk,def)
	{
		name = "Reksai";
		isFighter = 1;
		isTech = 0;
		isAtk = 1;
		sumPrice += 2;
	}
	virtual float damage(int slot)
	{
		float sumDame = 0;
		for (int i = 1; i <= slot; i++)
		{
			if (i % 4 == 0) sumDame += attack*2;
			else sumDame += attack;
		}
		return sumDame;
	}
};
class Sivir : public General
{
public:
	Sivir(int atk, int def) : General(atk,def)
	{
		name = "Sivir";
		isTech = 1;
		isFighter = 0;
		isAtk = 0;
		sumPrice += 4;
	}
	virtual float damage(int slot)
	{
		return attack * 2 * slot;
	}	
};
class Illaoi : public General
{
public:
	Illaoi(int atk, int def) : General(atk, def)
	{
		isAtk = 1;
		name = "Illaoi";
		isFighter = 1;
		isTech = 0;
		sumPrice += 1;
	}
	virtual float damage(int slot)
	{
		return slot * (attack + defend) / 2.0;
	}
};
int main()
{
	int n,m;
	cin >> n >> m;
	int type, atk, def;
	vector<bool> appear(5,0);
	vector<General*> general(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>type>>atk>>def;
		if (type == 1) general[i] = new Jarvan(atk,def);
		else if (type == 2) general[i] = new Reksai(atk,def);
		else if (type == 3) general[i] = new Sivir(atk,def);
		else if (type == 4) general[i] = new Illaoi(atk,def);
		appear[type] = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (appear[1] && appear[2] && appear[4]) general[i]->upgradeFighter(3);
		else if ((appear[1] && appear[2]) || (appear[2] && appear[4]) || (appear[4] && appear[1]))
			general[i]->upgradeFighter(2);
		if (appear[2] && appear[4]) general[i]->upgradeAtk();
		if (appear[1] && appear[3]) general[i]->upgradeTech();
	}
	for (int i = 0; i < n; ++i)
	{
		general[i]->print(m);
	}
	cout<<"Tong gia tri: "<<general[0]->sumPrice;
	for (int i = 0; i < n; ++i)
	{
		delete general[i];
	}
	return 0;
}