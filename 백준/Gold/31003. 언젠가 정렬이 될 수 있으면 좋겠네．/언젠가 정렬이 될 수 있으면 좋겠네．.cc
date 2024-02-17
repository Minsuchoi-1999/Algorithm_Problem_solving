#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

#define F first
#define S second

using namespace std;

vector<int> arr;

struct cmp
{
    bool operator()(int i, int j)
    {
        if (arr[i] > arr[j])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<int> indegree(n);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (gcd(arr[i], arr[j]) != 1)
            {
                graph[i].push_back(j);
                indegree[j] += 1;
            }
        }
    }

    priority_queue<int, vector<int>, cmp> pq;
    vector<int> answer(n);

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
        {
            exit(0);
        }

        int x = pq.top();
        pq.pop();

        answer[i] = arr[x];

        for (int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if (--indegree[y] == 0)
            {
                pq.push(y);
            }
        }
    }

    for (auto e : answer)
    {
        cout << e << " ";
    }

    return 0;
}