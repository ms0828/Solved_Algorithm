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
#include<string>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;
int n, l, ret;
int h[101][101];
int g[101][101];

bool goRow(int r)
{
    fill(g[r], g[r] + n, 0);

    int prev = h[r][0];
    for (int i = 1; i < n; i++)
    {
        if (prev == h[r][i])
            continue;
        if (abs(prev - h[r][i]) > 1)
            return false;

        if (prev > h[r][i]) //ex : 3 2 2 1 1
        {
            for (int j = 0; j < l; j++)
            {
                if (i + j > n - 1)
                    return false;
                if (h[r][i + j] != h[r][i])
                    return false;
                g[r][i + j] = 1;
            }
        }
        else if(prev < h[r][i]) // ex : 2 2 3 3 3
        {
            for (int j = 0; j < l; j++)
            {
                if (i - j - 1 < 0)
                    return false;
                if (h[r][i - j - 1] != prev)
                    return false;
                if (g[r][i - j - 1])
                    return false;
                g[r][i - j - 1] = 1;
            }
        }
        prev = h[r][i];
    }

    return true;
}

bool goCol(int c)
{
    for (int i = 0; i < n; i++)
        g[i][c] = 0;

    int prev = h[0][c];
    for (int i = 1; i < n; i++)
    {
        if (prev == h[i][c])
            continue;
        if (abs(prev - h[i][c]) > 1)
            return false;

        if (prev > h[i][c]) //ex : 3 2 2 1 1
        {
            for (int j = 0; j < l; j++)
            {
                if (i + j > n - 1)
                    return false;
                if (h[i+j][c] != h[i][c])
                    return false;
                g[i+j][c] = 1;
            }
        }
        else if (prev < h[i][c]) // ex : 2 2 3 3 3
        {
            for (int j = 0; j < l; j++)
            {
                if (i - j - 1 < 0)
                    return false;
                if (h[i - j - 1][c] != prev)
                    return false;
                if (g[i - j - 1][c])
                    return false;
                g[i - j - 1][c] = 1;
            }
        }
        prev = h[i][c];
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> h[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        if (goRow(i))
            ret++;
        if (goCol(i))
            ret++;
    }

    cout << ret << '\n';


    return 0;
}