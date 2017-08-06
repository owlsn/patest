#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int weight;
	vector<int> children;
	Node(){
		weight = 0;
	}
}node[100];

void DFS(Node root[], int index, int num, int count, vector<int> seq){
	seq.push_back(index);
	count += root[index].weight;
	if(root[index].children.size() == 0){
		if(count == num){
			for(int i = 0; i < seq.size(); i ++){
				cout << root[seq[i]].weight;
				if(i != seq.size() - 1){
					cout << " ";
				}
				else{
					cout << endl;
				}
			}
		}
	}
	else{
		for(int i = 0; i < root[index].children.size(); i ++){
			DFS(root, root[index].children[i], num, count, seq);
		}
	}
	seq.pop_back();
}

bool cmp(int a, int b){
	return node[a].weight > node[b].weight;
}

int main(int argc, char * argv[]){
	int total, nonleaf, num, temp, child, c;
	cin >> total >> nonleaf >> num;
	for(int i = 0; i < total; i++){
		cin >> node[i].weight;
	}
	for(int i = 0; i < nonleaf; i ++){
		cin >> temp >> child;
		for(int j = 0; j < child ; j++){
			cin >> c;
			node[temp].children.push_back(c);
		}
		sort(node[temp].children.begin(), node[temp].children.end(), cmp);
	}
	int count = 0;
	vector<int> seq;
	DFS(node, 0, num, count, seq);
	return 0;
}