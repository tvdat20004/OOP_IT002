#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct ps
{
    ll ts,ms;
};
bool cmp(ps a,ps b)
{
    return ((double)a.ts / a.ms < (double)b.ts / b.ms);
}
void rutGon(ps &x)
{
    ll d = __gcd(x.ts,x.ms);
    x.ts /= d;
    x.ms /= d;
}
ps nhanPs(ps a, ps b)
{
    ps x;
    x.ts = a.ts * b.ts;
    x.ms = a.ms * b.ms;
    rutGon(x);
    return x;
}
void check(vector<int> idx, int n, int k, ps phanso[], ps x, bool &alert) 
{
    vector<int> combination(k, 0);
    for (int i = 0; i < k; i++) 
    {
        combination[i] = idx[i];
    }
    while (true)
    {
        ps tich = {1,1};
        for (int i = 0; i < k; i++) 
        {
            tich = nhanPs(tich, phanso[combination[i]]);
        }
        if (tich.ts * x.ms == x.ts * tich.ms) 
        {
            for (int i = 0; i < k; ++i)
            {
                cout<<phanso[combination[i]].ts <<' '<<phanso[combination[i]].ms<<endl;
            }
            alert = 1;
            return;
        }
        int i = k - 1;
        while (i >= 0 && combination[i] == n - k + i) 
        {
            i--;
        }
        if (i < 0) {
            break;
        }
        combination[i]++;
        for (int j = i + 1; j < k; j++) {
            combination[j] = combination[j - 1] + 1;
        }
    }
}
int main() {
    ll n;
    cin>>n;
    ps phanso[n],k;
    for(ll i = 0; i< n; i++)
    {
        cin>> phanso[i].ts>> phanso[i].ms;
    }
    cin >> k.ts >> k.ms;
    sort(phanso, phanso + n, cmp);
    vector<int> idx(n);
    for (int i = 0; i < n; ++i)
    {
        idx[i] = i;
    }
    bool alert = 0;
    for (int i = 1; i <= n; ++i)
    {
        check(idx, n, i, phanso, k, alert);
        if (alert) break;
    }
    return 0;
}