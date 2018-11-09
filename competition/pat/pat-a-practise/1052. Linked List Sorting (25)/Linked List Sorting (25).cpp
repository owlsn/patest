#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Node{
	int key;
	int address;
	int next;
	Node(){
		key = -10001;
		address = -1;
		next = -1;
	}
};

bool cmp(Node a, Node b){
	return a.key < b.key;
}

int main(int argc, char * argv[]){
	vector<Node> list;
	map<int, Node> m;
	int n, head, key, address, next;
	Node temp_node;
	cin >> n >> head;
	for(int i = 0; i < n; i++){
		cin >> address >> key >> next;
		temp_node.key = key;
		temp_node.next = next;
		temp_node.address = address;
		m[address] = temp_node;
	}
	int p = head;
	while(p != -1){
		list.push_back(m[p]);
		p = m[p].next;
	}
	if(list.size() == 0){
		cout << 0 << " " << -1;
		return 0;
	}
	sort(list.begin(), list.end(), cmp);
	cout << list.size() << " " ;
	printf("%05d", list[0].address);
	cout << endl;
	for(int i = 0; i < list.size(); i++){
		printf("%05d", list[i].address);
		cout << " " << list[i].key << " ";
		if(i != list.size() - 1){
			printf("%05d", list[i + 1].address);
			cout << endl;
		}
		else{
			cout << -1;
		}
	}
	return 0;
}