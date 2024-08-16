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
string d[10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        for (int j = 0; j < 10; j++)
        {
            string ds = d[j];
            if (ds.find(ch) != string::npos)
            {
                ret = ret + (j + 1);
            }
        }
    }
    cout << ret << '\n';
    
    return 0;
}
