#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        // dp[i] = minimum total height to place first i books
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // Base case: no books, height = 0

        // Iterate over each book as the ending book of a shelf
        for (int i = 1; i <= n; i++) {
            int width = 0;   // Current shelf total width
            int height = 0;  // Current shelf max height

            // Try to include books[j-1 ... i-1] on the same shelf
            for (int j = i; j >= 1; j--) {
                width += books[j - 1][0]; // Add the width of the current book
                if (width > shelfWidth) break; // Can't fit more books on this shelf

                // Update shelf height based on tallest book
                height = max(height, books[j - 1][1]);

                // Update dp[i]:
                // dp[j-1] → total height of books before current shelf
                // + height → height of this shelf
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }

        // dp[n] holds the minimum total height for all books
        return dp[n];
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<vector<int>> books1 = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    int shelfWidth1 = 4;
    int result1 = solution.minHeightShelves(books1, shelfWidth1);
    cout << "Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: Minimum total height is 6" << endl << endl;
    
    // Test Case 2: Another example
    cout << "Test Case 2:" << endl;
    vector<vector<int>> books2 = {{1,3},{2,4},{3,2}};
    int shelfWidth2 = 6;
    int result2 = solution.minHeightShelves(books2, shelfWidth2);
    cout << "Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: All books can fit on one shelf with height 4" << endl << endl;
    
    // Test Case 3: Each book on separate shelf
    cout << "Test Case 3:" << endl;
    vector<vector<int>> books3 = {{1,1},{1,2},{1,3}};
    int shelfWidth3 = 1;
    int result3 = solution.minHeightShelves(books3, shelfWidth3);
    cout << "Input: books = [[1,1],[1,2],[1,3]], shelfWidth = 1" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: Each book on separate shelf, total height is 6" << endl << endl;
    
    // Test Case 4: All on one shelf
    cout << "Test Case 4:" << endl;
    vector<vector<int>> books4 = {{1,5},{1,3},{1,2}};
    int shelfWidth4 = 10;
    int result4 = solution.minHeightShelves(books4, shelfWidth4);
    cout << "Input: books = [[1,5],[1,3],[1,2]], shelfWidth = 10" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: All books on one shelf, height is 5 (tallest)" << endl << endl;
    
    // Test Case 5: Mixed arrangement
    cout << "Test Case 5:" << endl;
    vector<vector<int>> books5 = {{7,3},{8,7},{2,7},{2,5}};
    int shelfWidth5 = 10;
    int result5 = solution.minHeightShelves(books5, shelfWidth5);
    cout << "Input: books = [[7,3],[8,7],[2,7],[2,5]], shelfWidth = 10" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: Optimal arrangement needed" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<vector<int>>> testBooks = {
        {{2,2},{2,2}},
        {{1,1},{1,1},{1,1}}
    };
    vector<int> testWidths = {3, 2};
    vector<int> expected = {4, 3};
    
    for (int i = 0; i < testBooks.size(); i++) {
        int result = solution.minHeightShelves(testBooks[i], testWidths[i]);
        cout << "Test " << (i + 6) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}

