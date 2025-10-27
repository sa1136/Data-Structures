#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, result);
        return result;
    }
    
    int dfs(TreeNode* node, vector<vector<int>>& result) {
        if (!node) return -1; // base case: null nodes have height -1
        
        int left = dfs(node->left, result);
        int right = dfs(node->right, result);
        
        int height = 1 + max(left, right);
        
        if (result.size() <= height) {
            result.push_back({});
        }
        result[height].push_back(node->val);
        
        return height;
    }
};

// Helper function to create a binary tree for testing
TreeNode* createTestTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

TreeNode* createTestTree2() {
    TreeNode* root = new TreeNode(1);
    return root;
}

TreeNode* createTestTree3() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: Tree with multiple levels
    cout << "Test Case 1:" << endl;
    TreeNode* root1 = createTestTree1();
    /*
        1
       / \
      2   3
     / \
    4   5
    */
    vector<vector<int>> result1 = solution.findLeaves(root1);
    cout << "Input: [1,2,3,4,5]" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << "Explanation: Leaves are [4,5,3], then [2], then [1]" << endl << endl;
    
    // Test Case 2: Single node
    cout << "Test Case 2:" << endl;
    TreeNode* root2 = createTestTree2();
    /*
        1
    */
    vector<vector<int>> result2 = solution.findLeaves(root2);
    cout << "Input: [1]" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << "Explanation: Only one leaf [1]" << endl << endl;
    
    // Test Case 3: Complete binary tree
    cout << "Test Case 3:" << endl;
    TreeNode* root3 = createTestTree3();
    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
    */
    vector<vector<int>> result3 = solution.findLeaves(root3);
    cout << "Input: [1,2,3,4,5,6,7]" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << "Explanation: Leaves are [4,5,6,7], then [2,3], then [1]" << endl << endl;
    
    return 0;
}
