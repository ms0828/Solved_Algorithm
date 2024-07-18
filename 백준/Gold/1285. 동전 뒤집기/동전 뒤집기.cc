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
int n, a[44], ret = INT_MAX;

void go(int here)
{
    if (here == n + 1)
    {
        int sum = 0;
        for (int i = 1; i <= (1 << (n - 1)); i *= 2)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] & i)
                    cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    go(here + 1);
    a[here] = ~a[here];
    go(here + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int value = (1 << s.size() - 1);
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'T')
                a[i] |= value;
            value /= 2;
        }
    }
    go(1);
    cout << ret << '\n';
    
    return 0;
}