class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> target_counts;
        for (char c : t) target_counts[c]++;

        unordered_map<char, int> window_counts;
        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start_idx = 0;
        
        // Tracks how many unique characters match the exact target frequencies
        int formed = 0; 
        int required = target_counts.size();

        while (r < s.size()) {
            char c = s[r];
            window_counts[c]++;

            // If the current character match frequency hits the target frequency
            if (target_counts.count(c) && window_counts[c] == target_counts[c]) {
                formed++;
            }

            // Shrink the window from the left as long as it's valid
            while (l <= r && formed == required) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }

                char left_char = s[l];
                window_counts[left_char]--;
                
                if (target_counts.count(left_char) && window_counts[left_char] < target_counts[left_char]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};
