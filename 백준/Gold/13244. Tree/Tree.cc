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
int t, n, m;
int adj[1001][1001];
int visited[1001];
bool isGraph = false;

void dfs(int s, int prev)
{
    visited[s] = 1;

    for (int e = 1; e <= n; e++)
    {
        if (adj[s][e] && e != prev)
        {
            if (visited[e])
            {
                isGraph = true;
                return;
            }
            dfs(e, s);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        fill(&adj[0][0], &adj[1000][1001], 0);
        fill(&visited[0], &visited[1001], 0);
        cin >> n;
        cin >> m;
        isGraph = false;
        
        for (int j = 1; j <= m; j++)
        {
            int a, b;
            cin >> a >> b;
            if (adj[a][b] == 1 || adj[b][a] == 1)
                isGraph = true;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        dfs(1, 0);

        for (int k = 1; k <= n; k++)
        {
            if(visited[k] == 0)
            {
                isGraph = true;
                break;
            }
        }
        if (isGraph)
            cout << "graph\n";
        else
            cout << "tree\n";
    }
    return 0;
}
