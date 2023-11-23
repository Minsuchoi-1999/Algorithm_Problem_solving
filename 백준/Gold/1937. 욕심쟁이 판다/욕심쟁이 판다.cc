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
vector<vector<long long>> arr;
vector<vector<long long>> dp;

long long dfs(int i, int j)
{
    long long &ret = dp[i][j];

    if (ret != 1)
    {
        return ret;
    }

    if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
    {
        return 0;
    }

    ret = 1;

    long long temp = 0;

    if (arr[i][j - 1] > arr[i][j])
    {
        temp = max(temp, dfs(i, j - 1));
    }
    if (arr[i][j + 1] > arr[i][j])
    {
        temp = max(temp, dfs(i, j + 1));
    }
    if (arr[i - 1][j] > arr[i][j])
    {
        temp = max(temp, dfs(i - 1, j));
    }
    if (arr[i + 1][j] > arr[i][j])
    {
        temp = max(temp, dfs(i + 1, j));
    }

    ret += temp;

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

    cin >> n;

    arr = vector<vector<long long>>(n + 2, vector<long long>(n + 2, 0));
    dp = vector<vector<long long>>(n + 2, vector<long long>(n + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long long temp = 0;

            dp[i][j] += temp;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == 1)
            {
                dfs(i, j);
            }
        }
    }

    /*
        for (auto l : dp)
        {
            for (auto e : l)
            {
                cout << e << " ";
            }
            cout << "\n";
        }
    */

    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}