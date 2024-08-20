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
string s, b, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    cin >> b;

    for (int i = 0; i < s.size(); i++)
    {
        ret += s[i];

        if (ret.size() >= b.size() && ret.substr(ret.size() - b.size(), ret.size()) == b)
        {
            ret.erase(ret.size() - b.size(), ret.size());
        }
    }
    if (ret.size() == 0)
        cout << "FRULA\n";
    else
        cout << ret << '\n';
    return 0;
}
