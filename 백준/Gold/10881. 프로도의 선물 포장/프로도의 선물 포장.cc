#include <iostream>
#include <vector>
#include <queue>

#define F first
#define S second

using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;

int minimum(ii largest, ii small1, ii small2){
		ii comb = {max(small1.F,small2.F), small1.S + small2.S};
		ii comb2 = {small1.F+small2.F, max(small1.S, small2.S)};
		ii comb3 = {small1.F + small2.S, max(small1.S, small2.F)};
		ii comb4 = {small1.S + small2.F, max(small1.F, small2.S)};
		//cout<< largest.F<<" "<<largest.S<<" "<<comb.F<<" "<<comb.S<<"\n";
		
		int area1 = (comb.F + largest.F) * max(comb.S, largest.S);
		int area2 = (comb.S + largest.F) * max(comb.F, largest.S);
		int area3 = (comb.F + largest.S) * max(comb.S, largest.F);
		int area4 = (comb.S + largest.S) * max(comb.F, largest.F);
		
		int mid = min(min(area1, area2), min(area3, area4));
		
		area1 = (comb2.F + largest.F) * max(comb2.S, largest.S);
		area2 = (comb2.S + largest.F) * max(comb2.F, largest.S);
		area3 = (comb2.F + largest.S) * max(comb2.S, largest.F);
		area4 = (comb2.S + largest.S) * max(comb2.F, largest.F);
		
		mid = min(mid, min(min(area1, area2), min(area3, area4)));
		
		area1 = (comb3.F + largest.F) * max(comb3.S, largest.S);
		area2 = (comb3.S + largest.F) * max(comb3.F, largest.S);
		area3 = (comb3.F + largest.S) * max(comb3.S, largest.F);
		area4 = (comb3.S + largest.S) * max(comb3.F, largest.F);
		
		mid = min(mid, min(min(area1, area2), min(area3, area4)));
		
		area1 = (comb4.F + largest.F) * max(comb4.S, largest.S);
		area2 = (comb4.S + largest.F) * max(comb4.F, largest.S);
		area3 = (comb4.F + largest.S) * max(comb4.S, largest.F);
		area4 = (comb4.S + largest.S) * max(comb4.F, largest.F);
		
		mid = min(mid, min(min(area1, area2), min(area3, area4)));
		
		return mid;
}


int main() {
	int test;
	cin>> test;
	
	while(test--){
		vector<ii> arr(3);
		
		for(int i= 0; i<3; i++){
			int num1, num2;
			cin>> num1 >> num2;
			
			if(num1 > num2){
				arr[i].F = num1;
				arr[i].S = num2;
			}
			else{
				arr[i].F = num2;
				arr[i].S = num1;
			}
		}
		
		int answer = 123456789;
		
		for(int i= 0; i<3; i++){
			for(int j= 0; j<3; j++){
				for(int k= 0; k<3; k++){
					if(i ==k || k== j || i == j){
						continue;
					}
					 answer = min(answer, minimum(arr[i], arr[j], arr[k]));
				}
			}
		}
		

		cout<<answer<<"\n";
		
	}
	return 0;
}