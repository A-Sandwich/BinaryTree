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
    string name = "default";
    node* leftNode = NULL;
    node* rightNode = NULL;
};

int main(int argc, const char * argv[]) {
    node* root = new node;
    node* left = new node;
    node* right = new node;
    root->name = "root";
    
    
    std::cout << "Hello, World!\n" << endl;
    cout << root->name << ", " << root->leftNode->name;
    return 0;
}
