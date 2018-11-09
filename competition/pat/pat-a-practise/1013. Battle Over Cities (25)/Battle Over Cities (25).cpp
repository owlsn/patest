#include <iostream>
using namespace std;

int road[1000][1000] = {0};

void dfs(int root, int visited[], const int n){
	for(int i = 1; i <= n ; i++){
		//cout << "des:" << i << endl;
		if(visited[i] == 0 && (road[root][i] == 1 || road[i][root] == 1)){
			visited[i] = 1;
			dfs(i, visited, n);
		}
	}
}

int main(int argc, char * argv[]){
	int n, m, k, a, b;
	int concern[1000] = {0};
	cin >> n >> m >> k;
	for(int i = 0; i < m; i ++){
		cin >> a >> b;
		road[a][b] = 1;
	}
	for(int i = 0; i < k; i ++){
		cin >> concern[i];
	}
	for(int i = 0; i < k; i ++){
		int visited[1001] = {0};

		int count = 0, start = 0;
		visited[concern[i]] = 1;
		//cout << "concern[i]:" << concern[i] << endl;
		for(int c = 1; c <= n; c ++){
			if(visited[c] == 0){
				start = c;
			}
			else{
				continue;
			}
			visited[start] == 1;
			//cout << "start:" << start << endl;
			dfs(start, visited, n);
			count ++ ;
		}
		if(count > 0){
			cout << count - 1;
		}
		else{
			cout << 0;
		}
		if(i != k - 1){
			cout << endl;
		}
	}
	return 0;
}