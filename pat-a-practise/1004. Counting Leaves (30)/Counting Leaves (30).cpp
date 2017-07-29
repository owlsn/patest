#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
	int node[101] = {0};
	int non_leaf[101] = {0}, level_num[101] = {0};
	int num, nonleaf, index, child_num, parent;
	cin >> num;
	cin >> nonleaf;
	if(num == 1){
		cout << 1;
	}
	else{
		for(int i = 0; i < nonleaf; i++){
		cin >> parent;
		non_leaf[parent] = 1;
		cin >> child_num;
		for(int j = 0; j < child_num; j++){
			cin >> index;
			node[index] = parent; 
		}
	}
	
	int level, depth = 0;
	for(int i = 1; i <= num; i++){
		if(non_leaf[i] == 0 && node[i] != 0){
			level = 0;
			parent = i;
			while(parent != 1){
				parent = node[parent];
				level ++;
			}
			level_num[level] ++;
			if(depth < level){
				depth = level;
			}
		}
	}
	for(int i = 0; i <= depth; i++){
		cout << level_num[i];
		if(i != depth){
			cout << ' ';
		}
	}
	}
	return 0;
}
