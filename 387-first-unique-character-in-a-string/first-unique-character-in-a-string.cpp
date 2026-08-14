class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> q;
        unordered_map<char,int> m;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]] = -1;
            }else{
                m[s[i]] = i;
                q.push(s[i]);
            }
        }
        while(!q.empty() && m[q.front()] == -1 ){
            q.pop();
        }
        if(q.empty()){
            return -1;
        }else{
            return m[q.front()];
        }
        
    }
};