class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
                nums.erase(nums.begin()+i,nums.begin()+i+1);
                i--;
                
        }
        }
        // nums.erase(nums.begin(),nums.begin()+count);
        for(int i=0;i<count;i++){
            nums.push_back(0);
        }
        }
};