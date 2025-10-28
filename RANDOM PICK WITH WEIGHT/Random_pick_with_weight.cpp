#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

class Solution {
public:
    vector<int> prefix;
    int totalSum;

    Solution(vector<int>& w) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < (int)w.size(); ++i) {
            prefix[i] = prefix[i - 1] + w[i];
        }
        totalSum = prefix.back();
    }

    int pickIndex() {
        int randomNum = rand() % totalSum + 1; // random number in [1, totalSum]
        int index = (int)(lower_bound(prefix.begin(), prefix.end(), randomNum) - prefix.begin());
        return index;
    }
};

int main() {
    srand((unsigned)time(nullptr));

    vector<int> w1 = {1, 3};
    Solution sol1(w1);
    vector<int> cnt1(w1.size());
    for (int i = 0; i < 10000; ++i) cnt1[sol1.pickIndex()]++;
    cout << "Test 1 counts: ";
    for (int c : cnt1) cout << c << ' ';
    cout << "\n";

    vector<int> w2 = {2, 5, 3};
    Solution sol2(w2);
    vector<int> cnt2(w2.size());
    for (int i = 0; i < 20000; ++i) cnt2[sol2.pickIndex()]++;
    cout << "Test 2 counts: ";
    for (int c : cnt2) cout << c << ' ';
    cout << "\n";

    return 0;
}
