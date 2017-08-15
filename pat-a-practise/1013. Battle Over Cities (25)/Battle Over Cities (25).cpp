#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
	int n, m, k, a, b;
	int road[1000][1000] = {0};
	int concern[1000] = {0}, visited[1001] = {0};
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

		int count = 0;
		int start = 1;
		visited[concern[i]] = 1;
		for(int c = 1; c <= n; c ++){
			if(visited[c] == 0 && c != start){
				count ++;
				start = c;
			}
			else{
				continue;
			}
			visited[c] == 1;
			for(int a = 1; a <= n; a ++){
				if(visited[a] == 0 && (road[start][a] == 1 || road[a][start] == 1)){
					visited[a] = 1;
					start = a;
				}
			}
		}
		cout << count - 1;
		if(i != k - 1){
			cout << endl;
		}
	}
	return 0;
}