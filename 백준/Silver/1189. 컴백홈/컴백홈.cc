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

int r, c, k, ret;
char a[6][6];
int visited[6][6];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void go(int y, int x, int dis)
{
    if (dis > k)
        return;

    if (y == 1 && x == c && dis == k)
    {
        ret++;
        return;
    }
  

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 1 || ny > r || nx < 1 || nx > c)
            continue;
        if (visited[ny][nx] || a[ny][nx] == 'T')
            continue;
        
        visited[ny][nx] = 1;
        go(ny, nx, dis + 1);
        visited[ny][nx] = 0;
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;

    for (int i = 1; i <= r; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= c; j++)
        {
            a[i][j] = s[j - 1];
        }
    }


    visited[r][1] = 1;
    go(r, 1, 1);

    cout << ret << '\n';
}