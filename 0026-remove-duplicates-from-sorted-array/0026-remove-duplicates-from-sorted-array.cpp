
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=nums.size();
        for(int i=0;i<x-1;i++){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i,nums.begin()+i+1);
                i--;
                x--;
            }
        }
        return nums.size();
    }
};