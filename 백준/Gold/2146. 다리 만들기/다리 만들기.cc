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

#define FOR(i, n) for (int i = 0; i < n; i++)
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
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

typedef int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int n;
int maps[101][101];
vector<vi> graphs;

// 생각해보니 flood fill이 나은 듯

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
    {
        return false;
    }
    return true;
}

void bfs(int i, int j, int color)
{
    queue<ii> q;
    q.push({i, j});
    maps[i][j] = color;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny) && maps[nx][ny] == 1)
            {
                q.push({nx, ny});
                maps[nx][ny] = color;
            }
        }
    }
}

void bfs2(int i, int j)
{
    int s = maps[i][j];

    vector<vector<int>> visited(n, vi(n, 0));

    queue<pair<int, ii>> q;
    q.push({-1, {i, j}});

    while (!q.empty())
    {
        int cnt = q.front().first;
        auto [x, y] = q.front().second;
        q.pop();

        if (maps[x][y] != 0 && maps[x][y] != s)
        {
            int e = maps[x][y];

            graphs[s - 2][e - 2] = min(graphs[s - 2][e - 2], cnt);
            graphs[e - 2][s - 2] = min(graphs[e - 2][s - 2], cnt);

            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny) && maps[nx][ny] != s && visited[nx][ny] == 0)
            {
                q.push({cnt + 1, {nx, ny}});
                visited[nx][ny] = 1;
            }
        }
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

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
        }
    }

    int color = 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maps[i][j] == 1)
            {
                bfs(i, j, color++);
            }
        }
    }

    int num_island = color - 2;

    graphs = vector<vi>(num_island, vi(num_island));

    for (int i = 0; i < num_island; i++)
    {
        for (int j = 0; j < num_island; j++)
        {
            if (i == j)
            {
                graphs[i][j] = 0;
            }
            else
            {
                graphs[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maps[i][j] != 0)
            {
                bfs2(i, j);
            }
        }
    }

    int minimum = 1000;

    for (int i = 0; i < num_island; i++)
    {
        for (int j = i + 1; j < num_island; j++)
        {
            minimum = min(minimum, graphs[i][j]);
        }
    }
    cout << minimum;
}
