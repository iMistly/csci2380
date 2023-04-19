#include<iostream>
using namespace std;

#include "treeNode.h"

int main(){
    TreeNode* root = new TreeNode(4);

    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(0);
    // root->right->left = new TreeNode(1);
    // root->right->right = new TreeNode(3);
    // root->right->right->left = new TreeNode(5);

    UniqueTree tree(root);
    int input{};
    cout << "Enter a number: ";
    cin >> input;
    while(!cin.fail()){
        tree.addNode(new TreeNode(input));
        cout << "Enter a number: ";
        cin >> input;
    }

    return 0;
}