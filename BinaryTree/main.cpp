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
    bool isRoot = false;
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
void findAndRemove(node* parent, node* currentNode, int value){
    
    if(parent->value == value){
        if(parent->isRoot && currentNode->isRoot){
            if(parent->leftNode == NULL && parent->rightNode == NULL && currentNode->quantity <= 1){
                parent->value = NULL;
                parent->quantity = 0;
            }else{
                parent->quantity--;
            }
        }else{
            
        }
    }else if(parent->value > value){
        findAndRemove(currentNode, currentNode->leftNode, value);
    }else{
        findAndRemove(currentNode, currentNode->rightNode, value);
    }
}//end findAndRemove
