/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL || *s == '\0') return 0;
        char *i = (char *)s;
        bool prespace = true;
        int length = 0;
        while (*i != '\0') {
            if (*i == ' ')  {
                prespace = true;
            } else {
                if (prespace == true) {
                    length = 1;
                    prespace = false;
                } else {
                    length ++;
                }
            }
            i++;
        }
        return length;
    }
};
