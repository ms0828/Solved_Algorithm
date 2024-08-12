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
int a, b, c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    
    if (a == b && b == c)
        cout << 10000 + a * 1000 << '\n';
    else if (a == b)
        cout << 1000 + a * 100 << '\n';
    else if (a == c)
        cout << 1000 + a * 100 << '\n';
    else if (b == c)
        cout << 1000 + b * 100 << '\n';
    else
    {
        int t = (b > c) ? b : c;
        t = (t > a) ? t : a;
        cout << t * 100 << '\n';
    }

    return 0;
}
