class Solution {
public:
    int countHomogenous(string s) {
        int curr_streak = 1;
        long long total_slices = 1;
        int MOD = 1e9 + 7;

        for(int i = 1; i < s.size(); i++){
            // 1. Only manage the streak logic inside the if-else
            if(s[i] == s[i-1]){
                curr_streak++;
            }
            else{
                curr_streak = 1;
            }
            
            // 2. Perform the calculation uniformly for every character
            total_slices = (total_slices + curr_streak) % MOD;
        }

        return (int)total_slices; // Cast back to int for the return type
    }
};
