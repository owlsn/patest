#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char * argv[]){
	int n, m; 
	int temp = 0;
	double n1[1001] = {0.0}, m1[1001] = {0.0};
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		cin >> n1[temp];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> temp;
		cin >> m1[temp];
	}
	int count = 0;
	double result[1001] = {0.0};
	for(int i = 0; i < 1001; i++){
		result[i] = n1[i] + m1[i];
		if(result[i] != 0.0){
			count ++ ;
		}
	}
	printf("%d", count);
	for(int i = 1000; i >= 0; i--){
		if(result[i] != 0.0){
			printf(" %d %.1f", i,result[i]);
		}
	}
	return 0;
}
