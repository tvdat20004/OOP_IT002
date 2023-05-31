#include <bits/stdc++.h>
using namespace std;

class Room
{
public:
	string name;
	int floor,num,capacity;
	static int sumOfCapacity;
	Room(string _name, int _floor, int _num, int _capacity) : name(_name), floor(_floor), num(_num), capacity(_capacity)
	{
		sumOfCapacity += _capacity;
	}
};
int Room::sumOfCapacity = 0;
class Theory : public Room
{
private: 
	bool air_conditioned;
public:
	Theory(string _name, int _floor, int _num, int _capacity, bool _air_conditioned) : Room(_name, _floor, _num, _capacity)
	{
		air_conditioned = _air_conditioned;
	}
	
};
class Practice : public Room
{
private:
	int numOfPC;
public:
	Practice(string _name, int _floor, int _num, int _capacity, int _numOfPC) : Room(_name, _floor, _num, _capacity)
	{
		numOfPC = _numOfPC;
	}	
};
class Lecture_hall : public Room
{
private: 
	int numOfProjector;
public:
	Lecture_hall(string _name, int _floor, int _num, int _capacity, int _numOfProjector) : Room(_name, _floor, _num, _capacity)
	{
		numOfProjector = _numOfProjector;
	}
};
bool cmp(Room* r1,Room* r2)
{
	if (r1->capacity != r2->capacity) return r1->capacity < r2->capacity;
	else if (r1->floor != r2->floor) return r1->floor < r2->floor;
	else return r1->num < r2->num;
}
int main()
{
	int n;
	cin>>n;
	int type,floor,num,capacity;
	string name;
	vector<Room*> room(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>type>>name>>floor>>num>>capacity;
		if (type == 1) 
		{
			bool air_conditioned;
			cin>>air_conditioned;
			room[i] = new Theory(name, floor, num, capacity, air_conditioned);
		}
		else if (type == 2)
		{
			int numOfPC;
			cin>>numOfPC;
			room[i] = new Practice(name,floor,num, capacity, numOfPC);
		}
		else if (type == 3)
		{
			int numOfProjector;
			cin>>numOfProjector;
			room[i] = new Lecture_hall(name, floor, num, capacity, numOfProjector);
		}
	}
	int k;
	cin>>k;
	sort(room.begin(), room.end(), cmp);
	cout<<room[0]->sumOfCapacity<<endl;
	bool isNull = 1;
	for (int i = 0; i < n; ++i)
	{
		if (k < room[i]->capacity) 
		{
			cout<<room[i]->name;
			isNull = 0;
			break;
		}
	}
	if (isNull) cout<<"NULL";
	for (int i = 0; i < n; ++i)
	{
		delete room[i];
	}
	return 0;
}