#include "tree.h"

Tree::Tree(){
    root = nullptr;
}

Tree::~Tree(){
	while(root!= nullptr){
		RemoveNode(root, root->getData());
	}
    delete root;
}

void Tree::PreOrderTraversal(){
	if(root == nullptr){
		std::cout << "Empty Tree";
	}else{
		PreOrderTraversal(this->root);
	}
	return;
}

void Tree::InOrderTraversal(){
	if(root == nullptr){
		std::cout << "Empty Tree";
	}else{
		InOrderTraversal(this->root);
	}
	return;
}

void Tree::PostOrderTraversal(){
	if(root == nullptr){
		std::cout << "Empty Tree";
	}else{
		PostOrderTraversal(this->root);
	}
	return;
}

void Tree::PreOrderTraversal(Node* node){
	if(node == nullptr){
		return;
	}

	// print current node -> recur left subtree -> recur right subtree
	std::cout << node->getData() << " ";
	PreOrderTraversal(node->left);
	PreOrderTraversal(node->right);
}

void Tree::InOrderTraversal(Node* node){
	if(node == nullptr){
		return;
	}
	
	// recur left subtree -> print current node -> recur right subtree
	InOrderTraversal(node->left);
	std::cout << node->getData() << " ";
	InOrderTraversal(node->right);
}

void Tree::PostOrderTraversal(Node* node){
	if(node == nullptr){
		return;
	}
	
	// recur left subtree -> recur right subtree -> print current node
	PostOrderTraversal(node->left);
	PostOrderTraversal(node->right);
	std::cout << node->getData() << " ";
}

void Tree::Insert(int input){
	Insert(root, input);
}

Node* Tree::Insert(Node* node, int input){
	if (node == nullptr){
		node = new Node(input);
		if(root == nullptr)
		root = node;
	}else if (input < node->getData()){
		Node *temp = Insert(node->left, input);
		node->left = temp;
		temp->parent = node;
	}else if (input > node->getData()){
		Node *temp = Insert(node->right, input);
		node->right = temp;
		temp->parent = node;
	}
	return node;
}

void Tree::RemoveNode(int input){
	RemoveNode(root, input);
}

void Tree::RemoveNode(Node* node, int input){
	if (node == nullptr){
		free(node);
		return;
	}
	if (input == node->getData()){
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
            node->setData(temp->getData());
			RemoveNode(temp, temp->getData());
			return;
		}
	}else if (input < node->getData()){
		RemoveNode(node->left, input);
	}else if (input > node->getData()){
		RemoveNode(node->right, input);
	}

}