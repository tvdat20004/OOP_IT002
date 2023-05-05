#include <bits/stdc++.h>
using namespace std;
#define ll long long
int lx[4] = {1,-1,0,0};
int ly[4] = {0,0,-1,1};
struct DSU
{
    vector<int> trace,sz;
    int n;
    DSU(int _n=0)
    {
        n = _n;
        trace.resize(n + 7);
        sz.resize(n + 7);
        iota(trace.begin(),trace.end(),0);
        for(int i = 1;i <= n; i++) sz[i] = 1;
    }
    int get(int x)
    {
        return trace[x] == x ? trace[x] : (trace[x] = get(trace[x]));
    }
    void connect(int x,int y)
    {
        int u = get(x);
        int v = get(y);
        if (u == v) return ;
        if (u > v) swap(u,v);
        trace[v] = u;
        sz[u] += sz[v];
    }
};
struct node
{
    int x,y,w,h;
    node(int _x = 0, int _y = 0, int _w = 0, int _h = 0)
    {
        x = _x, y = _y, w = _w, h = _h;
    }
    bool operator<(const node &a)const
    {
        return(x == a.x && y < a.y) || x < a.x;
    }
};
int n,m;
bool check_on(int x,int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<vector<int> >a(n + 1, vector<int>(m + 1));
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= m; j++) cin>>a[i][j];
    }
    vector<int> h(m + 1);
    DSU s(n * m);
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= m; j++)
        {
            if(!a[i][j]) continue;
            for(int type = 0; type <= 3;type++)
            {
                int u = i + lx[type];
                int v = j + ly[type];
                if (!check_on(u,v)) continue;
                if (!a[u][v]) continue;
                int value_x = (i - 1)*m + j;
                int value_y = (u - 1)*m + v;
                s.connect(value_x,value_y);
            }
        }
    }
    vector<node> hcn;
    for(int i = n;i >= 1; i--)
    {
        for(int j = 1;j <= m; j++)
        {
            if(!a[i][j]) h[j] = 0;
            else h[j] = h[j] + 1;
        }
        vector<int> q;
        vector<int> value_x(m + 1);
        vector<int>value_y(m + 1);
        for(int j = 1;j <= m; j++)
        {
            while (!q.empty() && h[q.back()]) q.pop_back();
            if (q.empty()) value_x[j] = 1;
            else value_x[j] = q.back() + 1;
            q.push_back(j);
        }
        q.clear();
        for(int j = m;j >= 1; j--)
        {
            while(!q.empty() && h[q.back()]) q.pop_back();
            if(q.empty()) value_y[j] = m;
            else value_y[j] = q.back() - 1;
            q.push_back(j);
        }
        for(int j = 1;j <= m;j++)
        {
            int index = (i - 1)*m + j;
            if (s.get(index) != index) continue;
            bool ok = true;
            for (int node = value_x[j];node <= value_y[j];node++)
                if (h[node] != h[i]) ok=false;
            int num_x = h[j];
            int num_y = value_y[j] - value_x[j] + 1;
            int num = s.sz[index];
            if (num_x * num_y != num) continue;
            if (min(num_x,num_y) < 2) continue;
            hcn.push_back({j - 1,i - 1,value_y[j] - value_x[j] + 1,h[j]});
        }
    }
    sort(hcn.begin(),hcn.end());
    for (node need : hcn)
        cout<<"["<<need.x<<","<<need.y<<","<<need.w<<","<<need.h<<"]"<<endl;
}