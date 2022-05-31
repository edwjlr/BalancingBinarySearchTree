#include <iostream>

//class binary tree node, also creates nodes
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
	
	std::cout << node->data << " ";
	PreOrderTraversal(node->left);
	PreOrderTraversal(node->right);
}

void InOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}
	
	InOrderTraversal(node->left);
	std::cout << node->data << " ";
	InOrderTraversal(node->right);
}

void PostOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}
	
	PostOrderTraversal(node->left);
	PostOrderTraversal(node->right);
	std::cout << node->data << " ";
}

Node* InsertNode(class Node* nodeMarker, int input){
	
	if (nodeMarker == NULL){
		return new Node(input);
	}else if (input < nodeMarker->data){
		nodeMarker->left = InsertNode(nodeMarker->left, input);
	}else if (input > nodeMarker->data){
		nodeMarker-> right = InsertNode(nodeMarker->right, input);
	}
	
}

int main(){
	
	Node* root = NULL;
	root = InsertNode(root, 1);
	InsertNode(root, 3);
	InsertNode(root, 2);
	InsertNode(root, 6);
	InsertNode(root, 7);
	InsertNode(root, 4);
	
	InOrderTraversal(root);
	std::cout << std::endl;
	PreOrderTraversal(root);
	std::cout << std::endl;
	PostOrderTraversal(root);
	
return 0;
}