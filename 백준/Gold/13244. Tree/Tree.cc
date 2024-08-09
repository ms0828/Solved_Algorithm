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
int t, n, m, cnt;
vector<int> adj[1001];
int visited[1001];

void dfs(int here)
{
    visited[here] = 1;
    for (int there : adj[here])
    {
        if (visited[there] == 0)
            dfs(there);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int i = 1; i <= 1000; i++)
            adj[i].clear();
        fill(&visited[0], &visited[1001], 0);
        cnt = 0;
        cin >> n;
        cin >> m;

        for (int j = 1; j <= m; j++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int k = 1; k <= n; k++)
        {
            if (visited[k] == 0)
            {
                dfs(k);
                cnt++;
            }
        }
        if (m == n - 1 && cnt == 1)
            cout << "tree\n";
        else
            cout << "graph\n";
    }
    return 0;
}
