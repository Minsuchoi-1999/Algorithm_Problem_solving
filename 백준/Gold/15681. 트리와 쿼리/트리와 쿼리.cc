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

vector<int> v[100001];
// maps
bool visit[100001] = {
    false,
};
// 무향그래프니까 그리다가 갔던데를 다시 갈 수 있다는 거
int num[100001];
// dp
int node, query, s, e;

int dfs(int n)
{
    if (num[n] != 0)
        return num[n];

    visit[n] = true;
    int ret = 1; // subtree는 본인만 있어도 subtree니까

    for (int i = 0; i < v[n].size(); i++)
    {
        int next = v[n][i];
        if (visit[next])
            continue;
        ret += dfs(next);
    }
    num[n] = ret;
    return ret;
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

    int root;
    cin >> node >> root >> query;
    for (int i = 0; i < node - 1; i++)
    {
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    } // 무향 그래프니까

    num[root] = dfs(root);

    for (int i = 0; i < query; i++)
    {
        cin >> s;
        cout << num[s] << '\n';
    }
    return 0;
}