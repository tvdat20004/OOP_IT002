#include<bits/stdc++.h>
using namespace std;
class point{
private:
    float x,y;
public:
    void setPoint(float a,float b){
        x = a;y = b;
    };
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
};
class polygon
{
private:
    int numOfPoint;
    point *A;
public:
    polygon(int n)
    {
        numOfPoint = n;
        A = new point[n];
    }
    void setPolygon()
    {
        float hoanh,tung;
        for (int i = 0; i < numOfPoint; ++i)
        {
            cin>>hoanh>>tung;
            A[i].setPoint(hoanh,tung);
        }
    }
    float areaOfPol()
    {
        float area = 0;
        for (int i = 0; i < numOfPoint - 1; ++i)
        {
            area += A[i].getX() * A[i+1].getY() - A[i].getY() * A[i+1].getX();
        }
        area += A[numOfPoint - 1].getX() * A[0].getY() - A[0].getX() * A[numOfPoint - 1].getY();
        return 0.5 * abs(area);
    }
};
int main()
{
    int n;
    cin>>n;
    polygon H(n);
    H.setPolygon();
    cout<<H.areaOfPol();
    return 0;
}