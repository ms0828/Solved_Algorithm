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

struct food
{
    int p;
    int f;
    int s;
    int v;
    int c;
};
food f[16];
int visited[16];
vector<int> retV;
int n, mp, mf, ms, mv, ret = INT_MAX;

void solve(int index, int ps, int fs, int ss, int vs, int cs)
{
    vector<int> find;
    if (cs >= ret)
        return;

    if (ps >= mp && fs >= mf && ss >= ms && vs >= mv)
    {
        ret = cs;
        
        for (int i = 1; i <= n; i++)
            if (visited[i])
                find.push_back(i);
        retV = find;
        return;
    }

    for (int i = index; i <= n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = 1;
        solve(i+1 , ps + f[i].p, fs + f[i].f, ss + f[i].s, vs + f[i].v, cs + f[i].c);
        visited[i] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].p >> f[i].f >> f[i].s >> f[i].v >> f[i].c;
    }

    solve(1,0,0,0,0,0);

    if (retV.empty())
    {
        cout << "-1\n";
        return 0;
    }

    cout << ret << '\n';
    for (int i : retV)
    {
        cout << i << " ";
    }
    return 0;
}