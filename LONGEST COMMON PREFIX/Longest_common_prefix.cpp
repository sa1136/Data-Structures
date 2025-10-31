#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0]; // assume first string is the prefix

        // compare with every other string
        for (int i = 1; i < strs.size(); i++) {
            // shrink prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<string> strs1 = {"flower","flow","flight"};
    string result1 = solution.longestCommonPrefix(strs1);
    cout << "Input: [\"flower\",\"flow\",\"flight\"]" << endl;
    cout << "Output: \"" << result1 << "\"" << endl;
    cout << "Explanation: Common prefix is \"fl\"" << endl << endl;
    
    // Test Case 2: No common prefix
    cout << "Test Case 2:" << endl;
    vector<string> strs2 = {"dog","racecar","car"};
    string result2 = solution.longestCommonPrefix(strs2);
    cout << "Input: [\"dog\",\"racecar\",\"car\"]" << endl;
    cout << "Output: \"" << result2 << "\"" << endl;
    cout << "Explanation: No common prefix, returns \"\"" << endl << endl;
    
    // Test Case 3: Single string
    cout << "Test Case 3:" << endl;
    vector<string> strs3 = {"single"};
    string result3 = solution.longestCommonPrefix(strs3);
    cout << "Input: [\"single\"]" << endl;
    cout << "Output: \"" << result3 << "\"" << endl;
    cout << "Explanation: Single string, returns itself" << endl << endl;
    
    // Test Case 4: All same
    cout << "Test Case 4:" << endl;
    vector<string> strs4 = {"same","same","same"};
    string result4 = solution.longestCommonPrefix(strs4);
    cout << "Input: [\"same\",\"same\",\"same\"]" << endl;
    cout << "Output: \"" << result4 << "\"" << endl;
    cout << "Explanation: All strings are identical" << endl << endl;
    
    // Test Case 5: Empty array
    cout << "Test Case 5:" << endl;
    vector<string> strs5 = {};
    string result5 = solution.longestCommonPrefix(strs5);
    cout << "Input: []" << endl;
    cout << "Output: \"" << result5 << "\"" << endl;
    cout << "Explanation: Empty array, returns \"\"" << endl << endl;
    
    // Test Case 6: Partial match
    cout << "Test Case 6:" << endl;
    vector<string> strs6 = {"ab","a"};
    string result6 = solution.longestCommonPrefix(strs6);
    cout << "Input: [\"ab\",\"a\"]" << endl;
    cout << "Output: \"" << result6 << "\"" << endl;
    cout << "Explanation: Common prefix is \"a\"" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<string>> testCases = {
        {"preview","prefix","prepare"},
        {"interspecies","interstellar","interstate"},
        {"throne","throne"}
    };
    vector<string> expected = {"pre", "inters", "throne"};
    
    for (int i = 0; i < testCases.size(); i++) {
        string result = solution.longestCommonPrefix(testCases[i]);
        cout << "Test " << (i + 7) << ": \"" << result << "\" (expected: \"" << expected[i] << "\")" << endl;
    }
    
    return 0;
}

