#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> arr;  // arr[index] -> list of (snap_id, val)
    int snap_id = 0;
    
    SnapshotArray(int length) {
        arr.resize(length);
        for (int i = 0; i < length; ++i) {
            arr[i].push_back({0, 0});  // initial value
        }
    }
    
    void set(int index, int val) {
        if (arr[index].back().first == snap_id)
            arr[index].back().second = val;  // update same snap
        else
            arr[index].push_back({snap_id, val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto &v = arr[index];
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m].first <= snap_id)
                l = m + 1;
            else
                r = m - 1;
        }
        return v[r].second;
    }
};

int main() {
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    SnapshotArray* obj1 = new SnapshotArray(3);
    obj1->set(0, 5);
    int snap_id1 = obj1->snap();
    cout << "SnapshotArray(3), set(0, 5), snap() = " << snap_id1 << endl;
    obj1->set(0, 6);
    int result1 = obj1->get(0, 0);
    cout << "set(0, 6), get(0, 0) = " << result1 << endl;
    cout << "Explanation: Value at snap_id 0 is 5" << endl << endl;
    
    // Test Case 2: Multiple snaps
    cout << "Test Case 2:" << endl;
    SnapshotArray* obj2 = new SnapshotArray(4);
    obj2->set(1, 4);
    obj2->set(2, 5);
    int snap1 = obj2->snap();
    cout << "SnapshotArray(4), set(1, 4), set(2, 5), snap() = " << snap1 << endl;
    int result2_1 = obj2->get(1, snap1);
    int result2_2 = obj2->get(2, snap1);
    cout << "get(1, " << snap1 << ") = " << result2_1 << endl;
    cout << "get(2, " << snap1 << ") = " << result2_2 << endl;
    obj2->set(1, 7);
    int snap2 = obj2->snap();
    cout << "set(1, 7), snap() = " << snap2 << endl;
    int result2_3 = obj2->get(1, snap1);
    int result2_4 = obj2->get(1, snap2);
    cout << "get(1, " << snap1 << ") = " << result2_3 << " (old value)" << endl;
    cout << "get(1, " << snap2 << ") = " << result2_4 << " (new value)" << endl;
    cout << endl;
    
    // Test Case 3: Multiple updates before snap
    cout << "Test Case 3:" << endl;
    SnapshotArray* obj3 = new SnapshotArray(2);
    obj3->set(0, 10);
    obj3->set(0, 20);
    obj3->set(0, 30);
    int snap3 = obj3->snap();
    cout << "SnapshotArray(2), set(0, 10), set(0, 20), set(0, 30), snap() = " << snap3 << endl;
    int result3 = obj3->get(0, snap3);
    cout << "get(0, " << snap3 << ") = " << result3 << endl;
    cout << "Explanation: Only last value before snap is stored (30)" << endl << endl;
    
    // Test Case 4: Getting initial values
    cout << "Test Case 4:" << endl;
    SnapshotArray* obj4 = new SnapshotArray(3);
    int snap4 = obj4->snap();
    cout << "SnapshotArray(3), snap() = " << snap4 << endl;
    int result4_1 = obj4->get(0, snap4);
    int result4_2 = obj4->get(1, snap4);
    int result4_3 = obj4->get(2, snap4);
    cout << "get(0, " << snap4 << ") = " << result4_1 << " (initial value 0)" << endl;
    cout << "get(1, " << snap4 << ") = " << result4_2 << " (initial value 0)" << endl;
    cout << "get(2, " << snap4 << ") = " << result4_3 << " (initial value 0)" << endl;
    cout << endl;
    
    // Test Case 5: Binary search for correct snapshot
    cout << "Test Case 5:" << endl;
    SnapshotArray* obj5 = new SnapshotArray(1);
    obj5->set(0, 1);
    int snap5_1 = obj5->snap();
    obj5->set(0, 2);
    int snap5_2 = obj5->snap();
    obj5->set(0, 3);
    int snap5_3 = obj5->snap();
    cout << "Multiple snaps: " << snap5_1 << ", " << snap5_2 << ", " << snap5_3 << endl;
    cout << "get(0, " << snap5_1 << ") = " << obj5->get(0, snap5_1) << endl;
    cout << "get(0, " << snap5_2 << ") = " << obj5->get(0, snap5_2) << endl;
    cout << "get(0, " << snap5_3 << ") = " << obj5->get(0, snap5_3) << endl;
    cout << "Explanation: Binary search finds correct snapshot value" << endl << endl;
    
    return 0;
}

