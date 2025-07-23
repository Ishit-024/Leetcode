class Solution {
public:
    string removeDuplicates(string s) {
        for (int i = 0; i < (int)s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                s.erase(i, 2);  // erase 2 characters starting at index i
                i = max(-1, i - 2);  // step back to check for new duplicates
            }
        }
        return s;
    }
};