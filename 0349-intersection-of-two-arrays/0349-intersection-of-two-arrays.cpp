class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       std::sort(nums1.begin(),nums1.end());
       std::sort(nums2.begin(),nums2.end());
       vector<int>ans;
       set<int>s;
       int i=0;
       int j=0;
       while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]==nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
       }
       int x=i;
    //    if(i<nums1.size()){
    //     for(int k=i;k<nums1.size();k++){
    //         ans.push_back(nums1[k]);
    //     }
    //    }
    //    else if(j<nums2.size()){
    //     for(int t=j;t<nums2.size();t++){
    //         ans.push_back(nums2[t]);
    //     }
    //    }
       for(auto i:ans){
        s.insert(i);
       }
       vector<int>v;
       for(auto i:s){
        v.push_back(i);
       }
       return v;
    }
};