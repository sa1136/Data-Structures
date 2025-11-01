#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int same = 0;
        
        for (auto& p : points) {
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];
            if (dx == 0 && dy == 0) {
                same++; // Points at the same location
                continue;
            }
            double ang = atan2(dy, dx) * 180 / M_PI;
            angles.push_back(ang);
        }
        
        sort(angles.begin(), angles.end());
        
        // Duplicate the array to handle circular wrap
        int n = angles.size();
        vector<double> extended(angles);
        for (double a : angles)
            extended.push_back(a + 360);
        
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < extended.size() && extended[j] - extended[i] <= angle)
                j++;
            res = max(res, j - i);
        }
        
        return res + same;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<vector<int>> points1 = {{2,1},{2,2},{3,4},{1,1}};
    int angle1 = 90;
    vector<int> location1 = {1,1};
    int result1 = solution.visiblePoints(points1, angle1, location1);
    cout << "Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: Maximum visible points within 90 degree angle" << endl << endl;
    
    // Test Case 2: Another example
    cout << "Test Case 2:" << endl;
    vector<vector<int>> points2 = {{2,1},{2,2},{3,3}};
    int angle2 = 90;
    vector<int> location2 = {1,1};
    int result2 = solution.visiblePoints(points2, angle2, location2);
    cout << "Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: Three points visible" << endl << endl;
    
    // Test Case 3: Points at same location
    cout << "Test Case 3:" << endl;
    vector<vector<int>> points3 = {{1,0},{2,1},{1,1}};
    int angle3 = 13;
    vector<int> location3 = {1,1};
    int result3 = solution.visiblePoints(points3, angle3, location3);
    cout << "Input: points = [[1,0],[2,1],[1,1]], angle = 13, location = [1,1]" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: One point at same location counts as visible" << endl << endl;
    
    // Test Case 4: Circular wrap
    cout << "Test Case 4:" << endl;
    vector<vector<int>> points4 = {{0,0},{0,2}};
    int angle4 = 90;
    vector<int> location4 = {1,1};
    int result4 = solution.visiblePoints(points4, angle4, location4);
    cout << "Input: points = [[0,0],[0,2]], angle = 90, location = [1,1]" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Handles circular wrap around 360 degrees" << endl << endl;
    
    // Test Case 5: All points visible
    cout << "Test Case 5:" << endl;
    vector<vector<int>> points5 = {{1,1},{2,2},{3,3}};
    int angle5 = 360;
    vector<int> location5 = {0,0};
    int result5 = solution.visiblePoints(points5, angle5, location5);
    cout << "Input: points = [[1,1],[2,2],[3,3]], angle = 360, location = [0,0]" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: Full 360 degrees, all points visible" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<vector<int>>> testPoints = {
        {{0,1},{1,0}},
        {{1,0},{2,1}}
    };
    vector<int> testAngles = {90, 13};
    vector<vector<int>> testLocations = {{1,1}, {1,1}};
    vector<int> expected = {2, 2};
    
    for (int i = 0; i < testPoints.size(); i++) {
        int result = solution.visiblePoints(testPoints[i], testAngles[i], testLocations[i]);
        cout << "Test " << (i + 6) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}

