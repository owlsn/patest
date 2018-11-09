#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

struct person_time{
	string ID;
	int hour;
	int min;
	int sec;
};

person_time format(string in_time, string ID){
	person_time in;
	in.ID = ID;
	int length = 0, start = 0, time[3] = {0}, v = 0;
	for(int j = 0; j < in_time.length(); j++){
		if(in_time[j] == ':'){
			if(v == 0){
				in.hour = atoi(in_time.substr(start, length).c_str());
			}
			else if(v == 1){
				in.min = atoi(in_time.substr(start, length).c_str());
			}
			v ++;
			start = j + 1;
			length = 0;
		}
		else{
			length ++;
		}
	}
	in.sec = atoi(in_time.substr(start, length).c_str());
	return in;
}

int main(int argc, char * argv[]){
	int num = 0;
	vector<person_time> p;
	string id = "", in_time ="", left_time = "";
	cin >> num;
	for(int i = 0; i < num; i++){
		cin >> id >> in_time >> left_time;
		person_time in, left;
		in = format(in_time, id);
		left = format(left_time, id);
		p.push_back(in);
		p.push_back(left);
	}
	person_time max, min;
	max.hour = min.hour = 0;
	max.min = min.min = 0;
	max.sec = min.sec = 0;
	if(p.size()){
		min = p[0];
	}
	for(vector<person_time>::iterator it = p.begin(); it != p.end(); it++){
		string id = (*it).ID;
		if((*it).hour > max.hour){
			max = *it;
		}
		else if((*it).hour == max.hour){
			if((*it).min > (*it).min){
				max = *it;
			}
			else if((*it).min == (*it).min){
				if((*it).sec > (*it).sec){
					max = *it;
				}
			}
		}

		if((*it).hour < min.hour){
			min = *it;
		}
		else if((*it).hour == min.hour){
			if((*it).min < (*it).min){
				min = *it;
			}
			else if((*it).min == (*it).min){
				if((*it).sec < (*it).sec){
					min = *it;
				}
			}
		}
	}
	cout << min.ID << " "<< max.ID;
	return 0;
}