#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;

        dp[q] = dp[q - 1] + 1;
    }

    int answer = 0;

    for (auto e : dp)
    {
        answer = max(answer, e);
    }

    cout << n - answer;

    return 0;
}