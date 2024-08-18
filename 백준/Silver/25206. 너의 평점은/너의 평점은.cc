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

float sumCredit, sumScore, avg, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 20; i++)
    {
        float credit;
        string subject, score;
        cin >> subject >> credit >> score;
        
        sumCredit += credit;
        cnt++;
        if (score == "A+" )
            sumScore += credit * 4.5f;
        else if(score == "A0")
            sumScore += credit * 4.0f;
        if (score == "B+")
            sumScore += credit * 3.5f;
        if (score == "B0")
            sumScore += credit * 3.0f;
        if (score == "C+")
            sumScore += credit * 2.5f;
        if (score == "C0")
            sumScore += credit * 2.0f;
        if (score == "D+")
            sumScore += credit * 1.5f;
        if (score == "D0")
            sumScore += credit * 1.0f;
        if (score == "P")
        {
            sumCredit -= credit;
            cnt--;
        }
    }
    
    cout << sumScore / sumCredit << '\n';

    return 0;
}
