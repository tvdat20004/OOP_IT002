#include <bits/stdc++.h>
using namespace std;
int day,month,year;
bool check_valid()
{
    if (month < 1 || month > 12) return 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 1 || day > 31) return 0;
    }
    else if (month != 2) 
    {
        if (day < 1 || day > 30) return 0;
    }
    else 
    {
        if (year % 4 == 0 && year % 100 != 0)
        {
            if (day < 1 || day > 29) return 0;
        }
        else if (day < 1 || day > 28) return 0;
    }
    return 1;
}
void next_day(int &day,int &month, int &year)
{
	if (month == 12 && day == 31)
	{
		year++;
		month = 1;
		day = 1;
		return;
	}
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ) && day == 31)
	{
		day = 1;
		month ++;
		return;
	}
	if (month != 2 && day == 30)
	{
		day = 1;
		month++;
		return;
	}
	else 
	{
		if (year % 4 == 0 && year % 100 != 0 && day == 29)
		{
			day = 1;
			month++;
			return;
		}
		else if (day == 28)
		{
			day = 1;
			month++;
			return;
		}
	}
	day++;
}
int main()
{
    cin >> day >> month >> year;
    if (!check_valid()) cout<<"ERROR";
    else 
    {
    	next_day(day,month,year);
    	cout<<day<<'/'<<month<<'/'<<year<<endl;
    }
    return 0;
}