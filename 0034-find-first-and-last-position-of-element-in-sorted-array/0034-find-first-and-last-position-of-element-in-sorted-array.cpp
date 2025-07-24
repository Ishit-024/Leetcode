class Solution {
public:
int search(vector<int>&nums,int t){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==t){
            count++;
        }
    }
    return count;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int a=search(nums,target);
        if(a==0){
            v.push_back(-1);
            v.push_back(-1);
        }
        else{
            if(a==1){
                 for(int i=0;i<nums.size();i++){
                    if(nums[i]==target){
                        v.push_back(i);
                        v.push_back(i);
                        break;
                    }
            }
            }
            else{
                for(int i=0;i<nums.size();i++){
                    if(nums[i]==target){
                        v.push_back(i);
                        break;
                    }
                }
                for(int i=nums.size()-1;i>=0;i--){
                    if(nums[i]==target){
                        v.push_back(i);
                        break;
                    }
                }
            }
        }
        return v;
        }
};