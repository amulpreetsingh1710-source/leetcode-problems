class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;

        for(int i :nums){
            m[i]++;
        }
        for (int i = 0; i < k; i++){
            int g = 0;
            int el = 0;
            for (auto &p:m)
            {
                if (p.second > g)
                {
                    g = p.second;
                    el = p.first;
                }
            }
            ans.push_back(el);
            m.erase(el);
        }
        return ans;
    }
};