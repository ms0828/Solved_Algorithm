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
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int max = 1 + (n - 1) * 2;
    int mid = max / 2;
    
    for (int i = 0; i <= mid; i++)
    {
        for (int j = 0; j <= mid + i; j++)
        {
            if (j < mid - i)
                cout << " ";
            else
                cout << "*";
        }
        cout << '\n';
    }
    for (int i = mid - 1; i >= 0; i--)
    {
        for (int j = 0; j <= mid + i; j++)
        {
            if (j < mid - i)
                cout << " ";
            else
                cout << "*";
        }
        cout << '\n';
    }

    return 0;
}
