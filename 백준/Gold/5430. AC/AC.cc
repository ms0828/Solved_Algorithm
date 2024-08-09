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
int t, n;
deque<int> d;
string p, order;
bool flag, errorTag;
void print()
{
    cout << "[";
    if (flag)
    {
        for (int i = d.size() - 1; i >=0; i--)
        {
            cout << d[i];
            if (i != 0)
                cout << ",";
        }
    }
    else
    {
        for (int i = 0; i < d.size(); i++)
        {
            cout << d[i];
            if (i != d.size() - 1)
                cout << ",";
        }
    }
    
    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while (t--)
    {
        cin >> p;
        cin >> n;
        cin >> order;

        int temp = 0;
        flag = false;
        errorTag = false;
        d.clear();
        for (char c : order)
        {
            if (c == '[' || c == ']')
                continue;
            if (c == ',')
            {
                d.push_back(temp);
                temp = 0;
                continue;
            }
            temp = temp * 10 + (c - '0');
        }
        if(n!= 0)
            d.push_back(temp);

        for (char c : p)
        {
            if (c == 'R')
            {
                if (flag)
                    flag = false;
                else
                    flag = true;
            }
            else if (c == 'D')
            {
                if (d.size() == 0)
                {
                    cout << "error\n";
                    errorTag = true;
                    break;
                }
                if (flag)
                {
                    d.pop_back();
                }
                else
                {
                    d.pop_front();
                }
            }
        }
        if(!errorTag)
            print();
    }

    return 0;
}
