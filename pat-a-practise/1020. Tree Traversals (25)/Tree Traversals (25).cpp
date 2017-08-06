#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node * left;
	Node * right;
	Node(){
		data = -1;
		left = NULL;
		right = NULL;
	}
};

Node * create(int post[], int in[], int postL, int postR, int inL, int inR){
	if(postL > postR){
		return NULL;
	}
	Node  * root = new Node;
	root->data = post[postR];
	int k;
	for(k = inL; k <= inR; k ++){
		if(in[k] == root->data){
			break;
		}
	}
	int divide = k - inL;
	root->left = create(post, in, postL, postL + divide - 1, inL, k - 1);
	root->right = create(post, in , postL + divide, postR - 1, k + 1, inR);
	return root;
}

int main(int argc, char * argv[]){
	int post[30], in[30], n;
	queue<Node *> t;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> post[i];
	}
	for(int i = 0; i < n; i++){
		cin >> in[i];
	}
	Node * tree = create(post, in, 0, n -1 , 0, n -1 );
	if(tree == NULL){
		cout << 0;
		return 0;
	}
	t.push(tree);
	while(!t.empty()){
		Node * node = t.front();
		t.pop();
		if(node->left != NULL) t.push(node->left);
		if(node->right != NULL) t.push(node->right);
		cout << node->data;
		if(!t.empty()){
			cout << " ";
		}
	}
	return 0;
}