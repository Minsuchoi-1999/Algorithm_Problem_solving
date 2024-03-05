#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[101][1000001];

int n, m;

int main()
{
    cin >> n >> m;

    vector<pair<int, int>> items(n + 1);
    vector<int> bags(m + 1);

    for (int i = 1; i <= n; i++)
    {
        int weight, price;
        cin >> weight >> price;

        items[i] = {weight, price};
    }

    int max_weight = 0;

    for (int i = 1; i <= m; i++)
    {
        int capacity;
        cin >> capacity;
        bags[i] = capacity;
        max_weight = max(max_weight, capacity);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = max_weight; j >= 1; j--)
        {
            dp[i][j] = dp[i - 1][j]; // 물건을 더 담지 않기
            if (j >= items[i].first)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i].first] + items[i].second); // 물건을 더 담기
            }
        }
    }
    /*
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= weight_sum; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    */

    long long ratio = dp[n][bags[1]];
    long long bag = 1;

    for (int i = 2; i <= m; i++)
    {
        long long tmp_ratio = dp[n][bags[i]];

        if (tmp_ratio == 0)
            continue;

        if (ratio * bags[i] < tmp_ratio * bags[bag])
        {
            ratio = tmp_ratio;
            bag = i;
        }
    }

    cout << bag;

    return 0;
}