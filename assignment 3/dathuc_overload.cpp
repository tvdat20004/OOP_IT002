#include<bits/stdc++.h>
using namespace std;
class dathuc
{
public:
    int n;
    vector<int> heso;
    dathuc(int bac = 0)
    {
        n = bac;
        heso.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            heso[i] = 0;
        }
    }
    void nhap()
    {
        for (int i = 0; i <= n; ++i)
        {
            cin>>heso[i];
        }
    }
    // void expand(int bac)
    // {
    //     heso.resize(bac);
    //     for (int i = n + 1; i <= bac; ++i)
    //     {
    //         heso[i] = 0;
    //     }
    // }
    void inDaThuc()
    {
        bool ptdau = 0;
        if (heso[0] != 0)
        {
            cout<<heso[0]<<"x^0";
            ptdau = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (heso[i] > 0) 
            {
                if (ptdau == 1) cout<<'+'<<heso[i]<<"x^"<<i;
                else 
                {
                    cout<<heso[i]<<"x^"<<i;
                    ptdau = 1;
                }
            }
            else if (heso[i] < 0) 
            {
                cout<<heso[i]<<"x^"<<i;
                ptdau = 1;
            }
        }
    }    
};
void expand(dathuc &a, int n)
{
    for (int i = a.n; i <= n; ++i)
    {
        a.heso.push_back(0);
    }
}
dathuc operator + (dathuc a, dathuc b) 
{
    int bacLon = max(b.n,a.n);
    int bacNho = min(b.n,a.n);
    dathuc ans(bacLon);
    int i = 0;
    while (i <= bacLon)
    {
        if (bacNho == a.n) expand(a,bacLon);
        else expand(b,bacNho); 
        ans.heso[i] = b.heso[i] + a.heso[i];
        i++;
    }
    return ans;
}
dathuc operator - (dathuc a, dathuc b) 
{
    int bacLon = max(b.n,a.n);
    int bacNho = min(b.n,a.n);
    dathuc ans(bacLon);
    int i = 0;
    while (i <= bacLon)
    {
        if (bacNho == a.n) expand(a,bacLon);
        else expand(b,bacNho); 
        ans.heso[i] = a.heso[i] - b.heso[i];
        i++;
    }
    return ans;
}
dathuc nhanDonthuc(dathuc a, int b, int n)//nhan da thuc a voi don thuc b.x^n
{
    dathuc ans(a.n + n);
    for (int i = a.n; i >=0; i--)
    {
        if (n != 0)
        {
            ans.heso[i + n] = a.heso[i]*b;
            ans.heso[i] = 0;
        }
        else ans.heso[i + n] = a.heso[i]*b;
    }
    return ans;
}
dathuc operator *(dathuc a,dathuc b)
{
    dathuc ans(a.n + b.n);
    for (int i = 0; i <= a.n; ++i)
    {
        ans = ans + nhanDonthuc(b,a.heso[i],i);
    }
    return ans;
}
int main()
{
    int bac_a,bac_b;
    cin>>bac_a;
    dathuc a(bac_a);
    a.nhap();
    cin>>bac_b;
    dathuc b(bac_b);
    b.nhap();
    char dau;
    cin>>dau;
    if (dau == '+') (a+b).inDaThuc();
    else if (dau == '-') (a-b).inDaThuc();
    else if (dau == '*') (a*b).inDaThuc();
    return 0;
}