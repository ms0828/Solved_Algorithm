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
int n, ret;
int a[4000001];
bool che[4000001];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (che[i])
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            che[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (che[i] == 0)
            v.push_back(i);
    }
    
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            if (sum >= n)
                break;
            sum += v[j];
        }
        if (sum == n)
            ret++;
    }
    cout << ret << '\n';
    return 0;
}
