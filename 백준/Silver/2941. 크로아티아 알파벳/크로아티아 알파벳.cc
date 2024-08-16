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

string cr[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
string s;
int cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        bool isFind = false;
        for (int j = 0; j < 8; j++)
        {
            string cmp = cr[j];
            string cs = s.substr(i, cmp.size());
            if (cmp == cs)
            {
                cnt++;
                i += cmp.size() - 1;
                isFind = true;
                break;
            }
        }
        if (!isFind)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
