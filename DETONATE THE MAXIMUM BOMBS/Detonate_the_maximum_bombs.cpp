#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
        visited[node] = true;
        count++;
        for (int next : graph[node]) {
            if (!visited[next]) dfs(next, graph, visited, count);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = (int)bombs.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x1 - x2, dy = y1 - y2;
                long long distSq = dx * dx + dy * dy;
                if (distSq <= r1 * r1) graph[i].push_back(j);
            }
        }
        int maxDetonated = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = 0;
            dfs(i, graph, visited, count);
            maxDetonated = max(maxDetonated, count);
        }
        return maxDetonated;
    }
};

static void runCase(const vector<vector<int>>& bombs) {
    vector<vector<int>> b = bombs;
    Solution s;
    cout << "Input: [";
    for (size_t i = 0; i < b.size(); ++i) {
        cout << "[" << b[i][0] << "," << b[i][1] << "," << b[i][2] << "]";
        if (i + 1 < b.size()) cout << ",";
    }
    cout << "]\n";
    cout << "Output: " << s.maximumDetonation(b) << "\n\n";
}

int main() {
    cout << "Test Case 1:\n";
    runCase({{2,1,3},{6,1,4}}); // expected 2

    cout << "Test Case 2:\n";
    runCase({{1,1,5},{10,10,5}}); // expected 1

    cout << "Test Case 3:\n";
    runCase({{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}}); // chain

    cout << "Test Case 4:\n";
    runCase({{0,0,2},{2,0,2},{4,0,2}}); // overlap chain => 3

    cout << "Test Case 5:\n";
    runCase({}); // 0

    return 0;
}
