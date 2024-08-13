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

int t, cnt;
int a[42];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++)
    {
        cin >> t;
        int r = t % 42;
        a[r] = 1;
    }
    
    for (int i = 0; i < 42; i++)
    {
        if (a[i] == 1)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
