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
        char *start = NULL;
        char *end = NULL;
        bool prespace = true;
        while (*i != '\0') {
            if (*i == ' ')  {
                prespace = true;
            } else {
                if (prespace == true) {
                    start = i;
                    end = start;
                    prespace = false;
                } else {
                    end = i;
                }
            }
            i++;
        }
        if (start == NULL) {
            return 0;
        }
        int j = 0;
        while (start != end + 1) {
            j++;
            start ++;
        }
        return j;
    }
};
