#include<bits/stdc++.h>
using namespace std;
class Enemy
{
public:
	float phiscalDEF, magicalDEF;
	float HP,maxHP;
	Enemy(float hp, float phiscal_def, float magical_def)
	{
		HP = hp;
		maxHP = hp;
		phiscalDEF = phiscal_def;
		magicalDEF = magical_def;
	}
	bool isDead()
	{
		return HP <= 0;
	}
};
class Tower
{
public:
	int ID;
	virtual void attack	(Enemy* e) = 0;
};
class Archer : public Tower
{
private:
	float phisicalDame;
public:
	Archer(float _phisicalDame)
	{
		phisicalDame = _phisicalDame;
		ID = 1;
	}
	virtual void attack(Enemy* e)
	{
		float dame = 0.1 * e->maxHP + phisicalDame;
		if (dame > e->phiscalDEF) e->HP -= dame - e->phiscalDEF;		
	}
};
class Arcane : public Tower
{
private:
	float magicalDame;
public:
	Arcane(float _magicalDame)
	{
		ID = 2;	
		magicalDame = _magicalDame;
	}
	virtual void attack(Enemy* e)
	{
		if (magicalDame > e->magicalDEF) 
		{
			e->HP -= magicalDame - e->magicalDEF;
			e->phiscalDEF = 0;
		}
	}
};
bool cmp_enemy(Enemy* e1,Enemy* e2)
{
	return e1->HP > e2->HP;
}
void releaseMemory(vector<Tower*> &tower, vector<Enemy*> &enemy)
{
	for (auto i = 0; i < tower.size(); ++i)
	{
		delete tower[i];
	}
	for (auto i = 0; i < enemy.size(); ++i)
	{
		delete enemy[i];
	}
}
int findMinHP(vector<Enemy*> &e)
{
	int min = 0;
	for (auto i = 1; i < e.size(); ++i)
	{
		if (e[i]->HP < e[min]->HP) min = i;
	}
	return min;
}
int main()
{
	// int n;
	// cin>>n;
	// int type,nSoldier,time;
	// vector<Tower*> tower;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin>>type;
	// 	if (type == 1) 
	// 	{
	// 		int phisicalDame;
	// 		cin>>phisicalDame;
	// 		Tower* _tower = new Archer(phisicalDame);
	// 		tower.push_back(_tower);
	// 	}
	// 	else if (type == 2)
	// 	{
	// 		int magicalDame;
	// 		cin>>magicalDame;
	// 		Tower* _tower = new Arcane(magicalDame);
	// 		tower.push_back(_tower);
	// 	}
	// 	else if(type == 3) cin>>nSoldier>>time;
	// }
	// int m,phiscalDEF, magicalDEF;
	// cin>>m;
	// float HP;
	// vector<Enemy*> enemy(m);
	// for (int i = 0; i < m; ++i)
	// {
	// 	cin>>HP>>phiscalDEF>>magicalDEF;
	// 	enemy[i] = new Enemy(HP,phiscalDEF,magicalDEF);
	// }
	// if (m > nSoldier) 
	// {
	// 	cout<<"FAILED";
	// 	releaseMemory(tower,enemy);
	// 	return 0;
	// }
	int n;
    cin>>n;
    int type,nSoldier,time;
    vector<Tower*> tower;
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        cin>>type;
        if (type == 1) 
        {
            int phisicalDame;
            cin>>phisicalDame;
            Tower* _tower = new Archer(phisicalDame);
            tower.push_back(_tower);
        }
        else if (type == 2)
        {
            int magicalDame;
            cin>>magicalDame;
            Tower* _tower = new Arcane(magicalDame);
            tower.push_back(_tower);
        }
        else if(type == 3) cin>>nSoldier>>time;
    }
    int m,phiscalDEF, magicalDEF;
    cin>>m;
    float HP;
    vector<Enemy*> enemy(m);
    for (int i = 0; i < m; ++i)
    {
        cin>>HP>>phiscalDEF>>magicalDEF;
        enemy[i] = new Enemy(HP,phiscalDEF,magicalDEF);
    }
    if (m > nSoldier) 
    {
        cout<<"FAILED";
        releaseMemory(tower,enemy);
        return 0;
    }
	while (time > 0 && !enemy.empty())
	{
		sort(enemy.begin(), enemy.end(),cmp_enemy);
		// cout<<enemy.back()->HP<<endl;
		for(auto &x : tower)
		{
			if (x->ID == 2) x->attack(enemy.back());
		}
		for (auto &x : tower)
		{
			if (x->ID == 1) x->attack(enemy.back());
		}
		if (enemy.back()->isDead()) enemy.pop_back();
		time--;
	}
	if(!enemy.empty()) 
	{
		for(auto x : enemy)
		{
			cout<<x->HP<<endl;
		}
		return 0;
	}	
	if (time >= 0) cout<<"SUCCESS";
	releaseMemory(tower,enemy);
	return 0;
}