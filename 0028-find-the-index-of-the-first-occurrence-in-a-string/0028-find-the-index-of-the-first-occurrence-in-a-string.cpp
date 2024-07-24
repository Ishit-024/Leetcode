class Solution {
public:
    int strStr(string haystack, string needle) {
       int i = 0;
        int j = 0;
        int count = 0;
        std::vector<int> v;
        while (i < haystack.length()) {
            if (haystack[i] == needle[j]) {
                j++;
                if (j == needle.length()) {
                    return i - j + 1;
                }
            } else {
                i = i - j; 
                j=0;
            }
            i++;
        }
        return -1;
    }
};