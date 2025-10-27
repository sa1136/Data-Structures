#include <iostream>
#include <unordered_map>
using namespace std;

class Logger {
    private:
    unordered_map<string, int> m;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message)==m.end() || timestamp - m[message] >= 10){
            m[message] = timestamp;
            return true;
        }
        return false;
    }
};

int main() {
    Logger logger;
    bool results[6];
    
    // Test cases
    results[0] = logger.shouldPrintMessage(1, "foo");    // true
    results[1] = logger.shouldPrintMessage(2, "bar");    // true  
    results[2] = logger.shouldPrintMessage(3, "foo");    // false
    results[3] = logger.shouldPrintMessage(8, "bar");    // false
    results[4] = logger.shouldPrintMessage(10, "foo");   // false
    results[5] = logger.shouldPrintMessage(11, "foo");   // true
    
    cout << "Results array: ";
    for(int i = 0; i < 6; i++) {
        cout << (results[i] ? "true" : "false");
        if(i < 5) cout << ", ";
    }
    cout << endl;
    
    return 0;
}
