class Solution {
public:
    int countx(vector<int>&arr,int e){
        int count1=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==e){
                count1++;
            }
        }
        return count1;
    }
    bool uniqueOccurrences(vector<int>& arr) {
      vector<int>ans;
      set<int>s;
      std::sort(arr.begin(),arr.end());
      int count=0;
      for(int i=0;i<arr.size();i+=count){
        count=countx(arr,arr[i]);
        ans.push_back(count);
      }
      for(auto i:ans){
        s.insert(i);
      }
      if(s.size()==ans.size()){
        return true;
      }
      return false;
    }
};