#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, char * argv[]){
	int n, m, in, des;
	int city[500] = {0}, len[500][500] = {0}, hashTable[500][500] = {0};
	scanf("%d %d %d %d", &n, &m, &in, &des);
	for(int i = 0; i < n; i++){
		scanf("%d", &city[i]);
	}
	for(int i = 0; i < m; i++){
		int s, d;
		scanf("%d %d", &s, &d);
		scanf("%d", &len[s][d]);
	}
	int count = 0, max = 0, l = 0;;
	int min = 0;
	if(len[in][des] != 0){
		count ++;
		min = city[i];
	}
	int start = in;
	for(int i = 0; i < 500; i++){
		if((hashTable[start][i] == 0 && hashTable[i][start] == 0) && len[start][i] != 0){
			max += len[start][i];
			l += city[i];
			start = i;
			hashTable[start][i] = 1;
			hashTable[i][start] = 1;
			if(i == des){
				count ++;
				continue;
			}
		}
		if(min < l){
			min = l;
		}
	}
		
	printf("%d %d", count, min);
	cin >> n;
	return 0;
}
