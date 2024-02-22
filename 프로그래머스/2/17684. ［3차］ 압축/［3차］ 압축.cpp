#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dict;

vector<int> solution(string msg) {
    int index = 26;
    
    for(int i= 0; i<26; i++){
        string s;
        s+= i + 'A';
        dict[s] = i+1;
    }
    
    vector<int> answer;
   
    for(int i= 0; i<msg.size(); i++){
        string s;
        s += msg[i];
        
        for(int j= i+1; j<msg.size() ; j++){
           if(dict[s + msg[j]] != 0){
               s+= msg[j];
               if(j == msg.size()-1){
                    i = j;
               }
           }
           else{
               dict[s+msg[j]] = ++index;
               i = j-1;
               break;
           }
        }
        answer.push_back(dict[s]);
        
    }
    
    
    return answer;
}