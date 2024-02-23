#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(long long i= 0; i*k <= d; i++){
        answer+=floor(sqrt(1.0*d*d/k/k - 1.0*i*i)) + 1;
    }
    
    return answer;
}