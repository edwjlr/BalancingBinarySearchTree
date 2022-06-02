#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <vector>

class Tree{
    public:
		void PreOrderTraversal();
		void InOrderTraversal();
		void PostOrderTraversal();
		void Insert(int);
		void Remove(int);
		bool Search(int);
		int Height(int);
		void Balance();
		int getRoot(){
			return root->getData();
		}
		void Display();
        Tree();
        ~Tree();

    private:
		Node *root;

        void PreOrderTraversal(Node *);
		void InOrderTraversal(Node *);
		void PostOrderTraversal(Node *);
		Node *Insert(Node *, int);
		void Remove(Node *, int);
		bool Search(Node *, int);
		int Height(Node *);
		Node *SearchNode(Node *, int);
		void BuildVector(Node *, std::vector<int> &);
		void BalanceTree(std::vector<int> &, int, int);
		void Display(int , Node *);
};

#endif