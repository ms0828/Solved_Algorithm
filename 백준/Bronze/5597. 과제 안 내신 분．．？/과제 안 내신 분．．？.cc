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

int n;
int a[31];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 28; i++)
    {
        int t;
        cin >> t;
        a[t] = 1;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (a[i] == 0)
            cout << i << '\n';
    }
    
    return 0;
}
