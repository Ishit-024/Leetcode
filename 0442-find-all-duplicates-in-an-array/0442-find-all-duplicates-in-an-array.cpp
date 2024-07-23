// #include<set>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    vector<int>v;
    int count=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]==nums[i]){
            v.push_back(nums[i]);
        }
    }
    return v;
    }
    };