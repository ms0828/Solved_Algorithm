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

string a, b;
string ret;
string add(string a, string b)
{
    int sum = 0;
    string ret;
    
    while (a.size() || b.size() || sum)
    {
        if (a.size())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    
    cout << add(a,b) << '\n';

    return 0;
}
