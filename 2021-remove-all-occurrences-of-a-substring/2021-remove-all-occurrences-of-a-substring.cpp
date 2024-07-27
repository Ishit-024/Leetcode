class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.begin()+s.find(part),s.begin()+s.find(part)+part.length());
        }
        return s;
       
    }
};