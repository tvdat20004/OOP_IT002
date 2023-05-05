#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
bool check_year(int year)
{
    if (year % 100 == 0) return year % 400 == 0;
    return year % 4 == 0;
}
bool check_digit(char c)
{
    return (c >= '0' && c <= '9');
}

class Student
{
private:
    string name;
    int day,month,year;
    float dtb;
    bool check_all = true;
    bool check_tp = true;
    bool check_tuoi = true;
    bool ok = true;
    bool check_dtb = true;
    vector<float> diem;
public:
    bool check_day(string s)
    {
        if (s.empty()) return false;
        int type = 0;
        for (int i = 0;i <= s.size() - 1;i++)
        {
            int index = i;
            if (!check_digit(s[i])) continue;
            int total = s[index] - '0';
            while (check_digit(s[index + 1]) && index + 1 <= s.size() - 1)
            {
                index++;
                total = total * 10 + s[index] - '0';
            }
            if (!type) day = total;
            if (type == 1) month = total;
            if (type == 2) year = total;
            type++;
            i = index;

        }
        if (month <= 0 || month > 12) return false;
        if (check_year(year)) c[1]++;
        if (day > c[month-1]) return false;
        return true;
    }
    void get_name(string s)
    {
        name = s;
    }
    bool check_num(float value)
    {
        if (value < 0 || value > 10) return false;
        return true;
    }
    void set_up(vector<float> q)
    {
        diem = q;
    }
    void calc()
    {
        for(int i = 0;i <= 5;i += 2)
        {
            float value_x = diem[i] * 30 / 100;
            float value_y = diem[i+1] * 70 / 100;
            if (value_x + value_y < 7) check_all = false;
            if (min(diem[i],diem[i + 1]) < 5) check_tp = false;
            dtb += value_x + value_y;
        }
        dtb /= (double)3;
        if (dtb <= 8) check_dtb = false;
        int res = 2023 - year - 1;
        if (day == 1 && month == 1) res++;
        if (res < 17) check_tuoi = false;
        if (!check_all || !check_tp || !check_tuoi || !check_dtb) ok = false;
        dtb = dtb * 100;
        dtb = round(dtb);
        dtb /= 100;
    }
    string get_name()
    {
        return name;
    }
    bool check_ok()
    {
        return ok;
    }
    float get_dtb()
    {
        return dtb;
    }
    void output()
    {
        cout<<day<<" "<<month<<" "<<year<<" "<<name<<endl;
    }
};
class info
{
public:
    info (float _dtb = 0,int _index = 0)
    {
        dtb = _dtb,index = _index;
    }
    bool operator < (const info &a)const
    {
        return (dtb == a.dtb && index < a.index) || dtb > a.dtb;
    }
    float dtb;
    int index;
};
int main()
{
    int n,k;
    cin>>n>>k;
    vector<Student> p(n+1);
    for (int i = 1;i <= n; i++)
    {
        string name;
        getline(cin,name);
        getline(cin,name);
        p[i].get_name(name);
        string day;
        while (getline(cin,day))
        {
            if (p[i].check_day(day)) break;
        }
        while (true)
        {
            vector<float> q;
            for(int i = 0;i <= 5; i++)
            {
                float value;
                cin>>value;
                q.push_back(value);
            }
            bool ok = true;
            for (float node : q)
                if (!p[i].check_num(node)) ok = false;
            if (!ok) continue;
            p[i].set_up(q);
            break;
       }
       //p[i].output();
    }
    vector<info>block;
    for (int i = 1;i <= n; i++) p[i].calc();
    for(int i = 1;i <= n;i++)
    {
        if(p[i].check_ok()) block.push_back({p[i].get_dtb(),i});
    }
    sort(block.begin(),block.end());
    for (int i = 1;i <= k;i++)
    {
        if (i > block.size()) break;
        int index = block[i - 1].index;
        cout<<"Ho ten:"<<" "<<p[index].get_name()<<" "<<"-"<<" "<<"Diem trung binh:"<<" "<<p[index].get_dtb()<<endl;
    }
}