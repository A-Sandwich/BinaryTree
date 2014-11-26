//
//  main.cpp
//  BinaryTree
//
//  Created by Kyle Burkholder on 11/3/14.
//  Copyright (c) 2014 Kyle Burkholder. All rights reserved.
//

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class BinaryTree{
private:
    struct node{
        int value = NULL;
        int quantity = 1;
        node* leftNode = NULL;
        node* rightNode = NULL;
        bool isRoot = false;
        bool traversed = false;
    };
    node* root;
    node* findMin(node* parent);
    node* findParentMin(node* parent, int value);
    void positionAndInsertNode(node* root, node* newNode);
    void findAndRemove(node* parent, node* currentNode, int value);
    node* createAndInitNode(int value);
    void inOrderTraversal(node* root);

    
public:
    void iOT();
    BinaryTree(int rootValue);
    void insert(int num);
    void remove(int num);

};

BinaryTree::BinaryTree(int rootValue){
    root = new node;
    root->isRoot = true;
    root->quantity = 1;
    root->value = rootValue;
    root->traversed = false;
    
}

void BinaryTree::iOT(){
    inOrderTraversal(root);
}

void BinaryTree::insert(int num){
    positionAndInsertNode(root, createAndInitNode(num));
}

void BinaryTree::remove(int num){
    findAndRemove(root, root, num);
}

int main(int argc, const char * argv[]) {

    int randomNum;
    int size = 500;
    int* usedNumber = new int[size];
    srand(time(NULL));
    int rootValue = rand() % 1000 + 1;
    BinaryTree* myTree = new BinaryTree(rootValue);
    for(int i = 0; i < size; i++){
         randomNum = rand() % 1000 + 1;
        usedNumber[i] = randomNum;
        cout << randomNum << " ";
        myTree->insert(randomNum );//1 - 1000
    }
    cout << endl << " |||| " << endl;
    for(int i = 0; i < size; i++){
        if(i % 2 == 0 && usedNumber[i] != rootValue){
            myTree->remove(usedNumber[i]);
        }
    }
    /*positionAndInsertNode(root, createAndInitNode(30));
    positionAndInsertNode(root, createAndInitNode(20));
    positionAndInsertNode(root, createAndInitNode(40));
    //positionAndInsertNode(root, createAndInitNode(25));
    //positionAndInsertNode(root, createAndInitNode(15));
    positionAndInsertNode(root, createAndInitNode(35));
    //positionAndInsertNode(root, createAndInitNode(45));
    //positionAndInsertNode(root, createAndInitNode(100));
    findAndRemove(root, root, 30);
    //1,5,99,100,101,150,199*/
    myTree->iOT();
    //cout << root->value <<", "<<root->rightNode->value<<", "<<root->rightNode->rightNode->value;

}

void BinaryTree::inOrderTraversal(node* root){
    if(root->leftNode != NULL && !root->leftNode->traversed){
        inOrderTraversal(root->leftNode);
    }

    if(!root->traversed){
        cout << root->value <<", ";
        root->traversed = true;
    }

    if(root->rightNode != NULL && !root->rightNode->traversed){
        inOrderTraversal(root->rightNode);
    }
}

BinaryTree::node* BinaryTree::createAndInitNode(int value){
    node* newNode = new node;
    newNode->isRoot = false;
    newNode->value = value;
    newNode->quantity = 1;
    return newNode;
}



/*
 * Traverses tree and inserts node or iterates count.
 */
void BinaryTree::positionAndInsertNode(node* parent, node* newNode){
    if(parent->value > newNode->value){
        if(parent->leftNode == NULL)
            parent->leftNode = newNode;
        else
            positionAndInsertNode(parent->leftNode, newNode);
    }else if(parent->value < newNode->value){
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
void BinaryTree::findAndRemove(node* parent, node* currentNode, int value){
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
                if(currentNode->quantity > 1){
                    currentNode->quantity--;
                }else{
                    if(currentNode->value > parent->value)
                        parent->rightNode = NULL;
                    else
                        parent->leftNode = NULL;
                }
            }else if(currentNode->quantity > 1){
                currentNode->quantity--;
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
                    node* replacementNode = findMin(currentNode->rightNode);
                    node* parentOfReplacement;

                    if(currentNode->rightNode->value == replacementNode->value)
                        parentOfReplacement = currentNode;
                    else
                        parentOfReplacement = findParentMin(currentNode->rightNode, replacementNode->value);
                    currentNode->value = replacementNode->value;
                    currentNode->quantity = replacementNode->quantity;
                    if(parentOfReplacement->rightNode != NULL){
                        if(parentOfReplacement->rightNode->value == replacementNode->value)
                            parentOfReplacement->rightNode = replacementNode->rightNode;
                    }
                    if(parentOfReplacement->leftNode != NULL){
                        if(parentOfReplacement->leftNode->value == replacementNode->value){
                            parentOfReplacement->leftNode = replacementNode->rightNode;
                        }
                    }
                }

            }

        }
    }else if(currentNode->value > value){
        findAndRemove(currentNode, currentNode->leftNode, value);
    }else{
        findAndRemove(currentNode, currentNode->rightNode, value);
    }
}//end findAndRemove


BinaryTree::node* BinaryTree::findMin(node* parent){
    if(parent->leftNode == NULL)
        return parent;
    else
        return findMin(parent->leftNode);
    //build fails if I don't have a return outside of conditional statements. Code shoulde never reach here:
    //parent->value = NULL;
    //return parent;
}//end findMin

BinaryTree::node* BinaryTree::findParentMin(node* parent, int value){
    node* temp;
    if(parent->leftNode != NULL){
            temp = parent->leftNode;
        if(temp->value == value)
            return parent;
        else
            return findParentMin(temp, value);
    }else if(parent->value == value){
        return parent;
    }else{
        cout << "FAIL";

        return NULL;
    }
}
