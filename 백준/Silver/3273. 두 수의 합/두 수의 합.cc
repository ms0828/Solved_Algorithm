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
int n, x, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> x;

    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (v[l] + v[r] == x)
        {
            l++;
            ret++;
        }
        else if (v[l] + v[r] > x)
            r--;
        else if (v[l] + v[r] < x)
            l++;
    }
        
    cout << ret << '\n';

    return 0;
}
