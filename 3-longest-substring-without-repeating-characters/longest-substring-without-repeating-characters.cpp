class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> m;
        int max_sub = 0;
        int l = 0,r = 0;
        
        for(int i = 0; i< s.size(); i++){
            if(m.find(s[i]) != m.end()){
                r = i;
                max_sub = max(max_sub,r-l);
                l = m[s[i]] + 1;
                m[s[i]] = i;
                r++;
                break;
            }
            else{
                m[s[i]] = i;
            }
        }

        if(r == 0){
            return s.size();
        }
        while(r < s.size()){ 
            if(m.find(s[r]) != m.end()){
                if(m[s[r]] < l){
                   max_sub = max(max_sub, r -l + 1);
                   m[s[r]] = r; 
                }
                else{
                    l = m[s[r]] + 1;
                    m[s[r]] = r; 
                }
                
            }
            else{
                m[s[r]] = r;
                max_sub = max(max_sub, r -l + 1);
            }
            r++;
        }

        return max_sub;
    }
};