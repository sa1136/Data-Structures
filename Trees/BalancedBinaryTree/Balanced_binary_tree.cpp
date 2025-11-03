#include <iostream>
#include <algorithm>
#include <cmath>
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
    // Function to check if a binary tree is balanced
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

private:
    // Recursive function to calculate height
    int dfsHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) 
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Balanced tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* balancedTree = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3)
    );
    
    cout << "Test 1 - Balanced tree:" << endl;
    bool result1 = sol.isBalanced(balancedTree);
    cout << "Is balanced: " << (result1 ? "true" : "false") << endl;
    
    // Test case 2: Unbalanced tree
    //        1
    //       /
    //      2
    //     /
    //    3
    TreeNode* unbalancedTree = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), nullptr),
        nullptr
    );
    
    cout << "\nTest 2 - Unbalanced tree:" << endl;
    bool result2 = sol.isBalanced(unbalancedTree);
    cout << "Is balanced: " << (result2 ? "true" : "false") << endl;
    
    // Test case 3: Empty tree
    cout << "\nTest 3 - Empty tree:" << endl;
    bool result3 = sol.isBalanced(nullptr);
    cout << "Is balanced: " << (result3 ? "true" : "false") << endl;
    
    return 0;
}

