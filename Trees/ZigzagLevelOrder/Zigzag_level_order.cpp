#include <vector>
#include <queue>
#include <iostream>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // direction flag

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // find position to fill value
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                // push child nodes into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // after this level, change the direction
            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Build sample tree:      3
    //                       / \
    //                      9   20
    //                         / \
    //                        15  7
    TreeNode* root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7))
    );

    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    cout << "Zigzag Level Order:" << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j + 1 < result[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < result.size()) cout << endl;
    }
    cout << endl;
    
    // Expected output:
    // [3]
    // [20,9]
    // [15,7]
    
    return 0;
}

