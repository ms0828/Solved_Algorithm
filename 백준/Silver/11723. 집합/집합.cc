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

struct mySet
{
    int s = 0;

    void add(int x)
    {
        s |= (1 << x - 1);
    }

    void remove(int x)
    {
        s &= ~(1 << x - 1);
    }

    void check(int x)
    {
        if (s & (1 << x - 1))
            cout << "1\n";
        else
            cout << "0\n";
    }

    void toggle(int x)
    {
        s ^= (1 << x - 1);
    }

    void all()
    {
        for (int i = 1; i <= 20; i++)
            add(i);
    }

    void empty()
    {
        for (int i = 1; i <= 20; i++)
            remove(i);
    }
};

int m, t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    mySet ms;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s.compare("add") == 0)
        {
            cin >> t;
            ms.add(t);
        }
        if (s.compare("remove") == 0)
        {
            cin >> t;
            ms.remove(t);
        }
        if (s.compare("check") == 0)
        {
            cin >> t;
            ms.check(t);
        }
        if (s.compare("toggle") == 0)
        {
            cin >> t;
            ms.toggle(t);
        }
        if (s.compare("all") == 0)
            ms.all();
        if (s.compare("empty") == 0)
            ms.empty();
    }
    

    return 0;
}