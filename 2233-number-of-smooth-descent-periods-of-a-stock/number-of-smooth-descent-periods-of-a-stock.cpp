class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int curr_streak = 1;
        long long total_slices = 1;

        for(int i = 1; i< prices.size(); i++){
            if(prices[i] - prices[i-1] == -1){
                curr_streak++;
            }
            else{
                curr_streak = 1;
            }

            total_slices = (total_slices + curr_streak);
        }

        return total_slices;
    }
};