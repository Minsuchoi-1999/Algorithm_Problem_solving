#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> dusts;

struct node{
	int x;
	int y;
	int percent;
};

node LEFT[] = {{0, -2, 5}, {1, -1, 10}, {-1, -1, 10}, {-1, 0, 7}, {1, 0, 7}, {-2, 0, 2}, {2, 0, 2}, {-1, 1, 1}, {1, 1, 1}};
node RIGHT[] = {{0, 2, 5}, {-1, 1, 10}, {1, 1, 10}, {1, 0, 7}, {-1, 0, 7}, {2, 0, 2}, {-2, 0, 2}, {1, -1, 1}, {-1, -1, 1}};
node UP[] = {{-2, 0 , 5}, {-1, 1, 10}, {-1, -1, 10}, {0, -1, 7}, {0, 1, 7}, {0, -2, 2}, {0, 2, 2}, {1, -1, 1}, {1, 1, 1}};
node DOWN[] = {{2, 0 , 5}, {1, -1, 10}, {1, 1, 10}, {0, 1, 7}, {0, -1, 7}, {0, 2, 2}, {0, -2, 2}, {-1, 1, 1}, {-1, -1, 1}};


int next_dir(int dir){
	dir += 1;
	if(dir > 3){
		dir%=4;
	}
	return dir;
}


void sweep(int dir, int x, int y){
	int to_move = dusts[x][y];
	dusts[x][y] = 0;
	int conserve = to_move;
	
	if(dir == 0){
		for(int i= 0; i<9; i++){
			dusts[x + UP[i].x][y + UP[i].y] += to_move * UP[i].percent / 100;
			conserve -= to_move * UP[i].percent / 100;
		}
		dusts[x-1][y] += conserve;
	}
	if(dir == 1){
		for(int i= 0; i<9; i++){
			dusts[x + LEFT[i].x][y + LEFT[i].y] += to_move * LEFT[i].percent / 100;
			conserve -= to_move * LEFT[i].percent / 100;
		}
		dusts[x][y-1] += conserve;
	}
	if(dir == 2){
		for(int i= 0; i<9; i++){
			dusts[x + DOWN[i].x][y + DOWN[i].y] += to_move * DOWN[i].percent / 100;
			conserve -= to_move * DOWN[i].percent / 100;
		}
		dusts[x+1][y] += conserve;
	}
	if(dir == 3){
		for(int i= 0; i<9; i++){
			dusts[x + RIGHT[i].x][y + RIGHT[i].y] += to_move * RIGHT[i].percent / 100;
			conserve -= to_move * RIGHT[i].percent / 100;
		}
		dusts[x][y+1] += conserve;
	}
}

void tornado(int x, int y, int dir, int move){
	if(x == 2 && y == 1){
		return;
	}
	else{
		for(int i= 0; i<move; i++){
			if(dir == 0) x-=1;
			if(dir == 1) y-=1;
			if(dir == 2) x+=1;
			if(dir == 3) y+=1;
			sweep(dir, x, y);
			
			if(x == 2 && y == 2) return;
		}

		
		if(dir == 0 || dir == 2)
			tornado(x, y, next_dir(dir), move + 1);
		else
			tornado(x, y, next_dir(dir), move);
	}
}


int main() {
	cin>> n;
	
	dusts = vector<vector<int>>(n+4, vector<int>(n+4, 0));
	
	int start_x = n/2 + 2;
	int start_y = n/2 + 2;
	
	long long prev_sum = 0;
	
	for(int i= 0; i<n; i++){
		for(int j= 0; j<n; j++){
			int dust;
			cin>> dust;
			dusts[i+2][j+2] = dust;
			prev_sum += dust;
		}
	}
	
	tornado(start_x, start_y, 1, 1);
	
	long long sum = 0;
	
	for(int i= 0; i<n; i++){
		for(int j= 0; j<n; j++){
			sum += dusts[i+2][j+2];
		}
	}
	
	cout<<prev_sum - sum;
	
	return 0;
}