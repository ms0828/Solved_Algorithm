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
void go(string a, string b)
{
    int ai = a.size() - 1;
    int bi = b.size() - 1;
    bool flag = false;
    while (ai >= 0 && bi >= 0)
    {
        char temp = a[ai] + b[bi] - '0';
        if (flag)
            temp += 1;
        if (temp > '9')
        {
            flag = true;
            temp -= 10;
        }
        else
            flag = false;
        ret.insert(ret.begin(), temp);
        ai--;
        bi--;
    }
    while (ai >= 0)
    {
        char temp = a[ai];
        if (flag)
            temp += 1;
        if (temp > '9')
        {
            flag = true;
            temp -= 10;
        }
        else
            flag = false;
        ret.insert(ret.begin(), temp);
        ai--;
    }
    while (bi >= 0)
    {
        char temp = b[bi];
        if (flag)
            temp += 1;
        if (temp > '9')
        {
            flag = true;
            temp -= 10;
        }
        else
            flag = false;
        ret.insert(ret.begin(), temp);
        bi--;
    }
    if (flag)
        ret.insert(ret.begin(), '1');
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    go(a, b);
    cout << ret << '\n';

    return 0;
}
