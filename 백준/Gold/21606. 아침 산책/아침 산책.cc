#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n;
int node_info[200001];

vector<vector<int>> graphs;

int brute_force(int start, int cur)
{
    if (start != cur && node_info[cur])
    {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < graphs[cur].size(); i++)
    {
        int next = graphs[cur][i];

        if (next != start)
        {
            ret += brute_force(start, next);
        }
    }

    return ret;
}

int main()
{
    cin >> n;

    string infos;
    cin >> infos;

    for (int i = 1; i <= n; i++)
    {
        node_info[i] = infos[i - 1] - '0';
    }

    graphs = vector<vector<int>>(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        graphs[node1].push_back(node2);
        graphs[node2].push_back(node1);
    }

    int roads = 0;

    for (int i = 1; i <= n; i++)
    {
        if (node_info[i])
        {
            roads += brute_force(i, i);
        }
    }

    cout << roads;
}
