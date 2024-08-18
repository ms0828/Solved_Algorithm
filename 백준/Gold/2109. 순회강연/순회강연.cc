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
int n, d, p, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> d;
        v.push_back({ d,p });
    }
    sort(v.begin(), v.end());

    int day = 1;
    int j = 0;
    while (j < n)
    {
        while (j < n && day >= v[j].first)
        {
            pq.push(v[j].second);
            ret += v[j].second;
            j++;
        }
        while (pq.size() > day)
        {
            ret -= pq.top();
            pq.pop();
        }
        day++;
    }
    cout << ret << '\n';
    return 0;
}
