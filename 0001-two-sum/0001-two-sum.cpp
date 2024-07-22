class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>duplicate=nums;
        vector<int>ans;
        vector<int>ans1;
        std::sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<=nums.size() && j>=0){
        if(nums[i]+nums[j]<target){
            i++;
        }
        else if(i==j){
            j++;
        }
        else if(nums[i]+nums[j]==target){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            break;
        }
        else{
            j--;
        }        
        }
        for(int i=0;i<duplicate.size();i++){
            if(duplicate[i]==ans[0] || duplicate[i]==ans[1]){
                ans1.push_back(i);
            }
        }
        return ans1;
    }
};