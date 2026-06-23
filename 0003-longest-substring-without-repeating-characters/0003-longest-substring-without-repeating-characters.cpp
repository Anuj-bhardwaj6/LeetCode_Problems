class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool duplicate = false;

                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        duplicate = true;
                        break;
                    }
                }

                if (duplicate)
                    break;

                int curlen = j - i + 1;
                maxlen = max(maxlen, curlen);
            }
        }

        return maxlen;
    }
};