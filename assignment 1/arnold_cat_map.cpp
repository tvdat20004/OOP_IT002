#include <bits/stdc++.h>
using namespace std;

void cat_map(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    vector<vector<int> > temp(n, vector<int>(n, 0)); 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int new_i = (2 * i + j) % n;
            int new_j = (i + j) % n;
            temp[new_i][new_j] = matrix[i][j];
        }
    }
    matrix = temp;
}
long long findPeriod(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    vector<vector<int> > original = matrix;
    int k = 0;
    do 
    {
        cat_map(matrix);
        k++;
    } while (matrix != original);
    return k;
}
bool if_periodIs0(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] != matrix[0][0]) return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j];
        }
    }
    if (if_periodIs0(matrix)) 
    {
        cout<<0;
        return 0;
    }
    long long k = findPeriod(matrix);
    cout <<k;
    return 0;
}