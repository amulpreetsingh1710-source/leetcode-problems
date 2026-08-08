class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> s;
        int n = height.size();
        vector<int> right(n,0);

        for(int i = n-1;i >= 0;i--){
            while(s.size() != 0 && s.top() <= height[i]){
                s.pop();
            }
            right[i] = s.size() == 0 ? -1 : s.top();

            if(s.size() != 0 && height[i] < s.top()){
                continue;
            }
            s.push(height[i]);
        }

        while(s.size()!= 0){
            s.pop();
        }


        vector<int> left(n,0);

        for(int i = 0; i< n; i++){

            while(s.size() != 0 && s.top() <= height[i]){
                s.pop();
            }
            left[i] = s.size() == 0 ? -1 : s.top();

            if(s.size() != 0 && height[i] < s.top()){
                continue;
            }
            s.push(height[i]);
        }

        int area = 0;
        for(int i= 0; i< n ;i++){
            if(right[i] == -1 || left[i] == -1){
                continue;
            }
            else if(right[i] > left[i]){
                area += left[i] - height[i];
            }
            else{
                area += right[i] - height[i];
            }
            
        }
        return area;
    }
};