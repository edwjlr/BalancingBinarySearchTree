#include <iostream>
#include "tree.h"

int main(){
	//Build Tree
	Tree tree;

	std::string userInput;
	int userValue = -1;
	while(userInput != "exit"){
		std::cout << "1 - Insert new value" << std::endl;
		std::cout << "2 - Remove a value" << std::endl;
		std::cout << "3 - Display Tree" << std::endl;
		std::cout << "4 - Balance Tree" << std::endl;
		std::cout << "5 - Print Traversal" << std::endl;
		std::cout << "6 - Search value" << std::endl;
		std::cin >> userInput;
		if(userInput == "1"){
			std::cout << "Enter int to add to bst: ";
			std::cin >> userValue;
			tree.Insert(userValue);
			std::cout << std::endl;
		}else if (userInput == "2"){
			std::cout << "Value to remove: ";
			std::cin >> userValue;
			tree.Remove(userValue);
			std::cout << std::endl;
		}else if (userInput == "3"){
			tree.Display();
			std::cout << std::endl;
			std::cout << std::endl;
		}else if (userInput == "4"){
			tree.Balance();
			std::cout << "Tree Balanced" << std::endl;
			std::cout << std::endl;
		}else if (userInput == "5"){
			std::cout << "1 - Pre Order Traversal" << std::endl;
			std::cout << "2 - In Order Traversal" << std::endl;
			std::cout << "3 - Post Order Traversal" << std::endl;
			std::cin >> userInput;
			if (userInput == "1"){
				tree.PreOrderTraversal();
			}if (userInput == "2"){
				tree.InOrderTraversal();
			}if (userInput == "3"){
				tree.PostOrderTraversal();
			}
			std::cout << std::endl;
		}else if (userInput == "6"){
			std::cout << "Value to search: ";
			std::cin >> userValue;
			if (tree.Search(userValue)){
				std::cout << "Value found" << std::endl;
			}else{
				std::cout << "Value not found" << std::endl;
			}
		}
				std::cout << std::endl;
	}
/*
	tree.Insert(20);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(8);
	tree.Insert(4);
	tree.Insert(7);

	tree.Remove(1);
	tree.Remove(3);
	tree.Remove(2);
	tree.Remove(6);
	tree.Remove(8);
	tree.Remove(4);
	tree.Remove(7);
	
	Print Tree Traversal
	std::cout << "InOrder Traversal: ";
	tree.InOrderTraversal();
	std::cout << std::endl << "PreOrder Traversal: ";
	tree.PreOrderTraversal();
	std::cout << std::endl << std::endl;
	std::cout << std::endl << "PostOrder Traversal: ";
	tree.PostOrderTraversal();
	std::cout << std::endl;

	//Searching for value
	std::cout << "Search: " << tree.Search(20) << std::endl;

	std::cout << "Height: " << tree.Height(8) << std::endl;


	std::cout << "Root: " << tree.getRoot() << std::endl;
	tree.Balance();
	std::cout << "Root: " << tree.getRoot() << std::endl;

	Print Tree Traversal
	std::cout << "InOrder Traversal: ";
	tree.InOrderTraversal();
	std::cout << std::endl << "PreOrder Traversal: ";
	tree.PreOrderTraversal();
	std::cout << std::endl << "PostOrder Traversal: ";
	tree.PostOrderTraversal();
	std::cout << std::endl;
	tree.Display();
	*/
	
return 0;
}