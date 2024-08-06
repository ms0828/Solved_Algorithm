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

int m, n, ret1, ret2 = INT_MIN, ret3 = INT_MIN;
int a[51][51];
int visited[51][51];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
map<int, int> area;
map<int, vector<pair<int,int>>> adj;

void bfs(int num,int _y, int _x)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ _y,_x });
    visited[_y][_x] = num;

    while (q.size())
    {
        cnt++;
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > m - 1 || nx < 0 || nx > n - 1)
                continue;
            if (a[y][x] & (1 << i))
            {
                adj[num].push_back({ ny,nx });
                continue;
            }
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = num;
            q.push({ ny,nx });
        }
    }
    area[num] = cnt;
    ret2 = max(ret2, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j])
                continue;
            ret1++;
            bfs(ret1, i, j);
        }
    }
    for (auto it : adj)
    {
        for (auto it2 : it.second)
        {
            if (it.first == visited[it2.first][it2.second])
                continue;
            int roomNum = visited[it2.first][it2.second];
            ret3 = max(ret3, area[it.first] + area[roomNum]);
        }
    }
    cout << ret1 << '\n' << ret2 << '\n' << ret3 << '\n';

    return 0;
}