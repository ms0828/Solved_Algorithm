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
string s;

void comp(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    if (l1 > l2)
    {
        cout << s1 << '\n';
        return;
    }
    else if (l1 < l2)
    {
        cout << s2 << '\n';
        return;
    }
    else
    {
        for (int i = l1 - 1; i >= 0; i--)
        {
            if (s1[i] > s2[i])
            {
                reverse(s1.begin(), s1.end());
                cout << s1 << '\n';
                return;
            }
            else if (s1[i] < s2[i])
            {
                reverse(s2.begin(), s2.end());
                cout << s2 << '\n';
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    comp(s1, s2);
    
    return 0;
}
