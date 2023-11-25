#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans, sum;
int bite[101], cost[101];
int dp[10001];

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> bite[i];
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
        // sum : 모든 비용들의 합
        sum += cost[i];
    }

    // dp[i][j] == i번째 앱까지 탐색했을 때
    // j비용을 소모해서 얻을 수 있는 최대 메모리
    for (int i = 1; i <= N; i++)
    {
        for (int j = sum + 1; j >= 0; j--)
        {
            if (j >= cost[i])
                dp[j] = max(dp[j], dp[j - cost[i]] + bite[i]);
            else
                dp[j] = dp[j];
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[i] >= M)
        {
            cout << i << endl;
            break;
        }
    }
}