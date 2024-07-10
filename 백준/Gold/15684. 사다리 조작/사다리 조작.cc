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

int n, m, h, ret = INT_MAX;
int board[31][11];  // 0과 1, 1은 가로선을 나타냄 [i]가 1이면 [i+1]을 향하는 가로선
int visited[31][11];

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        for (int j = 1; j <= h; j++)
        {
            if (board[j][x - 1])
                x--;
            else if (board[j][x])
                x++;
        }
        if (x != i)
            return false;
    }
    return true;
}

void solve(int y, int x ,int cnt)
{
    if (cnt > 3 || cnt >= ret)
        return;
     
    if (check())
    {
        ret = min(ret, cnt);
        return;
    }

    for (int i = y; i <= h; i++)
    {
        for (int j = x; j <= n; j++)
        {
            if (board[i][j] || board[i][j - 1] || board[i][j + 1])
                continue;
            board[i][j] = 1;
            solve(i, j + 1, cnt + 1);
            board[i][j] = 0;
        }
        x = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    
    solve(1, 1, 0);
    
    if (ret == INT_MAX)
        cout << -1 << '\n';
    else
        cout << ret << '\n';
    return 0;
}