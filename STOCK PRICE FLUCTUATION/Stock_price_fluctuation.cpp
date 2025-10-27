#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class StockPrice {
private:
    unordered_map<int, int> time_Price;  // timestamp -> price
    priority_queue<pair<int, int>> max_heap;  // price, timestamp
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;  // price, timestamp 
    int latestTime;
    
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        // Update with new price
        time_Price[timestamp] = price;
        max_heap.push({price, timestamp});
        min_heap.push({price, timestamp});
        latestTime = max(latestTime, timestamp);
    }
    
    int current() {
        return time_Price[latestTime];
    }
    
    int maximum() {
        while(!max_heap.empty()){
            auto [price, timestamp] = max_heap.top();
            if(time_Price[timestamp] == price){
                return price;
            }
            max_heap.pop();
        }
        return -1;
    }
    
    int minimum() {
        while(!min_heap.empty()){
            auto [price, timestamp] = min_heap.top();
            if(time_Price[timestamp] == price){
                return price;
            }
            min_heap.pop();
        }
        return -1;
    }
};


vector<int> processOperations(vector<vector<int>> operations) {
    StockPrice stockPrice;
    vector<int> result;
    
    for (auto& op : operations) {
        if (op.size() == 2) {
            // Update operation: [timestamp, price]
            stockPrice.update(op[0], op[1]);
            result.push_back(-1); // null represented as -1
        } else if (op.size() == 1) {
            // Query operation: [operation_type]
            if (op[0] == 1) {
                result.push_back(stockPrice.current());
            } else if (op[0] == 2) {
                result.push_back(stockPrice.maximum());
            } else if (op[0] == 3) {
                result.push_back(stockPrice.minimum());
            }
        }
    }
    
    return result;
}

int main() {
    // Test case 1: operations as arrays
    // Format: [timestamp, price] for update, [operation_type] for query
    // operation_type: 1=current, 2=maximum, 3=minimum
    vector<vector<int>> operations1 = {
        {1, 10},    // update(1, 10)
        {2, 5},     // update(2, 5)
        {1},        // current() -> 5
        {2},        // maximum() -> 10
        {3},        // minimum() -> 5
        {1, 3},     // update(1, 3)
        {1},        // current() -> 5
        {2},        // maximum() -> 5
        {3},        // minimum() -> 3
        {4, 2},     // update(4, 2)
        {1},        // current() -> 2
        {2},        // maximum() -> 5
        {3}         // minimum() -> 2
    };
    
    cout << "Test Case 1 - Operations as Arrays:" << endl;
    vector<int> result1 = processOperations(operations1);
    
    cout << "Operations: ";
    for (auto& op : operations1) {
        if (op.size() == 2) {
            cout << "[" << op[0] << "," << op[1] << "] ";
        } else {
            cout << "[" << op[0] << "] ";
        }
    }
    cout << endl;
    
    cout << "Results: ";
    for (int i = 0; i < result1.size(); i++) {
        if (result1[i] == -1) {
            cout << "null ";
        } else {
            cout << result1[i] << " ";
        }
    }
    cout << endl << endl;
    
    // Test case 2: Another example
    vector<vector<int>> operations2 = {
        {1, 10},    // update(1, 10)
        {2, 5},     // update(2, 5)
        {1, 3},     // update(1, 3)
        {4, 2},     // update(4, 2)
        {1},        // current() -> 2
        {2},        // maximum() -> 5
        {3}         // minimum() -> 2
    };
    
    cout << "Test Case 2 - Operations as Arrays:" << endl;
    vector<int> result2 = processOperations(operations2);
    
    cout << "Operations: ";
    for (auto& op : operations2) {
        if (op.size() == 2) {
            cout << "[" << op[0] << "," << op[1] << "] ";
        } else {
            cout << "[" << op[0] << "] ";
        }
    }
    cout << endl;
    
    cout << "Results: ";
    for (int i = 0; i < result2.size(); i++) {
        if (result2[i] == -1) {
            cout << "null ";
        } else {
            cout << result2[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}
