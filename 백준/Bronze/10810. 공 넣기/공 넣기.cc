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
int n, m, i, j, k;
int a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int x = 0; x < m; x++)
    {
        cin >> i >> j >> k;
        for (int y = i; y <= j; y++)
        {
            a[y] = k;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}
