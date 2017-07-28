#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;


int main(int argc, char * argv[]){
	int n, m, in, des;
	int inf = INT_MAX;
	int city[500] = {0}, len[500][500] = {0};
	int dis[500] = {0};
	for(int i = 0; i< 500; i++){
		for(int j = 0; j < 500; j++){
			if(i == j){
				len[i][j] = 0;
			}
			else{
				len[i][j] = inf;
			}
		}
	}
	scanf("%d %d %d %d", &n, &m, &in, &des);
	for(int i = 0; i < n; i++){
		scanf("%d", &city[i]);
	}
	for(int i = 0; i < m; i++){
		int s, d;
		scanf("%d %d", &s, &d);
		scanf("%d", &len[s][d]);
	}
	int start = in;
	for(int i = 0; i < m; i++){
		dis[i] = len[start][i];
	}
	
	int visited[500] = {0};
	visited[start] = 1;
	int now;
	for(int i =0; i < n -1; i++){
		int min = inf;
		for(int j = 1; j < n; j++){
			if(visited[j] == 0 && dis[j] < min){
				min = dis[j];
				now = j;
			}
		}
		visited[now] = 1;
		for(int v = 0; v < n; v++){
			if(len[now][v] < inf && len[now][v] + dis[now] < dis[v]){
				dis[v] = dis[now] + len[now][v];
			}
		}
	}
	for(int i = 0; i < n; i ++){
		printf("%d:%d\t", i, dis[i]);
	}		
	cin >> n;
	return 0;
}
