#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));
        
        // Apply difference array updates
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            
            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }
        
        // Build prefix sum horizontally
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }
        
        // Build prefix sum vertically
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }
        
        // Trim to n x n result
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = diff[i][j];
            }
        }
        
        return res;
    }
};

int main() {
    Solution s;
    
    // Test case 1: n=3, queries = [[1,1,2,2],[0,0,1,1]]
    int n1 = 3;
    vector<vector<int>> queries1 = {{1,1,2,2}, {0,0,1,1}};
    vector<vector<int>> result1 = s.rangeAddQueries(n1, queries1);
    
    cout << "Test 1 - n=3, queries=[[1,1,2,2],[0,0,1,1]]:\n";
    for (int i = 0; i < n1; i++) {
        cout << "[";
        for (int j = 0; j < n1; j++) {
            cout << result1[i][j];
            if (j < n1 - 1) cout << ",";
        }
        cout << "]";
        if (i < n1 - 1) cout << "\n";
    }
    cout << "\n\n";
    
    // Test case 2: n=2, queries = [[0,0,1,1]]
    int n2 = 2;
    vector<vector<int>> queries2 = {{0,0,1,1}};
    vector<vector<int>> result2 = s.rangeAddQueries(n2, queries2);
    
    cout << "Test 2 - n=2, queries=[[0,0,1,1]]:\n";
    for (int i = 0; i < n2; i++) {
        cout << "[";
        for (int j = 0; j < n2; j++) {
            cout << result2[i][j];
            if (j < n2 - 1) cout << ",";
        }
        cout << "]";
        if (i < n2 - 1) cout << "\n";
    }
    cout << "\n";
    
    return 0;
}

