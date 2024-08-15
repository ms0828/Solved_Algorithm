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
int n, ret = INT_MIN, idx;
int a[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 9; i++)
    {
        cin >> a[i];
        if (a[i] > ret)
        {
            idx = i;
            ret = a[i];
        }
    }

    cout << ret << '\n' << idx << '\n';
    return 0;
}
