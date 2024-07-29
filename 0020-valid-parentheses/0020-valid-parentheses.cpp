class Solution {
public:
    bool opening(char c){
        if(c=='(' || c=='[' || c=='{'){
            return true;
        }
        else{
            return false;
        }
    }
    bool closing(char c){
        if(c==')' || c==']' || c=='}'){
            return true;
        }
        else{
            return false;
        }
    }
    bool matching(char c, char d){
        if(c=='(' && d==')' || c=='[' && d==']' || c=='{' && d=='}'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValid(string s) {
        int x;
       stack<char>st;
       if(s.length()==1){
        return false;
       }
       if(closing(s[0])){
        return false;
       }
       for(int i=0;i<s.length();i++){
            if(opening(s[i])){
                st.push(s[i]);
            }
            else if(closing(s[i])==true && !st.empty()){
                x=st.top();
                st.pop();
                if(matching(x,s[i])==false){
                    return false;
                }
            }
            else if(closing(s[i])==true && st.empty()){
                return false;
            }
       }
       if(st.empty()){
        return true;
       }
       else{
        return false;
       }
    }
};