class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0;
        int rmax = 0;

        int l = 0;
        int r = n -1;
        int area = 0;
        while(l < r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);

            if(lmax < rmax){
                area += lmax-height[l];
                l++;
            }
            else{
                area += rmax-height[r];
                r--;
            }
        }
        return area;
    }
};