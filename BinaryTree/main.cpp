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
node* findMin(node* parent);

int main(int argc, const char * argv[]) {
    
    
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
    
    if(currentNode->value == value){
        if(parent->isRoot && currentNode->isRoot){
            if(currentNode->leftNode == NULL && currentNode->rightNode == NULL && currentNode->quantity <= 1){
                currentNode->value = NULL;
                currentNode->quantity = 0;
            }else{
                currentNode->quantity--;
            }
        }else{
            if(currentNode->leftNode == NULL && currentNode->rightNode == NULL){
                if(currentNode->value > parent->value)
                    parent->rightNode = NULL;
                else
                    parent->leftNode = NULL;
            }else{
                if(currentNode->leftNode == NULL){
                    if(currentNode->value > parent->value)
                        parent->rightNode = currentNode->rightNode;
                    else
                        parent->leftNode = currentNode->rightNode;
                }else if(currentNode->rightNode == NULL){
                    if(currentNode->value > parent->value)
                        parent->rightNode = currentNode->leftNode;
                    else
                        parent->leftNode = currentNode->leftNode;
                }else{//two children
                    
                }
                    
            }
                
        }
    }else if(parent->value > value){
        findAndRemove(currentNode, currentNode->leftNode, value);
    }else{
        findAndRemove(currentNode, currentNode->rightNode, value);
    }
}//end findAndRemove


node* findMin(node* parent){
    if(parent->leftNode == NULL)
        return parent;
    else
        findMin(parent->leftNode);
    //build fails if I don't have a return outside of conditional statements. Code shoulde never reach here:
    parent->value = NULL;
    return parent;
}//end findMin
