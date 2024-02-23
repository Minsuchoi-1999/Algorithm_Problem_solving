#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i= 1; i<n; i++){
        int sum = i;
        for(int j= i+1; sum + j<=n; j++){
            sum += j;           
            if(sum == n){
                answer+=1;
            }
        }
    }
    
    return answer + 1;
}