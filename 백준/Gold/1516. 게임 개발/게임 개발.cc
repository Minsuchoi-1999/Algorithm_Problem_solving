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

int n;

vector<long long> dp;
vector<long long> arr;
vector<vector<int>> maps;

long long dfs(int i)
{
    long long &ref = dp[i];

    if (ref != -1)
    {
        return ref;
    }

    ref = 0;

    for (int j = 0; j < maps[i].size(); j++)
    {
        ref = max(ref, dfs(maps[i][j]));
    }

    ref += arr[i];

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

    cin >> n;
    arr = vector<long long>(n);
    dp = vector<long long>(n, -1);
    maps = vector<vector<int>>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        int num;

        while (1)
        {
            cin >> num;
            if (num == -1)
            {
                break;
            }
            maps[i].push_back(num - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == -1)
        {
            dfs(i);
        }
    }

    for (auto n : dp)
    {
        cout << n << " ";
    }
    cout << "\n";
}