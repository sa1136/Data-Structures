#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    // Sort meetings by start time
    sort(intervals.begin(), intervals.end());
    
    // Min heap for end times
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Add first meeting
    minHeap.push(intervals[0][1]);
    
    // Iterate over remaining meetings
    for (int i = 1; i < intervals.size(); i++) {
        // If current meeting starts after the earliest one ends, reuse room
        if (intervals[i][0] >= minHeap.top()) {
            minHeap.pop();
        }
        // Allocate room (new or reused)
        minHeap.push(intervals[i][1]);
    }
    
    return minHeap.size();
}

int main() {
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<vector<int>> intervals1 = {{0,30},{5,10},{15,20}};
    int result1 = minMeetingRooms(intervals1);
    cout << "Input: [[0,30],[5,10],[15,20]]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: We need two meeting rooms. Room1: [0,30], Room2: [5,10],[15,20]" << endl << endl;
    
    // Test Case 2: No overlap
    cout << "Test Case 2:" << endl;
    vector<vector<int>> intervals2 = {{7,10},{2,4}};
    int result2 = minMeetingRooms(intervals2);
    cout << "Input: [[7,10],[2,4]]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: We need one meeting room. Room1: [2,4],[7,10]" << endl << endl;
    
    // Test Case 3: All overlap
    cout << "Test Case 3:" << endl;
    vector<vector<int>> intervals3 = {{1,3},{2,4},{3,5}};
    int result3 = minMeetingRooms(intervals3);
    cout << "Input: [[1,3],[2,4],[3,5]]" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: We need two meeting rooms. Room1: [1,3],[3,5], Room2: [2,4]" << endl << endl;
    
    // Test Case 4: Single meeting
    cout << "Test Case 4:" << endl;
    vector<vector<int>> intervals4 = {{9,10},{4,9},{4,17}};
    int result4 = minMeetingRooms(intervals4);
    cout << "Input: [[9,10],[4,9],[4,17]]" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: We need two meeting rooms. Room1: [4,17], Room2: [4,9],[9,10]" << endl << endl;
    
    // Test Case 5: Empty intervals
    cout << "Test Case 5:" << endl;
    vector<vector<int>> intervals5 = {};
    int result5 = minMeetingRooms(intervals5);
    cout << "Input: []" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: No meetings, so 0 rooms needed" << endl << endl;
    
    // Test Case 6: Complex case
    cout << "Test Case 6:" << endl;
    vector<vector<int>> intervals6 = {{1,4},{2,6},{3,8},{5,7},{6,9}};
    int result6 = minMeetingRooms(intervals6);
    cout << "Input: [[1,4],[2,6],[3,8],[5,7],[6,9]]" << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: We need 3 meeting rooms" << endl << endl;
    
    // Test Case 7: Same start and end times
    cout << "Test Case 7:" << endl;
    vector<vector<int>> intervals7 = {{1,2},{1,2},{2,3}};
    int result7 = minMeetingRooms(intervals7);
    cout << "Input: [[1,2],[1,2],[2,3]]" << endl;
    cout << "Output: " << result7 << endl;
    cout << "Explanation: We need 2 meeting rooms" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<vector<int>>> testIntervals = {
        {{0,1},{1,2},{2,3}},
        {{1,5},{2,3},{3,4}},
        {{0,5},{1,3},{2,4},{4,6}}
    };
    vector<int> expected = {1, 2, 2};
    
    for (int i = 0; i < testIntervals.size(); i++) {
        int result = minMeetingRooms(testIntervals[i]);
        cout << "Test " << (i + 8) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}
