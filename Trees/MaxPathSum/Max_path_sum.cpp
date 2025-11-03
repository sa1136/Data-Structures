#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Compute max gain from left and right subtrees, ignore negative paths
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));

        // Check the maximum path that passes through this node
        int pathSum = node->val + leftGain + rightGain;

        // Update global maximum path sum
        maxSum = max(maxSum, pathSum);

        // Return the max gain to continue upward
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Tree with positive values
    //        1
    //       / \
    //      2   3
    TreeNode* root1 = new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3)
    );
    
    int result1 = sol.maxPathSum(root1);
    cout << "Test 1 - Tree [1,2,3]: " << result1 << endl; // Expected: 6
    
    // Test case 2: Tree with negative values
    //        -10
    //       /  \
    //      9   20
    //         /  \
    //        15   7
    Solution sol2;
    TreeNode* root2 = new TreeNode(-10,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7))
    );
    
    int result2 = sol2.maxPathSum(root2);
    cout << "Test 2 - Tree [-10,9,20,null,null,15,7]: " << result2 << endl; // Expected: 42
    
    // Test case 3: Single node
    Solution sol3;
    TreeNode* root3 = new TreeNode(-3);
    int result3 = sol3.maxPathSum(root3);
    cout << "Test 3 - Single node [-3]: " << result3 << endl; // Expected: -3
    
    return 0;
}

