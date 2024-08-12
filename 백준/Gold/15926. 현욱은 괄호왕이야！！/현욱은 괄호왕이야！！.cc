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
string s;
int n, ret, cnt;
int d[200001];
stack<int> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> s;
    
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (st.empty())
                continue;
            d[i] = 1;
            d[st.top()] = 1;
            st.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i])
        {
            cnt++;
            ret = max(ret, cnt);
        }
        else
            cnt = 0;
    }
    cout << ret << '\n';
    return 0;
}
