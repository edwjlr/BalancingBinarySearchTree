#include <iostream>
#include "tree.h"

int main(){
	//Build Tree
	Tree tree;
	// tree.Insert(20);
	// tree.Insert(3);
	// tree.Insert(2);
	// tree.Insert(6);
	// tree.Insert(8);
	// tree.Insert(4);
	// tree.Insert(7);

	// tree.Remove(1);
	// tree.Remove(3);
	// tree.Remove(2);
	// tree.Remove(6);
	// tree.Remove(8);
	// tree.Remove(4);
	// tree.Remove(7);
	
	//Print Tree Traversal
	std::cout << "InOrder Traversal: ";
	tree.InOrderTraversal();
	std::cout << std::endl << "PreOrder Traversal: ";
	tree.PreOrderTraversal();
	std::cout << std::endl << "PostOrder Traversal: ";
	tree.PostOrderTraversal();
	std::cout << std::endl;

	//Searching for value
	std::cout << "Search: " << tree.Search(20) << std::endl;
	
return 0;
}