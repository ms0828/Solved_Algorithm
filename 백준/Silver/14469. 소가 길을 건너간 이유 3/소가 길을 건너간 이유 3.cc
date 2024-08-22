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
int n, d, g, ret;
vector<pair<int, int>> cow;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> g;
        cow.push_back({ d, d + g });
    }
    sort(cow.begin(), cow.end());

    ret += cow[0].second;
    for (int i = 1; i < n; i++)
    {
        if (cow[i].first <= cow[i - 1].second)
        {
            ret += (cow[i].second - cow[i].first);
            int waitTime = cow[i - 1].second - cow[i].first;
            cow[i].second += waitTime;
        }
        else
        {
            ret = cow[i].second;
        }
    }

    cout << ret << '\n';
    return 0;
}
