#include <iostream>
#include <map>
using namespace std;

class MyCalendar {
    private: map <int , int > m;

    public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            sum += it->second;
            if(sum > 1){
                // Revert the changes if booking fails
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

int main() {
    MyCalendar cal;
    bool results[3];
    
    results[0] = cal.book(10,20);
    results[1] = cal.book(15,25);
    results[2] = cal.book(20,30);
    
    cout << "Results array: ";
    for(int i = 0; i < 3; i++) {
        cout << (results[i] ? "true" : "false");
        if(i < 2) cout << ", ";
    }
    cout << endl;
    
    return 0;
}