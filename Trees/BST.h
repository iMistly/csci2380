#include <iostream>
using namespace std;

#include "treeNode.h"

// Class DemoTree
// Fill values correctly for the following
// {0, -6, 3, 1, 8, 7, 14}
//         0
//     -6      3
//          1     8
//               7  14
class DemoTree{
    public:
        TreeNode* root;

        DemoTree(){
            root = new TreeNode(0);
            root->left = new TreeNode(-6);
            root->right = new TreeNode(3);
            root->right->left = new TreeNode(1);
            root->right->right = new TreeNode(8);
            root->right->right->left = new TreeNode(7);
            root->right->right->right = new TreeNode(14);
        }

        // Assuming the max height is 1
        // Check if tree is empty, if yes, return 0
        // Check if the root has a child node, if no, add 1 to the leaf counter and stop
        // Check if left has a child node on either side, if no, add 1 to the leaf counter
        // Check if right has a child node on either side, if no, add 1 to the leaf counter
        int countOneLevelLeaves(){
            int leaves{};
            if (root == nullptr){
                return 0;
            }
            else if (root->left == nullptr && root->right == nullptr){
                return 1;
            }
            if (root->left != nullptr){
                leaves += 1;
            }
            if (root->right != nullptr){
                leaves += 1;
            }
            return leaves;
        }

        // Recursive solutions...
            // Count all the odd numbers in the tree
};