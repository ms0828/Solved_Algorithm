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

int x, cnt = 1;
void go(int sum, int a)
{
    if (sum + a == x)
        return;

    int l = a / 2;
    int r = l;
    if (sum + l >= x)
        go(sum, l);
    else
    {
        cnt++;
        go(sum + l, r);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;
    go(0, 64);
    cout << cnt << '\n';
    return 0;
}