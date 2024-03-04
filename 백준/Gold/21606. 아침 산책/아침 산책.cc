#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

long long n;
long long node_info[200001];
long long visited[200001];

vector<vector<long long>> graphs;

long long brute_force(long long prev, long long cur)
{
    if (node_info[cur])
    {
        return 1;
    }

    visited[cur] = 1;

    long long ret = 0;

    for (long long i = 0; i < graphs[cur].size(); i++)
    {
        long long next = graphs[cur][i];

        if (next != prev)
        {
            ret += brute_force(cur, next);
        }
    }

    return ret;
}

int main()
{
    cin >> n;

    string infos;
    cin >> infos;

    for (long long i = 1; i <= n; i++)
    {
        node_info[i] = infos[i - 1] - '0';
    }

    graphs = vector<vector<long long>>(n + 1);

    long long roads = 0;

    for (long long i = 0; i < n - 1; i++)
    {
        long long node1, node2;
        cin >> node1 >> node2;

        graphs[node1].push_back(node2);
        graphs[node2].push_back(node1);

        if (node_info[node1] && node_info[node2])
            roads += 2;
    }

    for (long long i = 1; i <= n; i++)
    {
        if (!node_info[i] && !visited[i])
        {
            int on_nodes = brute_force(i, i);
            roads += on_nodes * (on_nodes - 1);
        }
    }

    cout << roads;
}
