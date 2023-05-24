#include<bits/stdc++.h>
using namespace std;


class Person
{
public:
    string name, phoneNum, howToDie,pos;
    int age,type;
    float property,yearInPrison;
    Person(string _name, int _age,string _phoneNum)
    {
        name = _name;
        age = _age;
        phoneNum = _phoneNum;
    }
    friend string maxHowToDie(vector<Person*> p);
    string getName()
    {
        return name;
    }
    bool operator == (Person* other) const
    {
        return name == other->getName();
    }
    virtual void print(float sum, vector<Person*> &p) = 0;
};
class Politician : public Person
{
public:
    // string pos;
    Politician(string _name, int _age,string _phoneNum, string _pos) : Person(_name, _age, _phoneNum)
    {
        pos = _pos;
        howToDie = "dau tim";
        type = 1;
    }
    virtual void print(float sum,vector<Person*> &p)
    {
        cout<<name<<", Chuc vu: "<<pos<<endl;
    }
};
class Businessman : public Person
{
public:
    // float property;
    Businessman(string _name, int _age,string _phoneNum, float _property) : Person(_name,_age,_phoneNum)
    {
        property = _property;
        if (property > 5) howToDie = "nang";
        else if (property > 3) howToDie = "nhe";
        else howToDie = "nhe";
        type = 2;
    }
    virtual void print(float sum,vector<Person*> &p)
    {
        cout<<"Doanh nhan: "<<sum<<" ty dong, Cach thuc chet: "<<maxHowToDie(p)<<endl;
    }
};
class Prisoner : public Person
{
public:
    string guilty;
    // float yearInPrison;
    Prisoner(string _name, int _age,string _phoneNum, string _guilty, float _yearInPrison) : Person(_name, _age, _phoneNum)
    {
        yearInPrison = _yearInPrison;
        guilty = _guilty;
        if (yearInPrison > 20) howToDie = "nang";
        else if (yearInPrison > 10) howToDie = "binh thuong";
        else howToDie = "nhe";
        type = 3;
    }
    virtual void print(float sum,vector<Person*> &p)
    {
        cout<<"Tu nhan: "<<sum<<", Cach thuc chet: "<<maxHowToDie(p)<<endl;
    }
};
bool cmp_politician(Person* p1, Person* p2)
{
    return p1->pos.length() > p2->pos.length();
}
string maxHowToDie(vector<Person*> p)
{
    string howToDie = "nhe";
    for(auto x : p)
    {
        if (x->howToDie == "nang")
        {
            howToDie = "nang";
        }
        else if (x->howToDie == "binh thuong" && howToDie == "nhe") howToDie = "binh thuong";
    }
    return howToDie;
}
int main()
{
    int n,m;
    cin>>n>>m;
    queue<Person*> person;
    map< string, bool> exist;
    vector<Person*> politician;
    vector<Person*> businessman;
    vector<Person*> prisoner;
    int type,age;
    string name,phoneNum;
    for (int i = 0; i < n; ++i)
    {
        cin>>type;
        if (type == 1) 
        {
            cin>>name>>age>>phoneNum;
            string pos;
            cin>>pos;
            if (exist[name]) continue;
            Person* _person = new Politician(name, age, phoneNum, pos);
            person.emplace(_person);
            exist[name] = 1;
        }
        else if (type == 2)
        {
            cin>>name>>age>>phoneNum;
            float property;
            cin>>property;
            if (exist[name]) continue;
            Person* _person = new Businessman(name,age,phoneNum, property);
            person.emplace(_person);
            exist[name] = 1;
        }
        else if (type == 3)
        {
            cin>>name>>age>>phoneNum;
            string guilty;
            float yearInPrison;
            cin>>guilty>>yearInPrison;
            if (exist[name]) continue;
            Person* _person = new Prisoner(name, age, phoneNum, guilty, yearInPrison);
            person.emplace(_person);
            exist[name] = 1;
        }
        if (person.size() > m) person.pop();
    }
    while (!person.empty())
    {
        if (person.front()->type == 1) politician.push_back(person.front());
        else if (person.front()->type == 2) businessman.push_back(person.front());
        else if (person.front()->type == 3) prisoner.push_back(person.front());
        person.pop();
    }
    if (politician.empty() && businessman.empty() && prisoner.empty())
    {
        cout<<"Deathnote trong";
        return 0;
    }
    if (!politician.empty()) 
    {
        sort(politician.begin(), politician.end(), cmp_politician);
        politician[0]->print(0, politician);
        for(auto &x : politician)
        {
            delete x;
        }
    }
    if (!businessman.empty())
    {
        float sumOfProperty = 0;
        for(auto x : businessman)
        {
            sumOfProperty += x->property;
        }
        // cout<<"Doanh nhan: "<<sumOfProperty<<", Cach thuc chet: "<<maxHowToDie(businessman)<<endl;
        businessman[0]->print(sumOfProperty,businessman);
        for(auto &x : businessman)
        {
            delete x;
        }
    }
    if (!prisoner.empty())
    {
        float sumOfYear = 0;
        for (auto x : prisoner)
        {
            sumOfYear += x->yearInPrison;
        }
        // cout<<"Tu nhan: "<<sumOfYear<<" nam chiu an, Cach thuc chet "<<maxHowToDie(prisoner)<<endl;
        prisoner[0]->print(sumOfYear,prisoner);
        for(auto &x : prisoner)
        {
            delete x;
        }
    }
    return 0;
}