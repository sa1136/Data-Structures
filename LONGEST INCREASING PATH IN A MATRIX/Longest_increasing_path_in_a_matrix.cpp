#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // memoization table
        int ans = 0;

        // Directions: up, down, left, right
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        function<int(int,int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != 0) return dp[i][j]; // already computed

            int maxPath = 1; // at least the cell itself
            for (auto [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    maxPath = max(maxPath, 1 + dfs(x, y));
                }
            }
            return dp[i][j] = maxPath;
        };

        // Try starting from each cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<vector<int>> matrix1 = {{9,9,4},{6,6,8},{2,1,1}};
    int result1 = solution.longestIncreasingPath(matrix1);
    cout << "Input: [[9,9,4],[6,6,8],[2,1,1]]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: The longest increasing path is [1, 2, 6, 9] with length 4" << endl << endl;
    
    // Test Case 2: Another example
    cout << "Test Case 2:" << endl;
    vector<vector<int>> matrix2 = {{3,4,5},{3,2,6},{2,2,1}};
    int result2 = solution.longestIncreasingPath(matrix2);
    cout << "Input: [[3,4,5],[3,2,6],[2,2,1]]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: The longest increasing path is [3, 4, 5, 6] with length 4" << endl << endl;
    
    // Test Case 3: Single element
    cout << "Test Case 3:" << endl;
    vector<vector<int>> matrix3 = {{1}};
    int result3 = solution.longestIncreasingPath(matrix3);
    cout << "Input: [[1]]" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: Single cell, path length is 1" << endl << endl;
    
    // Test Case 4: All increasing
    cout << "Test Case 4:" << endl;
    vector<vector<int>> matrix4 = {{1,2,3},{6,5,4},{7,8,9}};
    int result4 = solution.longestIncreasingPath(matrix4);
    cout << "Input: [[1,2,3],[6,5,4],[7,8,9]]" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Path from 1 to 9 through diagonal" << endl << endl;
    
    // Test Case 5: Large value in corner
    cout << "Test Case 5:" << endl;
    vector<vector<int>> matrix5 = {{7,8,9},{9,7,6},{7,2,3}};
    int result5 = solution.longestIncreasingPath(matrix5);
    cout << "Input: [[7,8,9],[9,7,6],[7,2,3]]" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: Testing various paths" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<vector<int>>> testMatrices = {
        {{1,2},{2,3}},
        {{1},{2},{3}},
        {{3,2,1}}
    };
    vector<int> expected = {4, 3, 1};
    
    for (int i = 0; i < testMatrices.size(); i++) {
        int result = solution.longestIncreasingPath(testMatrices[i]);
        cout << "Test " << (i + 6) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}

