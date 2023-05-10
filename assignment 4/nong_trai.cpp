#include<bits/stdc++.h>
using namespace std;
class animals
{
public:
	int adult,sum;
	int count[4] = {};
	animals(int inp)
	{
		adult = inp;
		sum = 0;
	}
	//virtual int calMilk() = 0;
	virtual void next_generation()
	{
		// tinh so con truong thanh
		adult += count[3];
		count[3] = count[2];
		count[2] = count[1];
		count[1] = count[0];
		count[0] = adult / 2;
		sum += adult;
	}
};	
class rabbit : public animals
{
public:
	rabbit(int inp) : animals(inp){}
	virtual void next_generation()
	{
		adult += count[1];
		count[1] = count[0];
		count[0] = adult / 2;
		sum += adult / 2;
	}
	// virtual void print()
	// {
	// 	cout<<"Tho: "<<adult + count[0] + count[1]<<","<<0;
	// }
};

int main()
{
	int numCow, numSheep, numGoat, numRabbit;
	cin>>numCow>>numSheep>>numGoat>>numRabbit;
	animals cow(numCow);
	animals sheep(numSheep);
	animals goat(numGoat);
	rabbit _rabbit(numRabbit);
	int n;
	cin>>n;
	while(n--)
	{
		cow.next_generation();
		sheep.next_generation();
		goat.next_generation();
		_rabbit.next_generation();
	}
	cout<<"Bo: "<<cow.adult + cow.count[0] + cow.count[1] + cow.count[2] + cow.count[3]<<','<<cow.sum * 10<<"\n";
	cout<<"Cuu: "<<sheep.adult + sheep.count[0] + sheep.count[1] + sheep.count[2] + sheep.count[3]<<','<<sheep.sum * 5<<"\n";
	cout<<"De: "<<goat.adult + goat.count[0] + goat.count[1] + goat.count[2] + goat.count[3]<<','<<goat.sum * 8<<"\n";
	cout<<"Tho: "<<_rabbit.adult + _rabbit.count[0] + _rabbit.count[1]<<","<<0;
	return 0;
}