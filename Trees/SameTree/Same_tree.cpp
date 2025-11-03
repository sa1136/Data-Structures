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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base cases
        if (!p && !q) return true;       // Both are null
        if (!p || !q) return false;      // One is null, the other is not
        
        // Check current node value and recurse
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Same trees
    // Tree 1:     1      Tree 2:     1
    //            / \                / \
    //           2   3               2   3
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    
    cout << "Test 1 - Same trees [1,2,3]: " << (sol.isSameTree(p1, q1) ? "true" : "false") << endl;
    
    // Test case 2: Different trees (different values)
    // Tree 1:     1      Tree 2:     1
    //            / \                / \
    //           2   3               2   4
    TreeNode* p2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q2 = new TreeNode(1, new TreeNode(2), new TreeNode(4));
    
    cout << "Test 2 - Different values [1,2,3] vs [1,2,4]: " << (sol.isSameTree(p2, q2) ? "true" : "false") << endl;
    
    // Test case 3: Different structures
    // Tree 1:     1      Tree 2:     1
    //            /                    \
    //           2                      2
    TreeNode* p3 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* q3 = new TreeNode(1, nullptr, new TreeNode(2));
    
    cout << "Test 3 - Different structures: " << (sol.isSameTree(p3, q3) ? "true" : "false") << endl;
    
    // Test case 4: Both empty
    cout << "Test 4 - Both empty: " << (sol.isSameTree(nullptr, nullptr) ? "true" : "false") << endl;
    
    // Test case 5: One empty, one not
    TreeNode* p5 = new TreeNode(1);
    cout << "Test 5 - One empty, one not: " << (sol.isSameTree(p5, nullptr) ? "true" : "false") << endl;
    
    return 0;
}

