class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int max_sub = 0, l = 0;
        
        for (int r = 0; r < s.size(); r++) {
            // If the character is found inside our current active window, jump 'l'
            if (m.find(s[r]) != m.end() && m[s[r]] >= l) {
                l = m[s[r]] + 1;
            }
            m[s[r]] = r;
            max_sub = max(max_sub, r - l + 1);
        }
        
        return max_sub;
    }
};
