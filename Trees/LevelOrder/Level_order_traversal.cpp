#include <vector>
#include <queue>
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
    // Function to perform level-order
    // traversal of a binary tree
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Create a 2D vector to store levels
        vector<vector<int>> ans; 
        if (root == nullptr) {
            // If the tree is empty,
            // return an empty vector
            return ans; 
        }
        
        // Create a queue to store nodes
        // for level-order traversal
        queue<TreeNode*> q; 
        // Push the root node to the queue
        q.push(root); 

        while (!q.empty()) {
            // Get the size of the current level
            int size = q.size(); 
            // Create a vector to store
            // nodes at the current level
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                TreeNode* node = q.front(); 
                // Remove the front node from the queue
                q.pop(); 
                // Store the node value
                // in the current level vector
                level.push_back(node->val); 

                // Enqueue the child nodes if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            // Store the current level
            // in the answer vector
            ans.push_back(level); 
        }
        // Return the level-order
        // traversal of the tree
        return ans; 
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
    auto levels = sol.levelOrder(root);

    std::cout << "Level order:" << '\n';
    for (size_t i = 0; i < levels.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < levels[i].size(); ++j) {
            std::cout << levels[i][j];
            if (j + 1 < levels[i].size()) std::cout << ",";
        }
        std::cout << "]";
        if (i + 1 < levels.size()) std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}
#endif
