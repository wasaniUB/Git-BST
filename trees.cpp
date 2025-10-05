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
void insertIterative(BSTNode*& root, int value);
bool searchRecursive(BSTNode* root, int key);
bool searchIterative(BSTNode* root, int key);
void inorderPrint(BSTNode* root);
void freeTree(BSTNode* root);

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

void insertIterative(BSTNode*& root, int value) {
    if(!root) {
        root = new BSTNode(value);
        return;
    }
      
     BSTNode* cur = root;
     BSTNode* parent = nullptr;

      while(cur) {
        parent = cur;

         if(value < cur->data) {
            cur = cur->left;
         }

          else if(value > cur->data) {
            cur = cur->right;
          }

          else {
            return;
        }
      }

      if(value < parent->data) {
        parent->left = new BSTNode(value);
      }

      else{
        parent->right = new BSTNode(value);
      }

}

bool searchRecursive(BSTNode* root, int key) {
    if(!root) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key < root->data) {
        return searchRecursive(root->left, key);
    }

    else{
        return searchRecursive(root->right, key);
    }

}

bool searchIterative(BSTNode* root, int key) {
    BSTNode* cur = root;

     while(cur) {
        if(key == cur->data) {
            return true;
        }

        if(key < cur->data) {
            cur = cur->left;
        }

         else {
            cur = cur->right;
         }
     }
       return false;
}

void inorderPrint(BSTNode* root) {
    if(!root) {
        return;
    }

    inorderPrint(root->left);
     cout << root->data << " ";
    inorderPrint(root->right);
}

void freeTree(BSTNode* root) {
    if(!root){
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}