class Solution {
     bool equal(vector<int>v1,vector<int>v2){
        for(int i=0;i<v2.size();i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
     }
public:
    bool checkInclusion(string s1, string s2) {
     vector<int>v1(26);
     vector<int>v2(26);
     for(int i=0;i<s1.size();i++){
        v1[s1[i]-'a']++;
     }
     int window_size=s1.size();
     int i=0;
     while(i<window_size && i<s2.size()){
        int index=s2[i]-'a';
        v2[index]++;
        if(equal(v1,v2)){
            return true;
        }
        i++;
     }
     while(i<s2.size()){
        int index=s2[i]-'a';
        v2[index]++;
        int index2=s2[i-window_size]-'a';
        v2[index2]--;
        if(equal(v1,v2)){
            return true;
        }
        i++;
     }
        return false;
     }
};