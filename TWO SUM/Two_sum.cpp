#include <iostream>
using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        int n= nums.size();
        unordered_map<int, int> map;
        for( int i=0;i<n;i++){
            int num = nums[i];
            int more = target - num;
            if(map.find(more)!=map.end()){
                return {map[more],i};
            }
            map[num]=i;
        }
        return {-1,1};
    }
};

int main (){
    int target =5;
    vector<int> nums = {2,3,11,15};
    Solution sol;
    vector<int> result = sol.twoSum(nums,target);
    cout<<"The two indices are: "<< result[0] << " and " << result[1] << endl;
    return 0;
}
