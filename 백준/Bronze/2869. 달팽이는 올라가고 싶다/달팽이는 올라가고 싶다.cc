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
int a, b, v, ret, d;
bool isNight = false;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> v;

    ret = (v - b) / (a - b);
    d = (v - b) % (a - b);
    if (d)
    {
        cout << ret + 1 << '\n';
    }
    else
    {
        cout << ret << '\n';
    }
    return 0;
}
