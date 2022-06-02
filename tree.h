#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree{
    public:
		void PreOrderTraversal();
		void InOrderTraversal();
		void PostOrderTraversal();
		void Insert(int);
		void RemoveNode(int);
        Tree();
        ~Tree();

    private:
		Node *root;

        void PreOrderTraversal(Node *);
		void InOrderTraversal(Node *);
		void PostOrderTraversal(Node *);
		Node *Insert(Node *, int);
		void RemoveNode(Node *, int);
};

#endif