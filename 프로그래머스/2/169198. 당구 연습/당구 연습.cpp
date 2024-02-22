#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int left(int m, int n, int startX, int startY, int endX, int endY){
    endX = -endX;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

int right(int m, int n, int startX, int startY, int endX, int endY){
    endX = 2*m - endX;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

int down(int m, int n, int startX, int startY, int endX, int endY){
    endY = -endY;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

int up(int m, int n, int startX, int startY, int endX, int endY){
    endY = 2*n - endY;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

int leftdown(int m, int n, int startX, int startY, int endX, int endY){
    startX = -startX;
    startY = -startY;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

int rightup(int m, int n, int startX, int startY, int endX, int endY){
    startX = 2*m -startX;
    startY = 2*n -startY;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

int leftup(int m, int n, int startX, int startY, int endX, int endY){
    startX = -startX;
    startY = 2*n -startY;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

int rightdown(int m, int n, int startX, int startY, int endX, int endY){
    startX = 2*m -startX;
    startY = -startY;
    return (startX-endX)*(startX-endX) + (startY-endY)*(startY-endY);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i= 0; i<balls.size(); i++){
        int endX = balls[i][0];
        int endY = balls[i][1];
        
        int dist = INT_MAX;
        
        if(endX == startX){
            if(endY > startY){
                dist = min(dist, (endY + startY)*(endY + startY));    
            }
            else{
                dist = min(dist, (2*n - startY -endY) * (2*n - startY -endY));
            }
            dist = min(dist, left(m, n , startX, startY, endX, endY));
            dist = min(dist, right(m, n , startX, startY, endX, endY));
        }
        else if(endY == startY){
            if(endX > startX){
                dist = min(dist, (endX + startX) * (endX + startX));    
            }
            else{
                dist = min(dist, (2*m - startX - endX) * (2*m - startX - endX));
            }
            dist = min(dist, up(m, n , startX, startY, endX, endY));
            dist = min(dist, down(m, n , startX, startY, endX, endY));
        }
        else if((m*startY == n*startX) && (m*endY == n*endX)){
            if(endY > startY){ 
                dist = min(dist, leftdown(m, n , startX, startY, endX, endY));    
            }
            else{
                dist = min(dist, rightup(m, n , startX, startY, endX, endY));
            }
            dist = min(dist, left(m, n , startX, startY, endX, endY));
            dist = min(dist, right(m, n , startX, startY, endX, endY));
            dist = min(dist, up(m, n , startX, startY, endX, endY));
            dist = min(dist, down(m, n , startX, startY, endX, endY));
        }
       else if((m*startY == -n*startX + 2*n*m) && (m*endY == -n*endX)+ 2*n*m){
            if(endY > startY){ 
                dist = min(dist, leftup(m, n , startX, startY, endX, endY));    
            }
            else{
                dist = min(dist, rightdown(m, n , startX, startY, endX, endY));
            }
            dist = min(dist, left(m, n , startX, startY, endX, endY));
            dist = min(dist, right(m, n , startX, startY, endX, endY));
            dist = min(dist, up(m, n , startX, startY, endX, endY));
            dist = min(dist, down(m, n , startX, startY, endX, endY));
        }
        else{
            dist = min(dist, left(m, n , startX, startY, endX, endY));
            dist = min(dist, right(m, n , startX, startY, endX, endY));
            dist = min(dist, up(m, n , startX, startY, endX, endY));
            dist = min(dist, down(m, n , startX, startY, endX, endY));
        }
        
        cout<<left(n, m, startX, startY, endX, endY) <<" "<<right(n, m, startX, startY, endX, endY)<<" "<<up(n, m, startX, startY, endX, endY)<<" "<<down(n, m, startX, startY, endX, endY)<<"\n";
        answer.push_back(dist);
    }
    return answer;
}