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
int from, to, n, ret, idx;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> from >> to;
        v.push_back({ to, from });
    }
    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;
    ret = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second < to)
            continue;
        from = v[i].second;
        to = v[i].first;
        ret++;
    }
    cout << ret << '\n';
    
    return 0;
}
