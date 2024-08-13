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
int n = INT_MIN;
float a[1001], m, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        a[i] = s;
        m = max(m, a[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] / m * 100;
        sum += a[i];
    }
    cout << sum / n << '\n';

    return 0;
}
