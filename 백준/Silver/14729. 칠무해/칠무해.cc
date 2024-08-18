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
priority_queue<double> pq;
vector<double> retv;
double score;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> score;
        if (pq.size() < 7)
            pq.push(score);
        else
        {
            pq.push(score);
            pq.pop();
        }
    }

    while (pq.size())
    {
        retv.push_back(pq.top());
        pq.pop();
    }

    reverse(retv.begin(), retv.end());
    for (double e : retv)
        printf("%.3lf\n", e);
    return 0;
}
