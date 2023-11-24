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

long long v[2097153] = {
    0,
};

long long dp[2097153] = {
    0,
};
// 무향그래프니까 그리다가 갔던데를 다시 갈 수 있다는 거
long long node;
long long height;

long long dfs(int n)
{

    if (n >= node)
    {
        return 0;
    }

    int left = 2 * n + 1;
    int right = 2 * n + 2;

    int left_sum = dfs(left);
    int right_sum = dfs(right);

    dp[n] = max(left_sum, right_sum) - min(left_sum, right_sum);

    return v[n] + max(left_sum, right_sum);
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

    cin >> height;

    node = pow(2, height + 1) - 1;

    for (int i = 1; i < node; i++)
    {
        long long key;
        cin >> key;
        v[i] = key;
    }

    long long sum = 0;

    dfs(0);

    for (int i = 0; i < node; i++)
    {
        sum += v[i] + dp[i];
    }

    cout << sum;

    return 0;
}