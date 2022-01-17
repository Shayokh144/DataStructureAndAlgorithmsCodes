//
//  main.cpp
//  BinarySearchTree
//
//  Created by Asif on 18/01/22.
//

#include<iostream>
#define NULL 0

using namespace std;

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
}TreeNode;

TreeNode* createNewNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertTreeNode(TreeNode*& root, int value) {
    
    if (root == NULL) {
        root = createNewNode(value);
    }
    else {
        TreeNode* newNode = createNewNode(value);
        TreeNode* curNode = root;
        while (true) {
            if (value < curNode->val) {
                // left
                if (curNode->left == NULL) {
                    curNode->left = newNode;
                    return;
                }
                else {
                    curNode = curNode->left;
                }
            }
            else {
                // right
                if (curNode->right == NULL) {
                    curNode->right = newNode;
                    return;
                }
                else {
                    curNode = curNode->right;
                }
            }
        }
    }
}

bool searchValueInTree(TreeNode* root,int value) {
    if (root == NULL) {
        return false;
    }
    
    else{
        TreeNode* curNode = root;
        while (true) {
            if (value == curNode->val) {
                return true;
            }
            else if (value < curNode->val) {
                if (curNode->left == NULL) {
                    return false;
                }
                else {
                    curNode = curNode->left;
                }
            }
            else {
                if (curNode->right == NULL) {
                    return false;
                }
                else {
                    curNode = curNode->right;
                }
            }
        }
    }
    return false;
}

TreeNode* getMinValueNodeFromTree(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

bool deleteValueFromTree(TreeNode*& root, int value) {
    if (root == NULL) {
        return false;
    }
    bool isDeleted = true;
    if (value < root->val) {
        isDeleted = deleteValueFromTree(root->left, value);
    }
    else if (value > root->val) {
        isDeleted = deleteValueFromTree(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            // no child
            root = NULL;
            return true;
        }
        else if (root->left == NULL) {
            // only right child exist
            root->val = root->right->val;
            root = root->right;
        }
        else if (root->right == NULL) {
            // only left child exist
            root->val = root->left->val;
            root = root->left;
        }
        else {
            // both child exist
            TreeNode* minNode = getMinValueNodeFromTree(root->right);
            root->val = minNode->val;
            return deleteValueFromTree(root->right, root->val);
        }
    }
    return isDeleted;
}

void inorderTravarse(TreeNode* root) {
    if (root != NULL) {
        inorderTravarse(root->left);
        cout << root->val << " ";
        inorderTravarse(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    insertTreeNode(root, 10);
    insertTreeNode(root, 15);
    insertTreeNode(root, 5);
    insertTreeNode(root, 2);
    insertTreeNode(root, 12);
    insertTreeNode(root, 1);
    insertTreeNode(root, 3);
    insertTreeNode(root, 13);
    insertTreeNode(root, 14);
    inorderTravarse(root);
    cout << "\n";
    int d;
    cout << "enter number for delete: ";
    cin >> d;
    bool isDeleted = deleteValueFromTree(root, d);
    if (isDeleted == true) {
        cout << "True" << "\n";
    }
    else {
        cout << "False" << "\n";
    }
    
    inorderTravarse(root);
    cout << "\n";
    return 0;
}
