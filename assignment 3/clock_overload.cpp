#include<bits/stdc++.h>
#define ll long long
using namespace std;
class my_clock
{
public:
    ll hour,minute,second;
    my_clock(ll h = 0, ll m = 0, ll s = 0)
    {
        hour = abs(h) % 24;
        minute = abs(m) % 60;
        second = abs(s) % 60;
    }
    my_clock standardize(ll s) const
    {
        my_clock ans;
        ans.hour = s / 3600;
        s %= 3600;
        ans.minute = s / 60;
        s %= 60;
        ans.second = s;
        return ans; 
    }
    my_clock operator + (ll s) const
    {
        s += hour * 3600 + minute * 60 + second;
        my_clock ans = this->standardize(s);
        return ans;
    }
    my_clock operator - (ll s) const
    {
        return *this + (-s);
    }
};

int main()
{
    ll h,m,s;
    cin>>h>>m>>s;
    my_clock t(h,m,s);
    int n;
    cin>>n;
    while (n--)
    {
        string Operator;
        cin>>Operator;
        if (Operator == "++") t = t + 1;
        else if (Operator == "--") t = t - 1;
        else if (Operator == "-")
        {
            ll x;
            cin>>x;
            t = t - x;
        }
        else if (Operator == "+")
        {
            ll x;
            cin>>x;
            t = t + x;
        }
    }
    cout<<t.hour<<' '<<t.minute<<' '<<t.second;
    return 0;
}