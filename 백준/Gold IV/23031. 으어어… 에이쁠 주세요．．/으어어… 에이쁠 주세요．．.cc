#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int row;
char ahri_dir = 'D';
pair<int,int> ahri = {0, 0};

vector<pair<pair<int, int>, char>> zombies;

void move(){
	switch(ahri_dir){
		case 'D' : if(ahri.first + 1 <row) ahri.first++; break;
		case 'U' : if(ahri.first -1 >= 0)ahri.first--;  break;
		case 'L' : if(ahri.second -1 >= 0) ahri.second--; break;
		case 'R' : if(ahri.second +1 < row) ahri.second++; break;
	}
}

void turn_left(){
	switch(ahri_dir){
		case 'D' : ahri_dir = 'R'; break;
		case 'U' : ahri_dir = 'L'; break;
		case 'L' : ahri_dir = 'D'; break;
		case 'R' : ahri_dir = 'U'; break;
	}
}

void turn_right(){
	switch(ahri_dir){
		case 'D' : ahri_dir = 'L'; break;
		case 'U' : ahri_dir = 'R'; break;
		case 'L' : ahri_dir = 'U'; break;
		case 'R' : ahri_dir = 'D'; break;
	}
	
}

void z_move(pair<pair<int, int>, char>& zombie){
	switch(zombie.second){
		case 'D' : {
			if(zombie.first.first + 1 <row){ zombie.first.first++;}
			else{zombie.second = 'U';}
			break;
		}
		case 'U' : {
			if(zombie.first.first -1 >= 0){ zombie.first.first--;}
			else{zombie.second = 'D';}
			break;
		}
			
		}
	
}

void zombies_move(){
	for(int i= 0; i<zombies.size(); i++){
		z_move(zombies[i]);
	}
}

signed main() {
	cin>> row;
	
	string str;
	cin>> str;

	vector<vector<char>> maze(row, vector<char>(row));
	vector<vector<bool>> light(row, vector<bool>(row, false));
	
	for(int i= 0; i<row; i++){
		string rows;
		cin>> rows;
		
		for(int j= 0; j<rows.size(); j++){
			maze[i][j] = rows[j];
			
			if(maze[i][j] == 'Z'){
				zombies.push_back({{i, j}, 'D'});
			}
		}
	}
	
	for(int index= 0; index<str.size(); index++){
		switch(str[index])
		{
			case 'F' : move(); break;
			case 'L' : turn_left(); break;
			case 'R' : turn_right(); break;
		}
		
		int i = ahri.first;
		int j= ahri.second;
		
		if(maze[i][j] == 'S'){
			if(i-1>=0){
				if(j-1>=0) light[i-1][j-1] = true;
				if(j+1<row) light[i-1][j+1] = true;
				light[i-1][j] = true;
			}
			if(i+1<row){
				if(j-1>=0) light[i+1][j-1] = true;
				if(j+1<row) light[i+1][j+1] = true;
				light[i+1][j] = true;
			}
			if(j-1>=0){
				light[i][j-1] = true;
			}
			if(j+1<row){
				light[i][j+1] = true;
			}
			light[i][j] = true;
		}

	//	cout<<ahri.first<<" "<<ahri.second<<"\n";
		
		for(int z=0; z<zombies.size(); z++){
	//		cout<<zombies[z].first.first<<" "<<zombies[z].first.second<<"\n\n";
			 if(light[i][j] == false && zombies[z].first.first == ahri.first && zombies[z].first.second == ahri.second){
			 	cout<<"Aaaaaah!";
			 	exit(0);
			 }
		}
		
		zombies_move();
		
		for(int z=0; z<zombies.size(); z++){
	//		cout<<zombies[z].first.first<<" "<<zombies[z].first.second<<"\n\n";
			 if(light[i][j] == false && zombies[z].first.first == ahri.first && zombies[z].first.second == ahri.second){
			 	cout<<"Aaaaaah!";
			 	exit(0);
			 }
		}
		
	}
	
	cout<<"Phew...";
	
	return 0;
}