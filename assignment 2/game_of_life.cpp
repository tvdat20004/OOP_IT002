#include<bits/stdc++.h>
using namespace std;
int count(int x, int y, vector<vector<int> > &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(abs(i - x) <= 1 && abs(j - y) <= 1 && (i != x || j != y))
                if (matrix[i][j] == 1) cnt++;
        }
    }
    return cnt;
}
class lifespace
{
private:
    int m,n;
    vector<vector<int> > matrix;
public:
    void input()
    {
        cin>>m>>n;
        matrix.resize(m);
        for (int i = 0; i < m; ++i)
        {
            matrix[i].resize(n);
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin>>matrix[i][j];
            }
        }
    }
    void next_life()
    {
        vector<vector<int> > newMatrix(m,vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int cnt = count(i,j,matrix);
                if ((matrix[i][j]) == 1) 
                {
                    if(cnt < 2 || cnt > 3) newMatrix[i][j] = 0;
                    else newMatrix[i][j] = 1;
                }
                else if (cnt == 3) newMatrix[i][j] = 1;
                else newMatrix[i][j] = 0;
            }
        }
        matrix = newMatrix;
    }
    void print()
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout<<matrix[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
};
int main()
{
    lifespace game_of_life;
    game_of_life.input();
    int k;
    cin >> k;
    while (k--)
    {
        game_of_life.next_life();
    }
    game_of_life.print();
}