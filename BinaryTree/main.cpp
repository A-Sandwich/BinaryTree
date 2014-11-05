//
//  main.cpp
//  BinaryTree
//
//  Created by Kyle Burkholder on 11/3/14.
//  Copyright (c) 2014 Kyle Burkholder. All rights reserved.
//

#include <iostream>

using namespace std;

struct node{
    int value = NULL;
    int quantity = 1;
    node* leftNode = NULL;
    node* rightNode = NULL;
};

void positionAndInsertNode(node* root, int value);
void findAndRemove(node* parent, int value);

int main(int argc, const char * argv[]) {
    node* root = new node;
    node* left = new node;
    node* right = new node;
    
    
    std::cout << "Hello, World!\n" << endl;
    return 0;
}

/*
 * Traverses tree and inserts node or iterates count.
 */
void positionAndInsertNode(node* parent, node* newNode){
    if(parent->value < newNode->value){
        if(parent->leftNode == NULL)
            parent->leftNode = newNode;
        else
            positionAndInsertNode(parent->leftNode, newNode);
    }else if(parent->value > newNode->value){
        if(parent->rightNode == NULL)
            parent->rightNode = newNode;
        else
            positionAndInsertNode(parent->rightNode, newNode);
    }else{
        parent->quantity++;
    }
        
}//end insertNode

/*
 * traverses tree and if the node exists it either decrements quantity or removes node.
 */
void findAndRemove(node* parent, int value){
    
}//end findAndRemove
