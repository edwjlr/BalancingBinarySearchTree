#include "tree.h"

Tree::Tree(){
    root = nullptr;
}

Tree::~Tree(){
	while(root!= nullptr){
		Remove(root, root->getData());
	}
    delete root;
}

void Tree::PreOrderTraversal(){
	if (root == nullptr){
		std::cout << "Empty Tree";
	}else{
		PreOrderTraversal(root);
	}
	return;
}

void Tree::InOrderTraversal(){
	if (root == nullptr){
		std::cout << "Empty Tree";
	}else{
		InOrderTraversal(root);
	}
	return;
}

void Tree::PostOrderTraversal(){
	if (root == nullptr){
		std::cout << "Empty Tree";
	}else{
		PostOrderTraversal(root);
	}
	return;
}

void Tree::PreOrderTraversal(Node *node){
	if (node == nullptr){
		return;
	}

	// print current node -> recur left subtree -> recur right subtree
	std::cout << node->getData() << " ";
	PreOrderTraversal(node->left);
	PreOrderTraversal(node->right);
}

void Tree::InOrderTraversal(Node *node){
	if (node == nullptr){
		return;
	}
	
	// recur left subtree -> print current node -> recur right subtree
	InOrderTraversal(node->left);
	std::cout << node->getData() << " ";
	InOrderTraversal(node->right);
}

void Tree::PostOrderTraversal(Node *node){
	if (node == nullptr){
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

Node *Tree::Insert(Node *node, int input){
    //base case: at empty node
	if (node == nullptr){
		node = new Node(input);
		if (root == nullptr){
		    root = node;
        }
    }
    //case 1: value is less than that of the current node
	else if (input < node->getData()){
		Node *temp = Insert(node->left, input);
		node->left = temp;
		temp->parent = node;
    }
    //case 2: value is great than that of the current node
	else if (input > node->getData()){
		Node *temp = Insert(node->right, input);
		node->right = temp;
		temp->parent = node;
	}
	return node;
}

void Tree::Remove(int input){
	Remove(root, input);
}

void Tree::Remove(Node *node, int input){
    //base case: empty node
	if (node == nullptr){
		free(node);
//		return;
	}
    //case 1: found node to remove
	else if (input == node->getData()){
		//case 1, no children
		if (node->left == nullptr && node->right == nullptr){
            //case 1: node is root
			if (node->parent == nullptr){
				root = nullptr;
			}
            //case 2: node is right child
			else if (node->parent->right == node){
				node->parent->right = nullptr;
            }
            //case 3: node is left child
			else{
				node->parent->left = nullptr;
			}
			free(node);
//			return;
		}
		//case 2, 1 children
		else if ((node->left!=nullptr && node->right==nullptr) || (node->left==nullptr && node->right!=nullptr)){
			//if node->right != null
			//node->parent->child(left/right) = node->right
			//node->right->parent = node -> parent

            //case 1: removing root node
			if (node->parent == nullptr){
                //set correct child to root and remove parent pointer
				if (node->left != nullptr){
					root = node->left;
                    root->parent = nullptr;
				}else{
					root = node->right;
                    root->parent = nullptr;
				}
			}
            //case 2: left is the only child
			else if (node->left != nullptr ){
                //set child's parent to node's parent
				node->left->parent = node->parent;
                //set node parent to point to nodes only child instead of node
				if (node->parent->right == node){
					node->parent->right = node->left;
				}else{
					node->parent->left = node->left;
				}
			}
            //case 3: right is the only child
            else if (node->right != nullptr){
                //set child parent to node's parent
				node->right->parent = node->parent;
                //set parent child to nodes child
				if (node->parent->right == node){
					node->parent->right = node->right;
				}else{
					node->parent->left = node->right;
				}
			}
			free (node);
//			return;

		//case 3, 2 children - makes Remove into case 1 or case 2
		}else if ((node->left!=nullptr) && (node->right!=nullptr)){
			//find successor node->right->->->left
			Node *temp = node->right;
			while(temp->left != nullptr){
				temp = temp->left;
			}
            //replace node to delete data with successor
            node->setData(temp->getData());
            //call remove on successor
            //Remove will take care  of freeing *temp
			Remove(temp, temp->getData());
//			return;
		}
    //case 2: value to remove is less than that of current node
	}else if (input < node->getData()){
		Remove(node->left, input);
    //case 3: value to remove is greater than that of current node
	}else if (input > node->getData()){
		Remove(node->right, input);
	}
    return;
}

bool Tree::Search(int value){
   return Search(root, value);
}

bool Tree::Search(Node *node, int value){
    //Base case: not correct node
    if (node == nullptr){
        return false;
    }
    //case 1: found correct node
    else if (node->getData() == value){
        return true;
    }
    //case 2: value < node's value
    else if (value < node->getData() && node->left != nullptr){
        return Search(node->left, value);
    }
    //case 3: value > node's value
    else if (value > node->getData() && node->right != nullptr){
        return Search(node->right, value);

    }
    return false;
}

Node* Tree::SearchNode(Node* node, int value){
    //Base case: not correct node
    if (node == nullptr){
        return nullptr;
    }
    //case 1: found correct node
    else if (node->getData() == value){
        return node;
    }
    //case 2: value < node's value
    else if (value < node->getData() && node->left != nullptr){
        return SearchNode(node->left, value);
    }
    //case 3: value > node's value
    else if (value > node->getData() && node->right != nullptr){
        return SearchNode(node->right, value);

    }
    return nullptr;
}

int Tree::Height(int value){
    //return max height of value
    return Height(SearchNode(root, value));
}

int Tree::Height(Node *node){
    //base case: empty node
    if(node == nullptr){
        return 0;
    }else{
        //recursively find height
        int leftHeight = Height(node->left);
        int rightHeight = Height(node->right);
        //return biggest subtree height
        return std::max(leftHeight, rightHeight) + 1;
    }
}

void Tree::BuildVector(Node *node, std::vector<int> &nodesVector){
	if (node == nullptr){
		return;
	}
	
	// recur left subtree -> pushback node -> recur right subtree
	BuildVector(node->left, nodesVector);
	nodesVector.push_back(node->getData());
	BuildVector(node->right, nodesVector);
}

 void Tree::BalanceTree(std::vector<int> &nodesVector, int start, int end){
    //base case
    if (start > end){
        return;
    }
	
    //insert middle node
    int mid = (start + end)/2;
    Insert(nodesVector[mid]);

	//call on left subtree
    BalanceTree(nodesVector, start, mid-1);
	//call on right subtree
    BalanceTree(nodesVector, mid+1, end);
}

void Tree::Balance(){
    std::vector<int> nodesVector;
    BuildVector(root, nodesVector);
	while(root!= nullptr){
		Remove(root, root->getData());
	}
    int end = nodesVector.size() - 1;
	BalanceTree(nodesVector, 0, end);
	return;
}

void Tree::Display(){
	Display(1, root);
	return;
}

//http://www.cplusplus.com/forum/beginner/265166/
void Tree::Display(int level, Node *node){
	int i;
	if (node != NULL)
	{
		Display(level + 1, node->right);
		std::cout << std::endl;
		if (node == root){
			std::cout << "Root -> ";
		}
		for (i = 0; i < level && node != root; i++){
			std::cout << "        ";
		}
		std::cout << node->getData() << '(';
		if(node != root && node->parent != nullptr){
			std::cout << node->parent->getData();
		}
		std::cout << ')';

		Display(level + 1, node->left);
	}
	return;
}