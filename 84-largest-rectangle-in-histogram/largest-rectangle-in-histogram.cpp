class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> rightSmaller(n,0);

        //right smaller
        for(int i = n-1; i>= 0; i--){
            while(s.size()!= 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            rightSmaller[i] = s.size() == 0? n : s.top();
            s.push(i);
        } 

        //emptying the stack
        while(s.size()!= 0){
            s.pop();
        }

        vector<int> leftSmaller(n,0);
        //left smaller
        for(int i = 0; i< n; i++){
            while(s.size()!= 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            leftSmaller[i] = s.size() == 0? -1 : s.top();
            s.push(i);
        } 

        //final answer
        int ans = 0;
        for(int i = 0; i< n; i++){
            int width = rightSmaller[i] - leftSmaller[i] - 1;
            int currArea = heights[i]*width;
            ans = max(ans,currArea);
        }
        return ans;
    }
};