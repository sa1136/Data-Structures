#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Direction arrays for up, right, down, left
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Mark the current cell as visited
        grid[r][c] = '0';

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check boundary and if it's land
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == '1') {
                dfs(grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);  // Mark this island completely
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    int result1 = solution.numIslands(grid1);
    cout << "Input: grid = [[\"1\",\"1\",\"1\",\"1\",\"0\"],[\"1\",\"1\",\"0\",\"1\",\"0\"],[\"1\",\"1\",\"0\",\"0\",\"0\"],[\"0\",\"0\",\"0\",\"0\",\"0\"]]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: There is one island" << endl << endl;
    
    // Test Case 2: Multiple islands
    cout << "Test Case 2:" << endl;
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int result2 = solution.numIslands(grid2);
    cout << "Input: grid = [[\"1\",\"1\",\"0\",\"0\",\"0\"],[\"1\",\"1\",\"0\",\"0\",\"0\"],[\"0\",\"0\",\"1\",\"0\",\"0\"],[\"0\",\"0\",\"0\",\"1\",\"1\"]]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: There are three islands" << endl << endl;
    
    // Test Case 3: Single cell island
    cout << "Test Case 3:" << endl;
    vector<vector<char>> grid3 = {
        {'1','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };
    int result3 = solution.numIslands(grid3);
    cout << "Input: grid = [[\"1\",\"0\",\"0\"],[\"0\",\"0\",\"0\"],[\"0\",\"0\",\"0\"]]" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: There is one island" << endl << endl;
    
    // Test Case 4: No islands
    cout << "Test Case 4:" << endl;
    vector<vector<char>> grid4 = {
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };
    int result4 = solution.numIslands(grid4);
    cout << "Input: grid = [[\"0\",\"0\",\"0\"],[\"0\",\"0\",\"0\"],[\"0\",\"0\",\"0\"]]" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: There are no islands" << endl << endl;
    
    // Test Case 5: All land
    cout << "Test Case 5:" << endl;
    vector<vector<char>> grid5 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    int result5 = solution.numIslands(grid5);
    cout << "Input: grid = [[\"1\",\"1\",\"1\"],[\"1\",\"1\",\"1\"],[\"1\",\"1\",\"1\"]]" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: There is one large island" << endl << endl;
    
    // Test Case 6: Complex pattern
    cout << "Test Case 6:" << endl;
    vector<vector<char>> grid6 = {
        {'1','0','1','0','1'},
        {'0','1','0','1','0'},
        {'1','0','1','0','1'},
        {'0','1','0','1','0'}
    };
    int result6 = solution.numIslands(grid6);
    cout << "Input: grid = [[\"1\",\"0\",\"1\",\"0\",\"1\"],[\"0\",\"1\",\"0\",\"1\",\"0\"],[\"1\",\"0\",\"1\",\"0\",\"1\"],[\"0\",\"1\",\"0\",\"1\",\"0\"]]" << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: There are 10 separate islands" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<vector<char>>> testGrids = {
        {{'1','1','1'},{'0','1','0'},{'1','1','1'}},
        {{'1','0','1'},{'1','1','1'},{'1','0','1'}},
        {{'1','1','0'},{'0','0','1'},{'1','1','0'}}
    };
    vector<int> expected = {1, 1, 3};
    
    for (int i = 0; i < testGrids.size(); i++) {
        int result = solution.numIslands(testGrids[i]);
        cout << "Test " << (i + 7) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}
