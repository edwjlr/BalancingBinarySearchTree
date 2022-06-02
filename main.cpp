#include <iostream>

//class binary tree node, also creates nodes
class Node{
	public:
		int data;
		Node* parent;
		Node* left;
		Node* right;
		
		Node(int value){
			data = value;
			parent = NULL;
			left = NULL;
			right = NULL;
		}
};

void PreOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}

	// print current node -> recur left subtree -> recur right subtree
	std::cout << node->data << " ";
	PreOrderTraversal(node->left);
	PreOrderTraversal(node->right);
}

void InOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}
	
	// recur left subtree -> print current node -> recur right subtree
	InOrderTraversal(node->left);
	std::cout << node->data << " ";
	InOrderTraversal(node->right);
}

void PostOrderTraversal(class Node* node){
	if(node == NULL){
		return;
	}
	
	// recur left subtree -> recur right subtree -> print current node
	PostOrderTraversal(node->left);
	PostOrderTraversal(node->right);
	std::cout << node->data << " ";
}

Node* InsertNode(class Node* node, int input){
	
	if (node == NULL){
		return new Node(input);
	}else if (input < node->data){
		Node *temp = InsertNode(node->left, input);
		node->left = temp;
		temp->parent = node;
	}else if (input > node->data){
		Node *temp = InsertNode(node->right, input);
		node->right = temp;
		temp->parent = node;
	}
	return node;
}

void RemoveNode(class Node* node, int input){
	if (node == NULL){
		return;
	}
	if (input == node->data){
		//case 1, no children
		if (node->left == nullptr && node->right == nullptr){
			if(node->parent->right == node){
				node->parent->right = nullptr;
			}else{
				node->parent->left = nullptr;
			}
			free(node);
			return;
		}
		//case 2, 1 children
		else if ((node->left!=nullptr && node->right==nullptr) || (node->left==nullptr && node->right!=nullptr)){
			//if node->right != null
			//node->parent->child(left/right) = node->right
			//node->right->parent = node -> parent

			if(node->left != nullptr ){
				node->left->parent = node->parent;
				if(node->parent->right == node){
					node->parent->right = node->left;
				}else{
					node->parent->left = node->left;
				}
			}else if (node->right != nullptr){
				node->right->parent = node->parent;
				if(node->parent->right == node){
					node->parent->right = node->right;
				}else{
					node->parent->left = node->right;
				}
			}
			free (node);
			return;

		//case 3, 2 children
		}else if ((node->left!=nullptr) && (node->right!=nullptr)){
			//find successor node->right->->->left
			Node *temp = node->right;
			while(temp->left != nullptr){
				temp = temp->left;
			}
			node->data = temp->data;
			RemoveNode(temp, temp->data);
			return;
		}
	}else if (input < node->data){
		RemoveNode(node->left, input);
	}else if (input > node->data){
		RemoveNode(node->right, input);
	}

}


int main(){
	//Build Tree
	Node* root = NULL;
	root = InsertNode(root, 1);
	InsertNode(root, 3);
	InsertNode(root, 2);
	InsertNode(root, 6);
	InsertNode(root, 8);
	InsertNode(root, 4);
	InsertNode(root, 7);

	RemoveNode(root, 7);
	
	//Print Tree Traversal
	std::cout << "InOrder Traversal: ";
	InOrderTraversal(root);
	std::cout << std::endl << "PreOrder Traversal: ";
	PreOrderTraversal(root);
	std::cout << std::endl << "PostOrder Traversal: ";
	PostOrderTraversal(root);
	std::cout << std::endl;
	
return 0;
}