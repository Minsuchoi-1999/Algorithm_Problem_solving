#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int minimum = 1000000001; 
    int min_index;
    
    stack<int> st;
    stack<int> st2;
    
    for(int i= 0; i<a.size(); i++){
        if(minimum > a[i]){
            minimum = a[i];
            min_index = i;
        }
    }
    
    cout<<minimum<<" "<<min_index;

    
    for(int i= min_index -1 ; i>=0; i--){
        if(st.empty()){
            st.push(a[i]);
        }    
        else{
            if(st.top() > a[i]){
                while(!st.empty() && a[i] < st.top()){
                    st.pop();
                }
            }
            st.push(a[i]);
        }
    }
    
    for(int i= min_index ; i<a.size(); i++){
        if(st2.empty()){
            st2.push(a[i]);
        }    
        else{
            if(st2.top() > a[i]){
                while(!st2.empty() && a[i] < st2.top()){
                    st2.pop();
                }
            }
            st2.push(a[i]);
        }
    }
    
    return st.size() + st2.size();
}