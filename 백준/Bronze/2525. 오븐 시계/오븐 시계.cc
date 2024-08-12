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
int a, b, c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cin >> c;
    
    int temp = 60 * a + b;
    int temp2 = temp + c;
    int h = temp2 / 60;
    int m = temp2 % 60;

    while(h >= 24)
        h -= 24;
    
    cout << h << " "<< m << '\n';

    return 0;
}
