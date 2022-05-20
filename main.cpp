#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int value){
			data = value;
			left = NULL;
			right = NULL;
		}
};

void PreOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}
	
	cout << node->data << " ";
	InOrderTraversal(node->left);
	InOrderTraversal(node->right);
}

void InOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}
	
	InOrderTraversal(node->left);
	cout << node->data << " ";
	InOrderTraversal(node->right);
}

void PostOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}
	
	InOrderTraversal(node->left);
	InOrderTraversal(node->right);
	cout << node->data << " ";
}

int main(){
	
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	
	InOrderTraversal(root);
	cout << endl;
	PreOrderTraversal(root);
	cout << endl;
	PostOrderTraversal(root);
	
return 0;
}