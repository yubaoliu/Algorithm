#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

struct BinaryNode
{
    int data;
    struct BinaryNode* left;
    struct BinaryNode* right;
    BinaryNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }        
};



#endif