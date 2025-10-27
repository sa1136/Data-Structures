#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
        queue<tuple<int,int,int,int>> q; // (row, col, remaining_k, steps)
        q.push({0, 0, k, 0});
        visited[0][0][k] = true;

        // Direction arrays for up, down, left, right
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, remaining_k, steps] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (nr == m - 1 && nc == n - 1) return steps + 1;

                if (grid[nr][nc] == 1 && remaining_k > 0 && !visited[nr][nc][remaining_k - 1]) {
                    visited[nr][nc][remaining_k - 1] = true;
                    q.push({nr, nc, remaining_k - 1, steps + 1});
                } 
                else if (grid[nr][nc] == 0 && !visited[nr][nc][remaining_k]) {
                    visited[nr][nc][remaining_k] = true;
                    q.push({nr, nc, remaining_k, steps + 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {0,0,0},
        {1,1,0},
        {0,0,0},
        {0,1,1},
        {0,0,0}
    };
    int k = 1;
    cout << s.shortestPath(grid, k) << endl;  // Output: 6
    return 0;
}
