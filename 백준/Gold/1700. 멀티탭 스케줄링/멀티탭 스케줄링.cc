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
int n, k, ret, idx, space;
int visited1[101];
int visited2[101];
int d[101];
vector<int> v;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> idx;
        d[i] = idx;
    }
    v.push_back(0);

    visited1[d[1]] = 1;
    v.push_back(d[1]);

    for (int i = 2; i <= k; i++)
    {
        if (visited1[d[i]] == 1)
            continue;

        if (v.size() - 1 < n)
        {
            visited1[d[i]] = 1;
            v.push_back(d[i]);
        }
        else  // 뭘 교체할건데?
        {
            if (i == k)
            {
                ret++;
                break;
            }

            // 뒤에서 어떤 제품이 나올건데?  + 가장 늦게 사용할 제품 인덱스 기록
            fill(visited2, visited2 + 101, 0);
            map<int, int> when;
            for (int j = i + 1; j <= k; j++)
            {
                visited2[d[j]] = 1;

                if(visited1[d[j]] == 1)
                    when.insert({ d[j], j });
            }
            
            pair<int, int> last = { -1, -1 };
            int lastIdx = -1;
            for (pair<int, int> e : when)
            {
                if (e.second >= last.second)
                {
                    last = e;
                }
            }

            // 앞에서 어떤 제품을 뺄 껀데?
            bool check = false;
            for (int t = 1; t < v.size(); t++)
            {
                if (visited2[v[t]] == 0)
                {
                    // 교체!
                    ret++;
                    visited1[v[t]] = 0;
                    visited1[d[i]] = 1;

                    //cout << "교체된 것 (전) : " << v[t] << '\n';
                    v[t] = d[i];
                    //cout << "교체된 것 (후) : " << v[t] << '\n';
                    check = true;
                    break;
                }

                if(visited2[v[t]] == 1)
                {
                    if (v[t] == last.first)
                        lastIdx = t;
                }
            }


            // 예외 : 만약 뒤에서 모든 제품이 중복으로 나올거라면? 뭘 빼야하지? + 
            // 아무거나 빼도 됨 X  -->  뒤에 오는 중복 플러그 중 가장 늦게오는 플러그 
            if (check == false)
            {
                ret++;
                visited1[last.first] = 0;
                visited1[d[i]] = 1;
                //cout << "교체된 것2 (전) : " << v[1] << '\n';
                v[lastIdx] = d[i];
                //cout << "교체된 것2 (후) : " << v[1]<< '\n';
            }
        }
    }

    cout << ret << '\n';

    return 0;
}
