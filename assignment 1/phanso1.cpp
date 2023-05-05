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
    int n;
    cin>>n;
    ps phanso[n];
    for(int i = 0; i< n; i++)
    {
        do
        {
            cin>> phanso[i].ts>> phanso[i].ms;
        } while (phanso[i].ms == 0);
    }
    sort(phanso, phanso + n, cmp);
    cout<<phanso[0].ts<<'/'<<phanso[0].ms<<'\n';
    cout<<phanso[n-1].ts<<'/'<<phanso[n-1].ms<<'\n';
    return 0;
}