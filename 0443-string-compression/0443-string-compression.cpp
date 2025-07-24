class Solution {
public:
    int counter(vector<char>& chars,int start){
        int count1=1;
        for(int i=start;i<chars.size()-1;i++){
            if(chars[i]==chars[i+1]){
                count1++;
            }
            else{
                break;
            }
        }
        return count1;
    }

    int compress(vector<char>& chars) {
        int a=0;
        string s1;
        for(int i=0; i<chars.size(); i=i+a){
            a = counter(chars,i);
            if(a == 1){
                s1.push_back(chars[i]);
            }
            else{
                s1.push_back(chars[i]);
                string temp = to_string(a);
                for (char ch : temp) {
                    s1.push_back(ch);
                }
            }
        }
        for(int i=0;i<s1.length();i++){
            chars[i]=s1[i];
        }
        return s1.length();
    }
};
