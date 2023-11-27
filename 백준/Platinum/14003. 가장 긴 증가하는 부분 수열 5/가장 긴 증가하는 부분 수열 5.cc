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

long long n;
vector<long long> arr;
vector<long long> dp;
vector<long long> lis;

long long binary_search(long long start, long long end, long long element)
{
    while (start < end)
    {
        long long mid = (start + end) / 2;
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
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp.push_back(arr[0]);
    lis.push_back(1); // 부분 수열의 길이를 기록하는 벡터를 추가

    for (long long i = 1; i < n; i++)
    {
        if (arr[i] > dp.back())
        {
            dp.push_back(arr[i]);
            lis.push_back(dp.size()); // 부분 수열의 길이 갱신
        }
        else
        {
            long long pos = binary_search(0, dp.size(), arr[i]);
            dp[pos] = arr[i];
            lis.push_back(pos + 1); // 부분 수열의 길이 갱신
        }
    }

    long long ret = dp.size();

    cout << ret << '\n';

    vector<long long> result;
    for (long long i = n - 1; i >= 0; i--)
    {
        if (lis[i] == ret)
        {
            result.push_back(arr[i]);
            ret--;
        }
    }

    for (long long i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
    return 0;
}
