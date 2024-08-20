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
typedef long long ll;
int n;
long long ret;
vector<pair<ll, ll>> p;
int t1, t2;
priority_queue <ll, vector<ll>, greater<ll>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        p.push_back({ t1,t2 });
    }
    sort(p.begin(), p.end());

    int day = 1;
    for (int i = 0; i < p.size();)
    {
        while (i < p.size() && p[i].first <= day)
        {
            pq.push(p[i].second);
            ret += p[i].second;
            if (pq.size() > day)
            {
                ret -= pq.top();
                pq.pop();
            }
            i++;
        }
        day++;
    }
    cout << ret << '\n';
    return 0;
}
