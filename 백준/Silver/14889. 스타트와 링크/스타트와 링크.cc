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

int n, ret = INT_MAX;
int s[21][21];
vector<int> t1, t2;
int go(vector<int> t1, vector<int> t2)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < t1.size(); i++)
    {
        for (int j = i + 1; j < t1.size(); j++)
        {
            sum1 = sum1 + s[t1[i]][t1[j]] + s[t1[j]][t1[i]];
            sum2 = sum2 + s[t2[i]][t2[j]] + s[t2[j]][t2[i]];
        }
    }

    return abs(sum1 - sum2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cnt++;
        }
        if (cnt != n / 2)
            continue;

        vector<int> t1, t2;
        for (int k = 0; k < n; k++)
        {
            if (i & (1 << k))
                t1.push_back(k + 1);
            else
                t2.push_back(k + 1);
        }
        ret = min(ret, go(t1, t2));
    }
    cout << ret << '\n';
}
