#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> current;
        int num_of_letters = 0;

        for (string& word : words) {
            // Check if adding this word exceeds width
            if (num_of_letters + word.size() + current.size() > maxWidth) {
                int spaces = maxWidth - num_of_letters;
                int gaps = current.size() - 1;

                if (gaps == 0) {
                    // Only one word -> left justified
                    result.push_back(current[0] + string(spaces, ' '));
                } else {
                    int even_space = spaces / gaps;
                    int extra = spaces % gaps;
                    string line = "";
                    for (int i = 0; i < gaps; i++) {
                        line += current[i];
                        line += string(even_space + (i < extra ? 1 : 0), ' ');
                    }
                    line += current.back();
                    result.push_back(line);
                }

                current.clear();
                num_of_letters = 0;
            }
            current.push_back(word);
            num_of_letters += word.size();
        }

        // Handle last line - left justified
        string lastLine = "";
        for (int i = 0; i < current.size(); i++) {
            if (i > 0) lastLine += ' ';
            lastLine += current[i];
        }
        lastLine += string(maxWidth - lastLine.size(), ' ');
        result.push_back(lastLine);

        return result;
    }
};

void printResult(const vector<string>& result) {
    cout << "[" << endl;
    for (size_t i = 0; i < result.size(); i++) {
        cout << "  \"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ",";
        cout << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = solution.fullJustify(words1, maxWidth1);
    cout << "Input: words = [\"This\", \"is\", \"an\", \"example\", \"of\", \"text\", \"justification.\"], maxWidth = 16" << endl;
    cout << "Output:" << endl;
    printResult(result1);
    cout << endl;
    
    // Test Case 2: Another example
    cout << "Test Case 2:" << endl;
    vector<string> words2 = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth2 = 16;
    vector<string> result2 = solution.fullJustify(words2, maxWidth2);
    cout << "Input: words = [\"What\",\"must\",\"be\",\"acknowledgment\",\"shall\",\"be\"], maxWidth = 16" << endl;
    cout << "Output:" << endl;
    printResult(result2);
    cout << endl;
    
    // Test Case 3: Single word per line
    cout << "Test Case 3:" << endl;
    vector<string> words3 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth3 = 20;
    vector<string> result3 = solution.fullJustify(words3, maxWidth3);
    cout << "Input: words = [\"Science\",\"is\",\"what\",\"we\",\"understand\",\"well\",\"enough\",\"to\",\"explain\",\"to\",\"a\",\"computer.\",\"Art\",\"is\",\"everything\",\"else\",\"we\",\"do\"], maxWidth = 20" << endl;
    cout << "Output (first 3 lines):" << endl;
    for (int i = 0; i < min(3, (int)result3.size()); i++) {
        cout << "  \"" << result3[i] << "\"" << endl;
    }
    cout << endl;
    
    // Test Case 4: Single word
    cout << "Test Case 4:" << endl;
    vector<string> words4 = {"Single"};
    int maxWidth4 = 10;
    vector<string> result4 = solution.fullJustify(words4, maxWidth4);
    cout << "Input: words = [\"Single\"], maxWidth = 10" << endl;
    cout << "Output:" << endl;
    printResult(result4);
    cout << endl;
    
    // Test Case 5: Two words
    cout << "Test Case 5:" << endl;
    vector<string> words5 = {"Two", "words"};
    int maxWidth5 = 10;
    vector<string> result5 = solution.fullJustify(words5, maxWidth5);
    cout << "Input: words = [\"Two\", \"words\"], maxWidth = 10" << endl;
    cout << "Output:" << endl;
    printResult(result5);
    cout << endl;
    
    return 0;
}

