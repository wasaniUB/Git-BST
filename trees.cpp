#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

     BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
     }
};

void insertRecursive(BSTNode*& root, int value);

int main() {


    return 0;
}

void insertRecursive(BSTNode*& root, int value) {
    if(!root) {
        root = new BSTNode(value);
        return;
    }

     if(value < root->data) {
        insertRecursive(root->left, value);
     }

     else if(value > root->data) {
        insertRecursive(root->right, value);
     }
}