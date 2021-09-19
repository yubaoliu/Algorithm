// https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
#include "../include/BinaryTree.h"
#include <iostream>

int main()
{
    // create root
    struct BinaryNode* root = new BinaryNode(1);
    
    root->left = new BinaryNode(2);
    root->right = new BinaryNode(3);
    root->left->left = new BinaryNode(4);

    std::cout<<"Done"<<std::endl;
    return 0;
}