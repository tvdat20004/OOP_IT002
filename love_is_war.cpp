#include<bits/stdc++.h>
using namespace std;
int n;
class Friend
{
protected:
	string name;
	int age;
public:
	Friend(string _name, int _age) : name(_name), age(_age){}
	virtual float time(int n) = 0;
	virtual void printMostImportant() = 0;
};
class Bestfriend : public Friend
{
private:
	string phone;
public:
	Bestfriend(string _name, int _age, string _phone) : Friend(_name, _age)
	{
		phone = _phone;
	}
	virtual float time(int n)
	{
		return 5;
	}
	virtual void printMostImportant()
	{
		cout<<"Ten: "<<name<<", tuoi: "<<age<<", so dien thoai: "<<phone<<endl;
	}
};
class Boyfriend : public Friend
{
private: 
	string income;
public:
	Boyfriend(string _name, int _age, string _income) : Friend(_name, _age)
	{
		income = _income;
	}
	virtual float time(int n)
	{
		return 5 * stol(income) / 10000000.0;
	}
	virtual void printMostImportant()
	{
		cout<<"Ten: "<<name<<", tuoi: "<<age<<", thu nhap: "<<income<<"d\n";
	}
};
class OtherBoy : public Friend
{
private:
	float atr;
public:
	OtherBoy(string _name, int _age, float _atr) : Friend(_name, _age)
	{
		atr = _atr;
	}
	virtual float time(int n)
	{
		return atr * 20 / n;
	}
	virtual void printMostImportant()
	{
		string level;
		if (atr >= 0.7) level = "cao";
		else if (atr >= 0.4) level = "trung binh";
		else level = "thap";
		cout<<"Ten: "<<name<<", tuoi: "<<age<<", do thu hut: "<<level<<endl;
	}
};
bool cmp (Friend* f1, Friend* f2)
{
	return f1->time(n) > f2->time(n);
}
int main()
{
	cin>>n;
	int type, age;
	string name;
	vector<Friend*> friends(n);
	float timeForBestfriend(0), timeForBoyfriend(0), timeForOtherFriend(0);
	bool hasBestfriend(0), hasBoyfriend(0), hasOtherFriend(0);
	for (int i = 0; i < n; ++i)
	{
		cin>>type>>name>>age;
		if (type == 1) 
		{
			string phone;
			cin>>phone;
			friends[i] = new Bestfriend(name, age, phone);
			hasBestfriend = 1;
			timeForBestfriend += friends[i]->time(n);
		}
		else if (type == 2)
		{
			string income;
			cin>>income;
			friends[i] = new Boyfriend(name, age, income);
			hasBoyfriend = 1;
			timeForBoyfriend += friends[i]->time(n);
		}
		else if (type == 3)
		{
			float atr;
			cin>>atr;
			friends[i] = new OtherBoy(name, age, atr);
			hasOtherFriend = 1;
			timeForOtherFriend += friends[i]->time(n);
		}
	}
	cout<<"Thong ke:\n";
	if (hasBestfriend) cout<<"-Thoi gian cho ban than: "<<timeForBestfriend<<" h\n";
	if (hasBoyfriend) cout<<"-Thoi gian cho ban trai: "<<timeForBoyfriend<<" h\n";
	if (hasOtherFriend) cout<<"-Thoi gian cho ban trai khac: "<<timeForOtherFriend<<" h\n";
	cout<<"Nguoi ban quan trong nhat:\n";
	sort(friends.begin(), friends.end(),cmp);
	float maxTime = friends[0]->time(n);
	for (int i = 0; i < n; ++i)
	{
		if (friends[i]->time(n) == maxTime) friends[i]->printMostImportant();
		delete friends[i];
	}
	return 0;
}
