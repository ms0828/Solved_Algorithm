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

int n, k, l, t;
int a[101][101];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<int, char>> q;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        a[y-1][x-1] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int time;
        char dir;
        cin >> time >> dir;
        q.push({ time, dir });
    }

    deque<pair<int, int>> pos;
    pos.push_back({ 0,0 });
    int dir = 1;
    int _time = 0;
    char _dir = 'D';
    while (1)
    {
        if (!q.empty())
        {
            _time = q.front().first;
            _dir = q.front().second;
            q.pop();
        }
        else
        {
            _time = INT_MAX;
        }

        while (t < _time)
        {
            t++;
            int ny = pos.front().first + dy[dir];
            int nx = pos.front().second + dx[dir];
            if (ny == -1 || ny == n || nx == -1 || nx == n)
            {
                cout << t << '\n';
                return 0;
            }
            for (int i = 0; i < pos.size(); i++)
            {
                if (ny == pos[i].first && nx == pos[i].second)
                {
                    cout << t << '\n';
                    return 0;
                }
            }
            pos.push_front({ ny,nx });
            if (a[ny][nx] == 1)
                a[ny][nx] = 0;
            else
                pos.pop_back();
        }

        if (_dir == 'L')
        {
            dir--;
            if (dir < 0)
                dir += 4;
        }
        else
        {
            dir++;
            if (dir > 3)
                dir -= 4;
        }
    }



    return 0;
}
