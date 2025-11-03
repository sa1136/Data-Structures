#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; 
        preorder(root, result);
        return result;
    }
    
private:
    void preorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return; // use 'nullptr' instead of 'null'
        result.push_back(root->val); // store the value instead of print
        preorder(root->left, result);
        preorder(root->right, result);
    }
};

#ifdef __APPLE__
#include <iostream>
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
    vector<int> res = sol.preorderTraversal(root);

    std::cout << "Preorder: ";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i + 1 < res.size()) std::cout << ",";
    }
    std::cout << "\n";
    return 0;
}
#endif
