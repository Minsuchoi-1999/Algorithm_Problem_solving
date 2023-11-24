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
typedef pair<long long, long long> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

vector<long long> v[1000001];

// 무향그래프니까 그리다가 갔던데를 다시 갈 수 있다는 거
long long compliments[2][1000001];
// dp
long long node, s, e;

long long dfs(int n, int previous, int status)
{
    long long &ref = compliments[status][n];

    if (ref != -1)
    {
        return ref;
    }

    if (status == 1)
    {
        ref = 1;
    }
    else
    {
        ref = 0;
    }

    for (int i = 0; i < v[n].size(); i++)
    {
        int next = v[n][i];

        if (next == previous)
        {
            continue;
        }

        if (status == 0)
        {
            ref += dfs(next, n, 1);
        }
        else
        {
            ref += min(dfs(next, n, 1), dfs(next, n, 0));
        }
    }

    return ref;
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

    cin >> node;

    for (int i = 0; i < node; i++)
    {
        compliments[0][i] = -1;
        compliments[1][i] = -1;
    }

    for (long long i = 0; i < node - 1; i++)
    {
        int s, e;
        cin >> s >> e;

        v[s - 1].push_back(e - 1);
        v[e - 1].push_back(s - 1);
    }

    cout << min(dfs(0, -1, 1), dfs(0, -1, 0)) << "\n";
    /*
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < node; i++)
            {
                cout << compliments[j][i] << " ";
            }
            cout << "\n";
        }
    */
    return 0;
}