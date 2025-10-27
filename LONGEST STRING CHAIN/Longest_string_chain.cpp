#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Step 1: Sort words by length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp; // word → longest chain ending here
        int longest = 1;

        // Step 2: Build DP
        for (string word : words) {
            dp[word] = 1; // base case

            // Step 3: Try removing one character at every position
            for (int i = 0; i < word.size(); i++) {
                string pred = word.substr(0, i) + word.substr(i + 1); // remove char at i

                if (dp.find(pred) != dp.end()) {
                    dp[word] = max(dp[word], dp[pred] + 1);
                }
            }

            longest = max(longest, dp[word]);
        }

        return longest;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic chain
    cout << "Test Case 1:" << endl;
    vector<string> words1 = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result1 = solution.longestStrChain(words1);
    cout << "Input: [\"a\", \"b\", \"ba\", \"bca\", \"bda\", \"bdca\"]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: Chain: \"a\" -> \"ba\" -> \"bca\" -> \"bdca\" (length 4)" << endl << endl;
    
    // Test Case 2: Single character words
    cout << "Test Case 2:" << endl;
    vector<string> words2 = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    int result2 = solution.longestStrChain(words2);
    cout << "Input: [\"xbc\", \"pcxbcf\", \"xb\", \"cxbc\", \"pcxbc\"]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: Chain: \"xb\" -> \"xbc\" -> \"cxbc\" -> \"pcxbc\" (length 4)" << endl << endl;
    
    // Test Case 3: No valid chain
    cout << "Test Case 3:" << endl;
    vector<string> words3 = {"abcd", "dbqca"};
    int result3 = solution.longestStrChain(words3);
    cout << "Input: [\"abcd\", \"dbqca\"]" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: No valid chain possible, longest is 1" << endl << endl;
    
    // Test Case 4: Single word
    cout << "Test Case 4:" << endl;
    vector<string> words4 = {"a"};
    int result4 = solution.longestStrChain(words4);
    cout << "Input: [\"a\"]" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Single word, chain length is 1" << endl << endl;
    
    // Test Case 5: Complex chain
    cout << "Test Case 5:" << endl;
    vector<string> words5 = {"a", "ab", "abc", "abcd", "abcde"};
    int result5 = solution.longestStrChain(words5);
    cout << "Input: [\"a\", \"ab\", \"abc\", \"abcd\", \"abcde\"]" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: Perfect chain: \"a\" -> \"ab\" -> \"abc\" -> \"abcd\" -> \"abcde\" (length 5)" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<string>> testCases = {
        {"a", "b", "ab", "abc"},
        {"a", "b", "ab", "abc", "abcd"},
        {"a", "aa", "aab", "aabb", "aabbb"}
    };
    vector<int> expected = {3, 4, 5};
    
    for (int i = 0; i < testCases.size(); i++) {
        int result = solution.longestStrChain(testCases[i]);
        cout << "Test " << (i + 6) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}
