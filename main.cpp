#include <iostream>
#include "tree.h"

int main(){
	//Build Tree
	Tree tree;
	tree.Insert(1);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(8);
	tree.Insert(4);
	tree.Insert(7);

	// tree.RemoveNode(7);
	// tree.RemoveNode(1);
	// tree.RemoveNode(3);
	// tree.RemoveNode(4);
	// tree.RemoveNode(8);
	// tree.RemoveNode(6);
	// tree.RemoveNode(2);
	
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