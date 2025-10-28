#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } 
            else if (c == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            } 
            else if (c == ']') {
                int repeatCount = numStack.top(); numStack.pop();
                string prevStr = strStack.top(); strStack.pop();

                string repeated = "";
                for (int i = 0; i < repeatCount; i++)
                    repeated += currStr;

                currStr = prevStr + repeated;
            } 
            else {
                currStr += c;
            }
        }

        return currStr;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    string input1 = "3[a]2[bc]";
    string result1 = solution.decodeString(input1);
    cout << "Input: \"" << input1 << "\"" << endl;
    cout << "Output: \"" << result1 << "\"" << endl;
    cout << "Explanation: \"aaa\" + \"bcbc\" = \"aaabcbc\"" << endl << endl;
    
    // Test Case 2: Nested brackets
    cout << "Test Case 2:" << endl;
    string input2 = "3[a2[c]]";
    string result2 = solution.decodeString(input2);
    cout << "Input: \"" << input2 << "\"" << endl;
    cout << "Output: \"" << result2 << "\"" << endl;
    cout << "Explanation: \"a\" + \"cc\" = \"acc\", then \"acc\" repeated 3 times = \"accaccacc\"" << endl << endl;
    
    // Test Case 3: Multiple digits
    cout << "Test Case 3:" << endl;
    string input3 = "2[abc]3[cd]ef";
    string result3 = solution.decodeString(input3);
    cout << "Input: \"" << input3 << "\"" << endl;
    cout << "Output: \"" << result3 << "\"" << endl;
    cout << "Explanation: \"abcabc\" + \"cdcdcd\" + \"ef\" = \"abcabccdcdcdef\"" << endl << endl;
    
    // Test Case 4: Single character
    cout << "Test Case 4:" << endl;
    string input4 = "abc3[cd]xyz";
    string result4 = solution.decodeString(input4);
    cout << "Input: \"" << input4 << "\"" << endl;
    cout << "Output: \"" << result4 << "\"" << endl;
    cout << "Explanation: \"abc\" + \"cdcdcd\" + \"xyz\" = \"abccdcdcdxyz\"" << endl << endl;
    
    // Test Case 5: Complex nested
    cout << "Test Case 5:" << endl;
    string input5 = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string result5 = solution.decodeString(input5);
    cout << "Input: \"" << input5 << "\"" << endl;
    cout << "Output: \"" << result5 << "\"" << endl;
    cout << "Explanation: Complex nested decoding" << endl << endl;
    
    // Test Case 6: No brackets
    cout << "Test Case 6:" << endl;
    string input6 = "leetcode";
    string result6 = solution.decodeString(input6);
    cout << "Input: \"" << input6 << "\"" << endl;
    cout << "Output: \"" << result6 << "\"" << endl;
    cout << "Explanation: No brackets, return as is" << endl << endl;
    
    // Test Case 7: Single bracket
    cout << "Test Case 7:" << endl;
    string input7 = "3[a]";
    string result7 = solution.decodeString(input7);
    cout << "Input: \"" << input7 << "\"" << endl;
    cout << "Output: \"" << result7 << "\"" << endl;
    cout << "Explanation: \"a\" repeated 3 times = \"aaa\"" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<string> testInputs = {
        "10[a]",
        "2[3[a]b]",
        "1[a2[b3[c]]]"
    };
    vector<string> expected = {
        "aaaaaaaaaa",
        "aaabaaab",
        "abcccbccc"
    };
    
    for (int i = 0; i < testInputs.size(); i++) {
        string result = solution.decodeString(testInputs[i]);
        cout << "Test " << (i + 8) << ": \"" << result << "\" (expected: \"" << expected[i] << "\")" << endl;
    }
    
    return 0;
}
