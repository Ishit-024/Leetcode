class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       vector<int>v;
       vector<int>ans;
       int i=0;
       int j=0;
       std::sort(nums1.begin(),nums1.end());
       std::sort(nums2.begin(),nums2.end());
       while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            v.push_back(nums1[i]);
            i++;
            j++;
       }
       }
       set<int>s;
       for(auto i:v){
        s.insert(i);
       }
       for(auto i:s){
        ans.push_back(i);
       }
       return ans;
       }
};