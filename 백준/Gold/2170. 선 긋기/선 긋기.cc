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

pair<int, int> L[1000004];
int n, from, to, l, r, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> from >> to;
        L[i] = pair<int, int>(from, to);
    }
    sort(L, L + n);
    l = L[0].first;
    r = L[0].second;
    for (int i = 1; i < n; i++)
    {
        if (r < L[i].first)
        {
            ret += (r - l);
            l = L[i].first;
            r = L[i].second;
        }
        else if (L[i].first <= r && L[i].second >= r)
        {
            r = L[i].second;
        }
    }
    
    ret += r - l;
    cout << ret << '\n';
    return 0;
}
