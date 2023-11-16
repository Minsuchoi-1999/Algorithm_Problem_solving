#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <stack>
#include <climits>

using namespace std;

#define FOR(i, n) for (long long i = 0; i < n; i++)
#define INF 1234567890
#define MAX 1234567891
#define MOD 1234567891
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1)) // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((long long)pow(2.0, (long long)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int n, m;

vector<vi> dict;
unordered_map<int, int> visited;
vector<vi> maps;
vector<vi> dp;

bool check(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= n && y <= m)
    {
        return true;
    }
    return false;
}

int group = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y)
{
    group += 1;

    vii change;
    queue<ii> q;
    q.push({x, y});
    dp[x][y] = 0;
    change.push_back({x, y});
    int paths = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!check(nx, ny))
            {
                continue;
            }
            if (dp[nx][ny] != -1)
            {
                continue;
            }

            if (maps[nx][ny] == 0)
            {
                paths = (paths + 1) % 10;
                q.push({nx, ny});
                dp[nx][ny] = 0;
                change.push_back({nx, ny});
            }
        }
    }

    for (auto e : change)
    {
        dict[e.first][e.second] = group;
        dp[e.first][e.second] = paths % 10;
    }
}

signed main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    maps = vector<vi>(n + 2, vi(m + 2, 0));
    dp = vector<vi>(n + 2, vi(m + 2, -1));
    dict = vector<vi>(n + 2, vi(m + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            maps[i][j + 1] = s[j] - '0';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maps[i][j] == 0 && dp[i][j] == -1)
            {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maps[i][j] == 1)
            {
                dp[i][j] = 1;
                visited.clear();
                vii dirs = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};

                for (auto e : dirs)
                {
                    if (visited[dict[e.first][e.second]] == 0 && maps[e.first][e.second] == 0)
                    {
                        dp[i][j] = (dp[i][j] + dp[e.first][e.second] % 10) % 10;
                        visited[dict[e.first][e.second]] += 1;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maps[i][j] == 0)
            {
                cout << 0;
            }
            else
            {
                cout << dp[i][j];
            }
        }
        cout << "\n";
    }
}