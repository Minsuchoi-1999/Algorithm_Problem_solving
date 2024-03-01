#include <iostream>
#include <vector>
#include <string>

using namespace std;

int r1, r2, c1, c2;

vector<vector<string>> dp;

bool check(int x, int y){
	if( (x>= 5000 + r1) && (x <= 5000 + r2) && (y<= 5000 + c2) && (y>= 5000 + c1)){
		return true;
	}
	return false;
}

int max_length = 0;

void brute_force(int x, int y, int n, int dir, int temp){
//	cout<<x - 5000 <<" "<<y  - 5000<<"\n";
	if(x == 5000 && y == 5000 && check(x, y)){
		dp[x - 5000 - r1][y- 5000 - c1] = to_string(temp);
		int size = dp[x - 5000 - r1][y  - 5000 - c1].size();
		max_length = max(max_length, size);
	}
	
	
	if(x > 10000 || y > 10000) return;
	
	if(dir == 0){
		for(int i = 1; i<=n; i++){
			if(check(x, y+i)){
				dp[x - 5000 - r1][y+i  - 5000 - c1] = to_string(temp + i);
				int size = dp[x - 5000 - r1][y+i  - 5000 - c1].size();
				max_length = max(max_length, size);
			}
		}
		brute_force(x, y+n, n, 1, temp + n);
	}
	else if(dir == 1){
		for(int i = 1; i<=n; i++){
			if(check(x-i, y)){
				dp[x-i - 5000 - r1][y - 5000 - c1] = to_string(temp + i);
				int size = dp[x-i - 5000 - r1][y - 5000 - c1].size();
				max_length = max(max_length, size);
			}
		}
		brute_force(x-n, y, n+1, 2, temp + n);
	}
	else if(dir == 2){
		for(int i = 1; i<=n; i++){
			if(check(x, y-i)){
				dp[x - 5000 - r1][y-i - 5000 - c1] = to_string(temp + i);
				int size = dp[x - 5000 - r1][y-i - 5000 - c1].size();
				max_length = max(max_length, size);
			}
		}
		brute_force(x, y-n, n, 3, temp + n);	
	}
	else{
		for(int i = 1; i<=n; i++){
			if(check(x+i, y)){
				dp[x+i - 5000 - r1][y - 5000 - c1] = to_string(temp + i);
				int size = dp[x+i - 5000 - r1][y - 5000 - c1].size();
				max_length = max(max_length, size);
			}
		}
		brute_force(x+n, y, n+1, 0, temp + n);
	}
}


int main() {
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

	cin>>r1>>c1>>r2>>c2;
	
	dp = vector<vector<string>>(r2 - r1 + 1, vector<string>(c2 - c1 + 1)) ;
	
	brute_force(5000, 5000, 1, 0, 1);

	for(auto line : dp){
		for(auto e: line){
			if(e.size() < max_length){
				for(int i= 0; i<max_length - e.size(); i++){
					cout<<" ";
				}
			}
			cout<<e<<" ";
		}cout<<"\n";
	}cout<<"\n";

	return 0;
}