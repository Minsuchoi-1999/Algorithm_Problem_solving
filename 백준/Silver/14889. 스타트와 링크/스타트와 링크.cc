#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;

int minimum = 987654321;

int calculate(vector<vi>& powers, vi& arr){
	if(arr.size() == 1){
		return 0;
	}
	
	int ret = 0;
	
	for(int i= 0; i<arr.size(); i++){
		for(int j= 0; j<arr.size(); j++){
			ret += powers[arr[i]][arr[j]];
		}
	}
	return ret;
}

void brute_force(vector<vi> powers, int index, int end, vi& start, vi& link){
	if(index == end){
		if(start.size() != end/2 || link.size() != end/2) return;
		
		int start_num = calculate(powers, start);
		int link_num = calculate(powers, link);
		
	//	cout<<"-----\n";
		
	//	for(auto e: start){
	//		cout<<e<<" ";
	//	}cout<<"\n";
		
	//	for(auto e: link){
	//		cout<<e<<" ";
	//	}cout<<"\n";
		
	//	cout<< start_num<<" "<<link_num<<"\n";
		
		minimum = min(minimum, abs(start_num - link_num));
		return;
	}
	
	start.push_back(index);
	brute_force(powers, index + 1, end, start, link);
	start.pop_back();
	
	link.push_back(index);
	brute_force(powers, index + 1, end, start, link);
	link.pop_back();
}



int main() {
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

	int n;
	cin>> n;
	
	vector<vi> powers(n, vi(n));
	
	for(int i= 0; i<n; i++){
		for(int j= 0; j<n; j++){
			int num;
			cin>> num;
			powers[i][j] = num;
		}
	}
	
	vi start;
	vi link;
	
	brute_force(powers, 0, n, start, link);
	
	cout<<minimum;
	
	return 0;
}