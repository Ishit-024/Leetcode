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
      vector<int>v={0};
      std::sort(arr.begin(),arr.end());
      int a=0;
      for(int i=0;i<arr.size();i=i+a){
        a=countx(arr,arr[i]);
        v.push_back(a);
      }
      set<int>s;
      for(auto i:v){
        s.insert(i);
      }
      if(s.size()==v.size()){
        return true;
      }
      return false;
    }
};