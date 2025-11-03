#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;  // Base case: empty tree has depth 0

        int leftDepth = maxDepth(root->left);   // Find depth of left subtree
        int rightDepth = maxDepth(root->right); // Find depth of right subtree

        return 1 + max(leftDepth, rightDepth);  // Add current node to the max depth
    }
};

int main() {
    // Build sample tree:  1
    //                    / \
    //                   2   3
    //                  / \
    //                 4   5
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3)
    );

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "Max depth: " << depth << "\n";
    return 0;
}

