#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14159;
void convert(double &a,double &b, double p, double theta)
{
    a = p * cos(theta);
    b = p * sin(theta);
}
double printFormated(double x)
{
    return round(x*100) / 100.0;
}
class myComplex
{
private:
    double a,b;
    double p,theta;
public:
    void input()
    {
        cin>>a>>b;
        p = sqrt(a*a + b*b);
        theta = atan2(b, a);
    }
    void sqroot_n(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (a == 0 && b == 0)
            {
                cout<<"0 0\n";
                continue;
            }
            double new_p = pow(p,(double)((double)1.0 /(double) n));
            double new_theta = (theta + 2*i*PI) / n;
            convert(a,b,new_p,new_theta);
            cout<<printFormated(a)<<' '<<printFormated(b)<<endl;
        }
    }    
};
int main()
{
    myComplex c;
    c.input();
    int n;
    cin>>n;
    c.sqroot_n(n);
    return 0;
}