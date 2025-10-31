#include <iostream>
#include <string>
using namespace std;

int shortestWay(string source, string target) {
    int i = 0; // pointer for target
    int count = 0; // number of subsequences used

    while (i < target.size()) {
        int prev_i = i; // store position before current pass

        for (char c : source) {
            if (i < target.size() && c == target[i]) {
                i++;
            }
        }

        if (prev_i == i) {
            // No progress in this pass, impossible to form target
            return -1;
        }

        count++; // one subsequence used
    }

    return count;
}

// Example usage
int main() {
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    string source1 = "abc";
    string target1 = "abcbc";
    int result1 = shortestWay(source1, target1);
    cout << "Input: source = \"" << source1 << "\", target = \"" << target1 << "\"" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: We need 2 subsequences: \"abc\" and \"bc\"" << endl << endl;
    
    // Test Case 2: Impossible case
    cout << "Test Case 2:" << endl;
    string source2 = "abc";
    string target2 = "acdbc";
    int result2 = shortestWay(source2, target2);
    cout << "Input: source = \"" << source2 << "\", target = \"" << target2 << "\"" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: Cannot form target (character 'd' not in source)" << endl << endl;
    
    // Test Case 3: Single subsequence
    cout << "Test Case 3:" << endl;
    string source3 = "xyz";
    string target3 = "xzyxz";
    int result3 = shortestWay(source3, target3);
    cout << "Input: source = \"" << source3 << "\", target = \"" << target3 << "\"" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: We need 3 subsequences" << endl << endl;
    
    // Test Case 4: Target is same as source
    cout << "Test Case 4:" << endl;
    string source4 = "abc";
    string target4 = "abc";
    int result4 = shortestWay(source4, target4);
    cout << "Input: source = \"" << source4 << "\", target = \"" << target4 << "\"" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: We need 1 subsequence (exact match)" << endl << endl;
    
    // Test Case 5: Repeated characters
    cout << "Test Case 5:" << endl;
    string source5 = "aaaa";
    string target5 = "aaaaaaaaaaaaa";
    int result5 = shortestWay(source5, target5);
    cout << "Input: source = \"" << source5 << "\", target = \"" << target5 << "\"" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: Multiple subsequences needed for repeated characters" << endl << endl;
    
    // Test Case 6: Single character source
    cout << "Test Case 6:" << endl;
    string source6 = "a";
    string target6 = "aaaa";
    int result6 = shortestWay(source6, target6);
    cout << "Input: source = \"" << source6 << "\", target = \"" << target6 << "\"" << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: Single character can form multiple subsequences" << endl << endl;
    
    return 0;
}

