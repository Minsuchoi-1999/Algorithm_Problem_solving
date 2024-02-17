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
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;

int max_strike = 0;

int dp[1501][1501] = {
    0,
};

char next_time(char time)
{
    if (time == 'B')
        return 'L';
    if (time == 'L')
        return 'D';
    if (time == 'D')
        return 'B';

    return ' ';
}

int brute_force(string &type, int p1, int p2, char time)
{

    int &ret = dp[p1][p2];

    if (dp[p1][p2] != 0)
    {
        return ret;
    }

    if (p1 > p2)
    {
        return 0;
    }

    ret = 0;

    if (time == type[p1])
    {
        ret = max(ret, brute_force(type, p1 + 1, p2, next_time(time)) + 1);
    }
    if (time == type[p2])
    {
        ret = max(ret, brute_force(type, p1, p2 - 1, next_time(time)) + 1);
    }

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

    int num_of_set;
    cin >> num_of_set;

    string str;
    cin >> str;

    cout << brute_force(str, 0, 3 * num_of_set - 1, 'B');

    return 0;
}
