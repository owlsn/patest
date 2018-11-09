#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node * left;
	Node * right;
	Node(){
		data = 0;
		left = NULL;
		right = NULL;
	}
};

Node * insert(Node * &root, int data){
	if(root == NULL){
		root = new Node;
		root->data = data;
		return root;
	}
	if(data < root->data){
		insert(root->left, data);
	}
	else{
		insert(root->right, data);
	}
	return root;
}

Node * insertImage(Node * &root, int data){
	if(root == NULL){
		root = new Node;
		root->data = data;
		return root;
	}
	if(data >= root->data){
		insertImage(root->left, data);
	}
	else{
		insertImage(root->right, data);
	}
	return root;
}

void pre(Node * root, vector<int> &seq){
	if(root == NULL) return;
	seq.push_back(root->data);
	pre(root->left, seq);
	pre(root->right, seq);
	
}

void post(Node * root, vector<int> &seq){
	if(root == NULL)return ;
	post(root->left, seq);
	post(root->right, seq);
	seq.push_back(root->data);
}

int main(int argc, char * argv[]){
	int num, index;
	vector<int> seq, pre_seq, pre_image, post_seq;
	Node * root = NULL, * image_root = NULL;
	cin >> num;
	for(int i = 0; i < num; i ++){
		cin >> index;
		seq.push_back(index);
		root = insert(root, index);
		image_root = insertImage(image_root, index);
	}
	pre(root, pre_seq);
	pre(image_root, pre_image);
	bool flag = false;
	if(seq == pre_seq){
		flag = true;
		post(root, post_seq);
	}
	else if(seq == pre_image){
		flag = true;
		post(image_root, post_seq);
	}
	if(flag){
		cout << "YES" << endl;
		for(int i = 0; i < num; i++){
			cout << post_seq[i];
			if(i != num - 1){
				cout << " ";
			}
		}
	}
	else{
		cout << "NO";
	}
	return 0;
}