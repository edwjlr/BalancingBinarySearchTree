#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    public:
        Node(int value){
            data = value;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
        Node(){
            parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
        ~Node(){
            delete parent;
            delete left;
            delete right;
        }
        
        int getData(){
            return data;
        }
        void setData(int value){
            data  = value;
        }


        Node *parent;
        Node *left;
        Node *right;

    private:
        int data;
};

#endif