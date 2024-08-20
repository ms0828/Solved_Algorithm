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
string s, b, ret, temp;
stack<char> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    cin >> b;

    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);

        if (st.size() >= b.size() && st.top() == b[b.size() - 1])
        {
            temp = "";
            for (char c : b)
            {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp != b)
            {
                for (char c : temp)
                {
                    st.push(c);
                }
            }
        }
    }

    if(st.empty())
        cout << "FRULA\n";
    else
    {
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }
    return 0;
}
