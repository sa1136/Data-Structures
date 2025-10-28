#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        // Build the graph
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            indegree[recipe] = ingredients[i].size();
            for (auto& ing : ingredients[i]) {
                graph[ing].push_back(recipe);
            }
        }
        
        // Initialize queue with supplies
        queue<string> q;
        for (auto& s : supplies)
            q.push(s);
        
        vector<string> ans;
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // If this ingredient can help make recipes
            for (auto& next : graph[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    ans.push_back(next);
                    q.push(next); // recipe now becomes available ingredient
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<string> recipes1 = {"bread"};
    vector<vector<string>> ingredients1 = {{"yeast","flour"}};
    vector<string> supplies1 = {"yeast","flour","corn"};
    vector<string> result1 = solution.findAllRecipes(recipes1, ingredients1, supplies1);
    cout << "Input: recipes = [\"bread\"], ingredients = [[\"yeast\",\"flour\"]], supplies = [\"yeast\",\"flour\",\"corn\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Explanation: We can make bread" << endl << endl;
    
    // Test Case 2: Multiple recipes
    cout << "Test Case 2:" << endl;
    vector<string> recipes2 = {"bread","sandwich"};
    vector<vector<string>> ingredients2 = {{"yeast","flour"},{"bread","meat"}};
    vector<string> supplies2 = {"yeast","flour","meat"};
    vector<string> result2 = solution.findAllRecipes(recipes2, ingredients2, supplies2);
    cout << "Input: recipes = [\"bread\",\"sandwich\"], ingredients = [[\"yeast\",\"flour\"],[\"bread\",\"meat\"]], supplies = [\"yeast\",\"flour\",\"meat\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Explanation: We can make bread and sandwich" << endl << endl;
    
    // Test Case 3: No recipes possible
    cout << "Test Case 3:" << endl;
    vector<string> recipes3 = {"bread","sandwich"};
    vector<vector<string>> ingredients3 = {{"yeast","flour"},{"bread","meat"}};
    vector<string> supplies3 = {"yeast","flour"};
    vector<string> result3 = solution.findAllRecipes(recipes3, ingredients3, supplies3);
    cout << "Input: recipes = [\"bread\",\"sandwich\"], ingredients = [[\"yeast\",\"flour\"],[\"bread\",\"meat\"]], supplies = [\"yeast\",\"flour\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Explanation: We can only make bread (no meat for sandwich)" << endl << endl;
    
    // Test Case 4: Complex dependency chain
    cout << "Test Case 4:" << endl;
    vector<string> recipes4 = {"juice","salad","sandwich"};
    vector<vector<string>> ingredients4 = {{"water","sugar"},{"lettuce","tomato"},{"bread","meat","cheese"}};
    vector<string> supplies4 = {"water","sugar","lettuce","tomato","bread","meat","cheese"};
    vector<string> result4 = solution.findAllRecipes(recipes4, ingredients4, supplies4);
    cout << "Input: recipes = [\"juice\",\"salad\",\"sandwich\"], ingredients = [[\"water\",\"sugar\"],[\"lettuce\",\"tomato\"],[\"bread\",\"meat\",\"cheese\"]], supplies = [\"water\",\"sugar\",\"lettuce\",\"tomato\",\"bread\",\"meat\",\"cheese\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result4.size(); i++) {
        cout << "\"" << result4[i] << "\"";
        if (i < result4.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Explanation: We can make all recipes" << endl << endl;
    
    // Test Case 5: Empty recipes
    cout << "Test Case 5:" << endl;
    vector<string> recipes5 = {};
    vector<vector<string>> ingredients5 = {};
    vector<string> supplies5 = {"flour","sugar"};
    vector<string> result5 = solution.findAllRecipes(recipes5, ingredients5, supplies5);
    cout << "Input: recipes = [], ingredients = [], supplies = [\"flour\",\"sugar\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result5.size(); i++) {
        cout << "\"" << result5[i] << "\"";
        if (i < result5.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Explanation: No recipes to make" << endl << endl;
    
    return 0;
}
