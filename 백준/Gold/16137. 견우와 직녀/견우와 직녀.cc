#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 987654321
 
using namespace std;
 
int n, m;
int ans = MAX;
 
int mat[11][11];
int isVisited[11][11];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
 
vector<pair<int, int> > bridges;
 
 
bool is_valid(int y, int x){
    return (y>=0 && y<n) && (x>=0 && x<n);
}
 
// 교차 절벽인지 확인  
bool is_avail(int y, int x){
    if(is_valid(y+1, x) && is_valid(y, x+1) && mat[y+1][x]==0 && mat[y][x+1]==0) return false;
    if(is_valid(y, x+1) && is_valid(y-1, x) && mat[y][x+1]==0 && mat[y-1][x]==0) return false;
    if(is_valid(y-1, x) && is_valid(y, x-1) && mat[y-1][x]==0 && mat[y][x-1]==0) return false;
    if(is_valid(y, x-1) && is_valid(y+1, x) && mat[y][x-1]==0 && mat[y+1][x]==0) return false;
    return true;
}
 
 
void bfs(){
    memset(isVisited, 0, sizeof(isVisited));
    queue<pair<pair<int, int>, pair<int, int> > > q; // y, x, time, crossed
    q.push({{0,0}, {0,0}});
    isVisited[0][0] = 1;
    
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int ct = q.front().second.first;
        int flag = q.front().second.second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int ny = cy + dir[d][0];
            int nx = cx + dir[d][1];
            
            // 종 료  
            if(ny==n-1 && nx==n-1){
                ans = min(ans, ct+1);
                return;
            }
            
            if(!is_valid(ny, nx)) continue;
            if(isVisited[ny][nx]) continue;
            
            // 절벽이면 무시한다. 
            if(mat[ny][nx]==0) continue;
            // 일반 땅이면 그냥 간다. 
            else if(mat[ny][nx]==1){
                isVisited[ny][nx] = 1;
                q.push({{ny, nx}, {ct+1, 0}});
            }
            // 오작교가 만들어질 곳이면 이전에 오작교를 건넜는지 확인한다. 
            else if(mat[ny][nx]>=2 && !flag){
                if((ct+1) % mat[ny][nx] == 0){ // 지금 시간이 오작교 생성시간이라면 건넌다. 
                    isVisited[ny][nx] = 1;
                    q.push({{ny, nx}, {ct+1, 1}});
                }
                else{// 오작교 생성시간이 아니라면 기다려본다. 더 빠르게 갈 수도 있다. 
                    q.push({{cy, cx}, {ct+1, 0}});
                }
            }
        }
        
        
    }
}
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    
    // 교차되는 절벽을 제외한 절벽들 찾기  
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0 && is_avail(i, j)) 
                bridges.push_back({i, j}); 
        }
    }
    
    // 절벽 하나 하나에 오작교 놓아보기  
    for(int i=0; i<bridges.size(); i++){
        mat[bridges[i].first][bridges[i].second] = m;
        bfs();
        mat[bridges[i].first][bridges[i].second] = 0;
    }
    
    cout << ans << endl;
}