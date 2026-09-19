#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;

        // Step 1: Store frequencies of all characters in string t
        for(int i = 0; i < t.size(); i++){
            m[t[i]]++;
        }

        int count = 0;
        int minLen = INT_MAX;
        int l = 0, r = 0;
        int stIdx = -1;

        // Step 2: Expand the right pointer (r)
        while(r < s.size()){
            // If the character is needed (count in map > 0), increment our match count
            if(m[s[r]] > 0){
                count++;
            }
            // Decrement the map frequency (non-t characters will become negative)
            m[s[r]]--;

            // Step 3: When a valid window is found, try to shrink it from the left (l)
            while(count == t.size()) {
                // Update minimum length and starting index if a smaller window is found
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    stIdx = l;
                }

                // Since we are moving 'l' out of the window, we restore its count in the map
                m[s[l]]++;
                
                // If it goes back above 0, it means a required character from 't' is now missing
                if(m[s[l]] > 0){
                    count--;
                }
                l++; // Shrink the window
            }

            r++; // Expand the window
        }
        
        // Return the substring if found, otherwise return an empty string
        return stIdx == -1 ? "" : s.substr(stIdx, minLen);
    }
};
