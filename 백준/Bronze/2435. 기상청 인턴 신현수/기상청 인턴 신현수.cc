#include <iostream>
#include <vector>
#include <numeric>

#define F first
#define S second

using namespace std;

int main() {
	int n, k;
	cin>> n >> k;
	
	vector<long long> v(n+1);
	
	v[0] = 0;
	
	for(int i= 1; i<=n; i++){
		cin>>v[i];
	}
	vector<long long> p(n+1);
	
	partial_sum(v.begin(), v.end(), p.begin());
	
	long long maximum = -123456789;
	
	for(int i = k; i<=n; i++){
		maximum	= max(maximum, p[i] - p[i-k]);
	}
	cout<<maximum;
	
}