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
long long n, k, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<pair<long long, long long>> zv(n);
    vector<long long> bv(k);

    for (int i = 0; i < n; i++)
        cin >> zv[i].first >> zv[i].second;
    for (int i = 0; i < k; i++)
        cin >> bv[i];

    sort(zv.begin(), zv.end());
    sort(bv.begin(), bv.end());
    priority_queue<long long> pq;

    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && zv[j].first <= bv[i])
            pq.push(zv[j++].second);
        if (pq.size())
        {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';

    return 0;
}
