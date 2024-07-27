class Solution {
public:
string toLowerCase(string c){
    for(int i=0;i<c.length();i++){
    if(c[i]>='A' && c[i]<='Z'){
        c[i]=c[i]-'A'+'a';
    }
    }
    return c;
}
 bool valid(char c){
            if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
                return true;
            }
            return false;
        }
    bool isPalindrome(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            if(valid(s[i])){
                ans.push_back(s[i]);
            }
        }
       string ans2=toLowerCase(ans);
        string ans1=ans2;
        for(int i=0;i<ans2.length()/2;i++){
            swap(ans2[i],ans2[ans.length()-i-1]);
        }
        return ans2==ans1;
    }
};