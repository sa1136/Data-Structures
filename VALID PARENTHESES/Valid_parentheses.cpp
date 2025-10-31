#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> matching = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);  // push opening brackets
        } else {
            if (st.empty() || st.top() != matching[c]) {
                return false;  // mismatch or no opening bracket
            }
            st.pop();  // pop matching opening bracket
        }
    }
    
    return st.empty();  // valid if stack is empty
}

int main() {
    // Test Case 1: Valid parentheses
    cout << "Test Case 1:" << endl;
    string s1 = "()";
    bool result1 = isValid(s1);
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Explanation: Valid parentheses" << endl << endl;
    
    // Test Case 2: Valid with multiple types
    cout << "Test Case 2:" << endl;
    string s2 = "()[]{}";
    bool result2 = isValid(s2);
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Explanation: All brackets are properly closed" << endl << endl;
    
    // Test Case 3: Invalid - mismatch
    cout << "Test Case 3:" << endl;
    string s3 = "(]";
    bool result3 = isValid(s3);
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Explanation: Mismatched brackets" << endl << endl;
    
    // Test Case 4: Valid - nested
    cout << "Test Case 4:" << endl;
    string s4 = "([{}])";
    bool result4 = isValid(s4);
    cout << "Input: \"" << s4 << "\"" << endl;
    cout << "Output: " << (result4 ? "true" : "false") << endl;
    cout << "Explanation: Nested brackets are valid" << endl << endl;
    
    // Test Case 5: Invalid - unclosed
    cout << "Test Case 5:" << endl;
    string s5 = "([";
    bool result5 = isValid(s5);
    cout << "Input: \"" << s5 << "\"" << endl;
    cout << "Output: " << (result5 ? "true" : "false") << endl;
    cout << "Explanation: Unclosed brackets" << endl << endl;
    
    // Test Case 6: Invalid - extra closing
    cout << "Test Case 6:" << endl;
    string s6 = "])";
    bool result6 = isValid(s6);
    cout << "Input: \"" << s6 << "\"" << endl;
    cout << "Output: " << (result6 ? "true" : "false") << endl;
    cout << "Explanation: Extra closing bracket" << endl << endl;
    
    // Test Case 7: Empty string
    cout << "Test Case 7:" << endl;
    string s7 = "";
    bool result7 = isValid(s7);
    cout << "Input: \"" << s7 << "\"" << endl;
    cout << "Output: " << (result7 ? "true" : "false") << endl;
    cout << "Explanation: Empty string is valid" << endl << endl;
    
    // Test Case 8: Valid - complex nested
    cout << "Test Case 8:" << endl;
    string s8 = "{[]}";
    bool result8 = isValid(s8);
    cout << "Input: \"" << s8 << "\"" << endl;
    cout << "Output: " << (result8 ? "true" : "false") << endl;
    cout << "Explanation: Complex nested structure is valid" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<string> testCases = {
        "((()))",
        "([)]",
        "(([]))"
    };
    vector<bool> expected = {true, false, true};
    
    for (int i = 0; i < testCases.size(); i++) {
        bool result = isValid(testCases[i]);
        cout << "Test " << (i + 9) << ": \"" << testCases[i] << "\" -> " 
             << (result ? "true" : "false") 
             << " (expected: " << (expected[i] ? "true" : "false") << ")" << endl;
    }
    
    return 0;
}

