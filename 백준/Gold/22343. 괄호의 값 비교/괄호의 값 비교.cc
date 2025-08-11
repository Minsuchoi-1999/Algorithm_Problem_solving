#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <stack>
#include <climits>
#include <cstdint>

int N;

void stacking(std::string& s, std::vector<int>& arr){
    int depth = 0;
    int maxDepth = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            depth++;
            maxDepth = std::max(maxDepth, depth);
        } else { // ')'
            if (s[i-1] == '(') {
                arr[depth-1]++;
            }
            depth--;
        }
    }

    for(int i = 0; i<1500000; i++){
        if(arr[i]/2 > 0){
            arr[i+1] += arr[i]/2;
            arr[i] %= 2;
        }
    }
}

int compare(std::vector<int>& arr1, std::vector<int>& arr2){
    for(int j = 1500000 - 1; j>=0; j--){
        if(arr1[j] > arr2[j]){
            return -1;
        }
        else if(arr1[j] < arr2[j]){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;

    for(int i = 0; i< N; i++){    
        std::string s1, s2;
        std::cin>> s1 >> s2;

        std::vector<int> arr1(2000000, 0);
        std::vector<int> arr2(2000000, 0);

        stacking(s1, arr1);
        stacking(s2, arr2);

        //printf("i1 : %lld, i2: %lld\n", i1, i2);

        // for(int i= 0; i<10; i++){
        //     std::cout<<arr1[i]<<" ";
        // }std::cout<<"\n";

        // for(int i= 0; i<10; i++){
        //     std::cout<<arr2[i]<<" ";
        // }std::cout<<"\n";


        if(compare(arr1, arr2) == -1){
            std::cout<<">\n";
        }
        else if(compare(arr1, arr2) == 0){
            std::cout<<"=\n";
        }
        else{
            std::cout<<"<\n";
        }
    }
}
