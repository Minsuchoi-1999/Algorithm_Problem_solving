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

int n, m;
int maps[11][11];
int graphs[6][6];
int head[6];

int find(int x)
{
    if (x == head[x])
        return head[x];
    return head[x] = find(head[x]);
}

void _union(int x, int y)
{
    x = find(x);
    y = find(y);

    head[x] = y;
}

// 생각해보니 flood fill이 나은 듯

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
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

    queue<pair<ii, ii>> q;
    q.push({{1, -1}, {i, j}});
    q.push({{3, -1}, {i, j}});

    while (!q.empty())
    {
        auto [dir, cnt] = q.front().first;
        auto [x, y] = q.front().second;
        q.pop();

        if (maps[x][y] != 0 && maps[x][y] != s)
        {
            int e = maps[x][y];

            if (cnt != 1)
            {
                graphs[s - 2][e - 2] = min(graphs[s - 2][e - 2], cnt);
                graphs[e - 2][s - 2] = min(graphs[e - 2][s - 2], cnt);
            }
            continue;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (check(nx, ny) && maps[nx][ny] != s)
        {
            q.push({{dir, cnt + 1}, {nx, ny}});
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

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    int color = 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == 1)
            {
                bfs(i, j, color++);
            }
        }
    }

    int num_of_island = color - 2;

    // cout << num_of_island << "\n";

    for (int i = 0; i < num_of_island; i++)
    {
        for (int j = 0; j < num_of_island; j++)
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
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] != 0)
            {
                bfs2(i, j);
            }
        }
    }

    priority_queue<pair<int, ii>> pq;

    for (int i = 0; i < num_of_island; i++)
    {
        head[i] = i;

        for (int j = i + 1; j < num_of_island; j++)
        {
            if (graphs[i][j] != INF)
                pq.push({-graphs[i][j], {i, j}});
        }
    }

    /*
        for (int i = 0; i < num_of_island; i++)
        {
            for (int j = 0; j < num_of_island; j++)
            {
                if (graphs[i][j] == INF)
                {
                    cout << INF << " ";
                }
                else
                {
                    cout << graphs[i][j] << " ";
                }
            }
            cout << "\n";
        }
    */

    int t_cost = 0;
    int check_count = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        auto [x, y] = pq.top().second;
        pq.pop();

        if (find(x) != find(y))
        {
            t_cost += cost;
            check_count += 1;
            _union(x, y);
        }
    }

    if (check_count + 1 != num_of_island)
    {
        cout << -1;
    }
    else
    {
        cout << t_cost;
    }
}
