#include <bits/stdc++.h>
using namespace std;
struct ps
{
    int ts,ms;
};
bool cmp(ps a,ps b)
{
    return ((double)a.ts / a.ms < (double)b.ts / b.ms);
}
int main() {
    int n,k;
    cin>>n>>k;
    ps phanso[n];
    for(int i = 0; i< n; i++)
    {
        do
        {
            cin>> phanso[i].ts>> phanso[i].ms;
        } while (phanso[i].ms == 0);
    }
    sort(phanso, phanso + n, cmp);
    if( k >= 1 && k <= n)
    {
        cout<<phanso[n-k].ts<<'/'<<phanso[n-k].ms<<'\n';
        cout<<phanso[k-1].ts<<'/'<<phanso[k-1].ms<<'\n';
    }
    return 0;
}
