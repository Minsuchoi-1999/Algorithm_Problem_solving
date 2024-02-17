#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
int fibo[1010100];
string seq;
int q, m;
int T;
int32_t main()
{
    usecppio
    cin >> q >> m;
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i<m*m; i++)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2])%m;
        if (fibo[i] == 1 && fibo[i-1] == 1)
        {
            T = i-1;
            for (int j = 0; j<T; j++)
                seq += to_string(fibo[j]);
            break;
        }
    }
    if (m == 2)
        seq = "110";
    else if (m == 3)
        seq = "11202210";
    T = seq.size();
    while(q--)
    {
        int x;
        cin >> x;
        cout << seq[((x%T + T - 1)%T)] << '\n';
    }
}
//출처: https://gratus-blog.tistory.com/75 [Gratus' Blog:티스토리]