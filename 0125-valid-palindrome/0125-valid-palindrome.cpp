class Solution {
public:

 bool valid(char c){
    if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
        return true;
    }
    return false;
 }
 char tolower(char c){
    if(c>='a' && c<='z'){
        return c;
    }
    char t=c-'A'+'a';
    return t;
 }
    bool isPalindrome(string s) {
       string x;
       for(int i=0;i<s.length();i++){
        if(valid(s[i])){
            x.push_back(s[i]);
        }
       }
       for(int i=0;i<x.length();i++){
        x[i]=tolower(x[i]);
       }
       for(int i=0;i<x.length()/2;i++){
        if(x[i]!=x[x.length()-i-1]){
            return false;
        }
       }
       return true;
    }

};