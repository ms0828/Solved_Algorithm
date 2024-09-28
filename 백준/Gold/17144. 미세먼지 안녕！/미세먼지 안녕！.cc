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

int r, c, t, sc;
int m[51][51];
int addm[51][51];
int cp[2];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void spread()
{
    memset(addm, 0, sizeof(addm));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int y = i;
            int x = j;
            if (m[y][x] < 1)
                continue;
            
            int sa = m[y][x] / 5;
            int scnt = 0;
            for (int j = 0; j < 4; j++)
            {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (nx == 0 && (ny == cp[0] || ny == cp[1]))
                    continue;
                if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                    continue;
                addm[ny][nx] += sa;
                scnt++;
            }
            m[y][x] = m[y][x] - scnt * sa;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] += addm[i][j];
        }
    }
}

void clean1()
{
    int dy[4] = { -1,0,1,0 };
    int dx[4] = { 0,1,0,-1 };

    int y = cp[0] - 1;
    int x = 0;
    for (int i = 0; i < 4; )
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (i == 0 && ny < 0)
        {
            i++;
            continue;
        }
        if (i == 1 && nx > c - 1)
        {
            i++;
            continue;
        }
        if (i == 2 && ny > cp[0])
        {
            i++;
            continue;
        }
        if (i == 3 && nx < 1)
        {
            i++;
            m[cp[0]][1] = 0;
            continue;
        }
        m[y][x] = m[ny][nx];
        y = ny;
        x = nx;
    }
}

void clean2()
{
    int dy[4] = { 1,0,-1,0 };
    int dx[4] = { 0,1,0,-1 };

    int y = cp[1] + 1;
    int x = 0;
    for (int i = 0; i < 4; )
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (i == 0 && ny > r-1)
        {
            i++;
            continue;
        }
        if (i == 1 && nx > c - 1)
        {
            i++;
            continue;
        }
        if (i == 2 && ny < cp[1])
        {
            i++;
            continue;
        }
        if (i == 3 && nx < 1)
        {
            i++;
            m[cp[1]][1] = 0;
            continue;
        }
        m[y][x] = m[ny][nx];
        y = ny;
        x = nx;
    }
}
int sumDest()
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(m[i][j] > 0)
                sum += m[i][j];
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> r >> c >> t;

    int temp = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == -1)
            {
                cp[temp] = i;
                temp++;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        spread();
        clean1();
        clean2();
    }
    cout << sumDest() << '\n';
}
