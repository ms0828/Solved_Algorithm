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
int n, m, ret = INT_MIN;
int a[4][4];
int comp[4][4];

int cal()
{
    int sum = 0;
    string s;

    // 가로 숫자 더하기
    for (int i = 0; i < n; i++)
    {
        s = "";
        for (int j = 0; j < m; j++)
        {
            if (comp[i][j] == 0)
            {
                s += to_string(a[i][j]);
            }
            else
            {
                if (s != "")
                    sum += stoi(s);
                s = "";
            }
        }
        if (s != "")
            sum += stoi(s);
    }

    // 세로 숫자 더하기
    for (int i = 0; i < m; i++)
    {
        s = "";
        for (int j = 0; j < n; j++)
        {
            if (comp[j][i] == 1)
            {
                s += to_string(a[j][i]);
            }
            else
            {
                if (s != "")
                    sum += stoi(s);
                s = "";
            }
        }
        if (s != "")
            sum += stoi(s);
    }
    
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s; 
        for (int k = 0; k < m; k++)
            a[i][k] = s[k] - '0';
    }
    for (int c = 0; c < pow(2, n * m); c++)
    {
        fill(&comp[0][0], &comp[n-1][m], 0);
        for (int i = 0; i < n * m; i++)
        {
            if (c & (1 << i))
            {
                comp[n - 1 - i / m][m - 1 - i % m] = 1;     // 모든 경우의 수를 표현하는 비트를 2차원 배열로 변환
            }
        }
        ret = max(ret, cal());
    }
    cout << ret << '\n';

    return 0;
}
