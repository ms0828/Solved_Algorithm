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

int n, cnt, sum[2], num[2], ret = INT_MAX;
int v[11];
int visited[11];
int lc[11];
int adj[11][11];
int temp[2];
void dfs(int team, int vi)
{
    temp[team]++;
    visited[vi] = 1;
    sum[team] += v[vi];
    for (int i = 1; i <= n; i++)
    {
        if (lc[i] == team && adj[vi][i] && visited[i] == 0)
        {
            dfs(team, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            int vi;
            cin >> vi;
            adj[i][vi] = 1;
            adj[vi][i] = 1;
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++)
    {
        fill(lc, lc + 11, 0);
        fill(visited, visited + 11, 0);
        fill(sum, sum + 2, 0);
        fill(num, num + 2, 0);
        fill(temp, temp + 2, 0);

        int idx1 = -1; int idx0 = -1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                lc[j + 1] = 1;
                num[1]++;
                idx1 = j + 1;
            }
            else
            {
                num[0]++;
                idx0 = j + 1;
            }
        }

        dfs(1, idx1);
        dfs(0, idx0);

        if (num[0] == temp[0] && num[1] == temp[1])
            ret = min(ret, abs(sum[1] - sum[0]));
        
    }

    if (ret != INT_MAX)
        cout << ret << '\n';
    else
        cout << "-1\n";

    return 0;
}