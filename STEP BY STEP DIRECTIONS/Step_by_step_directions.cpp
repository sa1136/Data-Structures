#include <iostream>
#include <string>
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find paths from root to start and dest
        string pathToStart = findPath(root, startValue);
        string pathToDest = findPath(root, destValue);
        
        cout << "Path to start: " << pathToStart << endl;
        cout << "Path to dest: " << pathToDest << endl;
        
        // Remove common prefix
        int i = 0;
        while (i < pathToStart.length() && i < pathToDest.length() && 
               pathToStart[i] == pathToDest[i]) {
            i++;
        }
        
        cout << "Common prefix length: " << i << endl;
        
        // Convert remaining path to start into "U"s
        string result = string(pathToStart.length() - i, 'U');
        
        // Add remaining path to destination
        result += pathToDest.substr(i);
        
        return result;
    }
    
private:
    string findPath(TreeNode* root, int target) {
        if (!root) return "X";
        if (root->val == target) return "";
        
        string left = findPath(root->left, target);
        if (left != "X") return "L" + left;
        
        string right = findPath(root->right, target);
        if (right != "X") return "R" + right;
        
        return "X"; // Not found
    }
};

int main() {
    Solution s;
    
    // Test case: [5,1,2,3,null,6,4], startValue = 3, destValue = 6
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    
    cout << s.getDirections(root, 3, 6) << endl; // Expected: "UURL"
    
    return 0;
}
