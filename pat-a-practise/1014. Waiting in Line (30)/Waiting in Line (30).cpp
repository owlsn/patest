#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int main(int argc, char * argv[]){
	int n, max, k, q, index = 0, count = 0;
	cin >> n >> max >> k >> q;
	queue<int> *qu = new queue<int>[n];
	int *cost = new int[k], *person = new int[q], *out = new int[k];
	for(int i = 0; i < k; i ++){
		cin >> cost[i];
	}
	for(int i = 0; i < q; i ++){
		cin >> person[i];
	}
	for(int i = 0; i < k ;i ++){
		int temp = -1, min = max;
		for(int j = 0; j < n; j ++){
			if(qu[j].size() < max){
				if(qu[j].size() < min){
					//cout << "qu:" << j  << "is min"<< endl;;
					temp = j;
					min = qu[j].size();
				}
			}
			else{
				if(count == n){
					//cout << "qu:"<< j << "is full" << endl;
					continue;
				}
			}
		}
		if(temp != -1){
			qu[temp].push(i);
			count ++;
			//cout << "qu:" << temp << "push" << i << endl;
		}
	}
	index = count;
	//cout << "index is " << index << endl;
	for(int i = 0; i < 9 * 60; i ++){
		int min = max, temp = -1;
		for(int j = 0; j < n; j ++){
			if(!qu[j].empty()){
				//cout << "qu[j].front() left " << (cost[qu[j].front()] - 1) << endl;
				if(-- cost[qu[j].front()]  == 0){
					//cout << "person:" << qu[j].front() << "pop" << endl;
					out[qu[j].front()] = i + 1;
					qu[j].pop();
					continue;
				}
			}
			if(qu[j].size() < max){
				if(qu[j].size() < min){
					//cout << "qu:" << j << "is min" << endl;
					temp = j;
					min = qu[j].size();
				}
			}
		}
		if(temp != -1){
			//cout << "qu:" << temp << "push" << index;
			qu[temp].push(index ++ );
		}
	}
	for(int i = 0; i < q; i ++){
		if(out[person[i] - 1] == 0){
			cout << "Sorry";
		}
		else{
			printf("%02d:%02d", 8 + out[person[i] - 1]/60, out[person[i] - 1]%60);
		}
		if(i != q - 1){
			cout << endl;
		}
	}
	return 0;
}