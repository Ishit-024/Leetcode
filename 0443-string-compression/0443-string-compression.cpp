class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, i = 0;

        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            // Count the occurrences of the current character
            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the character to the write position
            chars[write++] = currentChar;

            // If count is greater than 1, write the count
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
