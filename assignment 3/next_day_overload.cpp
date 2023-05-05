#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
class Data
{
private:
    int day,month,year;
    int res;
    vector<int> max_day;
public:
    bool check_year(int year)
    {
        if(year % 100 == 0) return year % 400 == 0;
        return year % 4 == 0;
    }
    void input()
    {
        cin>>day>>month>>year;
    }
    void change()
    {
        max_day.resize(12);
        for (size_t i = 0;i <= max_day.size() - 1;i++) max_day[i] = c[i];
        day = abs(day);
        year = abs(year);
        month = abs(month);
        if (check_year(year)) max_day[1]++;
        month = (month % 12);
        month = (month == 0 ? (int)12 : (int)month);
        if (day > max_day[month - 1]) day = 1;
    }
    void find_value()
    {
        for(int i = 1;i <= month - 1; i++) res += max_day[i - 1];
        res += day;
        //cout<<res<<endl;
    }
    void increase(int x)
    {
        res += x;
    }
    void decrease(int x)
    {
        res -= x;
    }
    bool operator < (const Data &a)const
    {
        return (year < a.year) || (year == a.year && res < a.res);
    }
    int calc(Data A,Data B)
    {
        int ans = 0;
        if (A.year == B.year) ans = B.res - A.res;
        else
        {
            for(int i = A.year + 1;i <= B.year - 1;i++)
            {
                ans += 365;
                if(check_year(i)) ans++;
            }
            ans += 365 - A.res;
            ans += B.res;
            if (check_year(A.year)) ans++;
        }
        return ans;
    }
};
int main()
{
    Data A,B,ans;
    A.input();
    A.change();
    A.find_value();
    while(true)
    {
        int type;
        cin>>type;
        if (type > 3 || type <= 0) continue;
        if (type == 1)
        {
            int value;
            cin>>value;
            A.increase(value);
        }
        if (type == 2)
        {
            int value;
            cin>>value;
            A.decrease(value);
        }
        if (type == 3)
        {
            B.input();
            B.change();
            B.find_value();
            if (A < B) cout<<ans.calc(A,B);
            else cout<<ans.calc(B,A);
            return 0;
        }
    }
}