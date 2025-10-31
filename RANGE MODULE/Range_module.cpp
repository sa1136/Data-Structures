#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class RangeModule {
public:
    map<int, int> intervals; // key: start, value: end

    void addRange(int left, int right) {
        auto it = intervals.lower_bound(left);
        // Check previous interval if overlapping
        if (it != intervals.begin()) {
            auto itPrev = prev(it); // ✅ renamed variable
            if (itPrev->second >= left) {
                left = min(left, itPrev->first);
                right = max(right, itPrev->second);
                it = intervals.erase(itPrev);
            }
        }
        // Merge overlapping intervals
        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        --it;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = intervals.lower_bound(left);
        if (it != intervals.begin()) {
            auto itPrev = prev(it); // ✅ same rename here too
            if (itPrev->second > left) {
                if (itPrev->second > right)
                    intervals[right] = itPrev->second;
                intervals[itPrev->first] = left;
            }
        }

        while (it != intervals.end() && it->first < right) {
            if (it->second > right)
                intervals[right] = it->second;
            it = intervals.erase(it);
        }
    }
};

int main() {
    RangeModule rm;
    
    rm.addRange(10, 20);
    cout << "addRange(10, 20)" << endl;
    
    rm.removeRange(14, 16);
    cout << "removeRange(14, 16)" << endl;
    
    cout << "queryRange(10, 14): " << (rm.queryRange(10, 14) ? "true" : "false") << endl; // true
    cout << "queryRange(13, 15): " << (rm.queryRange(13, 15) ? "true" : "false") << endl; // false
    cout << "queryRange(16, 17): " << (rm.queryRange(16, 17) ? "true" : "false") << endl; // true
    
    return 0;
}
