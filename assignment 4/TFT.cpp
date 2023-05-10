#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ii pair<int,int>
struct node
{
    int star, damage, index;
    int total = 0;
    node(int _star = 0,int _damage = 0,int _index = 0)
    {
        star = _star, damage = _damage, index = _index;
    }
};
struct Carry
{
    int type,time,dame;
    Carry(int _type = 0, int _time = 0, int _dame = 0)
    {
        type = _type,time = _time,dame = _dame;
    }
    bool operator<(const  Carry &a)const
    {
        return time < a.time;
    }
};
vector<Carry>ans;
class Tuong
{
protected:
    int damage;
    int star;
    int num_change;
    deque<node> block;
    vector<int> totalNum;
public:
    void start()
    {
        num_change = 1;
        star = 3;
        totalNum.resize(star + 10);
    }
    void inPut()
    {
        cin>>damage;
    }
    void update(int time)
    {
        block.push_front({0,damage,time});
        totalNum[0] += 1;
        for(int i = 0; i <= star - 2; i++)
        {
            if (!totalNum[i]) continue;
            if (totalNum[i] % 3 == 0)
            {
                int totalDame = 0;
                while (!block.empty())
                {
                    if (block.front().star != i) break;
                    totalDame += block.front().damage;
                    block.pop_front();
                }
                totalNum[i + 1] += 1;
                totalNum[i] = 0;
                totalDame *= (i + 2);
                block.push_front({i + 1, totalDame, time});
            }
        }
    }
    void changeDamage()
    {
        for(node &need : block)
        	need.damage += 10;
    }
    void outPut()
    {
        for(node need : block)
        {
            cout<<need.total<<endl;
        }
    }
    virtual void NoiTai() = 0;
};
class Zed : public Tuong
{
public:
    void NoiTai()
    {
        for(node &need : block)
        {
            need.total += need.damage;
            if (!num_change) need.total += 2 * need.damage;
            num_change += 1;
            num_change %= 3;
        }
    }
    void Add()
    {
        for(node need : block)
        	ans.push_back({2, need.index, need.total});
    }
};
class Shaco : public Tuong
{
public:
    void NoiTai()
    {
        for(node &need : block)
        	need.total += need.damage * 2;
    }
    void Add()
    {
        for(node need : block)
        	ans.push_back({1, need.index, need.total});
    }
};
void calc()
{
    int n,m;
    cin>>n>>m;
    Zed Z;
    Shaco S;
    Z.start();
    S.start();
    int cnt_x = 0;
    int cnt_y = 0;
    for(int i = 1; i <= n; i++)
    {
        int type;
        cin>>type;
        if (type == 1)
        {
            cnt_x++;
            S.inPut();
            S.update(i);
        }
        else
        {
            cnt_y++;
            Z.inPut();
            Z.update(i);
        }
    }
    if(cnt_x && cnt_y)
    {
        Z.changeDamage();
        S.changeDamage();
    }
    for (int i = 1; i <= m; i++)
    {
        Z.NoiTai();
        S.NoiTai();
    }
    Z.Add();
    S.Add();
    sort(ans.begin(),ans.end());
    for(Carry need : ans)
    {
        if (need.type == 1) cout<<"Shaco"<<" ";
        else cout<<"Zed"<<" ";
        cout<<"-"<<" "<<need.dame<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    calc();
}
