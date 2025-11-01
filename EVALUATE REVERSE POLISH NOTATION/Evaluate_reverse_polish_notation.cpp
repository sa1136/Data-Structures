#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b);  // truncates toward zero
            } else {
                st.push(stoi(token));  // convert string to integer
            }
        }
        
        return st.top();
    }
};

void printTokens(const vector<string>& tokens) {
    cout << "[";
    for (size_t i = 0; i < tokens.size(); i++) {
        cout << "\"" << tokens[i] << "\"";
        if (i < tokens.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<string> tokens1 = {"2","1","+","3","*"};
    int result1 = solution.evalRPN(tokens1);
    cout << "Input: ";
    printTokens(tokens1);
    cout << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: ((2 + 1) * 3) = 9" << endl << endl;
    
    // Test Case 2: Division
    cout << "Test Case 2:" << endl;
    vector<string> tokens2 = {"4","13","5","/","+"};
    int result2 = solution.evalRPN(tokens2);
    cout << "Input: ";
    printTokens(tokens2);
    cout << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: (4 + (13 / 5)) = 6" << endl << endl;
    
    // Test Case 3: Complex expression
    cout << "Test Case 3:" << endl;
    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result3 = solution.evalRPN(tokens3);
    cout << "Input: ";
    printTokens(tokens3);
    cout << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: Complex nested expression" << endl << endl;
    
    // Test Case 4: Single number
    cout << "Test Case 4:" << endl;
    vector<string> tokens4 = {"18"};
    int result4 = solution.evalRPN(tokens4);
    cout << "Input: ";
    printTokens(tokens4);
    cout << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Single number returns itself" << endl << endl;
    
    // Test Case 5: All operations
    cout << "Test Case 5:" << endl;
    vector<string> tokens5 = {"3","4","+","2","*","7","/"};
    int result5 = solution.evalRPN(tokens5);
    cout << "Input: ";
    printTokens(tokens5);
    cout << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: ((3 + 4) * 2) / 7 = 2" << endl << endl;
    
    // Test Case 6: Negative numbers
    cout << "Test Case 6:" << endl;
    vector<string> tokens6 = {"-2","3","+"};
    int result6 = solution.evalRPN(tokens6);
    cout << "Input: ";
    printTokens(tokens6);
    cout << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: (-2 + 3) = 1" << endl << endl;
    
    // Test Case 7: Division truncation
    cout << "Test Case 7:" << endl;
    vector<string> tokens7 = {"7","3","/"};
    int result7 = solution.evalRPN(tokens7);
    cout << "Input: ";
    printTokens(tokens7);
    cout << endl;
    cout << "Output: " << result7 << endl;
    cout << "Explanation: (7 / 3) = 2 (truncates toward zero)" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<string>> testTokens = {
        {"2","3","4","*","+"},
        {"1","1","+"},
        {"4","2","/"}
    };
    vector<int> expected = {14, 2, 2};
    
    for (int i = 0; i < testTokens.size(); i++) {
        int result = solution.evalRPN(testTokens[i]);
        cout << "Test " << (i + 8) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}

