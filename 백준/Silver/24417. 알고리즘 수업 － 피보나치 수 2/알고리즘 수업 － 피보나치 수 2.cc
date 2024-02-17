#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	ll A = 1, B = 1;
	for (int i = 2; i < N; i++) {
		ll tmp = A + B;
		if (tmp > 1000000006) tmp -= 1000000007;
		swap(A, B); swap(B, tmp);
	}

	cout << B << ' ' << N - 2;
}