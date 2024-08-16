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

int cnt, n;
string s[100];
int a[100][26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    for (int i = 0; i < n; i++)
    {
        string w = s[i];
        bool flag = true;
        for (int j = 0; j < w.size(); j++)
        {
            if (a[i][w[j] - 'a'])
            {
                flag = false;
                break;
            }
            a[i][w[j] - 'a'] = 1;
            while (w[j] == w[j + 1])
                j++;
        }
        if (flag)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
