class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;  // char → last seen index
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If duplicate found INSIDE current window → shrink left
            if (lastSeen.count(c) && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;                        // update last seen
            maxLen = max(maxLen, right - left + 1);     // update answer
        }

        return maxLen;
    }
};