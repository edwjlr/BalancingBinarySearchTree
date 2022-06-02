#include <iostream>

//class binary tree node, also creates nodes
class Node{
	public:
		int data;
		Node* parent;
		Node* left;
		Node* right;
		Node* root;
		void PreOrderTraversal();
		void InOrderTraversal();
		void PostOrderTraversal();
		void Insert(int );
		void RemoveNode(int );
		
		Node(int value){
			data = value;
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			root = nullptr;
		}
		Node(){
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			root = nullptr;
		}

	private:
		void PreOrderTraversal(Node*);
		void InOrderTraversal(Node*);
		void PostOrderTraversal(Node*);
		Node* Insert(Node*, int);
		void RemoveNode(Node*, int);
};

void Node::PreOrderTraversal(){
	PreOrderTraversal(this->root);
}

void Node::InOrderTraversal(){
	InOrderTraversal(this->root);
}

void Node::PostOrderTraversal(){
	PostOrderTraversal(this->root);
}

void Node::PreOrderTraversal(class Node* node){
	if(node == nullptr){
		return;
	}

	// print current node -> recur left subtree -> recur right subtree
	std::cout << node->data << " ";
	PreOrderTraversal(node->left);
	PreOrderTraversal(node->right);
}

void Node::InOrderTraversal(class Node* node){
	if(node == nullptr){
		return;
	}
	
	// recur left subtree -> print current node -> recur right subtree
	InOrderTraversal(node->left);
	std::cout << node->data << " ";
	InOrderTraversal(node->right);
}

void Node::PostOrderTraversal(class Node* node){
	if(node == nullptr){
		return;
	}
	
	// recur left subtree -> recur right subtree -> print current node
	PostOrderTraversal(node->left);
	PostOrderTraversal(node->right);
	std::cout << node->data << " ";
}

void Node::Insert(int input){
	Insert(root, input);
}

Node* Node::Insert(class Node* node, int input){
	if (node == nullptr){
		node = new Node(input);
		if(root == nullptr)
		root = node;
	}else if (input < node->data){
		Node *temp = Insert(node->left, input);
		node->left = temp;
		temp->parent = node;
	}else if (input > node->data){
		Node *temp = Insert(node->right, input);
		node->right = temp;
		temp->parent = node;
	}
	return node;
}

void Node::RemoveNode(int input){
	RemoveNode(root, input);
}

void Node::RemoveNode(class Node* node, int input){
	if (node == nullptr){
		return;
	}
	if (input == node->data){
		//case 1, no children
		if (node->left == nullptr && node->right == nullptr){
			if(node->parent == nullptr){
				root = nullptr;
			}
			else if(node->parent->right == node){
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
			if (node->parent == nullptr){
				if(node->left != nullptr){
					node->left->parent = nullptr;
					root = node->left;
				}else{
					node->right->parent = nullptr;
					root = node->right;
				}
			}
			else if(node->left != nullptr ){
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
	Node tree;
	tree.Insert(1);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(8);
	tree.Insert(4);
	tree.Insert(7);

	tree.RemoveNode(7);
	
	//Print Tree Traversal
	std::cout << "InOrder Traversal: ";
	tree.InOrderTraversal();
	std::cout << std::endl << "PreOrder Traversal: ";
	tree.PreOrderTraversal();
	std::cout << std::endl << "PostOrder Traversal: ";
	tree.PostOrderTraversal();
	std::cout << std::endl;
	
return 0;
}