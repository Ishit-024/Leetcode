class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                return nums[i];
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            count=count^nums[i];
        }
        for(int i=1;i<nums.size();i++){
            count=count^i;
        }
        return count;
    }
};