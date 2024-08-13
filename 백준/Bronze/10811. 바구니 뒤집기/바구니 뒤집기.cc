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
int n, m;
int ar[101];

void reverse(int a, int b)
{
    int l = b - a + 1;
    for (int i = 0; i < l / 2; i++)
    {
        int temp = ar[a + i];
        ar[a + i] = ar[b - i];
        ar[b - i] = temp;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        ar[i] = i;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        reverse(a, b);
    }
    for (int i = 1; i <= n; i++)
        cout << ar[i] << " ";
    cout << '\n';
    return 0;
}
