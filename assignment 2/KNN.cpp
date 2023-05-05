#include<bits/stdc++.h>
using namespace std;

class Point 
{
public:
    double x, y;
    int label;
    Point(double x, double y, int label) : x(x), y(y), label(label) {}
};
class KNN 
{
private:
    vector<Point> data;
    int k;
    double euclidean_distance(const Point& p1, const Point& p2)
    {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
public:
    KNN(int k) : k(k) {}
    void add_point(double x, double y, int label) 
    {
        if (label < 1 || label > 9) return;
        data.emplace_back(x, y, label);
    }
    int predict(double x, double y) 
    {
        vector<pair<double, int>> distances;
        for (const auto& point : data) 
        {
            double distance = euclidean_distance(point, Point(x, y, 0));
            distances.emplace_back(distance, point.label);
        }
        sort(distances.begin(), distances.end());
        vector<int> labels_count(10, 0);
        for (int i = 0; i < k; ++i) 
        {
            labels_count[distances[i].second]++;
        }
        int max_count = 0;
        int predicted_label = -1;
        for (int i = 1; i < 10; ++i) 
        {
            if (labels_count[i] > max_count) 
            {
                max_count = labels_count[i];
                predicted_label = i;
            }
        }
        return predicted_label;
    }
    vector<Point> getData()
    {
        return data;
    }
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    KNN knn(k);
    for (int i = 0; i < n; ++i) 
    {
        double x, y;
        int label;
        cin >> x >> y >> label;
        knn.add_point(x, y, label);
    }
    for (int i = 0; i < m; ++i) 
    {
        double x, y;
        int a;
        cin >> x >> y >> a;
        for (auto& point : knn.getData()) 
        {
            if ((a == 0 && point.y < y) || (a == 1 && point.x < x) || (a == 3 && point.y > y) || (a == 4 && point.x > x)) 
            {
                if (a == 0) point.y += 2;
                else if (a == 1) point.x += 2;
                else if (a == 3) point.y -= 2;
                else if (a == 4) point.x -= 2;
            }
        }
        int predicted_label = knn.predict(x, y);
        cout << predicted_label << endl;
    }
    return 0;
}