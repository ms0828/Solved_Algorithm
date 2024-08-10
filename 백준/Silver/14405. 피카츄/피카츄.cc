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
bool isA;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    isA = true;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'p' && s[i + 1] == 'i')
        {
            i++;
        }
        else if (s[i] == 'k' && s[i + 1] == 'a')
        {
            i++;
        }
        else if (s[i] == 'c' && s[i+1] == 'h' && s[i+2] == 'u')
        {
            i += 2;
        }
        else
        {
            isA = false;
            break;
        }
    }
    if (isA)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
