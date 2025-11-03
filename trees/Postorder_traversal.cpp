#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;      
    }
private:
    void postorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};

int main() {
    // Tree:    1
    //         / \
    //        2   3
    //       / \
    //      4   5
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3)
    );

    Solution sol;
    vector<int> res = sol.postorderTraversal(root);
    cout << "Postorder: ";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i + 1 < res.size()) cout << ",";
    }
    cout << "\n";
    return 0;
}
