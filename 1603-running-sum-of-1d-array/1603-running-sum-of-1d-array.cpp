class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int k=0;k<=i;k++){
                sum=sum+nums[k];
            }
            v.push_back(sum);
        }
        return v;
    }
};