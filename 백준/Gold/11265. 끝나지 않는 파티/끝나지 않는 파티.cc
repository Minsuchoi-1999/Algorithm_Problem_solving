#include <iostream>
#include <vector>
using namespace std;

typedef vector<long long> vi;

int main() {
	int n, m;
	cin>> n>> m;
	
	vector<vi> roads(n, vi(n));
	
	for(int i= 0; i<n; i++){
		for(int j= 0; j<n; j++){
			long long dist;
			cin>> dist;
			roads[i][j] = dist;
		}
	}
	
	for(int k= 0; k<n; k++){
		for(int i= 0; i<n; i++){
			for(int j= 0; j<n; j++){
				if(i == j) continue;
				roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
			}
		}
	}
	
	while(m--){
		long long a, b, c;
		cin>> a>> b>> c;
		
		if(roads[a-1][b-1] <= c){
			cout<< "Enjoy other party"<<"\n";
		}
		else{
			cout<<"Stay here"<<"\n";
		}
	}
	return 0;
}