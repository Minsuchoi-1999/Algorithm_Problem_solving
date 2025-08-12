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
#include <cstdint>

typedef struct {
    int cost;
    int value;
} options;

std::vector<options> arr;
int dp[105][5055]; // dp[turn][speed] = 최대 carrot

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i].cost >> arr[i].value;
    }

    int maxSpeed = 1 + 50 * K; // B_i ≤ 50, K ≤ 100
    for (int i = 0; i <= K; i++) {
        for (int s = 0; s <= maxSpeed; s++) {
            dp[i][s] = -1;
        }
    }
    dp[0][1] = 0; // 시작 상태: 턴0, speed=1, carrot=0

    for (int t = 0; t < K; t++) {
        for (int s = 1; s <= maxSpeed; s++) {
            if (dp[t][s] == -1) continue;
            int carrot = dp[t][s];

            // 1) 클릭
            dp[t+1][s] = std::max(dp[t+1][s], carrot + s);

            // 2) 구매
            for (int i = 0; i < N; i++) {
                if (carrot >= arr[i].cost) {
                    dp[t+1][s + arr[i].value] =
                        std::max(dp[t+1][s + arr[i].value], carrot - arr[i].cost);
                }
            }
        }
    }

    int answer = 0;
    for (int s = 1; s <= maxSpeed; s++) {
        answer = std::max(answer, dp[K][s]);
    }
    std::cout << answer << "\n";
}
