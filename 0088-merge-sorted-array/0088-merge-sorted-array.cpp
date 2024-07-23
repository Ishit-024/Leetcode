class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>v;
        int i=0;
        int j=0;
        // nums1.erase(nums1.begin()+m,nums1.end());
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                nums1.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                nums1.push_back(nums2[j]);
                j++;
            }
            else{
                nums1.push_back(nums1[i]);
                nums1.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i<m){
            nums1.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            nums1.push_back(nums2[j]);
            j++;
        }
        nums1.erase(nums1.begin(),nums1.begin()+m+n);
        // return v;
    }
};