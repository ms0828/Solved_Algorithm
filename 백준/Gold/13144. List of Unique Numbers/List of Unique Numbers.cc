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
ll s, e, cnt[100001], n, a[100001], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (e < n)
    {
        if (cnt[a[e]] == 0)
        {
            cnt[a[e]] = 1;
            e++;
        }
        else
        {
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (e - s) * (e - s + 1) / 2;
    cout << ret << '\n';
    
    return 0;
}
