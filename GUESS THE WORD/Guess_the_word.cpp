#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Master class interface (provided by LeetCode)
class Master {
public:
    string secretWord;
    int allowedGuesses;
    int guessCount;
    
    Master(string secret, int allowed) : secretWord(secret), allowedGuesses(allowed), guessCount(0) {}
    
    int guess(string word) {
        guessCount++;
        if (guessCount > allowedGuesses) {
            cout << "Exceeded allowed guesses!" << endl;
            return -1;
        }
        
        // Count matches at same positions
        int matches = 0;
        for (int i = 0; i < 6 && i < word.size() && i < secretWord.size(); i++) {
            if (word[i] == secretWord[i]) matches++;
        }
        
        cout << "Guess #" << guessCount << ": \"" << word << "\" -> " << matches << " matches" << endl;
        return matches;
    }
};

class Solution {
public:
    // count matches at same positions between two 6-letter words
    int matchCount(const string &a, const string &b) {
        int cnt = 0;
        for (int i = 0; i < 6; ++i) if (a[i] == b[i]) ++cnt;
        return cnt;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        // According to constraints allowedGuesses is between 10 and 30.
        // Use 30 as an upper bound so we don't prematurely stop.
        for (int attempt = 0; attempt < 30 && !words.empty(); ++attempt) {
            // Compute for every candidate word, the worst-case bucket size
            // when used as a guess (minimax).
            unordered_map<string,int> worstBucket;
            for (const string &w1 : words) {
                int worst = 0;
                // buckets for match counts 0..6
                int buckets[7] = {0};
                for (const string &w2 : words) {
                    if (&w1 == &w2) continue; // skip same object (optional)
                    ++buckets[ matchCount(w1, w2) ];
                }
                for (int k = 0; k <= 6; ++k) worst = max(worst, buckets[k]);
                worstBucket[w1] = worst;
            }

            // choose the word with minimal worstBucket value
            string guessWord = words[0];
            int bestValue = worstBucket[guessWord];
            for (const string &w : words) {
                if (worstBucket[w] < bestValue) {
                    bestValue = worstBucket[w];
                    guessWord = w;
                }
            }

            int res = master.guess(guessWord);
            if (res == 6) {
                cout << "Found secret word: \"" << guessWord << "\"" << endl;
                return; // found secret
            }

            // filter candidates to those that would give same match count with guessWord
            vector<string> next;
            next.reserve(words.size());
            for (const string &w : words) {
                if (matchCount(guessWord, w) == res) next.push_back(w);
            }
            words.swap(next);
        }
        // If we exit loop without finding the secret, the judge will report failure.
        cout << "Could not find secret word within allowed guesses!" << endl;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<string> words1 = {"acckzz","ccbazz","eiowzz","abcczz"};
    string secret1 = "acckzz";
    Master master1(secret1, 10);
    vector<string> wordsCopy1 = words1;
    solution.findSecretWord(wordsCopy1, master1);
    cout << endl;
    
    // Test Case 2: Another example
    cout << "Test Case 2:" << endl;
    vector<string> words2 = {"hamada","khaled"};
    string secret2 = "hamada";
    Master master2(secret2, 10);
    vector<string> wordsCopy2 = words2;
    solution.findSecretWord(wordsCopy2, master2);
    cout << endl;
    
    // Test Case 3: Multiple words
    cout << "Test Case 3:" << endl;
    vector<string> words3 = {"abcdef","acdefg","bcdefg","cdefgh","defghi","efghij","fghijk"};
    string secret3 = "cdefgh";
    Master master3(secret3, 10);
    vector<string> wordsCopy3 = words3;
    solution.findSecretWord(wordsCopy3, master3);
    cout << endl;
    
    return 0;
}

