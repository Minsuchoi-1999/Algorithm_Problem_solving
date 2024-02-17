#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
int M, N, A, B;
int map[51][51];
int temp[51][51];
int res;
int total;
int flag;
int dayTotal, before;
int val;
vector<int> v;

int main()
{
    val = 1;
    scanf("%d%d", &N, &M);
    total = 0;

    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &A, &B);
        map[A][B] = val;
        total++;
        map[B][A] = val;
    }

    while (true)
    {
        before = total;
        val++;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (map[i][j] > 0 && map[i][j] < val && i != j)
                {
                    for (int z = 1; z <= N; z++)
                    {
                        if (map[j][z] > 0 && map[j][z] < val && i < z)
                        {
                            if (map[i][z] == 0)
                            {
                                map[i][z] = map[z][i] = val;
                                total = total + 1;
                            }
                        }
                    }
                }
            }
        }

        dayTotal = total - before;

        v.push_back(dayTotal);

        if (total == ((N * N) - N) / 2)
        {
            break;
        }
    }

    printf("%d", v.size());
    printf("\n");
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d", v[i]);
        printf("\n");
    }

    return 0;
}