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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        getline(cin, s);
        if (s == "")
            break;
        cout << s << '\n';
    }
    return 0;
}
