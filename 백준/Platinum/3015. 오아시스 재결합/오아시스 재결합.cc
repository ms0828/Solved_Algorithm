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
typedef long long ll;
int n, h;
ll ret;
stack<pair<ll, ll>> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        int cnt = 1;
        while (st.size() && h >= st.top().first)
        {
            ret += st.top().second;
            if (h == st.top().first)
            {
                cnt = st.top().second + 1;
            }
            else
            {
                cnt = 1;
            }
            st.pop();
        }
        if (st.size())
        {
            ret++;
        }
        st.push({h, cnt});
    }
    cout << ret << '\n';

    return 0;
}
