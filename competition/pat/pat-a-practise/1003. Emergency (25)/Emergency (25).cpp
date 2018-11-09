#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(int argc, char * argv[]){
	//n:城市个数,m边条数
	//dis:点到其他点的最短距离
	//weight:每个城市的权重
	//w:到其他城市的权重和
	//num:最短路径条数
	//e,路径长度
	//visit:访问标记
	//c1,c2:初始城市和目的城市
	
	
	int n, m, c1, c2, dis[500], weight[500],num[500] = {0}, w[500] = {0}, e[500][500];
	int inf = INT_MAX;
	bool visit[500] = {false};
	fill(dis, dis + 500, inf);
	fill(e[0], e[0] + 500*500, inf);
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; i++){
		scanf("%d", &weight[i]);
	}
	int a, b, c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		e[b][a] = e[a][b] = c;
	}
	
	//dis[c1] = 0;表示出发点
	dis[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;
	
	for(int i = 0; i< n; i++){
		int u = -1, min = inf;
		for(int j = 0; j < n; j++){
			if(visit[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		if(u == -1){
			break;
		}
		visit[u] = true;
		for(int v = 0; v < n; v++){
			if(visit[v] == false && e[u][v] != inf){
				if(dis[u] + e[u][v] < dis[v]){
					dis[v] = dis[u] + e[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if(dis[u] + e[u][v] == dis[v]){
					num[v] += num[u];
					if(w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}

	printf("%d %d", num[c2], w[c2]);
	return 0;
}
