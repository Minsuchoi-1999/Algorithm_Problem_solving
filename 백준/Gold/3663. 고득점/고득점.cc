#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		int answer = 0;
		int pos = 2e9;
		int size = str.size();
		for (int i = 0; i < size; i++)
			answer += min(str[i] - 'A', 'Z' - str[i] + 1);

		for (int i = 0, j; i < size; i++) {
			for (j = i + 1; j < size && str[j] == 'A'; j++);
			if (str[i] == 'A' && j == size + 1) break;
			int right = i * 2 + size - j;
			int left = i + (size - j) * 2;
			int temp = min(left, right);
			pos = min(temp, pos);
		}
		cout << answer + pos << "\n";
	}
}