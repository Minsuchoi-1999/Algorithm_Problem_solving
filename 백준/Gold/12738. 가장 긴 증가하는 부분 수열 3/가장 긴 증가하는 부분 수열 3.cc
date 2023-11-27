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

int n;
vector<int> arr;
vector<int> dp;

int binary_search(int start, int end, int element)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (element > dp[mid])
            start = mid + 1;
        else
            end = mid;
    }
    return end;
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

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp.push_back(arr[0]);
    int ret = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > dp.back())
        {
            dp.push_back(arr[i]);
            ret = dp.size() - 1;
        }
        else
        {
            int pos = binary_search(0, ret, arr[i]);
            dp[pos] = arr[i];
        }
    }

    cout << (ret + 1) << '\n';

    return 0;
}
