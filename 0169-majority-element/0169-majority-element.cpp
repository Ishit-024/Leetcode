class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int z=nums.size()/2;
        int a=0;
        int count=1;
        if(nums.size()==1){
            return nums[0];
        } 
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
            else{
                count=1;
            }
            if(count>z){
                a=nums[i];
                break;
            }
        }
        return a;
    }
};