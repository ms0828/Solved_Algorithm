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
#pragma warning(disable:4996)
using namespace std;
int r,c;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
char a[1501][1501];
int visited[1501][1501];
pair<int, int> start;
queue<pair<int, int>> waterQ, waterNQ;
queue<pair<int, int>> swanQ, swanNQ;
int day;
bool isFind = false;

void swanBfs()
{
    while (swanQ.size())
    {
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > r || nx < 0 || nx > c)
                continue;
            if (visited[ny][nx] != 0)
                continue;

            if (a[ny][nx] == 'L')
            {
                isFind = true;
                return;
            }
            else if (a[ny][nx] == '.')
            {
                visited[ny][nx] = 1;
                swanQ.push({ ny,nx });
            }
            else if (a[ny][nx] == 'X')
            {
                visited[ny][nx] = 1;
                swanNQ.push({ ny,nx });
            }
        }
    }

}

void waterBfs()
{
    while (waterQ.size())
    {
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > r || nx < 0 || nx > c)
                continue;

            if (a[ny][nx] == 'X')
            {
                a[ny][nx] = '.';
                waterNQ.push({ ny,nx });
            }
        }
    }
}

void solve()
{
    visited[start.first][start.second] = 1;
    swanQ.push({ start.first, start.second });
    
    while (!isFind)
    {
        swanBfs();
        swanQ = swanNQ;
        while (!swanNQ.empty())
            swanNQ.pop();

        if (isFind)
            break;

        waterBfs();
        waterQ = waterNQ;
        while (!waterNQ.empty())
            waterNQ.pop();
        
        day++;
    }

    cout << day << '\n';
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            if (s[j] == 'L')
            {
                start = { i,j };
                waterQ.push({ i,j });
            }
            if (s[j] == '.')
                waterQ.push({ i,j });

            a[i][j] = s[j];
        }
    }
    solve();
    return 0;
}
