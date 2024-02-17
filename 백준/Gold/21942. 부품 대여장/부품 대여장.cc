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

long long days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

map<string, long long> visited;
vector<pair<string, long long>> answer;

long long str_to_day(string date)
{
    long long month = (long long)stoi(date.substr(5, 2));
    long long day = 0;

    for (long long i = 0; i < month; i++)
    {
        day += days[i];
    }
    day += (long long)stoi(date.substr(8, 2));

    return day;
}

long long str_to_minute(string time)
{
    long long hour = (long long)stoi(time.substr(0, 2));
    long long minute = (long long)stoi(time.substr(3, 2));

    return hour * 60 + minute;
}

map<pair<string, string>, long long> dict;

signed main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long num_of_queries, deadline, penalty;
    cin >> num_of_queries;

    string str_deadline;
    cin >> str_deadline;

    long long day = (long long)stoi(str_deadline.substr(0, 3));
    long long hour = (long long)stoi(str_deadline.substr(4, 2));
    long long minute = (long long)stoi(str_deadline.substr(7, 2));

    deadline = day * 60 * 24 + hour * 60 + minute;

    cin >> penalty;

    for (long long i = 0; i < num_of_queries; i++)
    {
        string date, time, div, person;
        cin >> date >> time >> div >> person;

        long long q_minute = str_to_minute(time);
        long long q_day = str_to_day(date);

        if (dict[{div, person}] == 0)
        {
            dict[{div, person}] = q_day * 60 * 24 + q_minute;
        }
        else
        {
            long long borrow_min = q_day * 60 * 24 + q_minute - dict[{div, person}];
            if (borrow_min > deadline)
            {
                visited[person] += (borrow_min - deadline) * penalty;
            }
            dict[{div, person}] = 0;
        }
    }

    if (visited.size() == 0)
    {
        cout << "-1";
    }
    else
    {
        for (auto iter : visited)
        {
            cout << iter.first << " " << iter.second << "\n";
        }
    }
}
