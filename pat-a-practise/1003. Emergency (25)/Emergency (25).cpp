#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(int argc, char * argv[]){
	//n:���и���,m������
	//dis:�㵽���������̾���
	//weight:ÿ�����е�Ȩ��
	//w:���������е�Ȩ�غ�
	//num:���·������
	//e,·������
	//visit:���ʱ��
	//c1,c2:��ʼ���к�Ŀ�ĳ���
	
	
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
	
	//dis[c1] = 0;��ʾ������
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
