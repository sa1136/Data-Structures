#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]])
                total -= roman[s[i]];
            else
                total += roman[s[i]];
        }
        total += roman[s.back()];
        return total;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic Roman numerals
    cout << "Test Case 1:" << endl;
    string input1 = "III";
    int result1 = solution.romanToInt(input1);
    cout << "Input: \"" << input1 << "\"" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: I = 1, I = 1, I = 1. Total = 1 + 1 + 1 = 3" << endl << endl;
    
    // Test Case 2: Subtraction case
    cout << "Test Case 2:" << endl;
    string input2 = "IV";
    int result2 = solution.romanToInt(input2);
    cout << "Input: \"" << input2 << "\"" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: I = 1, V = 5. Since I < V, we subtract: 5 - 1 = 4" << endl << endl;
    
    // Test Case 3: Mixed case
    cout << "Test Case 3:" << endl;
    string input3 = "IX";
    int result3 = solution.romanToInt(input3);
    cout << "Input: \"" << input3 << "\"" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: I = 1, X = 10. Since I < X, we subtract: 10 - 1 = 9" << endl << endl;
    
    // Test Case 4: Larger number
    cout << "Test Case 4:" << endl;
    string input4 = "LVIII";
    int result4 = solution.romanToInt(input4);
    cout << "Input: \"" << input4 << "\"" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: L = 50, V = 5, I = 1, I = 1, I = 1. Total = 50 + 5 + 1 + 1 + 1 = 58" << endl << endl;
    
    // Test Case 5: Complex case with multiple subtractions
    cout << "Test Case 5:" << endl;
    string input5 = "MCMXC";
    int result5 = solution.romanToInt(input5);
    cout << "Input: \"" << input5 << "\"" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: M = 1000, C = 100, M = 1000, X = 10, C = 100" << endl;
    cout << "M + (M - C) + (C - X) = 1000 + 900 + 90 = 1990" << endl << endl;
    
    // Test Case 6: Edge case - single character
    cout << "Test Case 6:" << endl;
    string input6 = "M";
    int result6 = solution.romanToInt(input6);
    cout << "Input: \"" << input6 << "\"" << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: M = 1000" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<string> testCases = {"XXVII", "CDXLIV", "CMXCIX", "MMMCMXCIX"};
    vector<int> expected = {27, 444, 999, 3999};
    
    for (int i = 0; i < testCases.size(); i++) {
        int result = solution.romanToInt(testCases[i]);
        cout << "\"" << testCases[i] << "\" -> " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}
