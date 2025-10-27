#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());  // sort by timestamp
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        iota(parent.begin(), parent.end(), 0);  // parent[i] = i
        int components = n;
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);  // path compression
            return parent[x];
        };
        
        auto unite = [&](int a, int b) {
            int rootA = find(a), rootB = find(b);
            if (rootA == rootB) return false;  // already connected
            if (rank[rootA] < rank[rootB]) swap(rootA, rootB);
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB]) rank[rootA]++;
            components--;
            return true;
        };
        
        for (auto& log : logs) {
            int time = log[0], a = log[1], b = log[2];
            unite(a, b);
            if (components == 1) return time;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<vector<int>> logs1 = {{20190101,0,1},{20190104,3,4},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
    int n1 = 6;
    int result1 = solution.earliestAcq(logs1, n1);
    cout << "Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: Everyone becomes friends at timestamp 20190301" << endl << endl;
    
    // Test Case 2: Simple case
    cout << "Test Case 2:" << endl;
    vector<vector<int>> logs2 = {{0,2,0},{1,0,1},{3,0,3},{4,1,2},{7,3,1}};
    int n2 = 4;
    int result2 = solution.earliestAcq(logs2, n2);
    cout << "Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: Everyone becomes friends at timestamp 3" << endl << endl;
    
    // Test Case 3: Already connected
    cout << "Test Case 3:" << endl;
    vector<vector<int>> logs3 = {{0,0,1}};
    int n3 = 2;
    int result3 = solution.earliestAcq(logs3, n3);
    cout << "Input: logs = [[0,0,1]], n = 2" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: Everyone becomes friends at timestamp 0" << endl << endl;
    
    // Test Case 4: Multiple components
    cout << "Test Case 4:" << endl;
    vector<vector<int>> logs4 = {{0,0,1},{1,2,3}};
    int n4 = 4;
    int result4 = solution.earliestAcq(logs4, n4);
    cout << "Input: logs = [[0,0,1],[1,2,3]], n = 4" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Cannot connect all components, return -1" << endl << endl;
    
    // Test Case 5: Single person
    cout << "Test Case 5:" << endl;
    vector<vector<int>> logs5 = {};
    int n5 = 1;
    int result5 = solution.earliestAcq(logs5, n5);
    cout << "Input: logs = [], n = 1" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: Single person is already connected, return 0" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<vector<int>>> testLogs = {
        {{0,0,1},{1,1,2},{2,2,3}},
        {{0,0,1},{2,1,2},{4,2,3}},
        {{0,0,1},{1,1,2},{2,0,2}}
    };
    vector<int> testN = {4, 4, 3};
    vector<int> expected = {2, 4, 2};
    
    for (int i = 0; i < testLogs.size(); i++) {
        int result = solution.earliestAcq(testLogs[i], testN[i]);
        cout << "Test " << (i + 6) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}
