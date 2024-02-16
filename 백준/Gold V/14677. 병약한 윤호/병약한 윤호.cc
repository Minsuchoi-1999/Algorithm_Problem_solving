#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int max_strike = 0;

int dp[1501][1501] = {0,};

char next_time(char time){
	if(time == 'B') return 'L';
	if(time == 'L') return 'D';
	if(time == 'D') return 'B';
}


void brute_force(string& type, int strike, int p1, int p2, char time){
	//cout<<p1<<" "<<p2<< " "<<strike<<" "<<time<<"\n";
	
	if(dp[p1][p2] != 0){
		return;
	}
	
	max_strike = max(max_strike, strike);
	
	if(p1 > p2){
		return;
	}
	
	dp[p1][p2] = 1;
	
	//cout<<time<<" "<<type[p1] <<" "<< type[p2]<<"\n";
	
	if(time == type[p1]){
		brute_force(type, strike + 1, p1+1, p2, next_time(time));
	}
	if(time == type[p2]){
		brute_force(type, strike + 1, p1, p2 -1, next_time(time));
	}
}


signed main() {
	int num_of_set;
	cin>> num_of_set;
	
	string str;
	cin>> str;
	
	brute_force(str, 0, 0, 3*num_of_set-1, 'B');
	
	cout<<max_strike;
	
	return 0;
}