#include<bits/stdc++.h>
using namespace std;
class myList
{
private:
    vector<double> p;
    int size;
public:
    myList();
    void push(double);
    void erase1(double);
    void eraseAll(double);
    void replace(int,double);
    void print();
    ~myList(){}
};
myList::myList()
{
    size = 0;
}
void myList::push(double x)
{
    p.push_back(x);
    size++;
}
void myList::erase1(double x)
{
    for (int i = 0; i < size; ++i)
    {
        if (p[i] == x)
        {
            p.erase(p.begin() + i);
            size--;
            break;
        }
    }
}
void myList::eraseAll(double x)
{
    int i = 0;
    while (i < size)
    {
        if(p[i] == x) 
        {
            p.erase(p.begin() + i);
            size--;
        }
        else i++;
    }
}
void myList::replace(int x,double y)
{
    p[x] = y;
}
void myList::print()
{
    if (size == 0)
    {
        cout<<"[]";
        return;
    }
    for (int i = 0; i < size; ++i)
    {
        if (i == 0) cout<<"["<<p[i];
        else if (i == size - 1) cout<<','<<p[i]<<']';
        else cout<<','<<p[i];
    }
}
int main()
{
    int n;
    myList arr;
    while (true)
    {
        cin>>n;
        if(n == 0) 
        {
            double x;
            cin>>x;
            arr.push(x);
        }
        else if (n == 1) 
        {
            double x;
            cin>>x;
            arr.erase1(x);
        }
        else if (n == 2)
        {
            double x;
            cin>>x;
            arr.eraseAll(x);
        }
        else if (n == 3)
        {
            int index;
            double value;
            cin>>index>>value;
            arr.replace(index, value);
        }
        else if (n == -1)
        {
            arr.print();
            break;
        }
    }
    return 0;
}