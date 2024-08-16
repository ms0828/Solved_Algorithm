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
int h[6] = { 1,1,2,2,2,8 };
int a[6];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 6; i++)
        cin >> a[i];

    for (int i = 0; i < 6; i++)
    {
        cout << h[i] - a[i] << " ";
    }
    cout << '\n';


    return 0;
}
