#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i);
        int count = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            count++;
            for (int next : adj[curr]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }
        return count == numCourses;
    }
};

int main() {
    Solution sol;

    // Test 1: simple possible
    int n1 = 2; vector<vector<int>> p1 = {{1,0}};
    cout << "Test 1: " << (sol.canFinish(n1, p1) ? "true" : "false") << "\n"; // true

    // Test 2: cycle
    int n2 = 2; vector<vector<int>> p2 = {{1,0},{0,1}};
    cout << "Test 2: " << (sol.canFinish(n2, p2) ? "true" : "false") << "\n"; // false

    // Test 3: multiple deps
    int n3 = 4; vector<vector<int>> p3 = {{1,0},{2,0},{3,1},{3,2}};
    cout << "Test 3: " << (sol.canFinish(n3, p3) ? "true" : "false") << "\n"; // true

    // Test 4: no prereqs
    int n4 = 3; vector<vector<int>> p4 = {};
    cout << "Test 4: " << (sol.canFinish(n4, p4) ? "true" : "false") << "\n"; // true

    // Test 5: disconnected with a cycle component
    int n5 = 5; vector<vector<int>> p5 = {{1,0},{2,1},{0,2},{4,3}};
    cout << "Test 5: " << (sol.canFinish(n5, p5) ? "true" : "false") << "\n"; // false

    return 0;
}
