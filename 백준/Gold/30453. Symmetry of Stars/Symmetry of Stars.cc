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
typedef vector<ii> vii;
typedef vector<bool> vb;

int n;
vii arr;

unordered_map<long long, int> dict;

long long make_hash(ii e1, ii e2)
{
    long long head = e1.first + e2.first;
    long long tail = e1.second + e2.second;

    return (head << 32) + tail;
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

    for (int i = 0; i < n; i++)
    {
        ii key;
        cin >> key.first >> key.second;
        arr.push_back(key);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // cout << arr[i].first + arr[j].first << " " << arr[i].second + arr[i].second << " " << make_hash(arr[i], arr[j]) << "\n";
            if (i == j)
            {
                dict[make_hash(arr[i], arr[j])] += 1;
            }
            else
            {
                dict[make_hash(arr[i], arr[j])] += 2;
            }
        }
    }

    int max_value = 0;

    for (auto iter = dict.begin(); iter != dict.end(); iter++)
    {
        // cout << iter->first << " " << iter->second << "\n";
        max_value = max(max_value, iter->second);
    }

    cout << max_value;
}
