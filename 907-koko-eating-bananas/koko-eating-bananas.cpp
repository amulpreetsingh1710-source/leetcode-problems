class Solution {
public:

    long long time_koko_takes(vector<int>& piles,int k,int n){
        long long time = 0;                        //to prevent integer overflow take long long
        for(int i = 0; i< n; i++){
            time += (piles[i] + k - 1) / k;
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        

        int max_bananas = piles[0];       //maximum koko can eat in a hour
        int min_bananas = 1;

        for(int i = 1; i< n; i++){
            max_bananas = max(max_bananas,piles[i]);
            
        }

        if(n == h){
            return max_bananas;
        }
        
        int ans = -1;
        while(min_bananas <= max_bananas){
            int k = min_bananas + (max_bananas-min_bananas)/2;   //bananas per hpur koko can eat

            long long t = time_koko_takes(piles,k,n);   // time koko takes to finish all piles

            if(t <= h){
                ans = k;                         // if time less then decerease the max_baananas so that koko take more time to finish the piles
                max_bananas = k - 1;
            }
            else{
                // if time more then increase the max_baananas so that koko take less time to finish the piles
                min_bananas = k + 1;
            }
        }
        return ans;
    }
};