#include <iostream>
#include<string>
#include<vector>
#include<stack>
#include<climits>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
#include<unordered_set>
#include<sstream>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;

int n, ret = INT_MIN;

struct Board
{
    int a[21][21];
    
    void rotate()
    {
        int temp[21][21];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[i][j] = a[n - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }

    void move()
    {
        int visited[21][21] = { 0 };
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (visited[i][j] == 1)
                    continue;
                if (a[i][j] != 0 && a[i][j] == a[i + 1][j])
                {
                    a[i][j] *= 2;
                    visited[i][j] = 1;
                    a[i + 1][j] = 0;
                }
                else if (a[i][j] == 0 && a[i + 1][j] != 0)
                {
                    a[i][j] = a[i + 1][j];
                    a[i + 1][j] = 0;
                }
            }
        }
    }
    void _move() {
        int temp[21][21];
        for (int i = 0; i < n; i++) {
            int c = -1, d = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) continue;
                if (d && a[i][j] == temp[i][c]) temp[i][c] *= 2, d = 0;
                else temp[i][++c] = a[i][j], d = 1;
            }
            for (c++; c < n; c++) temp[i][c] = 0;
        }
        memcpy(a, temp, sizeof(a));
    }

    void getMax() {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                ret = max(ret, a[i][j]);
            }
        }
    }
};

void go(Board b, int cnt)
{
    if (cnt == 5)
    {
        b.getMax();
        return;
    }
    for (int i = 0; i < 4; i++) {
        Board d = b;
        d._move();
        go(d, cnt + 1);
        b.rotate();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;

    Board b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b.a[i][j];
        }
    }

    go(b, 0);
    cout << ret << '\n';

}
