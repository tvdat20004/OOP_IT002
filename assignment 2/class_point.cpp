#include<bits/stdc++.h>
using namespace std;

class point
{
private:
    float x,y;
public:
    point()
    {
        x = 0;
        y = 0;
    };
    void Set()
    {
        float temp_x,temp_y;
        cin>>temp_x>>temp_y;
        x = temp_x;
        y = temp_y;
    }   
    void nhandoi()
    {
        x = x * 2;
        y = y * 2;
    }
    void doiVeGoc()
    {
        x = 0;
        y = 0;
    }
    void tinhTien(int k, int d)
    {
        if (k == 0) x += d;
        else y += d;
    }
    void request()
    {
        int a;
        cin>>a;
        if (a == 1) nhandoi();
        else if (a == 2) doiVeGoc();
        else if (a == 3) 
        {
            int k,d;
            cin>>k>>d;
            tinhTien(k,d);
        }
    }
    void print()
    {
        cout<<'('<<x<<","<<y<<')'<<endl;
    }
    ~point() {}
};

int main()
{
    point A;
    A.Set();
    int n;
    cin>>n;
    while (n--)
    {
        A.request();
    }
    A.print();
    return 0;
}