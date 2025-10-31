#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class DetectSquares {
public:
    // rename the map to avoid shadowing the 'count' method
    unordered_map<int, unordered_map<int, int>> cnt;

    DetectSquares() {
        // nothing to do, cnt is empty
    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[x][y]++; // increment frequency of (x,y)
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int total = 0;

        // iterate all points that share the same x-coordinate
        auto it = cnt.find(x);
        if (it == cnt.end()) return 0;

        for (const auto &p : it->second) {
            int y2 = p.first;
            int freqY2 = p.second;
            if (y2 == y) continue;       // same point -> skip
            int side = abs(y2 - y);

            // square to the right: x + side
            int xRight = x + side;
            total += freqY2 * cnt[xRight][y] * cnt[xRight][y2];

            // square to the left: x - side
            int xLeft = x - side;
            total += freqY2 * cnt[xLeft][y] * cnt[xLeft][y2];
        }

        return total;
    }
};

int main() {
    DetectSquares ds;
    ds.add({3, 10});
    ds.add({11, 2});
    ds.add({3, 2});
    cout << ds.count({11, 10}) << "\n"; // expect 1
    ds.add({11, 2});
    cout << ds.count({11, 10}) << "\n"; // expect 2
    cout << ds.count({14, 8}) << "\n";  // expect 0
    return 0;
}
