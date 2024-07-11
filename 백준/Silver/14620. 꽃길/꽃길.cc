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
int n, ret = INT_MAX;
int board[11][11];
int visited[11][11];
int dy[5] = { -1, 0, 1, 0, 0 };
int dx[5] = { 0, 1, 0, -1, 0 };

int flower(int y, int x) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        sum += board[ny][nx];
    }
    return sum;
}

void cancel(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

bool isPossible(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || ny > n || nx < 1 || nx > n || visited[ny][nx])
            return false;
    }
    return true;
}

void go(int cnt, int sum) {
    if (cnt == 3) {
        ret = min(ret, sum);
        return;
    }

    for (int i = 2; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (isPossible(i, j)) {
                int price = flower(i, j);
                go(cnt + 1, sum + price);
                cancel(i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    go(0, 0);

    cout << ret << '\n';
    return 0;
}