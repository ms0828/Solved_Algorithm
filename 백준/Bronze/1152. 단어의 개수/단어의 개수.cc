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
int cnt;
vector<string> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);

    long long pos = 0;
    string token = "";
    string delimiter = " ";
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        if (token != "")
            v.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    if(s != "")
        v.push_back(s);
    cout << v.size() << '\n';
    return 0;
}
