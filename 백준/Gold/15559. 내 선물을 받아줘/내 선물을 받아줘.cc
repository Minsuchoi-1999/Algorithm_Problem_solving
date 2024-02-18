#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

vector<vector<char>> graph;
vector<vector<char>> visited;

int head[1000001];

unordered_map<int, int> dict;

int find(int x)
{
    if (x == head[x])
    {
        return x;
    }
    return head[x] = find(head[x]);
}

void _union(int x, int y)
{
    x = find(x);
    y = find(y);

    head[x] = y;
}

void dfs(int i, int j)
{
    visited[i][j] = 'o';

    int next_i = i;
    int next_j = j;

    switch (graph[i][j])
    {
    case 'S':
        next_i += 1;
        break;
    case 'W':
        next_j -= 1;
        break;
    case 'E':
        next_j += 1;
        break;
    case 'N':
        next_i -= 1;
        break;
    }

    int row = visited[0].size();

    _union(i * row + j, next_i * row + next_j);

    if (visited[next_i][next_j] == 'x')
    {
        dfs(next_i, next_j);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n * m; i++)
    {
        head[i] = i;
    }

    graph = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<char>>(n, vector<char>(m, 'x'));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 'x')
            {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n * m; i++)
    {
        dict[find(i)] += 1;
    }

    cout << dict.size();

    return 0;
}