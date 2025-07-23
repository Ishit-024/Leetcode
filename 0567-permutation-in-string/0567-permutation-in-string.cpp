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
     vector<int>v1(26,0);
     vector<int>v2(26,0);
     for(int i=0;i<s1.size();i++){
        v1[s1[i]-'a']++;
     }
     int w=s1.length();
     int j=0;
     for(j=0;j<s2.length();j++){
        for(int k=j;k<j+w;k++){
            if(k>=s2.length()){
                return false;
            }
            v2[s2[k]-'a']++;
        }
        if(equal(v1,v2)){
            return true;
        }
            fill(v2.begin(), v2.end(), 0); 

        }
     return false;
    }
};