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
int n, x, ret;
int a[10001];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < x)
            v.push_back(a[i]);
    }

    for (int e : v)
    {
        cout << e << " ";
    }
    cout << '\n';
    return 0;
}
