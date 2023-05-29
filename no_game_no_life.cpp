#include<bits/stdc++.h>
using namespace std;
class Item
{
protected:
	string name,producer;
	float value;
	bool isHat;
public:
	Item(string _name, float _value, string _producer) : name(_name), value(_value), producer(_producer){}
	void buff(float coef)
	{
		if (!isHat) value *= coef;
	}
	float getValue()
	{
		return value;
	}
};

class Jean : public Item
{
private:
	float length;
public:
	Jean(string _name, float _value, string _producer, float _length) : Item(_name,0.8 * _value,_producer)
	{
		isHat = 0;
		length = _length;
	}
};
class Kaki : public Item
{
private:
	float length;
public:
	Kaki(string _name, float _value, string _producer, float _length) : Item(_name, 1.5 * _value, _producer)
	{
		isHat = 0;
		length = _length;
	}

};
class T_shirt : public Item
{
private:
	bool collaredShirt;
	string color;
public:
	T_shirt(string _name, float _value, string _producer, string _color, bool collar) : Item(_name, _value, _producer)
	{
		isHat = 0;
		color = _color;
		collaredShirt = collar;
	}
	
};
class Long_sleeve_shirt : public Item
{
private: 
	float lengthOfSleeve;
	string color;
public:
	Long_sleeve_shirt(string _name, float _value, string _producer,string _color, float _lengthOfSleeve) : Item(_name, _value, _producer)
	{
		isHat = 0;
		color = _color;
		lengthOfSleeve = _lengthOfSleeve;
	}

};
class Iron_hat : public Item
{
private:
	int level;
public:
	Iron_hat(string _name, float _value, string _producer,int _level) : Item(_name, _value, _producer)
	{
		isHat = 1;
		level = _level;
		value = 0;
	}
};
class Silver_hat : public Item
{
private:
	int level;
public:
	Silver_hat(string _name, float _value, string _producer,int _level) : Item(_name, _value, _producer)
	{
		isHat = 1;
		level = _level;
	}
	
};
class Golden_hat : public Item	
{
private:
	int level;
public:
	Golden_hat(string _name, float _value, string _producer,int _level) : Item(_name, _value, _producer)
	{
		isHat = 1;
		level = _level;
	}
};
int main()
{
	int n;
	cin>>n;
	int type;
	float value;
	float buffCoef = 1;
	vector<Item*> item(n);
	string name, producer;
	for (int i = 0; i < n; ++i)
	{
		cin>>type>>name>>value>>producer;
		if (type == 1)
		{
			float length;
			cin>>length;
			item[i] = new Jean(name, value, producer,length);
		}
		else if (type == 2)
		{
			float length;
			cin>>length;
			item[i] = new Kaki(name, value, producer,length);
		}
		else if (type == 3)
		{
			string color;
			bool collaredShirt;
			cin>>color>>collaredShirt;
			item[i] = new T_shirt(name, value, producer, color, collaredShirt);
		}
		else if (type == 4)
		{
			string color;
			float lengthOfSleeve;
			cin>>color>>lengthOfSleeve;
			item[i] = new Long_sleeve_shirt(name, value, producer, color, lengthOfSleeve);
		}
		else if (type == 5) 
		{
			int level;
			cin>>level;
			item[i] = new Iron_hat(name, value, producer, level);
		}
		else if (type == 6)
		{
			int level;
			cin>>level;
			if (buffCoef == 1) buffCoef = 1.5;
			item[i] = new Silver_hat(name, value, producer, level);
		}
		else if (type == 7)
		{
			int level;
			cin>>level;
			if (buffCoef < 3) buffCoef = 3;
			item[i] = new Golden_hat(name, value, producer, level);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		item[i]->buff(buffCoef);
	}
	float sumOfValue = 0;
	for (int i = 0; i < n; ++i)
	{
		sumOfValue += item[i]->getValue();
		delete item[i];
	}
	cout<<sumOfValue;
	return 0;
}