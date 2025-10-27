#include <iostream>
using namespace std;

class Solution {
    public:
    int racecar(int target){
        vector<int> dp(target + 1, INT_MAX);
        dp[0]=0;

        for( int t=1; t<=target; t++){
            int k= 1;
            while((1<<k)-1<t){
                k++;
            }

            if((1<<k)-1==t){
                dp[t]=k;
                continue;
            }
            dp[t]=k+1+dp[t-(1<<k)+1];

            for( int m=0; m<k-1; m++){
                int forward= (1<<(k-1))-1;
                int backward= (1<<m)-1;
                dp[t]=min(dp[t], k-1+m+1+dp[t-forward+backward]);
            }
        }
        return dp[target];
    }

};

int main() {
    Solution sol;
    cout<<"Enter the target: ";
    int target;
    cin>>target;
    int result =sol.racecar(target);
    cout<<"The minimum number of instructions to reach the target is: "<< result << endl;
    return 0;
}