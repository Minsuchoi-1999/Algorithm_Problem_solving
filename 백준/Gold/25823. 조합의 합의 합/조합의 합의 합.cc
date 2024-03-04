#include <iostream>

const long long MOD = 1e9 + 7;

// 거듭제곱을 빠르게 계산하는 함수
long long fast_pow(long long n, long long p)
{
    if (p == 2)
    {
        return ((n % MOD) * (n % MOD)) % MOD;
    }
    if (p % 2 == 0)
    {
        return fast_pow(((n % MOD) * (n % MOD)) % MOD, p / 2) % MOD;
    }
    else
    {
        return ((n % MOD) * (fast_pow(n, p - 1) % MOD)) % MOD;
    }
}

signed main()
{
    long long M;
    std::cin >> M;

    // 초기값을 2C1로 설정
    long long cal = 6;
    long long sum_of_combination = 0;

    for (long long n = 3; n <= M; ++n)
    {
        // cal 값 갱신
        cal = cal * (2 * n - 1) % MOD;
        cal = cal * (2 * n) % MOD;
        cal = cal * fast_pow(n * n, MOD - 2) % MOD; // n^2의 역원을 곱함
        cal %= MOD;

        // sum_of_combination에 더하기
        sum_of_combination = (sum_of_combination + cal) % MOD;
    }

    // 최종 결과를 10^9+7로 나눈 나머지 출력
    std::cout << sum_of_combination << std::endl;

    return 0;
}
