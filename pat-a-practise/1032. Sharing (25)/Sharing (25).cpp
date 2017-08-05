#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
	char c;
	int next;
	bool flag;
};

int main(int argc, char * argv[]){
	int n, temp, next, head1, head2;
	char s; 
	Node node[100010];
	cin >> head1 >> head2;
	cin >> n;
	for(int i =0; i < n; i++){
		cin >> temp >> s >> next;
		node[temp].c = s;
		node[temp].next = next;
		node[temp].flag = false;
	}
	for(int h1 = head1; h1 != -1; h1 = node[h1].next){
		node[h1].flag = true;
	}
	int result = -1;
	for(int h2 = head2; h2 != -1; h2 = node[h2].next){
		if(node[h2].flag == true){
			result = h2;
			break;
		}
	}
	if(result != -1){
		printf("%05d", result);
	}
	else{
		cout << -1;
	}
	return 0;
}