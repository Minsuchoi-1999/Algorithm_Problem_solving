#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

map<string, long long> visited;
vector<pair<string, long long>> answer;

long long str_to_day(string date){
	long long month = (date[5]-'0')*10+ date[6]-'0';
	long long day = 0;
	
	for(long long i= 0; i<month; i++){
		day += days[i];	
	}
	day += (date[8]-'0')*10 + date[9]-'0';
	
	return day; 
}

long long str_to_minute(string time){
	long long hour =  (time[0]-'0')*10 + time[1]-'0'; 
	long long minute = (time[3]-'0')*10 + time[4]-'0';
	
	return hour*60+minute;
}

map<pair<string, string>, long long> dict;

signed main() {
	long long num_of_queries, deadline, penalty;
	cin>> num_of_queries;
	
	string str_deadline;
	cin>>str_deadline;
	
	long long day = (str_deadline[0]-'0')*100 + (str_deadline[1]-'0')*10 + str_deadline[2]-'0';
	long long hour =  (str_deadline[4]-'0')*10 + str_deadline[5]-'0'; 
	long long minute = (str_deadline[7]-'0')*10 + str_deadline[8]-'0';
	
	deadline = day*60*24 + hour*60 + minute;
	
	cin>> penalty;
	
	for(long long i= 0; i<num_of_queries; i++){
		string date, time, div, person;
		cin>> date>>time>>div>>person;
		
		long long q_minute = str_to_minute(time);
		long long q_day = str_to_day(date);
		
		if(dict[{div, person}] == 0){
			dict[{div, person}] = q_day*60*24 + q_minute;	
		}
		else{
			long long borrow_min = q_day*60*24 + q_minute - dict[{div, person}];
			if(borrow_min > deadline){
				visited[person] += (borrow_min - deadline) * penalty;
			}
			dict[{div, person}] = 0;
		}
	}
	
	if(visited.size() == 0){
		cout<<"-1";
	}
	else{
		for(auto iter : visited){
			cout<<iter.first<<" "<<iter.second<<"\n";
		}
	}
	
	return 0;
}