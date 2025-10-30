#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);   // adjacency list
        vector<int> indegree(numCourses, 0);   // indegree count
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        if (order.size() == numCourses)
            return order;
        else
            return {};
    }
};

static void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    Solution sol;
    // Test 1: Possible order
    cout << "Test 1:\n";
    int numCourses1 = 2;
    vector<vector<int>> prereq1 = {{1,0}};
    printVec(sol.findOrder(numCourses1, prereq1)); // expected: [0,1]
    cout << endl;
    // Test 2: Impossible (cycle)
    cout << "Test 2:\n";
    int numCourses2 = 2;
    vector<vector<int>> prereq2 = {{1,0},{0,1}};
    printVec(sol.findOrder(numCourses2, prereq2)); // expected: []
    cout << endl;
    // Test 3:
    cout << "Test 3:\n";
    int numCourses3 = 4;
    vector<vector<int>> prereq3 = {{1,0},{2,0},{3,1},{3,2}};
    printVec(sol.findOrder(numCourses3, prereq3)); // valid: [0,1,2,3] or [0,2,1,3]
    cout << endl;
    // Test 4: No prerequisites
    cout << "Test 4:\n";
    int numCourses4 = 1;
    vector<vector<int>> prereq4 = {};
    printVec(sol.findOrder(numCourses4, prereq4)); // [0]
    cout << endl;
    // Test 5: Empty
    cout << "Test 5:\n";
    int numCourses5 = 0;
    vector<vector<int>> prereq5 = {};
    printVec(sol.findOrder(numCourses5, prereq5)); // []
    cout << endl;
    // Test 6: All to one
    cout << "Test 6:\n";
    int numCourses6 = 3;
    vector<vector<int>> prereq6 = {{1,0},{2,0}};
    printVec(sol.findOrder(numCourses6, prereq6)); // [0,1,2] or [0,2,1]
    cout << endl;
    return 0;
}
