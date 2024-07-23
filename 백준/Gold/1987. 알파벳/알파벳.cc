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
#pragma warning(disable:4996)
using namespace std;
int r,c;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
char a[21][21];
int visited[21][21];
int ch[26];
int cnt = 1;
int ret = 1;


void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;
        if (visited[ny][nx] || ch[a[ny][nx]-'A'])
            continue;

        visited[ny][nx] = visited[y][x] + 1;
        ch[a[ny][nx] - 'A'] = 1;
        ret = max(ret, visited[ny][nx]);
        dfs(ny, nx);
        visited[ny][nx] = 0;
        ch[a[ny][nx] - 'A'] = 0;
    }
    
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
            a[i][j] = s[j];
        }
    }

    visited[0][0] = 1;
    ch[a[0][0] - 'A'] = 1;
    dfs(0,0);
    cout << ret << '\n';

    return 0;
}
